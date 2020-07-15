#include "lexical.h"
#include "class.h"
#include "definition.h"
#include <iostream>
#include <string>

using namespace std;

bool isIF(Definition *mas, int i)
{
	if (mas[i].character == 'i' && mas[i + 1].character == 'f'
		&& mas[i + 2].character == ' ') return true;
	else false;
}

bool isFUNC(Definition *mas, int i)
{
	if (mas[i].character == 'f' && mas[i + 1].character == 'u' &&
		mas[i + 2].character == 'n' && mas[i + 3].character == 'c' && mas[i + 4].character == '(') return true;
	else return false;
}

bool isTHEN(Definition *mas, int i)
{
	if (mas[i].character == 't' && mas[i + 1].character == 'h' &&
		mas[i + 2].character == 'e' && mas[i + 3].character == 'n'
		&& mas[i + 4].character == ' ') return true;
	else return false;
}

bool findIndex(Definition *mas, Class *arr, int size, int i, char *buf)
{
	int j = 0;


	while (mas[i].character != ']')
	{
		if (i != size)
		{
			if (mas[i].definition == "цифра")
			{
				buf[j] = mas[i].character;
				j++;
				i++;
			}
			else return false;
		}
		else return false;
	}
	return true;
}

bool isDIV(Definition *mas, int i)
{
	if (mas[i].character == 'd' && mas[i + 1].character == 'i' && mas[i + 2].character == 'v') return true;
	else return false;

}

bool isMOD(Definition *mas, int i)
{
	if (mas[i].character == 'm' && mas[i + 1].character == 'o' && mas[i + 2].character == 'd') return true;
	else return false;
}

bool isPROC(Definition *mas, int i)
{
	if (mas[i].character == 'p' && mas[i + 1].character == 'r'
		&& mas[i + 2].character == 'o' && mas[i + 3].character == 'c'
		&& mas[i + 4].character == '(') return true;
	else return false;
}

bool isID(Definition *mas, int i)
{
	if (mas[i].character == 'i' && mas[i + 1].character == 'd') return true;
	else return false;
}

