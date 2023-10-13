#include <iostream>
#include <stack>

void arrangeWagons(const std::string& wagonColors) {
    std::stack<char> stack1, stack2, stack3;
    int colorIndex = 0;

    // ������ ���� ����� ����� � ����
    for (char wagonColor : wagonColors) {
        if (!stack1.empty() && stack1.top() == wagonColor) {
            stack1.push(wagonColor);
        }
        else if (!stack2.empty() && stack2.top() == wagonColor) {
            stack2.push(wagonColor);
        }
        else {
            // ����������� ������� ����� �� ������ ����
            stack3.push(wagonColor);
        }
    }

    // ����������� ������ ������ �� ������ ���� � ������ ��� ������ ����
    while (!stack3.empty()) {
        char wagonColor = stack3.top();
        if (stack1.empty() || stack1.top() != wagonColor) {
            stack1.push(wagonColor);
        }
        else {
            stack2.push(wagonColor);
        }
        stack3.pop();
    }

    // ��������� ������������������ �� ��������
    while (!stack1.empty() || !stack2.empty() || !stack3.empty()) {
        if (!stack1.empty()) {
            std::cout << "� ";
            stack1.pop();
        }
        if (!stack2.empty()) {
            std::cout << "������� ";
            stack2.pop();
        }
        if (!stack3.empty()) {
            std::cout << "�� ";
            stack3.pop();
        }
    }

    std::cout << std::endl;
}

int main() {
    std::string wagonColors;
    std::cout << "�������� ���� �� ������: ";
    std::cin >> wagonColors;

    arrangeWagons(wagonColors);

    return 0;
}
