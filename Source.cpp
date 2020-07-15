//преобразование галлонов в литры
#include "pch.h"
#define GAL_IN_LIT 3.78541178

void main() {
	double gallons; //объем жидкости в галлонах
	double liters;	// объем жидкости в литрах

	scanf("%lf", &gallons);
	liters = gallons * GAL_IN_LIT;
	printf("%lf gallons is %lf liters\n", gallons, liters);
}