#include <iostream>

class Complex {
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // ������� ������� ��� �������������� ��������� +
    friend Complex operator+(const Complex& lhs, const Complex& rhs);

    void display() const {
        std::cout << "(" << real << " + " << imag << "i)" << std::endl;
    }

private:
    double real;
    double imag;
};

// ��������� ��������� ������� ��� �������������� ��������� +
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.real + rhs.real, lhs.imag + rhs.imag);
}

int main() {
    Complex num1(1.0, 2.0);
    Complex num2(3.0, 4.0);

    Complex sum = num1 + num2;
    sum.display();

    return 0;
}
