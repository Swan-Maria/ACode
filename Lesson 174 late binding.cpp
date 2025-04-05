#include <iostream>

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

    // Создаем указатель на функцию с именем pFcn (согласен, синтаксис ужасен)
    int (*pFcn)(int, int) = nullptr;

    // Указываем pFcn указывать на функцию, которую выберет пользователь
    switch (op)
    {
    case 0: pFcn = add; break;
    case 1: pFcn = subtract; break;
    case 2: pFcn = multiply; break;
    }

    // Вызываем функцию, на которую указывает pFcn с параметрами a и b.
    // Используется позднее связывание
    std::cout << "The answer is: " << pFcn(a, b) << std::endl;

    return 0;
}