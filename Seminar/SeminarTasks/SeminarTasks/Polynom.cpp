#include <iostream>

// Структура за моном
struct Monom {
    double coefficient;
    int exponent;
};

// Структура за елемент от списъка
struct Node {
    Monom data;
    Node* next;
};

// Структура за полином
struct Polynomial {
    Node* head;

    // Конструктор за инициализация
    Polynomial() {
        head = nullptr;
    }
};

// Функция за добавяне на моном към полином
void addMonom(Polynomial& poly, double coefficient, int exponent) {
    Node* newNode = new Node;
    newNode->data.coefficient = coefficient;
    newNode->data.exponent = exponent;
    newNode->next = poly.head;
    poly.head = newNode;
}

// Функция за пресмятане на стойността на полином в точка x
double evaluatePolynomial(const Polynomial& poly, double x) {
    double result = 0.0;
    Node* current = poly.head;
    while (current != nullptr) {
        result += current->data.coefficient * pow(x, current->data.exponent);
        current = current->next;
    }
    return result;
}

// Функция за събиране на два полинома
Polynomial addPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result;
    Node* current1 = poly1.head;
    Node* current2 = poly2.head;

    while (current1 != nullptr || current2 != nullptr) {
        Monom monom;
        if (current1 != nullptr && (current2 == nullptr || current1->data.exponent > current2->data.exponent)) {
            monom = current1->data;
            current1 = current1->next;
        }
        else if (current2 != nullptr && (current1 == nullptr || current2->data.exponent > current1->data.exponent)) {
            monom = current2->data;
            current2 = current2->next;
        }
        else { // Степените са равни
            monom.coefficient = current1->data.coefficient + current2->data.coefficient;
            monom.exponent = current1->data.exponent;
            current1 = current1->next;
            current2 = current2->next;
        }
        addMonom(result, monom.coefficient, monom.exponent);
    }
    return result;
}

// Функция за умножение на полином с моном
Polynomial multiplyPolynomialByMonom(const Polynomial& poly, double coefficient, int exponent) {
    Polynomial result;
    Node* current = poly.head;
    while (current != nullptr) {
        Monom monom;
        monom.coefficient = current->data.coefficient * coefficient;
        monom.exponent = current->data.exponent + exponent;
        addMonom(result, monom.coefficient, monom.exponent);
        current = current->next;
    }
    return result;
}

// Функция за умножение на два полинома
Polynomial multiplyPolynomials(const Polynomial& poly1, const Polynomial& poly2) {
    Polynomial result;
    Node* current1 = poly1.head;
    while (current1 != nullptr) {
        Polynomial partialResult = multiplyPolynomialByMonom(poly2, current1->data.coefficient, current1->data.exponent);
        result = addPolynomials(result, partialResult);
        current1 = current1->next;
    }
    return result;
}

// Функция за извеждане на полином
void printPolynomial(const Polynomial& poly) {
    Node* current = poly.head;
    while (current != nullptr) {
        std::cout << current->data.coefficient;
        if (current->data.exponent > 0) {
            std::cout << "x^" << current->data.exponent;
        }
        if (current->next != nullptr) {
            std::cout << " + ";
        }
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    Polynomial poly1;
    addMonom(poly1, 2.0, 3);
    addMonom(poly1, 1.0, 2);
    addMonom(poly1, -3.0, 1);
    addMonom(poly1, 5.0, 0);

    Polynomial poly2;
    addMonom(poly2, 1.0, 2);
    addMonom(poly2, 2.0, 1);
    addMonom(poly2, -4.0, 0);

    std::cout << "Полином 1: ";
    printPolynomial(poly1);

    std::cout << "Полином 2: ";
    printPolynomial(poly2);

    Polynomial sum = addPolynomials(poly1, poly2);
    std::cout << "Сума: ";
    printPolynomial(sum);

    Polynomial product = multiplyPolynomials(poly1, poly2);
    std::cout << "Произведение: ";
    printPolynomial(product);

    double x = 3.0;
    double result = evaluatePolynomial(poly1, x);
    std::cout << "Стойност на полином 1 при x=" << x << ": " << result << std::endl;

    return 0;
}
