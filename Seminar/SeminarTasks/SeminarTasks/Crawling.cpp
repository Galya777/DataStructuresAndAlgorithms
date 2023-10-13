#include <iostream>
#include <vector>
#include <queue>
#include <set>

class Graph {
public:
    Graph(int vertices) : V(vertices) {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    int getVertices() const {
        return V;
    }

    const std::vector<std::vector<int>>& getAdjList() const {
        return adjList;
    }

    // DFS за намиране на път между два върха
    bool findPathDFS(int start, int end, std::vector<int>& path, std::set<int>& visited) {
        visited.insert(start);
        path.push_back(start);

        if (start == end) {
            return true;  // Намерихме път до целевия връх
        }

        for (int neighbor : adjList[start]) {
            if (visited.find(neighbor) == visited.end() && findPathDFS(neighbor, end, path, visited)) {
                return true;
            }
        }

        path.pop_back();
        return false;  // Няма път до целевия връх
    }

    // Намиране на всички пътища между два върха с DFS
    std::vector<std::vector<int>> findAllPathsDFS(int start, int end) {
        std::vector<int> path;
        std::vector<std::vector<int>> allPaths;
        std::set<int> visited;
        findPathsDFS(start, end, path, allPaths, visited);
        return allPaths;
    }

    void findPathsDFS(int current, int end, std::vector<int>& path, std::vector<std::vector<int>>& allPaths, std::set<int>& visited) {
        visited.insert(current);
        path.push_back(current);

        if (current == end) {
            allPaths.push_back(path);
        }
        else {
            for (int neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    findPathsDFS(neighbor, end, path, allPaths, visited);
                }
            }
        }

        visited.erase(current);
        path.pop_back();
    }

    // BFS за намиране на път между два върха
    bool findPathBFS(int start, int end, std::vector<int>& path) {
        std::queue<std::vector<int>> q;
        std::set<int> visited;
        q.push({ start });

        while (!q.empty()) {
            path = q.front();
            q.pop();
            int current = path.back();
            visited.insert(current);

            if (current == end) {
                return true;  // Намерихме път до целевия връх
            }

            for (int neighbor : adjList[current]) {
                if (visited.find(neighbor) == visited.end()) {
                    std::vector<int> newPath = path;
                    newPath.push_back(neighbor);
                    q.push(newPath);
                }
            }
        }

        path.clear();
        return false;  // Няма път до целевия връх
    }

private:
    int V;
    std::vector<std::vector<int>> adjList;
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    int start = 0;
    int end = 5;
    std::vector<int> path;

    if (g.findPathDFS(start, end, path, std::set<int>())) {
        std::cout << "DFS Път между " << start << " и " << end << ": ";
        for (int vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "DFS Няма път между " << start << " и " << end << std::endl;
    }

    path.clear();

    if (g.findPathBFS(start, end, path)) {
        std::cout << "BFS Път между " << start << " и " << end << ": ";
        for (int vertex : path) {
            std::cout << vertex << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "BFS Няма път между " << start << " и " << end << std::endl;
    }

    return 0;
}
