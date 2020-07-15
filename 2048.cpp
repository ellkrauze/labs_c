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
char* gameNumber(int, char num�[5]);
int maxNumber(int matrix[4][4]);
int gen_random(int, int);

bool Start(int matrix[4][4], int score) {
	char num[16][5];													//���������� ��� ����������� ����� ������
	system("cls");														//�������� ���� �������
	//���������� � ������� ���� ������� ���� �� ����������
	if (!matrix) return false;
	// ---------- ��������� ������ ----------
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
	system("cls");														//�������� ���� �������
	// ������ / �����
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
	printf("|              ������ ����� ����?           |\n");
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
	// cout << "W, A, S, D - ��������"; 
	cout << "^, <-, v, -> - ��������";
	Sleep(5000);
	bool processing = true;				//��������� ������
	bool result;						//��������� ���������� ��������
	bool no_char;						//���� ��������� ��������
	char ch[2];							//������ ��������� �����
	char c;								//������ �������
	int max;							//������������ ��������
	int score = 0;						//���� ������
	int matrix[4][4] = {			//������� ����
		{NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL},
		{NULL, NULL, NULL, NULL}
	};
	system("cls");										//�������� ���� �������
	srand((unsigned int)time(NULL));					//������ �� �������

	//���������� ������� ����
	addRandomElement(matrix);
	addRandomElement(matrix);
	Start(matrix, score);

	//��������
	do {
		//����� ����������� ����� ������ �����
		result = false;
		no_char = false;
		//��������� ������� �������
		c = _getch();
		//����������� �������� �� �������� ������
		switch (c) {
			/* case 'W': case '�': case 'w': case '�':
				result = shiftElementsUp(matrix, &score);
				break;
			case 'S': case '�': case 's': case '�':
				turnElementsRight(matrix, 2);
				result = shiftElementsUp(matrix, &score);
				turnElementsRight(matrix, 2);
				break;
			case 'A': case '�': case 'a': case '�':
				turnElementsRight(matrix, 1);
				result = shiftElementsUp(matrix, &score);
				turnElementsRight(matrix, 3);
				break;
			case 'D': case '�': case 'd': case '�':
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

		//�������� ����� ����
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
	//����� ����
	GG(matrix, score, max);
	scanf("%1s", &ch);
	if (ch[0] == 'Y' || ch[0] == 'y') goto Start;
	WAIT_ANY_KEY;
	return 0;
}

// -------------------- ������� ----------------------------
bool addRandomElement(int matrix[4][4]) {

	bool success = false;					//���������� ���������� ��������
	bool processing = false;				//������� ����������
	int X, Y;							//���������� ������������ ��������
	//���������� � ������� ���� ������� ���� �� ����������
	if (!matrix) return false;
	//�������� ����������� �������� �������
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (matrix[i][j] == 0) processing = true;
	//���������� ���������� ��������
	while (processing && !success) {					//���� �� ����� �������� �������
		//��������� ��������� ���������
		X = gen_random(0, 3);
		Y = gen_random(0, 3);
		//�������� ��� � ������ ����������� ����� ���� ��������� ����
		if (matrix[Y][X] == 0) {
			matrix[Y][X] = gen_random(1, 2);				//���������� ��������� ������
			success = true;
		}
	}
	return success;
}

// ��������� ���������� ����� � ���������
int gen_random(int range_min, int range_max) {
	return range_min + rand() % (range_max - range_min + 1);
}

// ��������� ������� ����� �����
bool shiftElementsUp(int matrix[4][4], int* score) {
	bool success = false;
	//���������� � ������� ���� ������� ���� �� ����������
	if (!matrix) return false;
	// -------- ����� ����� ����� ����������� -------- 
	for (int i = 0; i < 4; i++)														//������� ����� �������� ����
		for (int j = 0; j < 4 - 1; j++)
			if (matrix[j][i] == 0)												//���� ������ ������ �������
				for (int k = j + 1; k < 4; k++) if (matrix[k][i] != 0) {			//���� ������ ������ ������� ����� �� ������� �� ������ ������ 
					matrix[j][i] = matrix[k][i];
					matrix[k][i] = 0;
					success = true;
					break;
				}
	// -------- ���������� -------- 
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4 - 1; j++)
			if (matrix[j][i] == matrix[j + 1][i] && matrix[j][i] != NULL) {				//���� �� ������ ���� ��������� ����� �� ������� � ���� ���� ������� �� NULL.
				if (matrix[j][i] == 1 && matrix[i][j] == 1) {
					*score += matrix[j][i] * 4;												//���������� �����
					matrix[j][i]++;
					matrix[j + 1][i] = 0;
				}
				else {
					*score += pow(2, matrix[j][i] + 1);												//���������� �����
					matrix[j][i]++;
					matrix[j + 1][i] = 0;
					success = true;
				}
			}
	// -------- ��������� �����, ����� ���������� -------- 
	for (int i = 0; i < 4; i++)														//������� ����� �������� ����
		for (int j = 0; j < 4 - 1; j++)
			if (matrix[j][i] == 0)														//���� ������ ������ ������� ����� �� ������� �� ������ ������
				for (int k = j + 1; k < 4; k++) if (matrix[k][i] != 0) {
					//����� ����� ��������� ����������� ������
					matrix[j][i] = matrix[k][i];
					matrix[k][i] = 0;
					success = true;
					break;
				}
	return success;
}

// ������� ������� n ���
bool turnElementsRight(int matrix[4][4], int count) {
	bool success;											//���������� ����������
	int buffer;													//����� ��������
	//���������� � ������� ���� ������� ���� �� ����������
	if (!matrix) return false;
	// -------- ������� ������� �� COUNT ���, �� ������� ������� --------
	for (int k = 0; k < count; k++)								//������� ���������
		//�������� �������� ������� �� ������� ������� �� 90 ��������
		for (int i = 0; i < 4 / 2 && matrix != NULL; i++)		//������� ���������...
			for (int j = i; j < 4 - 1 - i; j++) {				//...�������			
				buffer = matrix[i][j];
				matrix[i][j] = matrix[4 - j - 1][i];
				matrix[4 - j - 1][i] = matrix[4 - i - 1][4 - j - 1];
				matrix[4 - i - 1][4 - j - 1] = matrix[j][4 - i - 1];
				matrix[j][4 - i - 1] = buffer;
				success = true;
			}
	return success;
}

// ����� ������������� �������� �������� ����
int maxNumber(int matrix[4][4]) {                             //���������� � ������� ���� ������� ���� �� ����������.
	if (!matrix) return false;
	int maxNumber = 0;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (maxNumber < matrix[i][j]) maxNumber = matrix[i][j];
	return maxNumber;
}

// ������� ������ num ��� �������� ����
char* gameNumber(int n, char num[5]) {
	//������� � ������
	if (n == 0) {							//��� 0 �������
		num[0] = ' ';
		num[1] = '\0';
	}
	else {
		int buff = (int)pow(2, n);			//��������� 2 ������������ � ������� ����� n
		_itoa(buff, num, 10);				//������� � c�����
	}
	return num;
}

// �������� ����� ����
bool proverka_GG(int matrix[4][4]) {
	bool success = false;															//���������� ��������
	//���������� � ������� ���� ������� ���� �� ����������
	if (!matrix) return false;
	//�������� ������
	for (int k = 0; k < 4; k++) {														//�������� ������ �������
		//�������� �������� �����, �������� ��������
		for (int i = 0; i < 4 && !success; i++)
			for (int j = 0; j < 4 - 1 && !success; j++)
				if (matrix[j][i] == 0)
					for (int k = j + 1; k < 4; k++) if (matrix[k][i] != 0) {
						//����� ����� ��������� ����������� ������
						success = true;
						break;
					}
		//�������� �������� �����, �������� ����������
		for (int i = 0; i < 4 && k < 3 && !success; i++)
			for (int j = 0; j < 4 - 1 && !success; j++)
				//������� ������� ��������
				if (matrix[j][i] == matrix[j + 1][i] && matrix[j][i] != NULL) success = true;
		//������� �������
		turnElementsRight(matrix, 1);
	}
	return success;
}
