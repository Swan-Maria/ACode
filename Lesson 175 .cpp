#include <iostream>

class Parent
{
public:
   // FunctionPointer* __vptr; // здесь
    virtual void function1() { std::cout << "Parent f1\n"; };
    virtual void function2() { std::cout << "Parent f2\n"; };
};

class C1 : public Parent
{
public:
    virtual void function1() { std::cout << "C1 f1\n"; };
};

class C2 : public Parent
{
public:
    virtual void function2() { std::cout << "C2 f2\n"; };
};

int main()
{
    C1 c1;
    Parent* cPtr = &c1;
    cPtr->function1();
	cPtr->function2();

    Parent p;
    Parent* pPtr = &p;
    pPtr->function1();
	pPtr->function2();

}