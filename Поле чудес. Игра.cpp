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

void spell(char *word, Words list[], int i) //разбиение слова на буквы
{
	for (int j = 0; j < (list[i].name).length(); j++)
	{
		word[j] = (list[i].name)[j];
	}
}

int inWord(char letter, char *word, int i, Words list[], char *mas, int length) //есть ли в слове введенная буква
{
	for (int j = 0; j < length; j++)
	{
		if (word[j] == letter) mas[j] = letter; //если в массиве букв есть введенная буква, то на той же позиции
	}										// в изначально заполненном точками массиве пишется угаданная буква
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
	cout << "Добро пожаловать в консольную игру Поле чудес!\n";
	cout << "Перед вами слово, которое вам нужно угадать. \n";
	cout << "У вас есть определенное количество жизней.\nЗа каждую неправильно отгаданную букву отнимается одна жизнь.\n";
	cout << "На данный момент количество жизней: " << lifes << endl;
	cout << "Удачной игры!\n";

	cout << list[i].cathegory << " Что это?\n";
	
	for (int j = 0; j < length; j++) cout << " _ ";
	cout << endl;
	
	for (int v = 0; v < length; v++)
	{
		mas[v] = '.';
	}
	do
	{
		cout << "Введите букву: ";
		cin >> letter;
		inWord(letter, word, i, list, mas, length);
		for (int v = 0; v < length; v++)
		{
			if (mas[v] != '.') foundLetterCount++;
		}
		if (findInWord(letter, word, length) == false)
		{
			system("CLS");
			cout << list[i].cathegory << " Что это?\n";
			for (int v = 0; v < length; v++)
			{
				if (mas[v] == '.') cout << " _ ";
				else cout << mas[v] << " ";
			}
			cout << endl;
			lifes--;
			cout << "Такой буквы нет в этом слове\n";
			cout << "Количество жизней: " << lifes << endl;
			
		}
		else
		{
			system("CLS");
			cout << "Вы угадали правильную букву!\n";
			cout << list[i].cathegory << " Что это?\n";
			for (int v = 0; v < length; v++)
			{
				if (mas[v] == '.') cout << " _ ";
				else cout << mas[v] << " ";
			}
			cout << endl;
		}
		if (victory(mas, length) == true)
		{
			cout << "Поздравляем с победой! Ваша эрудиция вас не подвела!\n";
			getchar();
			getchar();
		}
	} while ((lifes != 0)&&!(victory(mas, length) == true));
	if (lifes == 0)
	{
		cout << "К сожалению, бывают такие моменты в жизни, когда просто не везет. Ну ничего, может повезти в следующий раз!\n";
		cout << "Загаданное слово: " << list[i].name << '.';
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
	list[0] = { "пряник", "На Руси этот продукт пряный, необычного вкуса, занимал почётное место и в свадебном угощении и поминальном обряде. Он был очень сладок и дорог." };
	list[1] = { "весть", "Известие, сообщение." };
	list[2] = { "интерпретатор", "Компонент среды, непосредственно выполняющий исходный код программы." };
	list[3] = { "ассемблер", "Транслятор языка низкого уровня." };
	list[4] = { "загрузчик", "Компонент среды, копирующий исполняемый файл с диска в память и осуществляющий его загрузку." };
	list[5] = { "авокадо", "Зеленый овощ с косточкой внутри." };
	//list[6] = { "помидор", "съедобное" };
	int arrSize = 6; //размер структурного массива
	int i; //
	int lifes = 3;
	
	i = generateRandom(arrSize);
	int length = (list[i].name).length();
	char *word = new char[length];
	spell(word, list, i);
	interaction(i, lifes, word, list, length);
}