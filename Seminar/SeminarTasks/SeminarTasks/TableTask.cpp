#include <iostream>
#include <cmath>
#include <iomanip>
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

// Функция, която отпечатва таблица със стойностите на дадена функция.
void PrintFunctionTable(MathFunction func, double start, double end, double step, double precision) {
    std::cout << "x\t\tf(x)" << std::endl;
    for (double x = start; x <= end; x += step) {
        double result = func(x);
        if (std::abs(result) < precision) {
            // Прекратяваме изчисленията, ако стойността на функцията е под зададената точност.
            break;
        }
        std::cout << std::fixed << std::setprecision(6) << x << "\t\t" << result << std::endl;
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

    // Въвеждане на граници, стъпка и точност.
    double start, end, step, precision;
    std::cout << "Въведете начало на интервала: ";
    std::cin >> start;
    std::cout << "Въведете край на интервала: ";
    std::cin >> end;
    std::cout << "Въведете стъпка: ";
    std::cin >> step;
    std::cout << "Въведете желана точност: ";
    std::cin >> precision;

    // Изчисляваме и отпечатваме стойностите на функцията.
    PrintFunctionTable(selectedFunction, start, end, step, precision);

    return 0;
}
