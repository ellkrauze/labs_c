#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <Windows.h>
#include "iostream"

using namespace std;

#define WAIT_ANY_KEY getchar()
enum class Keys {
	NOSET,
	LEFT = 1,
	RIGHT = 77,
	TOP = 72,
	DOWN = 80,
	ESC = 27
};

bool GG(int matrix[4][4], int score, int max);
bool Start(int matrix[4][4], int);
bool shiftElementsUp(int matrix[4][4], int* score);
bool turnElementsRight(int matrix[4][4], int);
bool addRandomElement(int matrix[4][4]);
bool proverka_GG(int matrix[4][4]);
char* gameNumber(int, char numх[5]);
int maxNumber(int matrix[4][4]);
int gen_random(int, int);

bool Start(int matrix[4][4], int score) {
	char num[16][5];													//Переменная для отображения числа ячейки
	system("cls");														//Очищение окна консоли
	//Завершение с ошибкой если игровое поле не существует
	if (!matrix) return false;
	// ---------- Отрисовка экрана ----------
	printf("_____________________________________________\n");
	printf("|                  GAME 2048                |\n");
	printf("|               Score: %7d              |\n", score);
	printf("|___________________________________________|\n");
	printf("|          |          |          |          |\n");
	printf("|          |          |          |          |\n");
	printf("| %5s    | %5s    | %5s    | %5s    |\n", gameNumber(matrix[0][0], num[0]), gameNumber(matrix[0][1], num[1]), gameNumber(matrix[0][2], num[2]), gameNumber(matrix[0][3], num[3]));
	printf("|          |          |          |          |\n");
	printf("|__________|__________|__________|__________|\n");
	printf("|          |          |          |          |\n");
	printf("|          |          |          |          |\n");
	printf("| %5s    | %5s    | %5s    | %5s    |\n", gameNumber(matrix[1][0], num[4]), gameNumber(matrix[1][1], num[5]), gameNumber(matrix[1][2], num[6]), gameNumber(matrix[1][3], num[7]));
	printf("|          |          |          |          |\n");
	printf("|__________|__________|__________|__________|\n");
	printf("|          |          |          |          |\n");
	printf("|          |          |          |          |\n");
	printf("| %5s    | %5s    | %5s    | %5s    |\n", gameNumber(matrix[2][0], num[8]), gameNumber(matrix[2][1], num[9]), gameNumber(matrix[2][2], num[10]), gameNumber(matrix[2][3], num[11]));
	printf("|          |          |          |          |\n");
	printf("|__________|__________|__________|__________|\n");
	printf("|          |          |          |          |\n");
	printf("|          |          |          |          |\n");
	printf("| %5s    | %5s    | %5s    | %5s    |\n", gameNumber(matrix[3][0], num[12]), gameNumber(matrix[3][1], num[13]), gameNumber(matrix[3][2], num[14]), gameNumber(matrix[3][3], num[15]));
	printf("|          |          |          |          |\n");
	printf("|__________|__________|__________|__________|\n");
	return true;
}

bool GG(int matrix[4][4], int score, int max) {
	system("cls");														//Очищение окна консоли
	// Начало / конец
	printf("_____________________________________________\n");
	printf("|                 GAME 2048                 |\n");
	printf("|              Score:  %7d              |\n", score);
	printf("|___________________________________________|\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                 %9s                 |\n", (max == 11) ? "YOU WIN!" : "GAME OVER");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|              Начать новую игру?           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|                                           |\n");
	printf("|___________________________________________|\n");
	return true;
}

