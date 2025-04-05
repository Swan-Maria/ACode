#include <iostream>

class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    const char* getName() { return "Parent"; }
    int getValue() { return m_value; }
};

class Child : public Parent
{
public:
    Child(int value)
        : Parent(value)
    {
    }

    const char* getName() { return "Child"; }
    int getValueDoubled() { return m_value * 2; }
};

int main()
{
    Child child(7);
    std::cout << "child is a " << child.getName() << " and has value " << child.getValue() << '\n';

    Child& rChild = child;
    std::cout << "rChild is a " << rChild.getName() << " and has value " << rChild.getValue() << '\n';

    Child* pChild = &child;
    std::cout << "pChild is a " << pChild->getName() << " and has value " << pChild->getValue() << '\n';

    Parent& rParent = child;
    Parent* pParent = &child;

    std::cout << "rParent is a " << rParent.getName() << " and has value " << rParent.getValue() << '\n';
    std::cout << "pParent is a " << pParent->getName() << " and has value " << pParent->getValue() << '\n';

    return 0;
}
