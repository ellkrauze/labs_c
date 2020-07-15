
#include "input.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string readFile(string str) //блок ввода данных
{
	ifstream file("C:\\Users\\Валерия\\source\\repos\\Распознаватель\\INPUT.txt");
	if (!file.is_open()) // если файл не открыт
		cout << "File can not be opened!\n";
	else
	{
		getline(file, str);
		file.close();
	}
	return str;
}