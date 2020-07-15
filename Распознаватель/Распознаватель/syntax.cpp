#include "syntax.h"
#include "class.h"
#include "definition.h"
#include <iostream>
#include <string>

using namespace std;

bool syntaxModule(Class *arr, int arrSize, int i)
{
	if (arr[i].definition == "условный оператор")
	{
		if (arr[i + 1].definition == "пробел"
			&& arr[i + 2].definition == "подпрограмма1") 
			return syntaxModule(arr, arrSize, i + 3);

		else return false;
	}
	else if (arr[i].definition == "откр.кругл.скобка")
	{
		if (arr[i + 1].definition == "элемент массива"
			&& arr[i + 2].definition == "откр.квадр.скобка") 
			return syntaxModule(arr, arrSize, i + 3);
		else return false;
	}
	else if (arr[i].definition == "минус")
	{
		if (arr[i + 1].definition == "целое" && arr[i + 2].definition == "закр.квадр.скобка"
			&& (arr[i + 3].definition == "пробел" | arr[i + 3].definition == "закр.кругл.скобка"))
		{
			if (arr[i + 3].definition == "пробел") 
				return syntaxModule(arr, arrSize, i + 4);
			if (arr[i + 3].definition == "закр.кругл.скобка") 
				return syntaxModule(arr, arrSize, i + 5);
		}
		else return false;
	}
	else if (arr[i].definition == "арифм.операция")
	{
		if (arr[i + 1].definition == "пробел" && arr[i + 2].definition == "элемент массива"
			&& arr[i + 3].definition == "откр.квадр.скобка") 
			return syntaxModule(arr, arrSize, i + 4);
		else return false;
	}
	else if (arr[i].definition == "целое")
	{
		if (arr[i + 1].definition == "закр.квадр.скобка"
			&& (arr[i + 2].definition == "пробел" | arr[i + 2].definition == "закр.кругл.скобка"))
		{
			if (arr[i + 2].definition == "пробел") 
				return syntaxModule(arr, arrSize, i + 3);
			if (arr[i + 2].definition == "закр.кругл.скобка") 
				return syntaxModule(arr, arrSize, i + 4);
		}
		else return false;
	}
	else if (arr[i].definition == "оператор1")
	{
		if (arr[i + 1].definition == "пробел" && arr[i + 2].definition == "подпрограмма2"
			&& arr[i + 3].definition == "откр.кругл.скобка" && arr[i + 4].definition == "идентификатор"
			&& arr[i + 5].definition == "закр.кругл.скобка")
		{
			if (arr[i + 6].definition == "тчкзпт")
			{
				return true;
			}
			else
			{
				if (arr[i + 6].definition == "пробел"
					&& arr[i + 7].definition == "оператор2") 
					return syntaxModule(arr, arrSize, i + 7);
				else return false;
			}
		}
		else return false;
	}
	else if (arr[i].definition == "оператор2")
	{
		if (arr[i + 1].definition == "пробел" && arr[i + 2].definition == "подпрограмма2"
			&& arr[i + 3].definition == "откр.кругл.скобка" && arr[i + 4].definition == "идентификатор"
			&& arr[i + 5].definition == "закр.кругл.скобка")
		{
			if (arr[i + 6].definition == "тчкзпт")
			{
				
				return true;
			}
			else
			{
				if (arr[i + 6].definition == "пробел" | (i == arrSize - 1)) return true; 
				else return false;						//не рабочий способ, т.к. i оказывается
			}												//гораздо меньше arrSize
		}
		else return false;
	}
}