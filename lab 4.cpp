#include<iostream>
#include<ctime>

using namespace std;

const int rows = 9, cols = 9;
void fillArray(int **mainArray)
{
	srand(time(NULL));
	for (int i= 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			mainArray[i][j] = rand()%31;
}

void printArray(int **mainArray)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%5d", mainArray[i][j]);

		}
		cout << "\n\n";
	}
}		

void swapChunks(int **mainArray)
{	
	int buf;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j <= 3; j++)
		{
			if (j >= i) break;
			buf = mainArray[i][j];
			mainArray[i][j] = mainArray[i][cols - j - 1]; 
			mainArray[i][cols - j - 1] = buf;
		}

	}
}

int main()
{
	int **mainArray = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		mainArray[i] = new int[cols] {};
	}

	fillArray(mainArray);
	printArray(mainArray);
	swapChunks(mainArray);
	cout << "\n New array: \n";
	printArray(mainArray);

	getchar();
}