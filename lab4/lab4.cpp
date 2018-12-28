// OOPFourthLabA.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// #include "pch.h"
#include <iostream>
#include <stdlib.h>
#include "time.h"
using namespace std;

template <typename type>
class Array
{
	type *arr, *D;
	int size;

  public:
	void sort()
	{
		for (int j = 0; j < size - 1; j++)
		{
			for (int i = 0; i < size - 1; i++)
			{
				if (arr[i] > arr[i + 1])
				{						 // перевірка, якщо так, то міняти місцями
					type tmp = arr[i];   // зберігаємо і
					arr[i] = arr[i + 1]; // в і кладемо і+1
					arr[i + 1] = tmp;	// в і+1 кладемо і
				}
			}
		}
	}
	void init()
	{
		size = 15;
		arr = new type[size];
		D = new type[1];
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 100;
		}
		int j = 0;
		size = (size + 1) / 2;
		while (size > 0)
		{
			D[j] = size;
			cout << "D[" << j << "]= " << size << endl;
			size = size / 2;
			j++;
		}
		cout << endl
			 << "Length of D array = " << (sizeof(*D) + 1) << endl;
		size = D[0];
		sort();
	}

	void print()
	{
		for (int i = 0; i < size; i++)
			cout << arr[i] << "  ";
	}

	int Search_Binary(type key)
	{
		int middle = D[0];

		for (int i = 0; i < sizeof(*D); i++)
		{
			if (key > arr[middle])
				middle = middle + D[i + 1];
			else if (key < arr[middle])
				middle = middle - D[i + 1];
			else
				return middle;
			if (i == (sizeof(*D) + 1))
				return -1;
		}
	}

	~Array()
	{
		delete arr;
		delete D;
	}
};
int main()
{
	srand(time(NULL));
	Array<int> a;
	a.init();
	a.print();
	int k;
	cout << endl
		 << "enter value to find: " << endl;
	cin >> k;
	cout << "Index: " << a.Search_Binary(k) + 1 << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
