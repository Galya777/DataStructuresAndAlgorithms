#include <iostream>
#include <vector>
#include <set>

class Graph {
public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    const std::vector<std::vector<int>>& getAdjList() const {
        return adjList;
    }

    bool hasCycle() {
        std::set<int> visited;
        std::set<int> recStack;

        for (int i = 0; i < V; i++) {
            if (hasCycleUtil(i, visited, recStack)) {
                return true;
            }
        }

        return false;
    }

private:
    int V;
    std::vector<std::vector<int>> adjList;

    bool hasCycleUtil(int v, std::set<int>& visited, std::set<int>& recStack) {
        visited.insert(v);
        recStack.insert(v);

        for (int neighbor : adjList[v]) {
            if (visited.find(neighbor) == visited.end() && hasCycleUtil(neighbor, visited, recStack)) {
                return true;
            }
            else if (recStack.find(neighbor) != recStack.end()) {
                return true;
            }
        }

        recStack.erase(v);
        return false;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    if (g.hasCycle()) {
        std::cout << "Графът съдържа цикъл." << std::endl;
    }
    else {
        std::cout << "Графът не съдържа цикъл." << std::endl;
    }

    return 0;
}
