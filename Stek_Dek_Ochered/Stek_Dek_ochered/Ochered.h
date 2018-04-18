#pragma once

template <class Type>
class Ochered
{
private: 
	struct och
	{
		int Data;
		och *next;
	};
	och *start = NULL;
	och *end = NULL;
	int N = 0;
public:
	Ochered() {};
	~Ochered() 
	{
		while (start != NULL)
		{
			och *ptr = start;
			start = top->next;
			delete ptr;

		}
	};
	void Add(Type D)
	{
		N++;
		och *element = new och;
		element->Data = D;
		if (N != 1) //все кроме первой записи
			end->next = element;
		if (N == 2)// при второй записи объ€вл€ем начало
			start = end;
		end = element;
		element->next = NULL;
	};

	void Print()
	{
		och *q = start;
		while (q != NULL)
		{
			cout << q->Data << " ";
			q = q->next;
		}
	};
	Type Get()
	{
		Type D = end->Data;
		och *q = start;
		for (int i = 0; i < N - 2; i++)
		{
			q = q->next;
			cout << q->next << endl;
		}
		delete end;
		q->next = nullptr;
		end = q;
		N--;
		return D;
	};
};

