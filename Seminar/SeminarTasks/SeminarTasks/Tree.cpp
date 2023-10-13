#include <iostream>
#include <queue>
#include <vector>

// ��������� �� ����� � �������
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// �������� �� ��������� �� ����� (���������� ��������� �� �������)
int findDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return std::max(leftDepth, rightDepth) + 1;
}

// �������� ���� ����� ������� �� ����� � �����
bool findElement(TreeNode* root, int target) {
    if (root == nullptr) return false;
    if (root->data == target) return true;
    return findElement(root->left, target) || findElement(root->right, target);
}

// �������� �� ���������� ����� �� �������
TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* mirrored = new TreeNode(root->data);
    mirrored->left = mirrorTree(root->right);
    mirrored->right = mirrorTree(root->left);
    return mirrored;
}

// �������� �� ��������� �� ��� �������
TreeNode* intersection(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == nullptr || tree2 == nullptr) return nullptr;
    TreeNode* intersected = new TreeNode(tree1->data);
    intersected->left = intersection(tree1->left, tree2->left);
    intersected->right = intersection(tree1->right, tree2->right);
    return intersected;
}

// �������� �� ������ ����� � ������ ����� ���� ��������� (in-order)
void findAllNodes(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return;
    findAllNodes(root->left, result);
    result.push_back(root->data);
    findAllNodes(root->right, result);
}

// �������� �� ��� ����� ��� ������ � �������, ��� ���������� (������)
bool findPath(TreeNode* root, int target, std::vector<int>& path) {
    if (root == nullptr) return false;
    path.push_back(root->data);
    if (root->data == target) return true;
    if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
        return true;
    }
    path.pop_back();
    return false;
}

// �������� �� ������ �������� �� ������ ���� � �������
void findElementsAtLevel(TreeNode* root, int level, std::vector<int>& result) {
    if (root == nullptr) return;
    if (level == 0) {
        result.push_back(root->data);
    }
    else {
        findElementsAtLevel(root->left, level - 1, result);
        findElementsAtLevel(root->right, level - 1, result);
    }
}

// �������� �� ������ �� ������ ���� �� �������
std::vector<std::vector<int>> findAllLevels(TreeNode* root) {
    std::vector<std::vector<int>> levels;
    int depth = findDepth(root);
    for (int i = 0; i < depth; ++i) {
        std::vector<int> level;
        findElementsAtLevel(root, i, level);
        levels.push_back(level);
    }
    return levels;
}

int main() {
    // ��������� �� ����� (������)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // ������� �� ���������� �� ���������
    int depth = findDepth(root);
    std::cout << "��������� �� �������: " << depth << std::endl;

    int target = 5;
    bool found = findElement(root, target);
    std::cout << "������� " << target << " �� ����� � �������: " << (found ? "��" : "��") << std::endl;

    TreeNode* mirrored = mirrorTree(root);

    std::vector<int> nodes;
    findAllNodes(root, nodes);
    std::cout << "������ ����� � �������: ";
    for (int node : nodes) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // ������ �� �������� �� ��� ����� ��� ������ (��������, �� ������ �� ����� 5)
    int targetNode = 5;
    std::vector<int> path;
    bool pathFound = findPath(root, targetNode, path);
    if (pathFound) {
        std::cout << "��� �� ����� " << targetNode << ": ";
        for (int node : path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "�� ���������� ��� �� ����� " << targetNode << std::endl;
    }

    // �������� �� �������� �� ���� (��������, �� ���� 2)
    int levelToFind = 2;
    std::vector<int> levelElements;
    findElementsAtLevel(root, levelToFind, levelElements);
    std::cout << "�������� �� ���� " << levelToFind << ": ";
    for (int node : levelElements) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // �������� �� ������ ����
    std::vector<std::vector<int>> allLevels = findAllLevels(root);
    for (int i = 0; i < allLevels.size(); ++i) {
        std::cout << "���� " << i << ": ";
        for (int node : allLevels[i]) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
