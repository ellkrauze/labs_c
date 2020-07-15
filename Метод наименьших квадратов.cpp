#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int n = 5;
const int p = 2;

double lms(double *x, double *y, double *c);


int main()
{
	setlocale(LC_ALL, "russian");
	double x[n], y[n], c[p + 1], temp[2][n];
	int i, j;
	cout.precision(4);
	cout.setf(ios::fixed);
	string file_path = "C:/Users/Валерия/source/repos/Метод наименьших квадратов/Метод наименьших квадратов/input.txt";
	ifstream input(file_path);
	if (!input)
	{
		cout << "Невозможно открыть файл!" << endl;
		return 0;
	}
	else
	{	
		cout << "Заданное значение количества узлов n = " << n << endl;
		cout << "Заданное значение степени полинома p = " << p << endl;
		for (i = 0; i < 2; i++)
		{
			for (j = 0; j < n; j++)
			{
				input >> temp[i][j];
				if (i == 0) x[j] = temp[i][j];
				if (i == 1) y[j] = temp[i][j];
			}
		}
		cout << "Абсциссы и ориднаты узлов загружены." << endl;
		for (i = 0; i < n; i++)
		{
			cout << 'x' << i << '=' << x[i] << ' ';
		}
		cout << endl;
		for (i = 0; i < n; i++)
		{
			cout << 'y' << i << '=' << y[i] << ' ';
		}
		cout << endl;
		
		lms(x, y, c);
	}

	
	return 0;
}

double lms(double *x, double *y, double *c)
{
	double X[2 * p + 1]; // sigma(xi), sigma(xi^2),sigma(xi^3)...sigma(xi^2n)
	int i, j, k;
	for (i = 0; i < 2 * p + 1; i++)
	{
		X[i] = 0;
		for (j = 0; j < n; j++)
		{
			X[i] = X[i] + pow(x[j], i);
		}
	}

	double B[p + 1][p + 2];
	for (i = 0; i <= p; i++)
		for (j = 0; j <= p; j++)
			B[i][j] = X[i + j];

	double Y[p + 1];
	for (i = 0; i < p + 1; i++)
	{
		Y[i] = 0;
		for (j = 0; j < n; j++)
			Y[i] = Y[i] + pow(x[j], i)*y[j];
	}
	for (i = 0; i <= p; i++) B[i][p + 1] = Y[i];

	int P = p + 1;

	for (i = 0; i < P; i++) // Решение линейных уравнений
		for (k = i + 1; k < P; k++)
			if (B[i][i] < B[k][i])
				for (j = 0; j <= P; j++)
				{
					double temp = B[i][j];
					B[i][j] = B[k][j];
					B[k][j] = temp;
				}
	for (i = 0; i < P - 1; i++)
		for (k = i + 1; k < P; k++)
		{
			double t = B[k][i] / B[i][i];
			for (j = 0; j <= P; j++)
				B[k][j] = B[k][j] - t * B[i][j];
		}
	for (i = P - 1; i >= 0; i--)
	{
		c[i] = B[i][P];
		for (j = 0; j < P; j++)
			if (j != i) c[i] = c[i] - B[i][j] * c[j];
		c[i] = c[i] / B[i][i];
	}

	cout << "Значения коэффициентов:\n";
	for (i = 0; i < P; i++)
		cout << "c" << i << "=" << c[i] << endl;
	cout << "Полином имеет вид:\ny=";
	for (i = 0; i < P; i++) cout << " + (" << c[i] << ")" << "x^" << i;
	cout << endl;
	return *c;
}