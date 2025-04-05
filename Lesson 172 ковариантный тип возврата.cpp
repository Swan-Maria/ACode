#include <iostream>

class Parent
{
public:
	// ���� ����� getThis() ���������� ��������� �� ����� Parent
	virtual Parent* getThis() { std::cout << "called Parent::getThis()\n"; return this; }
	void printType() { std::cout << "returned a Parent\n"; }
};

class Child : public Parent
{
public:
	// ������, ���� �������� ��������������� � ����������� ������� ������������� ������ ������ ���������.
	// ������, ��������� Child ��������� ����� Parent, ��������� ����� ����� ���������� Child* ������ Parent*
	virtual Child* getThis() { std::cout << "called Child::getThis()\n";  return this; }
	void printType() { std::cout << "returned a Child\n"; }
};

int main()
{
	Child ch;
	Parent* p = &ch;
	ch.getThis()->printType(); // ���������� Child::getThis(), ������������ Child*, ���������� Child::printType()
	p->getThis()->printType(); // ���������� Child::getThis(), ������������ Parent*, ���������� Parent::printType()
}