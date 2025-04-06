#include <iostream>

class Parent
{
public:
	Parent() {}

	// ���������� ��������� ������ <<
	friend std::ostream& operator<<(std::ostream& out, const Parent& p)
	{
		// ���������� ���������� �������� ������ ������ print()
		return p.print(out);
	}

	// ������ ����� print() �����������
	virtual std::ostream& print(std::ostream& out) const
	{
		out << "Parent";
		return out;
	}
};

class Child : public Parent
{
public:
	Child() {}

	// ��������������� ������ print() ��� ������ � ��������� ������ Child
	virtual std::ostream& print(std::ostream& out) const override
	{
		out << "Child";
		return out;
	}
};

int main()
{
	Parent p;
	std::cout << p << '\n';

	Child ch;
	std::cout << ch << '\n'; // �������� ��������, �� �������� ���� ��� ������� ���������� ��������� ������ � ������ Child

	Parent& pref = ch;
	std::cout << pref << '\n';

	return 0;
}