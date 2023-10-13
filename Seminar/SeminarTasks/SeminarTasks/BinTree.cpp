#include <iostream>
#include <vector>
#include <map>
#include <queue>

// Структура за представяне на връх в двоичното дърво
struct BinTreeNode {
    int data;
    BinTreeNode* left;
    BinTreeNode* right;
    BinTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// Клас за представяне на ориентиран граф
class IntGraph {
public:
    IntGraph(int vertices) : V(vertices) {
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

private:
    int V;
    std::vector<std::vector<int>> adjList;
};

// Рекурсивна функция за построяване на двоичното дърво от граф
BinTreeNode* buildBinTreeFromGraph(IntGraph& g, int v, std::map<int, BinTreeNode*>& nodeMap) {
    if (nodeMap.find(v) != nodeMap.end()) {
        return nodeMap[v]; // Вече сме създали възел с тази стойност
    }

    BinTreeNode* node = new BinTreeNode(v);
    nodeMap[v] = node; // Запазваме върха в мапа

    for (int neighbor : g.getAdjList()[v]) {
        BinTreeNode* child = buildBinTreeFromGraph(g, neighbor, nodeMap);
        if (!node->left) {
            node->left = child;
        }
        else {
            node->right = child;
        }
    }

    return node;
}

// Главна функция за преобразуване на граф в двоично дърво
BinTreeNode* toBinTree(IntGraph& g) {
    std::map<int, BinTreeNode*> nodeMap; // Мап за съответствие между върховете и възлите в дървото
    BinTreeNode* root = nullptr;

    for (int i = 0; i < g.getVertices(); i++) {
        // Избираме начален връх и строим дървото, ако не сме го построили преди
        if (!nodeMap[i]) {
            root = buildBinTreeFromGraph(g, i, nodeMap);
        }
    }

    return root;
}

// Функция за извеждане на двоичното дърво (обхождане в ширина)
void printBinTree(BinTreeNode* root) {
    if (!root) return;

    std::queue<BinTreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        BinTreeNode* current = q.front();
        q.pop();
        std::cout << current->data << " ";

        if (current->left) {
            q.push(current->left);
        }

        if (current->right) {
            q.push(current->right);
        }
    }
    std::cout << std::endl;
}

int main() {
    IntGraph g(8); // Примерен граф с 8 върха
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);

    BinTreeNode* binTree = toBinTree(g);

    if (binTree) {
        std::cout << "Двоичното дърво, построено от графа, е: ";
        printBinTree(binTree);
    }
    else {
        std::cout << "Графът не може да бъде преобразуван в двоично дърво." << std::endl;
    }

    return 0;
}
