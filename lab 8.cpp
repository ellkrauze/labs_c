#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

void printTens(string n);
void printByDigits(int j, char num, int length);
int func(string n)
{
	char num;
	int length = n.length();
	if (n == "0") cout << " ���� :)";
	if (length == 0)
	{
		return 0;
	}
	for (int j = 0; j < length; j++) //i=2; 
	{
		num = n[j];
		if (j == 1)
		{
			printTens(n);
		}
		printByDigits(j, num, length);
	}
	getchar();
	getchar();
}
void printTens(string n)
{
	if ((n[0] == '0') & (n[1] == '1')) cout << " ������";
	if ((n[0] == '1') & (n[1] == '1')) cout << " �����������";
	if ((n[0] == '2') & (n[1] == '1')) cout << " ����������";
	if ((n[0] == '3') & (n[1] == '1')) cout << " ����������";
	if ((n[0] == '4') & (n[1] == '1')) cout << " ������������";
	if ((n[0] == '5') & (n[1] == '1')) cout << " ����������";
	if ((n[0] == '6') & (n[1] == '1')) cout << " �����������";
	if ((n[0] == '7') & (n[1] == '1')) cout << " ����������";
	if ((n[0] == '8') & (n[1] == '1')) cout << " ������������";
	if ((n[0] == '9') & (n[1] == '1')) cout << " ������������";
}
void printByDigits(int j, char num, int length)
{
	int i = length - j - 1;
	
	if (num == '1')
	{
		if (i == 0) cout << " ����"; //������� - 10^0
		if (i == 2) cout << " ���";	//�����
		if (i == 3) cout << " ������"; //������
		if (i == 4) cout << " ������ �����"; //������� �����
		if (i == 5) cout << " ��� �����"; //����� �����
		if (i == 6) cout << " ���� �������"; //��������
	}
	if (num == '2')
	{
		if (i == 0) cout << " ���"; //������� - 10^0
		if (i == 1) cout << " ��������";
		if (i == 2) cout << " ������";	//�����
		if (i == 3) cout << " ��� ������"; //������
		if (i == 4) cout << " �������� �����"; //������� �����
		if (i == 5) cout << " ������ �����"; //����� �����
		if (i == 6) cout << " ��� ��������"; //��������
	}
	
	if (num == '3')
	{
		if (i == 0) cout << " ���"; //������� - 10^0
		if (i == 1) cout << " ��������";
		if (i == 2) cout << " ������";	//�����
		if (i == 3) cout << " ��� ������"; //������
		if (i == 4) cout << " �������� �����"; //������� �����
		if (i == 5) cout << " ������ �����"; //����� �����
		if (i == 6) cout << " ��� ��������"; //��������
	}

	if (num == '4')
	{
		if (i == 0) cout << " ������"; //������� - 10^0
		if (i == 1) cout << " �����"; //������� - 10^1
		if (i == 2) cout << " ���������";	//�����
		if (i == 3) cout << " ������ ������"; //������
		if (i == 4) cout << " ����� �����"; //������� �����
		if (i == 5) cout << " ��������� �����"; //����� �����
		if (i == 6) cout << " ������ ��������"; //��������
	}
	if (num == '5')
	{
		if (i == 0) cout << " ����"; //������� - 10^0
		if (i == 1) cout << " ���������"; //������� - 10^1
		if (i == 2) cout << " �������";	//�����
		if (i == 3) cout << " ���� �����"; //������
		if (i == 4) cout << " ��������� �����"; //������� �����
		if (i == 5) cout << " ������� �����"; //����� �����
		if (i == 6) cout << " ���� ���������"; //��������
	}
	if (num == '6')
	{
		if (i == 0) cout << " �����"; //������� - 10^0
		if (i == 1) cout << " ����������"; //������� - 10^1
		if (i == 2) cout << " ��������";	//�����
		if (i == 3) cout << " ����� �����"; //������
		if (i == 4) cout << " ���������� �����"; //������� �����
		if (i == 5) cout << " �������� �����"; //����� �����
		if (i == 6) cout << " ����� ���������"; //��������
	}
	if (num == '7')
	{
		if (i == 0) cout << " ����"; //������� - 10^0
		if (i == 1) cout << " ���������"; //������� - 10^1
		if (i == 2) cout << " �������";	//�����
		if (i == 3) cout << " ���� �����"; //������
		if (i == 4) cout << " ��������� �����"; //������� �����
		if (i == 5) cout << " ������� �����"; //����� �����
		if (i == 6) cout << " ���� ���������"; //��������
	}
	if (num == '8')
	{
		if (i == 0) cout << " ������"; //������� - 10^0
		if (i == 1) cout << " �����������"; //������� - 10^1
		if (i == 2) cout << " ���������";	//�����
		if (i == 3) cout << " ������ �����"; //������
		if (i == 4) cout << " ����������� �����"; //������� �����
		if (i == 5) cout << " ��������� �����"; //����� �����
		if (i == 6) cout << " ������ ���������"; //��������
	}
	if (num == '9')
	{
		if (i == 0) cout << " ������"; //������� - 10^0
		if (i == 1) cout << " ���������"; //������� - 10^1
		if (i == 2) cout << " ���������";	//�����
		if (i == 3) cout << " ������ �����"; //������
		if (i == 4) cout << " ��������� �����"; //������� �����
		if (i == 5) cout << " ��������� �����"; //����� �����
		if (i == 6) cout << " ������ ���������"; //��������
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string n;
	cout << "������� ���� ����� (�� 10 �����) � �������� ����: ";
	getline(cin, n);
	int number = atoi(n.c_str());
	string str = to_string(number);
	cout << "���� ����� � ��������� ����: ";
	func(str);
}