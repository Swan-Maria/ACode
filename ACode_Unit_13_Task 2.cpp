#include <iostream>

template <typename T1, typename T2>
class Pair
{
private:
	T1 m_a;
	T2 m_b;

public:
	Pair(const T1& a, const T2& b)
		: m_a(a), m_b(b)
	{}

	T1& first() { return m_a; }
	const T1& first() const { return m_a; }
	T2& second() { return m_b; }
	const T2& second() const { return m_b; }
};

int main()
{
	Pair<int, double> p1(6, 7.8);
	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair<double, int> p2(3.4, 5);
	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	return 0;
}