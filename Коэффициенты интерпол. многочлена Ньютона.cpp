#include <iostream>
#include <fstream>
#define n 5;
using namespace std;

int newton(int n, double *x, double *y, double *c)
{
	int result;

	result = 1;

	return result;
}

void main() 
{
	setlocale(LC_ALL, "Russian");
	double *x[n], *y[n], *c[n];
	int i;
	ifstream input_file("C:\Users\Валерия\source\repos\Коэффициенты интерпол. многочлена Ньютона\Коэффициенты интерпол. многочлена Ньютона\input.txt");
	ofstream output_file("C:\Users\Валерия\source\repos\Коэффициенты интерпол. многочлена Ньютона\Коэффициенты интерпол. многочлена Ньютона\output.txt");
	if (!input_file)
	{
		cout << "Невозможно открыть файл \n";
		return
	}
	else
	{
		cout << "Файл открыт" << endl;
	}
	getchar();
}