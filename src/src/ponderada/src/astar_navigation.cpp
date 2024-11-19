#include <rclcpp/rclcpp.hpp> 
#include <cg_interfaces/srv/move_cmd.hpp> 
#include <vector>
#include <queue> 
#include <string> 
#include <array> 
#include <iostream>

using namespace std::chrono_literals;

// Estrutura para representar a posição do robô na grade (x, y)
struct Position {
    int x, y; // Coordenadas x e y

    // Operador de comparação para verificar se duas posições são iguais
    bool operator==(const Position& other) const {
        return x == other.x && y == other.y;
    }
};

// Classe que representa o cliente que interage com o serviço de movimentação do robô
class MoveServiceClient : public rclcpp::Node
{
public:
    // Construtor da classe MoveServiceClient
    MoveServiceClient() : Node("move_service_client")
    {
        // Criação do cliente para interagir com o serviço '/move_command'
        client_ = this->create_client<cg_interfaces::srv::MoveCmd>("/move_command");

        // Inicializa a grade 20x20 com todas as posições marcadas como 'U' (não visitado)
        grid_ = std::vector<std::vector<char>>(20, std::vector<char>(20, 'U')); 
        robot_pos_ = {3, 3};  // Posição inicial do robô
        target_pos_ = {-1, -1}; // Posição do alvo ainda não definida
        last_direction_ = ""; // Última direção do movimento

        // Aguarda o serviço 'move_command' ser iniciado
        while (!client_->wait_for_service((std::chrono::milliseconds(1000)))) {
            RCLCPP_INFO(this->get_logger(), "Aguardando pelo serviço '/move_command'...");
        }

        // Marca a posição inicial do robô na grade
        grid_[robot_pos_.y][robot_pos_.x] = 'R';

        // Envia o movimento inicial
        send_initial_move();
    }

private:
    rclcpp::Client<cg_interfaces::srv::MoveCmd>::SharedPtr client_; // Cliente para o serviço MoveCmd
    std::vector<std::vector<char>> grid_; // Representação da grade 20x20
    Position robot_pos_; // Posição atual do robô
    Position target_pos_; // Posição do alvo
    std::queue<std::string> planned_moves_; // Fila de movimentos planejados
    std::string last_direction_; // Última direção de movimento

    // Função para enviar o primeiro movimento para o robô
    void send_initial_move()
    {
        std::vector<std::string> possible_directions = {"right", "down", "left", "up"};
        
        // Verifica as direções possíveis para o movimento inicial
        for (const auto &direction : possible_directions) {
            Position neighbor = get_neighbor_position(robot_pos_.x, robot_pos_.y, direction);
            
            // Se a posição vizinha está dentro dos limites e não é bloqueada, envia o movimento
            if (is_in_bounds(neighbor) && grid_[neighbor.y][neighbor.x] != 'B') {
                RCLCPP_INFO(this->get_logger(), "Enviando movimento inicial para a direção: %s", direction.c_str());
                send_move_request(direction);
                return;
            }
        }
        RCLCPP_WARN(this->get_logger(), "Nenhum movimento inicial válido encontrado!");
        rclcpp::shutdown(); // Encerra o ROS caso nenhum movimento válido seja encontrado
    }

    // Função para enviar a solicitação de movimento ao serviço
    void send_move_request(const std::string &direction)
    {
        last_direction_ = direction; // Atualiza a última direção movida

        auto request = std::make_shared<cg_interfaces::srv::MoveCmd::Request>(); // Cria a solicitação para o serviço
        request->direction = direction; // Define a direção do movimento

        RCLCPP_INFO(this->get_logger(), "Tentando mover %s da posição (%d, %d)", direction.c_str(), robot_pos_.x, robot_pos_.y);

        // Envia a solicitação de movimento e processa a resposta assíncrona
        auto future_result = client_->async_send_request(request,
            std::bind(&MoveServiceClient::process_response, this, std::placeholders::_1));
    }

