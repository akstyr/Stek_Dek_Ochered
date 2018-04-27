#pragma once

template <class Type>
class Dek
{
private:
	struct dek
	{
		Type Data;
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
	Type GetLeft()
	{
		if (start == NULL)
			return N;
		N--;
		dek *del = start;
		Type D = del->Data;
		start = start->next;
		delete del;		
		return D;
	};
	Type GetRight()
	{
		if (end == NULL)
			return N;
		N--;
		dek *del = end;
		Type D = del->Data;
		end = end->last;
		delete del;		
		return D;
		/*
		int D = end->Data;
		dek *previous = start->last;
		delete end;
		end = previous;
		return D;*/
	};
	void PrintLeft()
	{
		dek *pr = start;
		cout << " top dek-> ";
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
		cout << " end dek-> ";
		while (q != NULL)
		{
			cout << q->Data << " ";
			q = q->last;
		}
		cout << endl;
	};
};
