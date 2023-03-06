#include <iostream>
#include <cstring>

template <typename T>
class Array {
private:
    T* data;
    size_t size;
public:
    // Конструктор за замовчуванням
    Array() : data(nullptr), size(0) {}

    // Конструктор з параметром size
    Array(size_t size) : data(new T[size]), size(size) {}

    // Конструктор копіювання
    Array(const Array& other) : data(new T[other.size]), size(other.size) {
        memcpy(data, other.data, size * sizeof(T));
    }

    // Деструктор
    ~Array() {
        delete[] data;
    }

    // Перевантажена операція присвоювання
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.size];
            size = other.size;
            memcpy(data, other.data, size * sizeof(T));
        }
        return *this;
    }

    // Перевантажений оператор індексу
    T& operator[](size_t index) {
        return data[index];
    }

    // Перевантажений константний оператор індексу
    const T& operator[](size_t index) const {
        return data[index];
    }

    // Перевантажений оператор додавання для злиття двох масивів
    Array operator+(const Array& other) const {
        Array result(size + other.size);
        memcpy(result.data, data, size * sizeof(T));
        memcpy(result.data + size, other.data, other.size * sizeof(T));
        return result;
    }
};

// Клас, що використовується як параметр шаблону
class MyData {
private:
    int value;
public:
    MyData(int value = 0) : value(value) {}
    int getValue() const { return value; }
    void setValue(int value) { this->value = value; }
};

// Приклад використання класу-шаблону
int main() {
    Array<int> a(3);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;

    Array<int> b(2);
    b[0] = 4;
    b[1] = 5;

    Array<int> c = a + b;
    for (size_t i = 0; i < c.getSize(); i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    Array<MyData> d(2);
    d[0].setValue(10);
    d[1].setValue(20);

    Array<MyData> e(1);
    e[0].setValue(30);

    Array<MyData> f = d + e;
    for (size_t i = 0; i < f.getSize(); i++) {
        std::cout << f[i].getValue() << " ";
    }
    std::cout << std::endl;

    return 0;
}