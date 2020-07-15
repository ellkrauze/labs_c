#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;
int indSize = 1;

int randomize(int *arr, int arrSize, int i)
{
	srand(i);
	arr[i] = rand() % 20;
	i++;
	if (i == arrSize)
	{
		return *arr;
	}
	else
	{	
		return randomize(arr, arrSize, i);
	}
}

int searchMax(int *arr, int *maxInd,int arrSize, int i, int v, int max)
{
	if (max == -1) 
	{
		max = arr[0];
		maxInd[v] = i;
		i++;
		v++;
		return searchMax(arr, maxInd, arrSize, i, v, max);
	}
	if (i == arrSize) {
		return 0;
	}
	if (arr[i] > max)
	{
		delete[] maxInd;
		maxInd = nullptr;
		v = 0;
		indSize = 1;
		int *maxInd = new int[indSize];
		max = arr[i];
		i++;
		maxInd[v] = i;
		v++;
		return searchMax(arr, maxInd, arrSize, i, v, max);
	}
	if (max == arr[i])
	{
		maxInd[v] = i;
		i++;
		v++;
		indSize = v;
		return searchMax(arr, maxInd, arrSize, i, v, max);
	}
	if (arr[i] < max)
	{
		i++;
		return searchMax(arr, maxInd, arrSize, i, v, max);
	}
		
}

void printArray(int*arr, int arrSize)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
}

void printInd(int*arr)
{
	for (int i = 0; i < indSize; i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
}

int main()
{
	
	int v = 0;
	int i = 0;
	int arrSize; 
	cout << "Enter the array size: ";
	cin >> arrSize;
	int *arr = new int[arrSize];
	int *maxInd = new int[indSize];
	int max = -1;
	
	randomize(arr, arrSize, i);
	printArray(arr, arrSize);
	searchMax(arr, maxInd, arrSize, i, v, max);
	printInd(maxInd);

	getchar();
	getchar();
}