#include <iostream>
#include <string>

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

template <typename T2>
class StringValuePair : public Pair<std::string, T2>
{
public:
	StringValuePair(const std::string& key, const T2& value)
		: Pair<std::string, T2>(key, value)
	{}
};

int main()
{
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}