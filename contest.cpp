#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	string str;
	ifstream inFile("product.in");
	ofstream outFile("product.out");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1);
	}
	int mult = 1;
	while (!inFile.eof())
	{
		getline(inFile, str, ' ');
		int num = stol(str);
		if (abs(num) > abs(10^9))
		{
			outFile.clear();
			exit(1);
		}
		else 
		{
			mult *= num;
		}
	}
	outFile << mult;
	inFile.close();
	outFile.close();
}