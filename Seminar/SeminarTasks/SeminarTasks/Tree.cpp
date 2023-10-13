#include <iostream>
#include <queue>
#include <vector>

// Структура за възел в дървото
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Намиране на дълбочина на дърво (максимална дълбочина на възлите)
int findDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);
    return std::max(leftDepth, rightDepth) + 1;
}

// Проверка дали даден елемент се среща в дърво
bool findElement(TreeNode* root, int target) {
    if (root == nullptr) return false;
    if (root->data == target) return true;
    return findElement(root->left, target) || findElement(root->right, target);
}

// Намиране на огледалния образ на дървото
TreeNode* mirrorTree(TreeNode* root) {
    if (root == nullptr) return nullptr;
    TreeNode* mirrored = new TreeNode(root->data);
    mirrored->left = mirrorTree(root->right);
    mirrored->right = mirrorTree(root->left);
    return mirrored;
}

// Намиране на сечението на две дървета
TreeNode* intersection(TreeNode* tree1, TreeNode* tree2) {
    if (tree1 == nullptr || tree2 == nullptr) return nullptr;
    TreeNode* intersected = new TreeNode(tree1->data);
    intersected->left = intersection(tree1->left, tree2->left);
    intersected->right = intersection(tree1->right, tree2->right);
    return intersected;
}

// Намиране на всички възли в дадено дърво чрез обхождане (in-order)
void findAllNodes(TreeNode* root, std::vector<int>& result) {
    if (root == nullptr) return;
    findAllNodes(root->left, result);
    result.push_back(root->data);
    findAllNodes(root->right, result);
}

// Намиране на път между два възела в дървото, ако съществува (пример)
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

// Намиране на всички елементи на дадено ниво в дървото
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

// Намиране на списък от всички нива на дървото
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
    // Създаване на дърво (пример)
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Примери за използване на функциите
    int depth = findDepth(root);
    std::cout << "Дълбочина на дървото: " << depth << std::endl;

    int target = 5;
    bool found = findElement(root, target);
    std::cout << "Елемент " << target << " се среща в дървото: " << (found ? "Да" : "Не") << std::endl;

    TreeNode* mirrored = mirrorTree(root);

    std::vector<int> nodes;
    findAllNodes(root, nodes);
    std::cout << "Всички възли в дървото: ";
    for (int node : nodes) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // Пример за намиране на път между два възела (например, от корена до листо 5)
    int targetNode = 5;
    std::vector<int> path;
    bool pathFound = findPath(root, targetNode, path);
    if (pathFound) {
        std::cout << "Път до възел " << targetNode << ": ";
        for (int node : path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Не съществува път до възел " << targetNode << std::endl;
    }

    // Намиране на елементи на нива (например, на ниво 2)
    int levelToFind = 2;
    std::vector<int> levelElements;
    findElementsAtLevel(root, levelToFind, levelElements);
    std::cout << "Елементи на ниво " << levelToFind << ": ";
    for (int node : levelElements) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // Намиране на всички нива
    std::vector<std::vector<int>> allLevels = findAllLevels(root);
    for (int i = 0; i < allLevels.size(); ++i) {
        std::cout << "Ниво " << i << ": ";
        for (int node : allLevels[i]) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
