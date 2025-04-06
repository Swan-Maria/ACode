#include <iostream>
#include <string>

class Animal // ��� ����������� ������������ �����
{
protected:
    std::string m_name;

public:
    Animal(std::string name)
        : m_name(name)
    {
    }

    std::string getName() { return m_name; }
    virtual const char* speak() = 0; // �������� ��������, speak() �������� ������ ����������� ��������
};

const char* Animal::speak()
{
    return "buzz"; // ���������� �� ���������
}

class Dragonfly : public Animal
{

public:
    Dragonfly(std::string name)
        : Animal(name)
    {
    }

    virtual const char* speak() // ���� ����� ��� �� �������� �����������, ��� ��� �� �������������� ������� speak()
    {
        return Animal::speak(); // ������������ ���������� �� ��������� ������ Animal
    }
};

int main()
{
    Dragonfly dfly("Barbara");
    std::cout << dfly.getName() << " says " << dfly.speak() << '\n';
}