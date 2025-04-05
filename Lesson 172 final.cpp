class A
{
public:
	virtual const char* getName() { return "A"; }
};

class B final : public A // �������� �������� �� ����������� final �����
{
public:
	// �������� final � �����? ��� ��������, ��� ����� �������������� ��� ������
	virtual const char* getName() override final { return "B"; } // �� ������, ��������������� A::getName()
};

class C : public B // ������ ����������: ������ ����������� final-�����
{
public:
	virtual const char* getName() override { return "C"; } // ������ ����������: ��������������� ������ B::getName(), ������� �������� final
};
