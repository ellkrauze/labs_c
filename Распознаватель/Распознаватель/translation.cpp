#include "class.h"
#include "definition.h"
#include "translation.h"
#include <iostream>
#include <string>

using namespace std;

bool isLetter(char a)
{
	char alph1[26] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	char alph2[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	for (int i = 0; i < 26; i++)
	{
		if (a == alph1[i]) return true;
	}
	for (int i = 0; i < 26; i++)
	{
		if (a == alph2[i]) return true;
	}
	return false;
}

bool isNumber(char a)
{
	char numbers[] = { "0123456789" };
	for (int i = 0; i < 10; i++)
	{
		if (a == numbers[i]) return true;
	}
}

bool transliterateChain(string str, Definition *mas)
{

	for (int i = 0; i < str.length(); i++)
	{
		if (isLetter(str[i]) == true)
		{
			mas[i].character = str[i];
			mas[i].definition = "�����";
		}
		if (isNumber(str[i]) == true)
		{
			mas[i].character = str[i];
			mas[i].definition = "�����";
		}
		if (str[i] == '(')
		{
			mas[i].character = str[i];
			mas[i].definition = "����.�����.������";
		}
		if (str[i] == ')')
		{
			mas[i].character = str[i];
			mas[i].definition = "����.�����.������";
		}
		if (str[i] == '[')
		{
			mas[i].character = str[i];
			mas[i].definition = "����.�����.������";
		}
		if (str[i] == ']')
		{
			mas[i].character = str[i];
			mas[i].definition = "����.�����.������";
		}
		if (str[i] == ';')
		{
			mas[i].character = str[i];
			mas[i].definition = "������";
		}
		if (str[i] == '*')
		{
			mas[i].character = str[i];
			mas[i].definition = "���������";
		}
		if (str[i] == '/')
		{
			mas[i].character = str[i];
			mas[i].definition = "�������";
		}
		if (str[i] == '-')
		{
			mas[i].character = str[i];
			mas[i].definition = "�����";
		}
		if (str[i] == ' ')
		{
			mas[i].character = str[i];
			mas[i].definition = "������";
		}

		if (str[i] == '@' | str[i] == '"'
			| str[i] == '#' | str[i] == '�'
			| str[i] == '%' | str[i] == '$'
			| str[i] == '^' | str[i] == '&'
			| str[i] == '?' | str[i] == '~'
			| str[i] == '|' | str[i] == '+'
			| str[i] == ',' | str[i] == '\\'
			| str[i] == '`') return false;  //� ������� �������� ������� -> REJECT
	}
	return true;
}

