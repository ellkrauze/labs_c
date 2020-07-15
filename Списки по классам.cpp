#include <iostream>
#include <string>

using namespace std;

int main()
{
	string *input_text = new string[];
	getline(cin, *input_text, ' ');
	for (int i = 0; i < sizeof(input_text); i++)
	{
		cout << input_text[i];
	}
}