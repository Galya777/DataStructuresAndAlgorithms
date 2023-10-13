#include <iostream>
#include <stack>

void arrangeWagons(const std::string& wagonColors) {
    std::stack<char> stack1, stack2, stack3;
    int colorIndex = 0;

    // Проход през всеки вагон в реда
    for (char wagonColor : wagonColors) {
        if (!stack1.empty() && stack1.top() == wagonColor) {
            stack1.push(wagonColor);
        }
        else if (!stack2.empty() && stack2.top() == wagonColor) {
            stack2.push(wagonColor);
        }
        else {
            // Преместваме текущия вагон на третия стек
            stack3.push(wagonColor);
        }
    }

    // Обединяваме всички вагони от третия стек в първия или втория стек
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

    // Извеждаме последователността от операции
    while (!stack1.empty() || !stack2.empty() || !stack3.empty()) {
        if (!stack1.empty()) {
            std::cout << "В ";
            stack1.pop();
        }
        if (!stack2.empty()) {
            std::cout << "НАПРАВО ";
            stack2.pop();
        }
        if (!stack3.empty()) {
            std::cout << "ОТ ";
            stack3.pop();
        }
    }

    std::cout << std::endl;
}

int main() {
    std::string wagonColors;
    std::cout << "Въведете реда от вагони: ";
    std::cin >> wagonColors;

    arrangeWagons(wagonColors);

    return 0;
}
