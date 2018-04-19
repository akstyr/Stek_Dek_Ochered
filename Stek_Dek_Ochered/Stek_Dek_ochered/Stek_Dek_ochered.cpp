// Stek_Dek_ochered.cpp: определ€ет точку входа дл€ консольного приложени€.
//

#include "stdafx.h"
#include "Stek_template.h"
#include "iostream"
using namespace std;


int main()
{
	setlocale(0, "");
	int n;
	Stek <int> st1, st2, st3;
	cout << "¬ведите количество дисков n ";
	cin >> n;
	st1.AllAdd(n);
	st1.Print();

	while(true)
	{
		if (st2.top == NULL)

	}

	system("Pause");
    return 0;
}

