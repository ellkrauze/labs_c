#include "output.h"
#include <iostream>
#include <fstream>
using namespace std;

void printInFile(bool result) //���� ������ ������
{
	ofstream file;
	file.open("C:\\Users\\�������\\source\\repos\\��������������\\OUTPUT.txt", ios::trunc); //����� ������� ������� ����
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