#include <iostream>
#include <string>

// �������������� �������
enum ClassID
{
	PARENT,
	CHILD
	// ����� ����� �������� ��� ��������� �������
};

class Parent
{
protected:
	int m_value;

public:
	Parent(int value)
		: m_value(value)
	{
	}

	virtual ~Parent() {}

	virtual ClassID getClassID() { return PARENT; }
};

class Child : public Parent
{
protected:
	std::string m_name;

public:
	Child(int value, std::string name)
		: Parent(value), m_name(name)
	{
	}

	const std::string& getName() { return m_name; }
	virtual ClassID getClassID() { return CHILD; }
};

Parent* getObject(bool bReturnChild)
{
	if (bReturnChild)
		return new Child(1, "Banana");
	else
		return new Parent(2);
}

int main()
{
	Parent* p = getObject(true);
	//-------------------------- dynamic cast ------------------------

	Child* ch = dynamic_cast<Child*>(p); // ���������� dynamic_cast ��� ����������� ��������� ������ Parent � ��������� ������ Child

	if (ch) // ��������� �������� ch �� ������� ���������
		std::cout << "The name of the Child is: " << ch->getName() << '\n';

	//-------------------------- static cast -------------------------
	if (p->getClassID() == CHILD)
	{
		// �� ��� ��������, ��� p ��������� �� ������ ������ Child, ������� ������� ������� ����� �� ������ ����
		Child* ch = static_cast<Child*>(p);
		std::cout << "The name of the Child is: " << ch->getName() << '\n';
	}

	delete p;

	//---------------- operator dynamic cast and reference ------------------
	Child banana(1, "Banana");
	Parent& pp = banana;
	Child& chch = dynamic_cast<Child&>(pp); // ���������� �������� dynamic_cast ��� ����������� ������ ������ Parent � ������ ������ Child

	std::cout << "The name of the Child is: " << chch.getName() << '\n';

	return 0;
}