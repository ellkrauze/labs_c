#include <iostream>
#include <random>
#include <utility>
using namespace std;

const int arrSize = 150;
const int sumArrSize = 150;
int const row = 160, col = 2;

void fillRandom(int mainArr[], int const arrSize)
{
	default_random_engine generator;
	uniform_int_distribution<int> distribution(50, 250);

	for (int element = 0; element < arrSize; element++)
		mainArr[element] = distribution(generator);
}
	

void sumUpSegments(int mainArr[], int sumArr[], int startIndexesArr[], int finIndexesArr[])
{
	for (int i = 0; i <= arrSize-9; i++)
	{
		sumArr[i] = mainArr[i] + mainArr[i + 1] + mainArr[i + 2] + mainArr[i + 3] + mainArr[i + 4] + mainArr[i + 5] + mainArr[i + 6] + mainArr[i + 7] + mainArr[i + 8] + mainArr[i + 9];
		startIndexesArr[i] = i;
		finIndexesArr[i] = i + 9;
		
	}
}

void searchMaxSum(int sumArr[], int &maxSum, int &point)
{
	maxSum = sumArr[0];
	for (int element = 1; element < (sizeof(sumArr)/sizeof(sumArr[0])); element++)
	{
		if (maxSum < sumArr[element])
		{
			maxSum = sumArr[element];
			point = element;
		}
	}
}

void printResult(int point, int mainArr[], int maxSum, int startIndexesArr[], int finIndexesArr[])
{
	cout << "here is the whole array of random numbers: \n";
	for (int element = 0; element < arrSize; element++)
	{
		cout << mainArr[element] << " ";
	}
	cout << "\n the maximum sum of the 10 segment is " << maxSum;
	cout << "\n and the indexes of the beggining and the end are " << startIndexesArr[point] << " and " << finIndexesArr[point];
}

int main() 
{
	int maxSum = 0, point = 0;
	int mainArr[arrSize] = {};
	int sumArr[sumArrSize] = {};
	int startIndexesArr[arrSize] = {};
	int finIndexesArr[arrSize] = {};
	
	fillRandom(mainArr, arrSize);
	sumUpSegments(mainArr, sumArr, startIndexesArr, finIndexesArr);
	searchMaxSum(sumArr, maxSum, point);
	printResult(point, mainArr, maxSum, startIndexesArr, finIndexesArr);

	cin.get();
	cin.get();
	//return 0;

}