// Stek_Dek_ochered.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Stek_template.h"
#include "iostream"
using namespace std;

void Hannoi(int n, Stek <int> A, Stek <int> B, Stek <int> C)
{ 
	int i, x, a, b;
	for (i = 0; i < (pow(2, n)); i++)
	{
		A.Print();
		B.Print();
		C.Print();
		cout << endl;
		if ((A.top != NULL) && (A.top->Data == 1))
			x = 1;
		if (B.top != NULL && B.top->Data == 1)
			x = 2;
		if (C.top != NULL && C.top->Data == 1)
			x = 3;
		if (i % 2 == 0)
		{
			if (x == 1)
			{
				a = A.Get();
				C.Add(a);
			}
			if (x == 2)
			{
				a = B.Get();
				A.Add(a);
			}
			if (x == 3)
			{
				a = C.Get();
				B.Add(a);
			}
		}
		else
		{
			if (x == 1)
			{
				a = B.Get();
				b = C.Get();
				if (b == 0)
					C.Add(a);
				else if (a == 0)
					B.Add(b);
				else if (a < b && b != 0)
				{
					C.Add(b);
					C.Add(a);
				}
				else if (a > b && a != 0)
				{
					B.Add(a);
					B.Add(b);
				}
			}
			else if (x == 2)
			{
				a = A.Get();
				b = C.Get();
				if (b == 0)
					C.Add(a);
				else if (a == 0)
					A.Add(b);
				else if (a < b && b != 0)
				{
					C.Add(b);
					C.Add(a);
				}
				else if (a > b && a != 0)
				{
					A.Add(a);
					A.Add(b);
				}
			}
			else if (x == 3)
			{
				a = A.Get();
				b = B.Get();
				if (b == 0)
					B.Add(a);
				else if (a == 0)
					A.Add(b);
				else if (a < b && b != 0)
				{
					B.Add(b);
					B.Add(a);
				}
				else if (a > b && a != 0)
				{
					A.Add(a);
					A.Add(b);
				}
			}
		}
	}
};


int main()
{
	setlocale(0, "");
	int n;
	Stek <int> A, B, C;
	cout << "Введите количество дисков n ";
	cin >> n;
	if (n <= 0)
	{
		cout << endl << "Дисков нет";
		system("Pause");
		return 0;
	}
	A.AllAdd(n);
	A.Print();
	cout << endl << endl;

	Hannoi(n, A, B, C);

	A.~Stek();
	B.~Stek();
	C.~Stek();
	system("Pause");
    return 0;
}

