#include "input.h"
#include "output.h"
#include "class.h"
#include "definition.h"
#include "translation.h"
#include "lexical.h"
#include "syntax.h"
#include <iostream>
#include <Windows.h>
#include <string>


using namespace std;

int getSize(Definition *mas, int size)
{
	int arrSize = 0;
	for (int i = 0; i < size; i++)
	{
		if (mas[i].definition != mas[i + 1].definition)
		{
				arrSize += 1;
				if (mas[i].character = 'd' && (mas[i + 1].character == '1' | mas[i + 1].character == '2'))
					arrSize -= 1;
		}
	}
	return arrSize;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	string str; // chain
	str = readFile(str);

	int size = str.length();

	Definition *mas = new Definition [size];

	transliterateChain(str, mas); //ìîäèôèêàöèÿ ìàññèâà

	int arrSize = getSize(mas, size) + 2;
	Class *arr = new Class[arrSize];
	
	if (transliterateChain(str, mas) == true)
	{
		
		if (lexicalModule(mas, arr, size, 0, 0) == true)
		{
			/*for (int i = 0; i < arrSize; i++)
			{

				cout << '(' << arr[i].character << ";" << arr[i].definition << ")," << endl;
			}
			for (int i = 0; i < arrSize; i++)
			{

				cout << arr[i].definition << ",\n";
			}*/

			printInFile(true);
			
			syntaxModule(arr, arrSize, 0);
			if (syntaxModule(arr, arrSize, 0) == true)
			{
				cout << "ÏÐÀÂÈËÜÍÎ\n";
				printInFile(true);
			}
			else
			{
				cout << "ÍÅÏÐÀÂÈËÜÍÎ\n";
				printInFile(false);
			}
		}
		else printInFile(false);
		
		//int i = 0
		/*cout << str;
		cout << endl;
		for (int i = 0; i < size; i++)
		{

			cout << i << " : " << mas[i].character << " : " << mas[i].definition << endl;
		}*/
	}
	else printInFile(false);
	delete[] arr;
	delete[] mas;
	cin.get();
}