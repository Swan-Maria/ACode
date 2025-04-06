#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int power)
    {
        std::cout << "PoweredDevice: " << power << '\n';
    }
};

class Scanner : virtual public PoweredDevice // ����������: PoweredDevice ������ ����������� ������� �����
{
public:
    Scanner(int scanner, int power)
        : PoweredDevice(power) // ��� ������ ���������� ��� �������� �������� ������ Scanner, �� � ���� ��������� ��� ������������
    {
        std::cout << "Scanner: " << scanner << '\n';
    }
};

class Printer : virtual public PoweredDevice // ����������: PoweredDevice ������ ����������� ������� �����
{
public:
    Printer(int printer, int power)
        : PoweredDevice(power) // ��� ������ ���������� ��� �������� �������� ������ Printer, �� � ���� ��������� ��� ������������
    {
        std::cout << "Printer: " << printer << '\n';
    }
};

class Copier : public Scanner, public Printer
{
public:
    Copier(int scanner, int printer, int power)
        : Scanner(scanner, power), Printer(printer, power),
        PoweredDevice(power) // ���������� PoweredDevice ����������� �����
    {
    }
};

int main()
{
    Copier copier(1, 2, 3);
}