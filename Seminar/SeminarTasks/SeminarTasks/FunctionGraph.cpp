#include <iostream>
#include <cmath>
#include <vector>

// Дефиниране на тип, който представя указател към функция, която приема и връща double.
typedef double (*MathFunction)(double);

// Функция за изчисляване на квадратния корен.
double SquareRoot(double x) {
    return sqrt(x);
}

// Функция за изчисляване на синус.
double Sine(double x) {
    return sin(x);
}

// Функция за изчисляване на косинус.
double Cosine(double x) {
    return cos(x);
}

// Функция за изчисляване на логаритъм с основа 10.
double LogBase10(double x) {
    return log10(x);
}

// Функция, която отпечатва графика на дадена функция.
void PrintFunctionGraph(MathFunction func, double minValue, double maxValue, double step) {
    for (double y = maxValue; y >= minValue; y -= step) {
        for (double x = -10.0; x <= 10.0; x += 0.5) {
            double result = func(x);
            if (std::abs(result - y) < step / 2.0) {
                std::cout << '*';
            }
            else if (x == 0.0 && y == 0.0) {
                std::cout << 'O'; // Основата на координатната система
            }
            else if (x == 0.0) {
                std::cout << '|'; // Вертикална линия
            }
            else if (y == 0.0) {
                std::cout << '-'; // Хоризонтална линия
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // Създаваме вектор от функции.
    std::vector<MathFunction> functions = { SquareRoot, Sine, Cosine, LogBase10 };

    // Избор на функция от потребителя.
    std::cout << "Изберете функция:" << std::endl;
    for (int i = 0; i < functions.size(); ++i) {
        std::cout << i + 1 << ". " << functions[i] << std::endl;
    }

    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > functions.size()) {
        std::cout << "Невалиден избор." << std::endl;
        return 1;
    }

    MathFunction selectedFunction = functions[choice - 1];

    // Въвеждане на начална стойност, стъпка, минимална и максимална стойност на f(x).
    double minValue, maxValue, step;
    std::cout << "Въведете начална стойност на f(x): ";
    std::cin >> minValue;
    std::cout << "Въведете максимална стойност на f(x): ";
    std::cin >> maxValue;
    std::cout << "Въведете стъпка: ";
    std::cin >> step;

    // Отпечатваме графиката на функцията.
    PrintFunctionGraph(selectedFunction, minValue, maxValue, step);

    return 0;
}
