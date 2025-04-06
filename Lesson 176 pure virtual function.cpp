#include <iostream>
#include <string>

class Animal // этот Animal является абстрактным родительским классом
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

class Cat : public Animal
{
public:
    Cat(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() { return "Meow"; }
};

class Dog : public Animal
{
public:
    Dog(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() { return "Woof"; }
};

class Lion : public Animal
{
public:
    Lion(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() { return "RAWRR!"; }
};

int main()
{
    Lion lion("John");
    std::cout << lion.getName() << " says " << lion.speak() << '\n';
}