bool isELSE(Definition *mas, int i)
{
	if (mas[i].character == 'e' && mas[i + 1].character == 'l'
		&& mas[i + 2].character == 's' && mas[i + 3].character == 'e'
		&& mas[i + 4].character == ' ' && mas[i + 5].character == 'p') return true;
	else return false;
}
bool lexicalModule(Definition *mas, Class *arr, int size, int i, int k)
{
	switch (mas[i].character)
	{
	case 'i':
		if (isIF(mas, i) == true)
		{
			arr[k].character = 'if';
			arr[k].definition = "условный оператор";
			if (mas[i + 2].definition == "пробел")
			{
				arr[k + 1].character = ' ';
				arr[k + 1].definition = "пробел";
				lexicalModule(mas, arr, size, i + 3, k + 2);
				break;
			}
			else return false;
		}
		if (isID(mas, i) == true)
		{
			if (mas[i + 2].definition == "цифра")
			{
				if (mas[i + 2].character == '1')
				{
					arr[k].character = 'id1';
					arr[k].definition = "идентификатор";
					
					lexicalModule(mas, arr, size, i + 3, k + 1);
					break;
				}
				if (mas[i + 2].character == '2')
				{
					arr[k].character = 'id2';
					arr[k].definition = "идентификатор";
					
					lexicalModule(mas, arr, size, i + 3, k + 1);
					break;
				}
			}
			else
			{
				if (mas[i + 2].character == ')')
				{
					arr[k].character = 'id';
					arr[k].definition = "идентификатор";

					lexicalModule(mas, arr, size, i + 2, k + 1);
					break;
				}
			}
		}
		else return false;

	case 'f':
		if (isFUNC(mas, i) == true)
		{
			arr[k].character = 'func';
			arr[k].definition = "подпрограмма1";

			lexicalModule(mas, arr, size, i + 4, k + 1); //func(
			break;										 //01234
		}

		else return false;
	case '(':
		arr[k].character = '(';
		arr[k].definition = "откр.кругл.скобка";
		lexicalModule(mas, arr, size, i + 1, k + 1);
		break;
	case 'A': // допускаются случаи, когда название массива может быть только A или Arr
		if (mas[i + 1].character == '[')
		{
			arr[k].character = 'A';
			arr[k].definition = "элемент массива";
			k++;
			lexicalModule(mas, arr, size, i + 1, k);
			break;
		}
		else
			if (mas[i + 1].character == 'r' && mas[i + 2].character == 'r'
				&& mas[i + 3].character == '[')
			{
				arr[k].character = 'Arr';
				arr[k].definition = "элемент массива";
				k++;
				lexicalModule(mas, arr, size, i + 3, k);
				break;
			}
	case '[':
		arr[k].character = '[';
		arr[k].definition = "откр.квадр.скобка";

		if (mas[i + 1].definition == "минус")
		{
			arr[k + 1].character = '-';
			arr[k + 1].definition = "минус";
			if (mas[i + 2].definition == "минус")
				return false;
			else
			{
				int bufSize = 0;
				int j = i + 2;
				while (mas[j].character != ']')
				{
					bufSize++;
					j++;
				}
				char *buf = new char[bufSize];
				if (findIndex(mas, arr, size, i + 2, buf) == false) return false;
				else
				{
					arr[k + 2].character = *buf;
					arr[k + 2].definition = "целое";
					int length = bufSize;
					lexicalModule(mas, arr, size, i + length + 2, k + 3);
					break;
				}
			}
		}
		else
		{
			int bufSize = 0;
			int j = i + 1;
			while (mas[j].character != ']')
			{
				bufSize++;
				j++;
			}
			char *buf = new char[bufSize];
			if (findIndex(mas, arr, size, i + 1, buf) == false) return false;
			else
			{
				arr[k + 1].character = *buf;
				arr[k + 1].definition = "целое";
				int length = bufSize;
				lexicalModule(mas, arr, size, i + length + 1, k + 2);
				break;
			}
		}

	case ']':
		arr[k].character = ']';
		arr[k].definition = "закр.квадр.скобка";
		if (mas[i + 1].definition == "пробел")
		{
			arr[k + 1].character = ' ';
			arr[k + 1].definition = "пробел";
			if (mas[i + 2].definition == "буква")
			{
				if (isDIV(mas, i + 2) == true)
				{
					arr[k + 2].character = 'div';
					arr[k + 2].definition = "арифм.операция";
					if (mas[i + 5].definition == "пробел")
					{
						arr[k + 3].character = ' ';
						arr[k + 3].definition = "пробел";
						lexicalModule(mas, arr, size, i + 6, k + 4);
						break;
					}
					else return false;
				}
				if (isMOD(mas, i + 2) == true)
				{
					arr[k + 2].character = 'mod';
					arr[k + 2].definition = "арифм.операция";
					if (mas[i + 5].definition == "пробел")
					{
						arr[k + 3].character = ' ';
						arr[k + 3].definition = "пробел";
						lexicalModule(mas, arr, size, i + 6, k + 4);
						break;
					}
					else return false;
				}

			}
			if (mas[i + 2].definition == "умножение")
			{
				arr[k + 2].character = '*';
				arr[k + 2].definition = "арифм.операция";
				if (mas[i + 3].definition == "пробел")
				{
					arr[k + 3].character = ' ';
					arr[k + 3].definition = "пробел";
					lexicalModule(mas, arr, size, i + 4, k + 4);
					break;
				}
				else return false;
			}
			if (mas[i + 2].definition == "деление")
			{
				arr[k + 2].character = '/';
				arr[k + 2].definition = "арифм.операция";
				if (mas[i + 3].definition == "пробел")
				{
					arr[k + 3].character = ' ';
					arr[k + 3].definition = "пробел";
					lexicalModule(mas, arr, size, i + 4, k + 4);
					break;
				}
				else return false;
			}
		}
		if (mas[i + 1].character == ')')
		{
			lexicalModule(mas, arr, size, i + 1, k + 1);
			break;
		}
	case 't':
		if (isTHEN(mas, i) == true)
		{
			arr[k].character = 'then';
			arr[k].definition = "оператор1";
			arr[k + 1].character = ' ';
			arr[k + 1].definition = "пробел";
			lexicalModule(mas, arr, size, i + 5, k + 2);
			break;
		}
		else return false;
	case 'p':
		if (isPROC(mas, i) == true)
		{
			arr[k].character = 'proc';
			arr[k].definition = "подпрограмма2";
			lexicalModule(mas, arr, size, i + 4, k + 1);
			break;
		}
	case ')':
		if (mas[i + 1].definition == "пробел" && mas[i + 2].definition == "буква")
		{
			arr[k].character = ')';
			arr[k].definition = "закр.кругл.скобка";
			arr[k + 1].character = ' ';
			arr[k + 1].definition = "пробел";
			lexicalModule(mas, arr, size, i + 2, k + 2);
			break;
		}
		if (mas[i + 1].definition == "тчкзпт")
		{
			arr[k].character = ')';
			arr[k].definition = "закр.кругл.скобка";
			if (mas[i + 1].definition == "тчкзпт")
			{
				arr[k + 1].character = ';';
				arr[k + 1].definition = "тчкзпт";
			}
			return true;
		}
		if (mas[i - 1].character != '2' | mas[i - 1].character != '1' | mas[i - 1].character != 'd') return false;
		else return false;
	case 'e':
		if (isELSE(mas, i) == true)
		{
			arr[k].character = 'else';
			arr[k].definition = "оператор2";
			arr[k + 1].character = ' ';
			arr[k + 1].definition = "пробел";
			lexicalModule(mas, arr, size, i + 5, k + 2);
			break;
		}
	}
}