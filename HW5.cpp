// HW5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

void Bubble(string file);
void Insertion(string file);
void Quick(string file);
void Shell(string file);
void Merge(string file);

int main()
{
	string files [4] = { "FewUnique","NearlySorted","Random","Reversed" };
	for each (string file in files)
	{
		Bubble(file);
		Insertion(file);
		Quick(file);
		Shell(file);
		Merge(file);
	}
    return 0;
}

void Bubble(string file)
{

}

void Insertion(string file)
{

}

void Quick(string file)
{

}

void Shell(string file)
{

}

void Merge(string file)
{

}
