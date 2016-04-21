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
void QuickMain(int numbers []);
void Shell(int numbers []);
void MergeMain(int numbers []);
void reset(int numbers[],string file);
void MergeSort(int numbers [],int low, int high,int *comparisons, int *exchanges);
void Merge(int numbers[], int low, int high, int mid, int *comparisons, int *exchanges);
void Qsort(int numbers [],int low, int high,int *comparisons, int * exchanges);
void swap(int *x, int *y);
int partition(int numbers[],int low, int high, int *comparisons, int * exchanges);

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
		for (int i = 0; i < 10000; i++)
		{
			in >> numbers[i];
		}
		in.clear();
		in.close();
		cout << "for " << file << ":" << endl;
		Bubble(numbers);
		reset(numbers, file);
		Insertion(numbers);
		reset(numbers, file);
		//QuickMain(numbers); doesn't work
		reset(numbers, file);
		Shell(numbers);
		reset(numbers, file);
		//MergeMain(numbers);  doesn't work
		reset(numbers, file);
		system("pause");
	}
	system("pause");
	return 0;
}

void Bubble(int numbers [])
{
	int comparison = 0, exchange = 0, temp;
	for (int i = 1; i < 10000; i++)
	{
		for (int j = 0; j < 9999; j++)
		{
			comparison++;
			if (numbers[j] > numbers[j + 1])
			{
				exchange++;
				temp = numbers[j];
				numbers[j] = numbers[j + 1];
				numbers[j + 1] = temp;
			}
		}
	}
	cout << "Bubble comparisons=" << comparison << endl;
	cout << "Bubble exchanges=" << exchange << endl << endl;
}

void Insertion(int numbers [])
{
	int comparison = 0, exchange = 0, element, j;
	for (int i = 1; i < 10000; i++)
	{
		element = numbers[i];
		j = i;
		comparison++;//initial comparision to enter while loop
		while ((j > 0) && (numbers[j - 1] > element))
		{
			comparison++;//comparison each time while loop loops
			exchange++;
			numbers[j] = numbers[j - 1];
			j = j - 1;
		}
		numbers[j] = element;
	}
	cout << "Insertion comparisons=" << comparison << endl;
	cout << "Insertion exchanges=" << exchange << endl << endl;
}

void QuickMain(int numbers [])
{
	int comparison = 0, exchange = 0;
	Qsort(numbers, 0, 9999,&comparison,&exchange);
	cout << "Quick comparisons=" << comparison << endl;
	cout << "Quick exchanges=" << exchange << endl << endl;
}

void Shell(int numbers [])
{
	int comparison = 0, exchange = 0;
	int temp, gap,swapped;
	gap = 5000;
	do
	{
		do
		{
			swapped = 0;
			for (int i = 0; i < 10000 - gap; i++)
			{
				comparison++;
				if (numbers[i] > numbers[i + gap])
				{
					temp = numbers[i];
					numbers[i] = numbers[i + gap];
					numbers[i + gap] = temp;
					exchange++;
					swapped = 1;
				}
			}
		} while (swapped == 1);
	} while ((gap = gap / 2 >= 1));
	cout << "Shell comparisons=" << comparison << endl;
	cout << "Shell exchanges=" << exchange << endl << endl;
}

//void MergeMain(int numbers [])
//{
//	int comparison = 0, exchange = 0;
//	MergeSort(numbers, 0, 10000, &comparison, &exchange);
//	cout << "Merge comparisons=" << comparison << endl;
//	cout << "Merge exchanges=" << exchange << endl << endl;
//}

//void MergeSort(int numbers[], int low, int high, int *comparisons, int *exchanges)
//{
//	int mid;
//	if (low < high)
//	{
//		mid = (low + high) / 2;
//		MergeSort(numbers, low, mid,comparisons,exchanges);
//		MergeSort(numbers, mid + 1, high,comparisons,exchanges);
//		Merge(numbers, low, high, mid, comparisons, exchanges);
//	}
//}

//void Merge(int numbers[], int low, int high, int mid, int *comparisons, int *exchanges)
//{
//	int size = high - low + 1;
//	int i, j, k, C[size];
//	i = low;
//	j = mid + 1;
//	k = 0;
//	while ((i <= mid) && (j <= high))
//	{
//		comparisons++;
//		if (numbers[i] < numbers[j])
//		{
//			C[k] = numbers[i++];
//		}
//		else
//		{
//			exchanges++;
//			C[k] = numbers[j++];
//		}
//		k++;
//	}
//	while (i <= mid)//if there are still ints in first half
//	{
//		C[k++] = numbers[i++];
//	}
//	while (j <= high)//if there are still ints in second half
//	{
//		exchanges++;
//		C[k++] = numbers[j++];
//	}
//	for (i = low; i <= high; i++)//returns ordered ints to first array
//	{
//		numbers[i] = C[i];
//	}
//}

void reset(int numbers[],string file)//resets the array after being sorted
{
	ifstream in;
	in.open(file);
	for (int i = 0; i < 10000; i++)
	{
		in >> numbers[i];
	}
	in.clear();
	in.close();
}

void Qsort(int numbers[], int low, int high, int *comparisons, int * exchanges)
{
	int k;
	if (low < high)
	{
		k = partition(numbers, low, high,comparisons,exchanges);
		Qsort(numbers, low, k - 1,comparisons,exchanges);
		Qsort(numbers, k + 1, high,comparisons,exchanges);
	}
}

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x=*y;
	*y = temp;
}

int partition(int numbers[], int low, int high, int *comparisons, int * exchanges)
{
	int pivot, i, j;
	pivot = numbers[low];
	j = high + 1;
	i = low;
	do
	{
		i++;
		while(numbers[i]<pivot&&low<=high)
			do
			{
				j++;
			} while (pivot<numbers[j]);
			comparisons++;
			if (i < j)
			{
				exchanges++;
				swap(numbers[i], numbers[j]);
			}
	} while (i<j);
	exchanges++;
	numbers[low] = numbers[j];
	exchanges++;
	numbers[j] = pivot;
	return j;
}