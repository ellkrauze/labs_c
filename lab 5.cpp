#include <iostream>
#include <time.h>
#include<stdlib.h>
#include<stdio.h> 

using namespace std;

const int arrSize = 999999;

void generateArray(int *arr)
{
	srand(time(NULL));
	for (int element = 0; element < arrSize; element++)
	{
		arr[element] = rand() % 301;
	}
}

int copyArray(int*arr1, int*arr)
{
	for (int element = 0; element < arrSize; element++)
	{
		arr1[element] = arr[element];
	}
	return *arr1;
}

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void quickSort(int *arr, int left, int right) 
{

	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];

	//partition
	while (i <= j) 
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	//recursion
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);

}



void merge(int *arr, int left, int middle, int right) // слияние двух подмассивов (arr[1..m] и arr[m+1..r])
{
	int i, j, k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	int *L = new int[n1]; //временные массивы
	int	*R = new int[n2];

	for (i = 0; i < n1; i++) //копирование элементов во временные массивы
		L[i] = arr[left + i];
	for (j = 0; j < n2; j++)
		R[j] = arr[middle + 1 + j];

	//слияние подмассивов обратно в единый массив arr[0..r]
	i = 0; // индекс первого подмассива
	j = 0; // индекс второго подмассива
	k = left; // индекс merged подмассива
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j]) //Два единичных массива сливаются в общий, при этом из каждого выбирается
						//меньший элемент(сортировка по возрастанию) и записывается в свободную левую ячейку результирующего массива.
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	
	while (i < n1) //копирование оставшихся из L[] элементов
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) //копирование оставшихся из R[] элементов
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}


void mergeSort(int *arr, int left, int right)
{
	if (left < right)
	{
		//то же самое что и (l+r)/2, но позволяет избежать overflow
		//для больших left и right 
		int middle = left + (right - left) / 2;

		//сортировки первой и второй половин массива
		mergeSort(arr, left, middle);
		mergeSort(arr, middle + 1, right);

		merge(arr, left, middle, right);
	}
}
void printArray(int*arr)
{
	for (int i = 0; i < arrSize; i++)
	{
		cout << arr[i] << endl;
	}
	cout << endl;
}

int main()
{
	int *arr = new int[arrSize];
	int *arr1 = new int[arrSize]; //создается второй точно такой же массив для проверки merge sort
	generateArray(arr);
	copyArray(arr1, arr);

	clock_t start1, stop1, start2, stop2; //the type returned by clock
	start1 = clock();
	quickSort(arr, 0, arrSize - 1);
	stop1 = clock();

	start2 = clock();
	mergeSort(arr1, 0, arrSize - 1);
	stop2 = clock();

	cout << fixed; // флаг - вывод чисел с плавающей точкой в фиксированной форме(по умолчанию)
	cout.precision(6); //количество знаков после запятой 
	cout << "Quick sort time: " << (double (stop1 - start1))/ CLOCKS_PER_SEC << endl; //деление на макрос чтобы время возвращалось в секундах
	cout.precision(6);
	cout << "Merge sort time: " << (double (stop2 - start2))/ CLOCKS_PER_SEC << endl;

	delete[] arr;
	arr = nullptr;

	cin.get();
	cin.get();
}