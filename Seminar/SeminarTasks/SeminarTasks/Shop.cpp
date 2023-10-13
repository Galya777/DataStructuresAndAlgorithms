#include <iostream>
#include <fstream>
#include <string>

class Product {
private:
    std::string name;
    double price;
    int articleNumber;
    int quantity;

public:
    Product(const std::string& n = "", double p = 0.0, int a = 0, int q = 0)
        : name(n), price(p), articleNumber(a), quantity(q) {}

    // Функции за достъп и промяна
    const std::string& GetName() const { return name; }
    double GetPrice() const { return price; }
    int GetArticleNumber() const { return articleNumber; }
    int GetQuantity() const { return quantity; }

    void SetPrice(double p) { price = p; }
    void SetQuantity(int q) { quantity = q; }

    // Предефиниране на оператора за вход >>
    friend std::istream& operator>>(std::istream& in, Product& product) {
        in >> product.name >> product.price >> product.articleNumber >> product.quantity;
        return in;
    }
};

class ProductList {
private:
    std::fstream productFile;
    std::string fileName;

public:
    ProductList(const std::string& file) : fileName(file) {
        productFile.open(fileName, std::ios::in | std::ios::out | std::ios::binary);
        if (!productFile) {
            // Файлът не съществува, създаваме го и записваме броя продукти (0) в началото.
            productFile.open(fileName, std::ios::out | std::ios::binary);
            int initialProductCount = 0;
            productFile.write(reinterpret_cast<char*>(&initialProductCount), sizeof(int));
        }
    }

    ~ProductList() {
        if (productFile.is_open()) {
            productFile.close();
        }
    }

    // Допълнете този клас с функции, които изпълняват посочените задачи.
};

