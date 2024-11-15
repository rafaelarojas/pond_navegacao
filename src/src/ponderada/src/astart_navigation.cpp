#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cmath>
#include <unordered_map>

struct Node {
    int x, y;
    float g, h;
    Node* parent;
    
    Node(int x_, int y_, float g_, float h_, Node* parent_ = nullptr) : x(x_), y(y_), g(g_), h(h_), parent(parent_) {}
    
    float f() const { return g + h; }
    
    bool operator<(const Node& other) const {
        return f() > other.f();  // Min-Heap based on f = g + h
    }
};

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

bool isValid(int x, int y, const std::vector<std::vector<char>>& map) {
    return x >= 0 && x < map.size() && y >= 0 && y < map[0].size() && map[x][y] != 'b';
}

float heuristic(int x1, int y1, int x2, int y2) {
    return std::abs(x1 - x2) + std::abs(y1 - y2);  // Manhattan distance
}

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

std::vector<Node> aStar(const std::vector<std::vector<char>>& map, int startX, int startY, int goalX, int goalY) {
    std::priority_queue<Node> openSet;
    std::unordered_map<int, Node*> closedSet;

    Node* start = new Node(startX, startY, 0, heuristic(startX, startY, goalX, goalY));
    openSet.push(*start);

    while (!openSet.empty()) {
        Node current = openSet.top();
        openSet.pop();

        if (current.x == goalX && current.y == goalY) {
            std::vector<Node> path;
            Node* pathNode = &current;
            while (pathNode != nullptr) {
                path.push_back(*pathNode);
                pathNode = pathNode->parent;
            }
            return path;
        }

        closedSet[current.x * map[0].size() + current.y] = new Node(current);

        for (Node& neighbor : getNeighbors(&current, map)) {
            float tentative_g = current.g + 1;  // Distance between adjacent nodes is always 1
            int hash = neighbor.x * map[0].size() + neighbor.y;

            if (closedSet.find(hash) != closedSet.end()) continue;

            neighbor.g = tentative_g;
            neighbor.h = heuristic(neighbor.x, neighbor.y, goalX, goalY);

            openSet.push(neighbor);
        }
    }

    return {};  // Empty path if no solution found
}

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
    std::string filename = "../../maps/default.csv";
    std::vector<std::vector<char>> map = readCSV(filename);

    int startX = 17, startY = 18;  // Starting position of the robot
    int goalX = 18, goalY = 17;    // Target position

    std::vector<Node> path = aStar(map, startX, startY, goalX, goalY);

    if (!path.empty()) {
        std::cout << "Path found:\n";
        printPath(path, map);
    } else {
        std::cout << "No path found.\n";
    }

    return 0;
}
