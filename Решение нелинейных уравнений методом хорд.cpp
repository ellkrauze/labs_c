#include <iostream>
#include<cstdlib>
using namespace std;

double f(double x)
{
	// ������� ������ �������
	return x*x - log(x) - 2*cos(x) - 1;
}

double eqution(double(*f)(double), double a, double b, double e, double *x)
{
	while (abs(f(b) - f(a)) > e)
	{
		*x = (f(b)*a - f(a)*b) / (f(b) - f(a));
		if (f(a)*f(*x) > 0) a = *x;
		else b = *x;
	}
	return *x;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	double a, b, e, x;
	cout << "������� ����� ��������� ����� Enter: " << endl;
	cin >> a;
	cin >> b;

	if (f(a)*f(b) > 0)
	{
		cout << "������������ ��������!" << endl;
		return 0;
	}
	cout << "������� �������� �: ";
	cin >> e;
	cout << "x = " << eqution(f, a, b, e, &x) << endl;
	return 0;
}
