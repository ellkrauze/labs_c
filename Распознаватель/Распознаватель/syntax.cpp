#include "syntax.h"
#include "class.h"
#include "definition.h"
#include <iostream>
#include <string>

using namespace std;

bool syntaxModule(Class *arr, int arrSize, int i)
{
	if (arr[i].definition == "�������� ��������")
	{
		if (arr[i + 1].definition == "������"
			&& arr[i + 2].definition == "������������1") 
			return syntaxModule(arr, arrSize, i + 3);

		else return false;
	}
	else if (arr[i].definition == "����.�����.������")
	{
		if (arr[i + 1].definition == "������� �������"
			&& arr[i + 2].definition == "����.�����.������") 
			return syntaxModule(arr, arrSize, i + 3);
		else return false;
	}
	else if (arr[i].definition == "�����")
	{
		if (arr[i + 1].definition == "�����" && arr[i + 2].definition == "����.�����.������"
			&& (arr[i + 3].definition == "������" | arr[i + 3].definition == "����.�����.������"))
		{
			if (arr[i + 3].definition == "������") 
				return syntaxModule(arr, arrSize, i + 4);
			if (arr[i + 3].definition == "����.�����.������") 
				return syntaxModule(arr, arrSize, i + 5);
		}
		else return false;
	}
	else if (arr[i].definition == "�����.��������")
	{
		if (arr[i + 1].definition == "������" && arr[i + 2].definition == "������� �������"
			&& arr[i + 3].definition == "����.�����.������") 
			return syntaxModule(arr, arrSize, i + 4);
		else return false;
	}
	else if (arr[i].definition == "�����")
	{
		if (arr[i + 1].definition == "����.�����.������"
			&& (arr[i + 2].definition == "������" | arr[i + 2].definition == "����.�����.������"))
		{
			if (arr[i + 2].definition == "������") 
				return syntaxModule(arr, arrSize, i + 3);
			if (arr[i + 2].definition == "����.�����.������") 
				return syntaxModule(arr, arrSize, i + 4);
		}
		else return false;
	}
	else if (arr[i].definition == "��������1")
	{
		if (arr[i + 1].definition == "������" && arr[i + 2].definition == "������������2"
			&& arr[i + 3].definition == "����.�����.������" && arr[i + 4].definition == "�������������"
			&& arr[i + 5].definition == "����.�����.������")
		{
			if (arr[i + 6].definition == "������")
			{
				return true;
			}
			else
			{
				if (arr[i + 6].definition == "������"
					&& arr[i + 7].definition == "��������2") 
					return syntaxModule(arr, arrSize, i + 7);
				else return false;
			}
		}
		else return false;
	}
	else if (arr[i].definition == "��������2")
	{
		if (arr[i + 1].definition == "������" && arr[i + 2].definition == "������������2"
			&& arr[i + 3].definition == "����.�����.������" && arr[i + 4].definition == "�������������"
			&& arr[i + 5].definition == "����.�����.������")
		{
			if (arr[i + 6].definition == "������")
			{
				
				return true;
			}
			else
			{
				if (arr[i + 6].definition == "������" | (i == arrSize - 1)) return true; 
				else return false;						//�� ������� ������, �.�. i �����������
			}												//������� ������ arrSize
		}
		else return false;
	}
}