    // Função para processar a resposta do serviço de movimento
    void process_response(rclcpp::Client<cg_interfaces::srv::MoveCmd>::SharedFuture response_future)
    {
        auto response = response_future.get(); // Obtém a resposta do serviço

        // Se o movimento foi bem-sucedido
        if (response->success) {
            RCLCPP_INFO(this->get_logger(), "Movimento %s bem-sucedido", last_direction_.c_str());

            // Marca a posição anterior como livre
            grid_[robot_pos_.y][robot_pos_.x] = 'F';

            // Atualiza a posição do robô
            robot_pos_.x = response->robot_pos[1];
            robot_pos_.y = response->robot_pos[0];
            grid_[robot_pos_.y][robot_pos_.x] = 'R'; // Marca a nova posição do robô na grade

            RCLCPP_INFO(this->get_logger(), "Robô movido para a posição (%d, %d)", robot_pos_.x, robot_pos_.y);

            // Se o alvo ainda não foi definido, define a posição do alvo
            if (target_pos_.x == -1) {
                target_pos_.x = response->target_pos[1];
                target_pos_.y = response->target_pos[0];
                grid_[target_pos_.y][target_pos_.x] = 'T'; // Marca o alvo na grade
                RCLCPP_INFO(this->get_logger(), "Posição alvo identificada em (%d, %d)", target_pos_.x, target_pos_.y);
            }

            // Atualiza a grade com as informações do sensor
            update_grid(response);

            // Verifica se o robô alcançou o alvo
            if (robot_pos_ == target_pos_) {
                RCLCPP_INFO(this->get_logger(), "Alvo alcançado!");
                rclcpp::shutdown(); // Encerra o ROS
                return;
            }

        } else { // Se o movimento falhou
            RCLCPP_WARN(this->get_logger(), "Falha ao mover %s da posição (%d, %d)", last_direction_.c_str(), robot_pos_.x, robot_pos_.y);

            // Marca a posição bloqueada na grade
            Position blocked_pos = get_neighbor_position(robot_pos_.x, robot_pos_.y, last_direction_);
            if (is_in_bounds(blocked_pos)) {
                grid_[blocked_pos.y][blocked_pos.x] = 'B';
                RCLCPP_INFO(this->get_logger(), "Posição (%d, %d) marcada como bloqueada", blocked_pos.x, blocked_pos.y);
            }

            // Limpa os movimentos planejados caso o movimento tenha falhado
            planned_moves_ = std::queue<std::string>(); 
            RCLCPP_INFO(this->get_logger(), "Movimentos planejados apagados devido à falha no movimento. Replanejando o caminho...");
        }

        // Se o alvo foi definido, planeja o caminho
        if (target_pos_.x != -1) {
            plan_path();
        }

        // Se houver movimentos planejados, envia o próximo movimento
        if (!planned_moves_.empty()) {
            std::string next_direction = planned_moves_.front();
            planned_moves_.pop();
            RCLCPP_INFO(this->get_logger(), "Próximo movimento planejado: %s", next_direction.c_str());
            sleep(1);
            send_move_request(next_direction);
        } else {
            RCLCPP_WARN(this->get_logger(), "Nenhum caminho disponível!");
            rclcpp::shutdown(); // Encerra o ROS se não houver caminho disponível
        }
    }

    // Função para atualizar a grade com as informações recebidas do sensor
    void update_grid(const std::shared_ptr<cg_interfaces::srv::MoveCmd::Response> &response)
    {
        int x = robot_pos_.x;
        int y = robot_pos_.y;

        RCLCPP_INFO(this->get_logger(), "Atualizando grade com base nos dados do sensor...");

        // Verifica as direções ao redor do robô e atualiza a grade conforme a informação do sensor
        if (is_in_bounds({x, y - 1})) {
            if (response->up == "b") {
                grid_[y - 1][x] = 'B'; // Marca a posição como bloqueada
                RCLCPP_INFO(this->get_logger(), "Posição (%d, %d) está bloqueada (cima)", x, y - 1);
            } else if (grid_[y - 1][x] == 'U') {
                grid_[y - 1][x] = 'F'; // Marca a posição como livre
                RCLCPP_INFO(this->get_logger(), "Posição (%d, %d) livre (cima)", x, y - 1);
            }
        }
        // Atualiza as demais direções (direita, esquerda, baixo) de maneira similar...
    }

    // Função para verificar se uma posição está dentro dos limites da grade
    bool is_in_bounds(const Position& pos) const {
        return pos.x >= 0 && pos.x < grid_.size() && pos.y >= 0 && pos.y < grid_[0].size();
    }

    // Função para calcular a posição vizinha com base na direção
    Position get_neighbor_position(int x, int y, const std::string &direction)
    {
        if (direction == "right") {
            return {x + 1, y}; // Para a direita
        } else if (direction == "down") {
            return {x, y + 1}; // Para baixo
        } else if (direction == "left") {
            return {x - 1, y}; // Para a esquerda
        } else if (direction == "up") {
            return {x, y - 1}; // Para cima
        }
        return {x, y}; // Posição inválida se direção desconhecida
    }

    // Função para planejar o caminho do robô até o alvo
    void plan_path()
    {
        RCLCPP_INFO(this->get_logger(), "Planejando caminho...");
    }
};

// Função principal para inicializar o nó ROS e rodar o cliente
int main(int argc, char * argv[])
{
    // Inicializa o ROS2
    rclcpp::init(argc, argv);

    // Cria o cliente do serviço
    rclcpp::spin(std::make_shared<MoveServiceClient>());

    // Finaliza o ROS2
    rclcpp::shutdown();

    return 0;
}
