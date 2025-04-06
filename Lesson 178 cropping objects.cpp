#include <iostream>
#include <vector>
#include <functional> // ��� std::reference_wrapper

class Parent
{
protected:
    int m_value;

public:
    Parent(int value)
        : m_value(value)
    {
    }

    virtual const char* getName() const { return "Parent"; }
    int getValue() const { return m_value; }
};

class Child : public Parent
{
public:
    Child(int value)
        : Parent(value)
    {
    }

    virtual const char* getName() const { return "Child"; }
};
//------------------------------------------------
void printName(const Parent& parent) // ����������: �������� �� ������
{
    std::cout << "I am a " << parent.getName() << '\n';
}

int main()
{
    Child child(7);
    Parent parent = child; // ��� ���������� �����?
    std::cout << "child is a " << child.getName() << " and has value " << child.getValue() << '\n';
    std::cout << "parent is a " << parent.getName() << " and has value " << parent.getValue() << '\n';

    Parent& ref = child;
    std::cout << "ref is a " << ref.getName() << " and has value " << ref.getValue() << '\n';

    Parent* ptr = &child;
    std::cout << "ptr is a " << ptr->getName() << " and has value " << ptr->getValue() << '\n';
    //------------------------------------------------
    Child ch(7);
    printName(ch);
    //------------------------------------------------
    std::vector<Parent*> v;
    v.push_back(new Parent(7)); // ��������� ������ ������ Parent � ��� ������
    v.push_back(new Child(8)); // ��������� ������ ������ Child � ��� ������

    // ������� ��� �������� ������ �������
    for (int count = 0; count < v.size(); ++count)
        std::cout << "I am a " << v[count]->getName() << " with value " << v[count]->getValue() << "\n";

    for (int count = 0; count < v.size(); ++count)
        delete v[count];
    //------------------------------------------------
    std::vector<std::reference_wrapper<Parent> > w;
    Parent p(7); // p � ch �� ����� ���� ���������� ���������
    Child ch(8);
    w.push_back(p); // ��������� ������ ������ Parent � ��� ������
    w.push_back(ch); // ��������� ������ ������ Child � ��� ������

    // ������� ��� �������� ������ �������
    for (int count = 0; count < w.size(); ++count)
        std::cout << "I am a " << w[count].get().getName() << " with value " << w[count].get().getValue() << "\n"; // ���������� .get() ��� ��������� ��������� �� std::reference_wrapper


    return 0;
}