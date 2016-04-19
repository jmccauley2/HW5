// HW5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Bubble(vector <int> numbers);
void Insertion(vector <int> numbers);
void Quick(vector <int> numbers);
void Shell(vector <int> numbers);
void Merge(vector <int> numbers);

int main()
{
	string files [4] = { "FewUnique","NearlySorted","Random","Reversed" };
	for each (string file in files)//returns comparisons and exchanges for each file in each sort
	{
		vector <int> numbers;//vector to sort
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
		while (in>>NewNum)//adds numbers to vector
		{
			numbers.push_back(NewNum);
		}

		Bubble(numbers);
		Insertion(numbers);
		Quick(numbers);
		Shell(numbers);
		Merge(numbers);
	}
	system("pause");
    return 0;
}

void Bubble(vector <int> numbers)
{
	int comparison = 0, exchange = 0, temp;	
	for (int i = 1; i < numbers.size(); i++)
	{
		for (int j = 0; j < numbers.size() - 1; j++)
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
	cout << "Bubble exchanges="<< exchange << endl;
}

void Insertion(vector <int> numbers)
{
	int comparison = 0, exchange = 0,element,j;
	for (int i = 1; i < numbers.size(); i++)
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

void Quick(vector <int> numbers)
{
	int comparison = 0, exchange = 0;
	cout << "Quick comparisons=" << comparison << endl;
	cout << "Quick exchanges=" << exchange << endl;;
}

void Shell(vector <int> numbers)
{
	int comparison = 0, exchange = 0;
	cout << "Shell comparisons=" << comparison << endl;
	cout << "Shell exchanges=" << exchange << endl;
}

void Merge(vector <int> numbers)
{
	int comparison = 0, exchange = 0;
	cout << "Merge comparisons=" << comparison << endl;
	cout << "Merge exchanges=" << exchange << endl;
}