class A
{
public:
	virtual const char* getName() { return "A"; }
};

class B final : public A // обратите внимание на модификатор final здесь
{
public:
	// «аметили final в конце? Ёто означает, что метод переопределить уже нельз€
	virtual const char* getName() override final { return "B"; } // всЄ хорошо, переопределение A::getName()
};

class C : public B // ошибка компил€ции: нельз€ наследовать final-класс
{
public:
	virtual const char* getName() override { return "C"; } // ошибка компил€ции: переопределение метода B::getName(), который €вл€етс€ final
};