int main() {
	setlocale(LC_ALL, "Rus");
Start:
	// cout << "W, A, S, D - Движение"; 
	cout << "^, <-, v, -> - Движение";
	Sleep(5000);
	bool processing = true;				//Состояние работы
	bool result;						//Результат выполнения действия
	bool no_char;						//Флаг вводимого значения
	char ch[2];							//Буффер вводимого знака
	char c;								//Буффер клавиши
	int max;							//Максимальное значение
	int score = 0;						//Очки игрока
	int matrix[4][4] = {			//Игровое поле
		{NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL}
	};
	system("cls");										//Очищение окна консоли
	srand((unsigned int)time(NULL));					//Рандом по времени

	//Подготовка запуска игры
	addRandomElement(matrix);
	addRandomElement(matrix);
	Start(matrix, score);

	//Геймплей
	do {
		//Сброс результатов после одного цикла
		result = false;
		no_char = false;
		//Получение зажатой клавиши
		c = _getch();
		//Определение действия по вводимым данным
		switch (c) {
			/* case 'W': case 'Ц': case 'w': case 'ц':
				result = shiftElementsUp(matrix, &score);
				break;
			case 'S': case 'Ы': case 's': case 'ы':
				turnElementsRight(matrix, 2);
				result = shiftElementsUp(matrix, &score);
				turnElementsRight(matrix, 2);
				break;
			case 'A': case 'Ф': case 'a': case 'ф':
				turnElementsRight(matrix, 1);
				result = shiftElementsUp(matrix, &score);
				turnElementsRight(matrix, 3);
				break;
			case 'D': case 'В': case 'd': case 'в':
				turnElementsRight(matrix, 3);
				result = shiftElementsUp(matrix, &score);
				turnElementsRight(matrix, 1);
				break;
			/*/
		case 72:
			result = shiftElementsUp(matrix, &score);
			break;
		case 80:
			turnElementsRight(matrix, 2);
			result = shiftElementsUp(matrix, &score);
			turnElementsRight(matrix, 2);
			break;
		case 75:
			turnElementsRight(matrix, 1);
			result = shiftElementsUp(matrix, &score);
			turnElementsRight(matrix, 3);
			break;
		case 77:
			turnElementsRight(matrix, 3);
			result = shiftElementsUp(matrix, &score);
			turnElementsRight(matrix, 1);
			break;
		case 27:
			result = false;
			processing = false;
			break; /**/
		default:
			no_char = true;
		}

		//Проверка конца игры
		max = maxNumber(matrix);
		if (max == 11)
			processing = false;
		else if (result && !no_char) {
			addRandomElement(matrix);
			Start(matrix, score);
		}
		else if (!result) if (!proverka_GG(matrix))
			processing = false;

	} while (processing);
	//Конец игры
	GG(matrix, score, max);
	scanf("%1s", &ch);
	if (ch[0] == 'Y' || ch[0] == 'y') goto Start;
	WAIT_ANY_KEY;
	return 0;
}

// -------------------- функции ----------------------------
bool addRandomElement(int matrix[4][4]) {

	bool success = false;					//Успешность завершения действия
	bool processing = false;				//Процесс добавления
	int X, Y;							//Координаты добавляемого элемента
	//Завершение с ошибкой если игровое поле не существует
	if (!matrix) return false;
	//Проверка возможности добавить элемент
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (matrix[i][j] == 0) processing = true;
	//Добавление рандомного элемента
	while (processing && !success) {					//Пока не будет добавлен элемент
		//Генерация рандомных координат
		X = gen_random(0, 3);
		Y = gen_random(0, 3);
		//Проверка что в данных координатах точно есть свободное окно
		if (matrix[Y][X] == 0) {
			matrix[Y][X] = gen_random(1, 2);				//Заполнение свободной ячейки
			success = true;
		}
	}
	return success;
}

// Генерация рандомного числа в диапазоне
int gen_random(int range_min, int range_max) {
	return range_min + rand() % (range_max - range_min + 1);
}

