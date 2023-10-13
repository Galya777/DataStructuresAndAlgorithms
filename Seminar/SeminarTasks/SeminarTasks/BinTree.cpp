#include <iostream>
#include <vector>
#include <map>
#include <queue>

// ��������� �� ����������� �� ���� � ��������� �����
struct BinTreeNode {
    int data;
    BinTreeNode* left;
    BinTreeNode* right;
    BinTreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

// ���� �� ����������� �� ���������� ����
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

// ���������� ������� �� ����������� �� ��������� ����� �� ����
BinTreeNode* buildBinTreeFromGraph(IntGraph& g, int v, std::map<int, BinTreeNode*>& nodeMap) {
    if (nodeMap.find(v) != nodeMap.end()) {
        return nodeMap[v]; // ���� ��� ������� ����� � ���� ��������
    }

    BinTreeNode* node = new BinTreeNode(v);
    nodeMap[v] = node; // ��������� ����� � ����

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

// ������ ������� �� ������������� �� ���� � ������� �����
BinTreeNode* toBinTree(IntGraph& g) {
    std::map<int, BinTreeNode*> nodeMap; // ��� �� ������������ ����� ��������� � ������� � �������
    BinTreeNode* root = nullptr;

    for (int i = 0; i < g.getVertices(); i++) {
        // �������� ������� ���� � ������ �������, ��� �� ��� �� ��������� �����
        if (!nodeMap[i]) {
            root = buildBinTreeFromGraph(g, i, nodeMap);
        }
    }

    return root;
}

// ������� �� ��������� �� ��������� ����� (��������� � ������)
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
    IntGraph g(8); // �������� ���� � 8 �����
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);

    BinTreeNode* binTree = toBinTree(g);

    if (binTree) {
        std::cout << "��������� �����, ��������� �� �����, �: ";
        printBinTree(binTree);
    }
    else {
        std::cout << "������ �� ���� �� ���� ������������ � ������� �����." << std::endl;
    }

    return 0;
}
