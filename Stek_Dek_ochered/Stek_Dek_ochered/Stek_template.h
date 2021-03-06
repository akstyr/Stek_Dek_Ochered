#pragma once

template <class Type>
class Stek
{
public:
	struct entry //���������-������
	{
		Type Data;
		entry *next;
	};
	entry *top = NULL;
	int N = 0; //���-�� �������
public:
	Stek(){}; 
	void AllAdd(int n) //���������� ����� ����� (����� ��� ���. �������)
	{
		for (int i = n; i > 0; i--)
			Add(i);
	};

	~Stek() //����������
	{
		while (top != NULL)
		{
			entry *pr = top;
			top = top->next; //��������������� �������� ����
			delete pr; //������� ������
		}
		N = 0;
	};

	void Add(Type D) //���������� ��������
	{
		N++;
		entry *element = new entry; //��������� ������
		element->Data = D; //������ ������
		element->next = top; //��������� � ���������� ���������
		top = element; //����� �������
	};

	Type Get() //������ ��������
	{
		if (top == NULL)
			return N; //���� ��������� ���, ������ 0
		N--;
		entry *del = top;
		Type D = del->Data;
		top = top->next; //������ �������
		delete del; //������� ������ �������
		return D; 
	};

	void Print() //����� �� �����
	{
		entry *pr = top;
		cout << "top -> ";
		while (pr != NULL) //������� ���� �� ������ �� 0
		{
			cout << pr->Data << " ";
			pr = pr->next; //������� �� ����. �������
		}
		cout << endl;
	};
};