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
			line[j] = str[i]; //добавление символа в массив line
			j++; 
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string f_name = "C:\\Users\\Валерия\\source\\repos\\Lab10 Работа с текстовыми файлами\\New text.txt";
	string f_temp_name = "C:\\Users\\Валерия\\source\\repos\\Lab10 Работа с текстовыми файлами\\New text 2.txt";
	ifstream f(f_name, ios::out);
	ofstream f_temp(f_temp_name, ios::out);
	string str;
	int amount = 0; //количество !двойных пробелов
	int j = 0; //в дальнейшем - размер массива char
	if (!f.is_open()) //проверка, открыт ли файл
	{
		cout << "Файл не может быть открыт!";
		getchar();
	}
	else
	{
		cout << "Файл успешно открыт!" << endl;
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
		cout << "Процесс окончен." << endl;
		getchar();
		
	}
	
}