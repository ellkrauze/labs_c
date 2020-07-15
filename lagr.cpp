#include <iostream>
using namespace std;

double L(double x, double *yt, double *l, int n)
{
	double result = 0;
	int i;

	for (i = 0; i < n; i++)
	{
		result += yt[i] * l[i];
	}
	return result;
}

double l_func(double x, int i, int n, double *xt)
{
	double result = 1;
	int j;

	for (j = 0; j < n; j++)
	{
		if (j != i)
			if (x == xt[j]) return result = 0;
		if (x == xt[i]) return result = 1;
		if (j == i) {}
		else result *= (x - xt[j]) / (xt[i] - xt[j]);
	}
	return result;
}

double lagr(int n, double *xt, double *yt, double x)
{
	// n - кол-во узлов,
	// xt, yt - абсциссы и ординаты узловых точек,
	// x - абсцисса, в которой вычисляется значение многочлена


	double *l = new double[n]; // базисные полиномы
	for (int i = 0; i < n; i++)
	{
		l[i] = l_func(x, i, n, xt);
	}
	return L(x, yt, l, n);
}

int main()
{
	// [...] считывание кол-ва узлов с консоли
	// [...] считывание с файла абсцисс и ординат узловых точек
	int n;
	double x;
	cout << "Enter N = ";
	cin >> n;
	cout << endl;
	double *xt = new double[n];
	double *yt = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "Enter x[" << i << "] = ";
		cin >> xt[i];
		cout << endl;
		cout << "Enter y[" << i << "] = ";
		cin >> yt[i];
		cout << endl;
	}
	cout << "Enter X = ";
	cin >> x;
	cout << endl;
	double result = lagr(n, xt, yt, x);
	cout << "L(" << x << ") = " << result;
	return 0;
}