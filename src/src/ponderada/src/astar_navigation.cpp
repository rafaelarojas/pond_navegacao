#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <functional> // Para std::hash

struct Node {
    int x, y;
    float g, h;
    Node* parent;

    Node(int x_, int y_, float g_, float h_, Node* parent_ = nullptr)
        : x(x_), y(y_), g(g_), h(h_), parent(parent_) {}

    float f() const { return g + h; }

    bool operator<(const Node& other) const {
        return f() > other.f(); // Min-Heap baseado em f = g + h
    }
};

// Função hash para pares
struct PairHash {
    std::size_t operator()(const std::pair<int, int>& pair) const {
        return std::hash<int>()(pair.first) ^ std::hash<int>()(pair.second << 1);
    }
};

// Função para ler o arquivo CSV e criar o mapa
std::vector<std::vector<char>> readCSV(const std::string& filename) {
    std::vector<std::vector<char>> map;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line)) {
        std::vector<char> row;
        for (char c : line) {
            if (c != ',') row.push_back(c);
        }
        map.push_back(row);
    }

    return map;
}

// Verifica se uma posição é válida no mapa
bool isValid(int x, int y, const std::vector<std::vector<char>>& map) {
    return x >= 0 && x < map.size() && y >= 0 && y < map[0].size() && map[x][y] != 'b';
}

// Calcula a heurística (distância Manhattan)
float heuristic(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

// Obtém os vizinhos válidos de um nó
std::vector<Node> getNeighbors(Node* current, const std::vector<std::vector<char>>& map) {
    std::vector<Node> neighbors;
    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int nx = current->x + dx[i];
        int ny = current->y + dy[i];
        if (isValid(nx, ny, map)) {
            neighbors.emplace_back(nx, ny, 0, 0, current);
        }
    }

    return neighbors;
}

// Implementação do algoritmo A*
std::vector<Node> aStar(const std::vector<std::vector<char>>& map, int startX, int startY, int goalX, int goalY) {
    auto cmp = [](const Node* left, const Node* right) { return left->f() > right->f(); };
    std::priority_queue<Node*, std::vector<Node*>, decltype(cmp)> openSet(cmp);
    std::unordered_map<std::pair<int, int>, Node*, PairHash> closedSet;

    auto createKey = [](int x, int y) { return std::make_pair(x, y); };

    Node* start = new Node(startX, startY, 0, heuristic(startX, startY, goalX, goalY));
    openSet.push(start);

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        if (current->x == goalX && current->y == goalY) {
            std::vector<Node> path;
            while (current != nullptr) {
                path.push_back(*current);
                current = current->parent;
            }
            return path;
        }

        closedSet[createKey(current->x, current->y)] = current;

        for (Node& neighbor : getNeighbors(current, map)) {
            auto neighborKey = createKey(neighbor.x, neighbor.y);
            if (closedSet.find(neighborKey) != closedSet.end()) continue;

            neighbor.g = current->g + 1;
            neighbor.h = heuristic(neighbor.x, neighbor.y, goalX, goalY);

            openSet.push(new Node(neighbor));
        }
    }

    return {}; // Caminho vazio se nenhuma solução for encontrada
}

// Imprime o caminho encontrado no mapa
void printPath(const std::vector<Node>& path, const std::vector<std::vector<char>>& map) {
    std::vector<std::vector<char>> mapWithPath = map;
    for (const Node& node : path) {
        if (mapWithPath[node.x][node.y] != 'r' && mapWithPath[node.x][node.y] != 't') {
            mapWithPath[node.x][node.y] = '*';
        }
    }
    for (const auto& row : mapWithPath) {
        for (char c : row) std::cout << c << ' ';
        std::cout << '\n';
    }
}

int main() {
    std::string filename = "../maps/default.csv";
    std::vector<std::vector<char>> map = readCSV(filename);

    int startX = 17, startY = 18; // Posição inicial do robô
    int goalX = 18, goalY = 17;   // Posição final (alvo)

    std::vector<Node> path = aStar(map, startX, startY, goalX, goalY);

    if (!path.empty()) {
        std::cout << "Caminho encontrado:\n";
        printPath(path, map);
    } else {
        std::cout << "Nenhum caminho encontrado.\n";
    }

    return 0;
}
