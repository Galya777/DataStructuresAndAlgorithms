#include <iostream>
#include <cmath>
#include <vector>

// ���������� �� ���, ����� ��������� �������� ��� �������, ����� ������ � ����� double.
typedef double (*MathFunction)(double);

// ������� �� ����������� �� ���������� �����.
double SquareRoot(double x) {
    return sqrt(x);
}

// ������� �� ����������� �� �����.
double Sine(double x) {
    return sin(x);
}

// ������� �� ����������� �� �������.
double Cosine(double x) {
    return cos(x);
}

// ������� �� ����������� �� ��������� � ������ 10.
double LogBase10(double x) {
    return log10(x);
}

// �������, ����� ��������� ������� �� ������ �������.
void PrintFunctionGraph(MathFunction func, double minValue, double maxValue, double step) {
    for (double y = maxValue; y >= minValue; y -= step) {
        for (double x = -10.0; x <= 10.0; x += 0.5) {
            double result = func(x);
            if (std::abs(result - y) < step / 2.0) {
                std::cout << '*';
            }
            else if (x == 0.0 && y == 0.0) {
                std::cout << 'O'; // �������� �� ������������� �������
            }
            else if (x == 0.0) {
                std::cout << '|'; // ���������� �����
            }
            else if (y == 0.0) {
                std::cout << '-'; // ������������ �����
            }
            else {
                std::cout << ' ';
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    // ��������� ������ �� �������.
    std::vector<MathFunction> functions = { SquareRoot, Sine, Cosine, LogBase10 };

    // ����� �� ������� �� �����������.
    std::cout << "�������� �������:" << std::endl;
    for (int i = 0; i < functions.size(); ++i) {
        std::cout << i + 1 << ". " << functions[i] << std::endl;
    }

    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > functions.size()) {
        std::cout << "��������� �����." << std::endl;
        return 1;
    }

    MathFunction selectedFunction = functions[choice - 1];

    // ��������� �� ������� ��������, ������, ��������� � ���������� �������� �� f(x).
    double minValue, maxValue, step;
    std::cout << "�������� ������� �������� �� f(x): ";
    std::cin >> minValue;
    std::cout << "�������� ���������� �������� �� f(x): ";
    std::cin >> maxValue;
    std::cout << "�������� ������: ";
    std::cin >> step;

    // ����������� ��������� �� ���������.
    PrintFunctionGraph(selectedFunction, minValue, maxValue, step);

    return 0;
}
