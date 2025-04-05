#include <iostream>
#include <string>

class Animal
{
protected:
    std::string m_name;

    // �� ������ ���� ����������� protected ��� ��� �� �����, ����� ������������ ����� ����������� ��������� ������� ������ Animal ��������,
    // �� �����, ����� � �������� ������� ������ ��� ������
    Animal(std::string name)
        : m_name(name)
    {
    }

public:
    std::string getName() { return m_name; }
    virtual const char* speak() { return "???"; }
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

void report(Animal& animal)
{
    std::cout << animal.getName() << " says " << animal.speak() << '\n';
}

int main()
{
    Cat cat("Matros");
    Dog dog("Barsik");

    report(cat);
    report(dog);

    Cat matros("Matros"), ivan("Ivan"), martun("Martun");
    Dog barsik("Barsik"), tolik("Tolik"), tyzik("Tyzik");

    // ������� ������ ���������� �� ���� ������� Cat � Dog
    Animal* animals[] = { &matros, &barsik, &ivan, &tolik, &martun, &tyzik };
    for (int iii = 0; iii < 6; ++iii)
        std::cout << animals[iii]->getName() << " says " << animals[iii]->speak() << '\n';

    return 0;
}