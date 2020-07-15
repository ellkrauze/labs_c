#include <string>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
using namespace std;

struct Words
{
	string name;
	string cathegory;
};

int generateRandom(int arrSize)
{
	srand(time(NULL));
	int i = rand() % arrSize;
	return i;
}

void spell(char *word, Words list[], int i) //��������� ����� �� �����
{
	for (int j = 0; j < (list[i].name).length(); j++)
	{
		word[j] = (list[i].name)[j];
	}
}

int inWord(char letter, char *word, int i, Words list[], char *mas, int length) //���� �� � ����� ��������� �����
{
	for (int j = 0; j < length; j++)
	{
		if (word[j] == letter) mas[j] = letter; //���� � ������� ���� ���� ��������� �����, �� �� ��� �� �������
	}										// � ���������� ����������� ������� ������� ������� ��������� �����
	return *mas;
}
bool findInWord(char letter, char *word, int length)
{
	for (int j = 0; j < length; j++)
	{
		if (word[j] == letter) return true;
	}
	return false;
}
bool victory(char *mas, int length)
{
	int guessedLetters = 0;
	for (int v = 0; v < length; v++)
	{
		if (mas[v] != '.') guessedLetters++;
	}
	if (guessedLetters == length) return true;
	else return false;
}
void interaction(int i, int lifes, char *word, Words list[], int length)
{
	int foundLetterCount = 0;
	char letter;
	char *mas = new char[length];
	cout << "����� ���������� � ���������� ���� ���� �����!\n";
	cout << "����� ���� �����, ������� ��� ����� �������. \n";
	cout << "� ��� ���� ������������ ���������� ������.\n�� ������ ����������� ���������� ����� ���������� ���� �����.\n";
	cout << "�� ������ ������ ���������� ������: " << lifes << endl;
	cout << "������� ����!\n";

	cout << list[i].cathegory << " ��� ���?\n";
	
	for (int j = 0; j < length; j++) cout << " _ ";
	cout << endl;
	
	for (int v = 0; v < length; v++)
	{
		mas[v] = '.';
	}
	do
	{
		cout << "������� �����: ";
		cin >> letter;
		inWord(letter, word, i, list, mas, length);
		for (int v = 0; v < length; v++)
		{
			if (mas[v] != '.') foundLetterCount++;
		}
		if (findInWord(letter, word, length) == false)
		{
			system("CLS");
			cout << list[i].cathegory << " ��� ���?\n";
			for (int v = 0; v < length; v++)
			{
				if (mas[v] == '.') cout << " _ ";
				else cout << mas[v] << " ";
			}
			cout << endl;
			lifes--;
			cout << "����� ����� ��� � ���� �����\n";
			cout << "���������� ������: " << lifes << endl;
			
		}
		else
		{
			system("CLS");
			cout << "�� ������� ���������� �����!\n";
			cout << list[i].cathegory << " ��� ���?\n";
			for (int v = 0; v < length; v++)
			{
				if (mas[v] == '.') cout << " _ ";
				else cout << mas[v] << " ";
			}
			cout << endl;
		}
		if (victory(mas, length) == true)
		{
			cout << "����������� � �������! ���� �������� ��� �� �������!\n";
			getchar();
			getchar();
		}
	} while ((lifes != 0)&&!(victory(mas, length) == true));
	if (lifes == 0)
	{
		cout << "� ���������, ������ ����� ������� � �����, ����� ������ �� �����. �� ������, ����� ������� � ��������� ���!\n";
		cout << "���������� �����: " << list[i].name << '.';
		getchar();
		getchar();
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Words list[6];
	list[0] = { "������", "�� ���� ���� ������� ������, ���������� �����, ������� �������� ����� � � ��������� �������� � ����������� ������. �� ��� ����� ������ � �����." };
	list[1] = { "�����", "��������, ���������." };
	list[2] = { "�������������", "��������� �����, ��������������� ����������� �������� ��� ���������." };
	list[3] = { "���������", "���������� ����� ������� ������." };
	list[4] = { "���������", "��������� �����, ���������� ����������� ���� � ����� � ������ � �������������� ��� ��������." };
	list[5] = { "�������", "������� ���� � ��������� ������." };
	//list[6] = { "�������", "���������" };
	int arrSize = 6; //������ ������������ �������
	int i; //
	int lifes = 3;
	
	i = generateRandom(arrSize);
	int length = (list[i].name).length();
	char *word = new char[length];
	spell(word, list, i);
	interaction(i, lifes, word, list, length);
}