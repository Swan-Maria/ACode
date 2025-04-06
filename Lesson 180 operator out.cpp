#include <iostream>

class Parent
{
public:
	Parent() {}

	// Перегрузка оператора вывода <<
	friend std::ostream& operator<<(std::ostream& out, const Parent& p)
	{
		// Делегируем выполнение операции вывода методу print()
		return p.print(out);
	}

	// Делаем метод print() виртуальным
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

	// Переопределение метода print() для работы с объектами класса Child
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
	std::cout << ch << '\n'; // обратите внимание, всё работает даже без наличия перегрузки оператора вывода в классе Child

	Parent& pref = ch;
	std::cout << pref << '\n';

	return 0;
}