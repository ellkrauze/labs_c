#include <iostream>
#define a 1 //1 //1
#define b -2 //2	//-2
#define c -3 //17 //-3

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	#if b*b - 4*a*c == 0
	{
		double x1 = -b / (2 * a);
		cout << "�������� ����� ��������� ����� " << x1;
	}
	#endif

	#if (b*b - 4*a*c < 0)
	{
		cout << "��� �������������� ������";
	}
	#endif

	#if (b*b - 4*a*c > 0)
	{
		double x2 = (-b - sqrt(b*b - 4 * a*c)) / (2 * a); //3
		double x3 = (-b + sqrt(b*b - 4 * a*c)) / (2 * a); //4
		if (x2 < x3)
		{
			cout << "����� ��������� ����� " << x2 << " � " << x3;
		}
		else 
		{
			cout << "����� ��������� ����� " << x3 << " � " << x2;
		}
			
	}
	#endif


	getchar();
	getchar();
}