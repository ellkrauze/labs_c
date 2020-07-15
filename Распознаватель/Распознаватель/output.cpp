#include "output.h"
#include <iostream>
#include <fstream>
using namespace std;

void printInFile(bool result) //блок вывода данных
{
	ofstream file;
	file.open("C:\\Users\\Валерия\\source\\repos\\Распознаватель\\OUTPUT.txt", ios::trunc); //перед записью очищает файл
	if (result == true)
	{
		cout << "Check your file\n";
		file << "ACCEPT";
	}
	else
	{
		cout << "Check your file\n";
		file << "REJECT";
	}
	file.close();
}