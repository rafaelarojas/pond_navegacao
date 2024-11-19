# Navegação Reativa

O projeto implementa um cliente **ROS 2** que realiza a **navegação reativa** em um grid 20x20 utilizando o algoritmo de **busca em largura** (Breadth-First Search - BFS) para planejar o caminho até um alvo conhecido. A navegação é baseada em informações de sensores e comandos enviados para o serviço /move_command, que move o robô no grid em uma das quatro direções possíveis: cima, baixo, esquerda ou direita.

![alt text](gif.gif)

O projeto utiliza o seguinte pacote para a interface: https://github.com/rmnicola/Culling_Games

### Métodos Principais

- send_initial_move: Envia um comando inicial baseado nas direções disponíveis.
- send_move_request: Envia um comando de movimento ao serviço /move_command.
- process_response: Processa a resposta do serviço para atualizar o estado do robô, o mapa e planejar o próximo movimento.
- plan_path: Implementa o algoritmo BFS para encontrar o menor caminho entre a posição atual e o alvo.
- neighbor_pos: Calcula a posição vizinha com base na direção fornecida.
- is_in_bounds: Verifica se uma posição está dentro dos limites do grid.

### Tecnologias Utilizadas

- Linguagem: C++
- Framework: ROS 2 (Robot Operating System)
- Algoritmo de Planejamento: Breadth-First Search (BFS)
- Comunicação Cliente-Servidor: Serviço ROS 2 /move_command


## Como Executar

- Certifique-se que possui ROS 2 instalado
- Pacote cg_interfaces com o serviço MoveCmd configurado, pode ser encontrado [aqui](https://github.com/rmnicola/Culling_Games)

Rode o comando
```bash
colcon build
```

Execução Certifique-se de que o serviço /move_command está ativo. Em seguida, execute:
```bash
ros2 run ponderada navigation
```

---
#### Referências

- (Breadth First Search or BFS for a Graph)[https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/]
- (BFS in C++: Breadth-First Search Algorithm & Program)[https://favtutor.com/blogs/bfs-breadth-first-search-cpp]
- (C++ SDL AI Pathfinding: BFS, Dijkstra, GBFS and A* algorithms)[https://github.com/JoanStinson/Pathfinding]