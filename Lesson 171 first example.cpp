#include <iostream>

class Parent
{
public:
    virtual const char* getName() { return "Parent"; } // добавили ключевое слово virtual
};

class Child : public Parent
{
public:
    virtual const char* getName() { return "Child"; }
};

int main()
{
    Child child;
    Parent& rParent = child;
    std::cout << "rParent is a " << rParent.getName() << '\n';

    return 0;
}