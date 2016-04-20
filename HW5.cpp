// HW5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Bubble(int  numbers []);
void Insertion(int numbers []);
void Quick(int numbers []);
void Shell(int numbers []);
void Merge(int numbers []);

int main()
{
	string files[4] = { "FewUnique","NearlySorted","Random","Reversed" };
	for each (string file in files)//returns comparisons and exchanges for each file in each sort
	{
		int numbers [10000];//vector to sort
		file = file + ".txt";
		ifstream in;
		in.open(file);
		if (!in.is_open())
		{
			cout << "I could not find " << file << endl;
			cout << "Check the location.\n";
			return 0;
		}
		int NewNum;
		for (int i = 0; i < 10000; i++)
		{
			in >> numbers[i];
		}
		in.clear();
		in.close();
		Bubble(numbers);

		Insertion(numbers);
		Quick(numbers);
		Shell(numbers);
		Merge(numbers);
	}
	system("pause");
	return 0;
}

void Bubble(int numbers [])
{
	int comparison = 0, exchange = 0, temp;
	for (int i = 1; i < 10000; i++)
	{
		for (int j = 0; j < 10000 - 1; j++)
		{
			comparison++;
			if (numbers[j] > numbers[j + 1])
			{
				exchange++;
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = numbers[j];
			}
		}
	}
	cout << "Bubble comparisons=" << comparison << endl;
	cout << "Bubble exchanges=" << exchange << endl;
}

void Insertion(int numbers [])
{
	int comparison = 0, exchange = 0, element, j;
	for (int i = 1; i < 10000; i++)
	{
		element = numbers[i];
		j = i;
		while (j > 0 && numbers[j - 1] > element)
		{
			numbers[j] = numbers[j - i];
			j = j - 1;
		}
		numbers[j] = element;
	}
	cout << "Insertion comparisons=" << comparison << endl;
	cout << "Insertion exchanges=" << exchange << endl;
}

void Quick(int numbers [])
{
	int comparison = 0, exchange = 0;
	cout << "Quick comparisons=" << comparison << endl;
	cout << "Quick exchanges=" << exchange << endl;;
}

void Shell(int numbers [])
{
	int comparison = 0, exchange = 0;
	cout << "Shell comparisons=" << comparison << endl;
	cout << "Shell exchanges=" << exchange << endl;
}

void Merge(int numbers [])
{
	int comparison = 0, exchange = 0;
	cout << "Merge comparisons=" << comparison << endl;
	cout << "Merge exchanges=" << exchange << endl;
}