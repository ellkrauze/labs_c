#include <iostream>

using namespace std;

double f(double x)
{
	// ������� ������ �������
	return x * x - 9 * x + 14;
}

int eqution(double f(double), double a, double b, double e, double *x)
{
	while (abs(f(b) - f(a)) > e)
	{
		x = (f(b)*a - f(a)*b) / (f(b) - f(a));
		if (f(a)*f(x) > 0) a = x;
		else b = x;
	}
	return x;
}

int main
{
	double a, b, e, x;
	cout << '������� ����� ���������' << endl;
	cin >> '����� �����: ' >> a >> endl;
	cin >> '������ �����: ' >> b;

	if (f(a)*f(b) > 0)
	{
		cout >> '������������ ��������!' >> endl;
		return 0;
	}
	cout << '������� �������� �: ';
	cin >> e;
	cout << 'x = ' << equition(f, a, b, e) << endl;
	return 0;

}