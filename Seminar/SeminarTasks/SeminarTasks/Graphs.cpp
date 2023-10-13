#include <iostream>
#include <vector>

struct Edge {
    int from;
    int to;
    Edge(int start, int end) : from(start), to(end) {}
};

bool isAcyclicGraph(const std::vector<Edge>& edges) {
    // �������� �� ������� �� ����� � ����� (��������, ����������� Depth-First Search)
    // ��� ������� �����, ������ �� � ���������
    // ��� ��� �� �������� �� ����������� ���
}

bool isTree(const std::vector<Edge>& edges) {
    // �������� ���� ������ � ���������
    if (!isAcyclicGraph(edges)) {
        return false;
    }

    std::vector<int> inDegree;  // ����� �� ���� ������� ����� �� ����� ����

    // ������������� �� ������ �� ���� ������� �����
    for (const Edge& edge : edges) {
        inDegree[edge.to]++;
    }

    int rootCount = 0; // ���� �������� �������
    int leafCount = 0; // ���� ������� �������

    for (int i = 1; i < inDegree.size(); i++) {
        if (inDegree[i] > 1) {
            return false; // ����� � ������ �� 1 ������� �����
        }
        else if (inDegree[i] == 0) {
            leafCount++;
        }
    }

    for (int i = 1; i < inDegree.size(); i++) {
        if (inDegree[i] == 0) {
            rootCount++;
            if (rootCount > 1) {
                return false; // ������ �� ���� �����
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
        std::cout << "������ � �����." << std::endl;
    }
    else {
        std::cout << "������ �� � �����." << std::endl;
    }

    return 0;
}