// Выполнить игровой сдвиг вверх
bool shiftElementsUp(int matrix[4][4], int* score) {
	bool success = false;
	//Завершение с ошибкой если игровое поле не существует
	if (!matrix) return false;
	// -------- Сдвиг вверх перед склеиванием -------- 
	for (int i = 0; i < 4; i++)														//Перебор ячеек игрового поля
		for (int j = 0; j < 4 - 1; j++)
			if (matrix[j][i] == 0)												//Если пустая ячейка найдена
				for (int k = j + 1; k < 4; k++) if (matrix[k][i] != 0) {			//Если пустая ячейка найдена поиск по столбцу не пустую ячейку 
					matrix[j][i] = matrix[k][i];
					matrix[k][i] = 0;
					success = true;
					break;
				}
	// -------- Склеивание -------- 
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4 - 1; j++)
			if (matrix[j][i] == matrix[j + 1][i] && matrix[j][i] != NULL) {				//Если на ячейку ниже находится такой же элемент и если этот элемент не NULL.
				if (matrix[j][i] == 1 && matrix[i][j] == 1) {
					*score += matrix[j][i] * 4;												//Начисление очков
					matrix[j][i]++;
					matrix[j + 1][i] = 0;
				}
				else {
					*score += pow(2, matrix[j][i] + 1);												//Начисление очков
					matrix[j][i]++;
					matrix[j + 1][i] = 0;
					success = true;
				}
			}
	// -------- Повторный сдвиг, после склеивания -------- 
	for (int i = 0; i < 4; i++)														//Перебор ячеек игрового поля
		for (int j = 0; j < 4 - 1; j++)
			if (matrix[j][i] == 0)														//Если пустая ячейка найдена поиск по столбцу не пустую ячейку
				for (int k = j + 1; k < 4; k++) if (matrix[k][i] != 0) {
					//Сдвиг вверх найденной заполненной ячейки
					matrix[j][i] = matrix[k][i];
					matrix[k][i] = 0;
					success = true;
					break;
				}
	return success;
}

// Поворот матрици n раз
bool turnElementsRight(int matrix[4][4], int count) {
	bool success;											//Успешность переворота
	int buffer;													//Буфер значения
	//Завершение с ошибкой если игровое поле не существует
	if (!matrix) return false;
	// -------- Поворот матрицы на COUNT раз, по часовой стрелке --------
	for (int k = 0; k < count; k++)								//Счетчик поворотов
		//Алгоритм поворота матрици по часовой стрелке на 90 градусов
		for (int i = 0; i < 4 / 2 && matrix != NULL; i++)		//Перебор элементов...
			for (int j = i; j < 4 - 1 - i; j++) {				//...Матрици			
				buffer = matrix[i][j];
				matrix[i][j] = matrix[4 - j - 1][i];
				matrix[4 - j - 1][i] = matrix[4 - i - 1][4 - j - 1];
				matrix[4 - i - 1][4 - j - 1] = matrix[j][4 - i - 1];
				matrix[j][4 - i - 1] = buffer;
				success = true;
			}
	return success;
}

// Поиск максимального значения игрового поля
int maxNumber(int matrix[4][4]) {                             //Завершение с ошибкой если игровое поле не существует.
	if (!matrix) return false;
	int maxNumber = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (maxNumber < matrix[i][j]) maxNumber = matrix[i][j];
	return maxNumber;
}

// Выводит строку num для игрового окна
char* gameNumber(int n, char num[5]) {
	//Перевод в строку
	if (n == 0) {							//При 0 степени
		num[0] = ' ';
		num[1] = '\0';
	}
	else {
		int buff = (int)pow(2, n);			//Получение 2 возведенного в степень числа n
		_itoa(buff, num, 10);				//Перевод в cтроку
	}
	return num;
}

// Проверка конца игры
bool proverka_GG(int matrix[4][4]) {
	bool success = false;															//Успешность проверки
	//Завершение с ошибкой если игровое поле не существует
	if (!matrix) return false;
	//Проверка концца
	for (int k = 0; k < 4; k++) {														//Проверка каждой стороны
		//Алгоритм проверки конца, проверка смещений
		for (int i = 0; i < 4 && !success; i++)
			for (int j = 0; j < 4 - 1 && !success; j++)
				if (matrix[j][i] == 0)
					for (int k = j + 1; k < 4; k++) if (matrix[k][i] != 0) {
						//Сдвиг вверх найденной заполненной ячейки
						success = true;
						break;
					}
		//Алгоритм проверки конца, проверка склеивания
		for (int i = 0; i < 4 && k < 3 && !success; i++)
			for (int j = 0; j < 4 - 1 && !success; j++)
				//Склейка схожего элемента
				if (matrix[j][i] == matrix[j + 1][i] && matrix[j][i] != NULL) success = true;
		//Поворот матрици
		turnElementsRight(matrix, 1);
	}
	return success;
}
