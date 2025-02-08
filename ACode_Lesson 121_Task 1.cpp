#include <iostream>

class Numbers
{
public:
	int m_first;
	int m_second;

	void set(int first, int second)
	{
		m_first = first;
		m_second = second;
	}
	void print()
	{
		std::cout << "Numbers(" << m_first << ", " << m_second << ")\n";
	}
};

int main()
{
	Numbers n1;
	n1.set(3, 3);

	Numbers n2{ 4, 4 };

	n1.print();
	n2.print();

	return 0;
}