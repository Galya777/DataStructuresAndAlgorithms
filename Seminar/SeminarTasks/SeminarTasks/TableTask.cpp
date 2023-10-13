#include <iostream>
#include <cmath>
#include <iomanip>
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

// �������, ����� ��������� ������� ��� ����������� �� ������ �������.
void PrintFunctionTable(MathFunction func, double start, double end, double step, double precision) {
    std::cout << "x\t\tf(x)" << std::endl;
    for (double x = start; x <= end; x += step) {
        double result = func(x);
        if (std::abs(result) < precision) {
            // ������������ ������������, ��� ���������� �� ��������� � ��� ���������� �������.
            break;
        }
        std::cout << std::fixed << std::setprecision(6) << x << "\t\t" << result << std::endl;
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

    // ��������� �� �������, ������ � �������.
    double start, end, step, precision;
    std::cout << "�������� ������ �� ���������: ";
    std::cin >> start;
    std::cout << "�������� ���� �� ���������: ";
    std::cin >> end;
    std::cout << "�������� ������: ";
    std::cin >> step;
    std::cout << "�������� ������ �������: ";
    std::cin >> precision;

    // ����������� � ����������� ����������� �� ���������.
    PrintFunctionTable(selectedFunction, start, end, step, precision);

    return 0;
}
