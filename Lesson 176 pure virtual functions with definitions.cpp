#include <iostream>
#include <string>

class Animal // это абстрактный родительский класс
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() = 0; // обратите внимание, speak() является чистой виртуальной функцией
};

const char* Animal::speak()
{
    return "buzz"; // реализация по умолчанию
}

class Dragonfly : public Animal
{

public:
    Dragonfly(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() // этот класс уже не является абстрактным, так как мы переопределили функцию speak()
    {
        return Animal::speak(); // используется реализация по умолчанию класса Animal
    }
};

int main()
{
    Dragonfly dfly("Barbara");
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';
}