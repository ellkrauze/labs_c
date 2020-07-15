#include <iostream>
#include <map>
#include <string>

using namespace std;

const int arrSize = 7; //количество книг

struct Books
{
	char author[20];
	char title[30];
	int year;
	char publisher[40];
	int pages;
	int ISBN; 
};

map<char, int> Alphabet = 
{
	{'A', 1}, {'B', 2}, 
	{'C', 3}, {'D', 4},
	{'E', 5}, {'F', 6},
	{'G', 7}, {'H', 8},
	{'I', 9}, {'J', 10}, 
	{'K', 11}, {'L', 12},
	{'M', 13}, {'N', 14},
	{'O', 15}, {'P', 16},
	{'Q', 17}, {'R', 18},
	{'S', 19}, {'T', 20},
	{'U', 21}, {'V', 22},
	{'W', 23}, {'X', 24},
	{'Y', 25}, {'Z', 26}
};

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort_byauthor(Books *arr, int k)
{
	for (int i = 0; i < arrSize-1; i++)
	{ 
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (Alphabet[(arr[j].author)[k]] > Alphabet[(arr[j + 1].author)[k]])
			{
				swap(arr[j], arr[j + 1]);
			}
			if (Alphabet[(arr[j].author)[k]] == Alphabet[(arr[j + 1].author)[k]])
			{
				do
				{
					k++;
				}
				while (Alphabet[(arr[j].author)[k]] == Alphabet[(arr[j + 1].author)[k]]);
				if (Alphabet[(arr[j].author)[k]] > Alphabet[(arr[j + 1].author)[k]])
				{
					swap((arr[j]), (arr[j + 1]));
				}
				
			}
			k = 0;
		
		}
	}
}

void sort_bypublisher(Books *arr, int k)
{
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - i - 1; j++)
		{
			if (Alphabet[(arr[j].publisher)[k]] > Alphabet[(arr[j + 1].publisher)[k]])
			{
				swap(arr[j], arr[j + 1]);
			}
			if (Alphabet[(arr[j].publisher)[k]] == Alphabet[(arr[j + 1].publisher)[k]])
			{
				do
				{
					k++;
				} while (Alphabet[(arr[j].publisher)[k]] == Alphabet[(arr[j + 1].publisher)[k]]);
				if (Alphabet[(arr[j].publisher)[k]] > Alphabet[(arr[j + 1].publisher)[k]])
				{
					swap((arr[j]), (arr[j + 1]));
				}

			}
			k = 0;

		}
	}
}

void Bookstable(Books a)
{
		printf("|%19s| %29s| %7d| %14s| %7d| %17d|\n", a.author, a.title, a.year, a.publisher, a.pages, a.ISBN);
		for (int i = 0; i < 105; i++)
		{
			cout << "-";
		}
		cout << endl;
}
void display(Books *arr)
{
	for (int i = 0; i < 105; i++)
	{
		cout << "-";
	}
	cout << endl;
	printf("|%20s %30s %8s %15s %8s %18s\n", "Author|", "Title|", "Year|", "Publisher|","Pages|",
		"ISBN|");
	for (int i = 0; i < 105; i++)
	{
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < arrSize; i++)
	{
		Bookstable(arr[i]);
	}
	
	cout << endl;
}

int main()
{
	Books book[arrSize];
	book[0] = { "ORWELL", "1984", 1949, "SECKER", 328, 978849 };
	book[1] = { "REMARQUE", "THREE COMRADES", 1937, "LITTLE", 496, 978597 };
	book[2] = { "BRADBURY", "FAHRENHEIT 451", 1953, "BALLANTINE", 256, 978148};
	book[3] = { "RAND", "ATLAS SHRUGGED", 1957, "HOUSE", 1168, 978886 };
	book[4] = { "SALINGER", "THE CATCHER IN THE RYE", 1951, "SANTILIANA", 277, 978963 };
	book[5] = { "TOLSTOY", "ANNA KARENINA", 1878 , "MESSENGER", 864, 978154};
	book[6] = { "MARQUEZ", "ONE HUNDRED YEARS OF SOLITUDE", 1967,"SUDAMERICANA", 480, 978892 };

	cout << "original table: " << endl;
	display(book);

	cout << "\ntable sorted by author: " << endl;
	sort_byauthor(book,0);
	display(book);

	cout << "\ntable sorted by publisher: " << endl;
	sort_bypublisher(book,0);
	display(book);

	getchar();
	getchar();	
}