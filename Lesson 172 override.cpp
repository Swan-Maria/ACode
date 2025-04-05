#include <iostream>

class A
{
public:
	virtual const char* getName1(int x) { return "A"; }
	virtual const char* getName2(int x) { return "A"; }
	virtual const char* getName3(int x) { return "A"; }
};

class B : public A
{
public:
	// Эти методы не переопределяют родительские методы
	virtual const char* getName1(short int x) { return "B"; }  // тип параметра short int
	virtual const char* getName2(int x) const { return "B"; }  // метод является const

	// Эти методы не могут переопределить родительские методы, так как сингатура не совпадает
	virtual const char* getName1(short int x) override { return "B"; }  // ошибка компиляции, метод не является переопределением
	virtual const char* getName2(int x) const override { return "B"; }  // ошибка компиляции, метод не является переопределением
	
	// Этот метод не переопределяет родительский метод, так как сигнатура не совпадает
	virtual const char* getName3(int x) override { return "B"; }  // всё хорошо, метод является переопределением A::getName3(int)
};

int main()
{
	return 0;
}
};

int main()
{
	B b;
	A& rParent = b;
	std::cout << rParent.getName1(1) << '\n';
	std::cout << rParent.getName2(2) << '\n';

	return 0;
}