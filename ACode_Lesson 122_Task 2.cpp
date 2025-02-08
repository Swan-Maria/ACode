#include <iostream>

class Numbers
{
private:
	double m_a, m_b, m_c;

public:
	void setValues(double a, double b, double c)
	{
		m_a = a;
		m_b = b;
		m_c = c;
	}

	void print()
	{
		std::cout << "<" << m_a << ", " << m_b << ", " << m_c << ">";
	}

	// Здесь мы можем использовать тот факт, что контроль доступа осуществляется на основе класса для того,
	// чтобы получить доступ напрямую к закрытым членам объекта d класса Numbers
	bool isEqual(const Numbers& d)
	{
		return (m_a == d.m_a && m_b == d.m_b && m_c == d.m_c);
	}
};

int main()
{
	Numbers point1;
	point1.setValues(3.0, 4.0, 5.0);

	Numbers point2;
	point2.setValues(3.0, 4.0, 5.0);

	if (point1.isEqual(point2))
		std::cout << "point1 and point2 are equal\n";
	else
		std::cout << "point1 and point2 are not equal\n";

	Numbers point3;
	point3.setValues(7.0, 8.0, 9.0);

	if (point1.isEqual(point3))
		std::cout << "point1 and point3 are equal\n";
	else
		std::cout << "point1 and point3 are not equal\n";

	return 0;
}