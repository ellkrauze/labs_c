
#include "input.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

string readFile(string str) //���� ����� ������
{
	ifstream file("C:\\Users\\�������\\source\\repos\\��������������\\INPUT.txt");
	if (!file.is_open()) // ���� ���� �� ������
		cout << "File can not be opened!\n";
	else
	{
		getline(file, str);
		file.close();
	}
	return str;
}