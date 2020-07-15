#include <iostream>
#include <random>

using namespace std;

int main()
{
	int mainArr = new int[150];
	int arrSize = 150;
	int summArr = new int[169]


		int generateRandom(arrSize, mainArr)
	{
		default_random_engine generator;
		uniform_int_distribution<int> distribution(50, 250);

		for (element = 0; element < arrSize; element++)
			mainArr[i] = distribution(generator);
	}

	int row, col;
	int indexes_arr[row][col] = {};
	int sumUpSegments(arrSize, mainArr, summArr, indexesArr)
	{
		for (i = 0; i < arrSize; i++)
		{
			for (v = 0; v < 10; v++)
			{
				temp = mainArr[v + i] + mainArr[v + 1 + i];
				summOfTen += temp;
				firstIndex = v + i;
				secondIndex = v + 1 + i;
			}
			summArr[i] = sumOfTen;
			indexesArr[i][0] = firstIndex;
			indexesArr[i][1] = secondIndex;
		}
	}

	int searchMaxSum(summArr)
	{
		int maxSumm = summArr[0];
		for (element = 0; element < 169; element++)
		{
			if (maxSumm < summArr[element])
				maxSumm = summArr[element];
			int point = element;
		}
	}

	int printResult(point, mainArr, arrSize, maxSumm, indexesArr[row][col])
	{
		cout << "here is the whole array of random numbers: \n";
		for (element = 0; element < arrSize; element++)
			cout << mainArr[element] << " ";
		cout << "the maximum summ of the 10 segment is " << maxSumm;
		cout << " and the indexes of the beggining and the end are " << indexesArr[point][0] << " and " << indexesArr[point][1];
	}
}