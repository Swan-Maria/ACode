#include <iostream>

void printValue(int value)
{
    std::cout << value;
}
//--------------------------------------------------------
int add(int a, int b)
{
    return a + b;
}

int subtract(int a, int b)
{
    return a - b;
}

int multiply(int a, int b)
{
    return a * b;
}

int main()
{
    printValue(7); // это прямой вызов функции
    //--------------------------------------------------------
    int a;
    std::cout << "Enter a number: ";
    std::cin >> a;

    int b;
    std::cout << "Enter another number: ";
    std::cin >> b;

    int op;
    do
    {
        std::cout << "Enter an operation (0 = add, 1 = subtract, 2 = multiply): ";
        std::cin >> op;
    } while (op < 0 || op > 2);

    int result = 0;
    switch (op)
    {
        // Вызываем конкретную функцию напрямую. Используется раннее связывание
    case 0: result = add(a, b); break;
    case 1: result = subtract(a, b); break;
    case 2: result = multiply(a, b); break;
    }

    std::cout << "The answer is: " << result << std::endl;
    //--------------------------------------------------------
    return 0;
}