#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

using namespace std;

void uploadToFile(ofstream &f_temp, char *line, int amount, int j)
{
	for (int i = 0; i < amount; i++) f_temp << "  ";
	for (int jj = 0; jj < j; jj++) f_temp << line[jj];
	f_temp << endl;
}

void func(string str, char *line, int &amount, int &j)
{
	for (int i = 0; i < str.length(); i++)
	{
		if ((str[i] == ' ') && (str[i + 1] == ' ')) amount++;
		else
		{
			line[j] = str[i]; //���������� ������� � ������ line
			j++; 
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string f_name = "C:\\Users\\�������\\source\\repos\\Lab10 ������ � ���������� �������\\New text.txt";
	string f_temp_name = "C:\\Users\\�������\\source\\repos\\Lab10 ������ � ���������� �������\\New text 2.txt";
	ifstream f(f_name, ios::out);
	ofstream f_temp(f_temp_name, ios::out);
	string str;
	int amount = 0; //���������� !������� ��������
	int j = 0; //� ���������� - ������ ������� char
	if (!f.is_open()) //��������, ������ �� ����
	{
		cout << "���� �� ����� ���� ������!";
		getchar();
	}
	else
	{
		cout << "���� ������� ������!" << endl;
		while (getline(f, str))
		{
			int size = str.length();
			char *line = new char[size];
			func(str, line, amount, j);
			uploadToFile(f_temp, line, amount, j);
			delete[] line;
			amount = 0;
			j = 0;
		}
		f_temp.close();
		f.close();
		remove(f_name.c_str());
		rename(f_temp_name.c_str(), f_name.c_str());
		cout << "������� �������." << endl;
		getchar();
		
	}
	
}