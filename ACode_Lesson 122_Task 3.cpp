#include <iostream>
#include <cassert>

class Stack
{
private:
	int m_array[10]; // ��� ����� ������ ������ ����� 
	int m_next; // ��� ����� �������� ���������� ���������� �������� �����

public:

	void reset()
	{
		m_next = 0;
		for (int i = 0; i < 10; ++i)
			m_array[i] = 0;
	}

	bool push(int value)
	{
		// ���� ���� ��� ��������, �� ���������� false
		if (m_next == 10)
			return false;

		m_array[m_next++] = value; // ����������� ���������� ���������� �������� �������� value, � ����� ����������� m_next
		return true;
	}

	int pop()
	{
		// ���� ��������� � ����� ���, �� ������� ��������� assert
		assert(m_next > 0);

				// m_next ��������� �� ��������� ��������� �������, ������� ��������� ������� �� ��������� - ��� m_next-1.
				// �� ����� ������� ���������:
				// int val = m_array[m_next-1]; // �������� ��������� ������� �� ���������
				// --m_next; // m_next ������ �� ������� ������, ��� ��� �� ������ ��� �������� ������� ������� �����
				// return val; // ���������� �������
				// ���� ��������������� ��� ����� �������� ��������� (�����) ������� ����
		return m_array[--m_next];
	}

	void print()
	{
		std::cout << "( ";
		for (int i = 0; i < m_next; ++i)
			std::cout << m_array[i] << ' ';
		std::cout << ")\n";
	}
};

int main()
{
	Stack stack;
	stack.reset();

	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();

	stack.print();

	return 0;
}