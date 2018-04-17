#pragma once

template <class Type>
class Stek
{
private:
	struct entry
	{
		Type Data;
		entry *next;
	};
	entry *top = NULL;
public:
	Stek(){}; 
	~Stek() 
	{
		while (top != NULL)
		{
			entry *pr = top;
			top = top->next;
			delete pr;

		}
	};

	void Add(Type D)
	{
		entry *element = new entry;
		element->Data = D;
		element->next = top;
		top = element;
	};

	Type Get()
	{
		Type D = top->Data;
		entry *previous = top->next;
		delete top;
		top = previous;
		return D;
	};

	void Print()
	{
		entry *pr = top;
		while (pr != NULL)
		{
			cout << pr->Data;
			pr = pr->next;
		}
	};
};