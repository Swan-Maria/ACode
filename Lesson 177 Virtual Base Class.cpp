#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner : virtual public PoweredDevice // примечание: PoweredDevice теперь виртуальный базовый класс
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power) // эта строка необходима для создания объектов класса Scanner, но в этой программе она игнорируется
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice // примечание: PoweredDevice теперь виртуальный базовый класс
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power) // эта строка необходима для создания объектов класса Printer, но в этой программе она игнорируется
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power),
        PoweredDevice(power) // построение PoweredDevice выполняется здесь
    {
    }
};

int main()
{
    Copier copier(1, 2, 3);
}