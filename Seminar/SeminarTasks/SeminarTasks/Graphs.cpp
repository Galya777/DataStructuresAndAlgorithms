#include <iostream>
#include <vector>

struct Edge {
    int from;
    int to;
    Edge(int start, int end) : from(start), to(end) {}
};

bool isAcyclicGraph(const std::vector<Edge>& edges) {
    // Проверка за наличие на цикли в графа (например, използвайки Depth-First Search)
    // Ако намерим цикъл, графът не е ацикличен
    // Ваш код за проверка за ацикличност тук
}

bool isTree(const std::vector<Edge>& edges) {
    // Проверка дали графът е ацикличен
    if (!isAcyclicGraph(edges)) {
        return false;
    }

    std::vector<int> inDegree;  // Масив за брой входящи ребра за всеки връх

    // Инициализация на масива за брой входящи ребра
    for (const Edge& edge : edges) {
        inDegree[edge.to]++;
    }

    int rootCount = 0; // Брой коренови върхове
    int leafCount = 0; // Брой листови върхове

    for (int i = 1; i < inDegree.size(); i++) {
        if (inDegree[i] > 1) {
            return false; // Възел с повече от 1 входящи ребра
        }
        else if (inDegree[i] == 0) {
            leafCount++;
        }
    }

    for (int i = 1; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            rootCount++;
            if (rootCount > 1) {
                return false; // Повече от един корен
            }
        }
    }

    return rootCount == 1 && leafCount == 1;
}

int main() {
    std::vector<Edge> edges;
    edges.push_back(Edge(1, 2));
    edges.push_back(Edge(2, 3));
    edges.push_back(Edge(1, 3));

    if (isTree(edges)) {
        std::cout << "Графът е дърво." << std::endl;
    }
    else {
        std::cout << "Графът не е дърво." << std::endl;
    }

    return 0;
}
