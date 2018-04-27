#pragma once

template <class Type>
class Stek
{
public:
	struct entry //процедура-запись
	{
		Type Data;
		entry *next;
	};
	entry *top = NULL;
	int N = 0; //кол-во записей
public:
	Stek(){}; 
	void AllAdd(int n) //заполнение всего стека (нужно для инд. задания)
	{
		for (int i = n; i > 0; i--)
			Add(i);
	};

	~Stek() //деструктор
	{
		while (top != NULL)
		{
			entry *pr = top;
			top = top->next; //последовательно сдвигаем вниз
			delete pr; //очищаем память
		}
		N = 0;
	};

	void Add(Type D) //добавление элемента
	{
		N++;
		entry *element = new entry; //выделение памяти
		element->Data = D; //запись данных
		element->next = top; //связываем с предидущим элементом
		top = element; //новая вершина
	};

	Type Get() //взятие элемента
	{
		if (top == NULL)
			return N; //если элементов нет, вернет 0
		N--;
		entry *del = top;
		Type D = del->Data;
		top = top->next; //меняем вершину
		delete del; //очищаем старую вершину
		return D; 
	};

	void Print() //вывод на экран
	{
		entry *pr = top;
		cout << "top -> ";
		while (pr != NULL) //выводим пока не дойдем до 0
		{
			cout << pr->Data << " ";
			pr = pr->next; //переход на след. элемент
		}
		cout << endl;
	};
};