#include <iostream>
#include <random>

using namespace std;

int main() 
{
	const int row = 15;
	const int col = 15;
	int *ptr_arr, *ptr_buf_arr, i, j, v, temp, buf, name1, name2;
	int first_element, second_element;
	default_random_engine generator;
	uniform_int_distribution<int> distribution(50, 250);
	
	
	ptr_arr = new int[150];
	ptr_buf_arr = new int[15];
	//arr = (int *)calloc(150, sizeof(int));
	//buf_arr = (int *)calloc(15, sizeof(int));
	//names_arr = (int *)calloc(30, sizeof(int));

	for (i=0; i < 150; i++)
		ptr_arr[i] = distribution(generator);

	int names_arr[row][col] = {};
	int indexes_arr[row][col] = {};
	int ind1;
	int ind2;
	buf = 0;
	for (j = 0; j < row; j++) 
	{
		i = 10 * j;
		do 
		{
			temp = ptr_arr[i] + ptr_arr[i + 1];
			buf += temp;
			i++;
			ind1 = i;
			ind2 = i + 1;
		} while ((10* j <= i) and (i < 10*j + 10));
		name1 = ptr_arr[10 * j];		//the first element of the 10
		name2 = ptr_arr[10 * j + 9];		//the last
		ptr_buf_arr[j] = buf;
		//for (v=0; v<col; v++)
		names_arr[j][0] = name1;
		names_arr[j][1] = name2;
		indexes_arr[j][0] = ind1;
		indexes_arr[j][0] = ind2;

			
	}
	//for (i = 0; i < 15; i++) {
		/* cout << ptr_buf_arr[i] << "\t" << endl;
	}
	cout << "End";

	for (i = 0; i < 15; i++) {
		cout << ptr_names_arr[i] << "\t" << endl;
	}
	//cout << "\nnames_arr: "<<&ptr_names_arr; */
		int max = ptr_buf_arr[0]; //Search MAX summ
		for (v = 0; v < 15; v++) 
		{
			if (ptr_buf_arr[v] > max) 
			{
				max = ptr_buf_arr[v];
				first_element = indexes_arr[v][0];
				//f_index = 2 * v + 1;
				second_element = indexes_arr[v][1];
				//s_index = 2 * v;
			}

		}
	
	cout << "Array of random numbers: \n";
	for (i = 0; i < 150; i++) 
	{
		cout << ptr_arr[i] << " ";
	}
	cout << "\nHere are the begging and the end of section: " << first_element << " and " << second_element;
	cout << "\nHere are the begging and the end of section: " << first_element << " and " << second_element;
	cout << "\nSum = " << max;
	getchar();

}