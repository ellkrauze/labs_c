//�������������� �������� � �����
#include "pch.h"
#define GAL_IN_LIT 3.78541178

void main() {
	double gallons; //����� �������� � ��������
	double liters;	// ����� �������� � ������

	scanf("%lf", &gallons);
	liters = gallons * GAL_IN_LIT;
	printf("%lf gallons is %lf liters\n", gallons, liters);
}