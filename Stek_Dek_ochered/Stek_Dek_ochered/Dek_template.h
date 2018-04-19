#pragma once

template <class Type>
class Dek
{
private:
	struct dek
	{
		int Data;
		dek *next;
		dek *last;
	};
	dek *start = NULL;
	dek *end = NULL;
	int N = 0;

public:
	Dek() {};
	~Dek()
	{
		while (start != NULL)
		{
			dek *ptr = start;
			start = start->next;
			delete ptr;
		}
		end = NULL;
		N = 0;
	};
	void AddLeft(Type D)
	{
		N++;
		dek *element = new dek;
		element->Data = D;
		element->next = start;
		element->last = nullptr;
		if (N != 1)
			start->last = element; //связываем next нового элемента и last прошлого
		start = element;
		if (N == 1)
			end = element;
		if (N == 2)
			end->last = element;
	};
	void AddRight(Type D)
	{
		N++;
		dek *element = new dek;
		element->Data = D;
		element->next = nullptr;
		element->last = end;
		if (N != 1)
			end->next = element;
		end = element;
		if (N == 1)
			start = element;
		if (N == 2)
			start->next = element;
	};
	int GetLeft()
	{
		int D = start->Data;
		dek *previous = start->next;
		delete start;
		start = previous;
		return D;
	};
	int GetRight()
	{
		int D = end->Data;
		dek *previous = start->last;
		delete end;
		end = previous;
		return D;
	};
	void PrintLeft()
	{
		dek *pr = start;
		while (pr != NULL)
		{
			cout << pr->Data << " ";
			pr = pr->next;
		}
		cout << endl;
	};
	void PrintRight()
	{
		dek *q = end;
		while (q != NULL)
		{
			cout << q->Data << " ";
			q = q->last;
		}
		cout << endl;
	};
};
