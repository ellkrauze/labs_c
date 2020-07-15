#include <iostream>
#include<cstdlib>
using namespace std;

double f(double x)
{
	// впишите нужную функцию
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
	cout << "Введите концы интервала через Enter: " << endl;
	cin >> a;
	cin >> b;

	if (f(a)*f(b) > 0)
	{
		cout << "Неправильный интервал!" << endl;
		return 0;
	}
	cout << "Введите точность Е: ";
	cin >> e;
	cout << "x = " << eqution(f, a, b, e, &x) << endl;
	return 0;
}
