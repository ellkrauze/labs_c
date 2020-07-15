#include <iostream>
#include <string>
#define size 7

using namespace std;

const int arrSize = 7;

class Stack
{
	public:
	int top;

	int a[size];

	Stack()
	{
		top = -1;
	}
	//объявление всех функций
	void push(int bar_int);
	int pop();
	int isEmpty();
	void print(int x);

};

struct Books
{
	int number;
	char author[20];
	char title[30];
	int year;
	char publisher[40];
	int pages;
	int ISBN;
};

void Stack::push(int bar_int) //вставляет элемент в стек
{
	if (top >= size)
	{
		cout << "Stack Overflow \n";
	}
	else
	{
		a[++top] = bar_int;
		cout << "Element Inserted \n";
	}
}

int Stack::pop() //извлечение головного элемента стэка
{
	if (top < 0) //пустой стек
	{
		cout << "Stack Underflow \n";
		return 0;
	}
	else
	{
		int d = a[top--];
		return d;
	}
}

int Stack::isEmpty()
{
	if (top < 0)
	{
		//cout << "Stack is empty \n";
		return 1; // is Empty? - yes 
	}
	else
	{
		//cout << "Stack is not empty \n";
		return 0; // is Empty? - no
	}
}

void Bookstable(Books a)
{
	printf("| %5d| %19s| %29s| %7d| %14s| %7d| %17d|\n", a.number, a.author, a.title, a.year, a.publisher, a.pages, a.ISBN);
	for (int i = 0; i < 113; i++)
	{
		cout << "-";
	}
	cout << endl;
}

void head()
{
	for (int i = 0; i < 113; i++)
	{
		cout << "-";
	}
	cout << endl;
	printf("|%7s %20s %30s %8s %15s %8s %18s\n", "Number|", "Author|", "Title|", "Year|", "Publisher|", "Pages|",
		"ISBN|");
	for (int i = 0; i < 113; i++)
	{
		cout << "-";
	}
	cout << endl;
}

void display_t(Books book[], int j)
{
	Bookstable(book[j]);
	cout << endl;
}

void Stack::print(int x)
{
	Books book[arrSize];
	book[0] = { 0, "ORWELL", "1984", 1949, "SECKER", 328, 978849 };
	book[1] = { 1, "REMARQUE", "THREE COMRADES", 1937, "LITTLE", 496, 978597 };
	book[2] = { 2, "BRADBURY", "FAHRENHEIT 451", 1953, "BALLANTINE", 256, 978148 };
	book[3] = { 3, "RAND", "ATLAS SHRUGGED", 1957, "HOUSE", 1168, 978886 };
	book[4] = { 4, "SALINGER", "THE CATCHER IN THE RYE", 1951, "SANTILIANA", 277, 978963 };
	book[5] = { 5, "TOLSTOY", "ANNA KARENINA", 1878 , "MESSENGER", 864, 978154 };
	book[6] = { 6, "MARQUEZ", "ONE HUNDRED YEARS OF SOLITUDE", 1967,"SUDAMERICANA", 480, 978892 };
	//int num = stoi(bar);
	
	if (x == 0)
	{
		if (isEmpty() == 0)
		{
			head();
			display_t(book, a[top]);
		}
		if (isEmpty() == 1) cout << "Stack is empty! \n";
	}
	else 
	{
		head();
		while (isEmpty() == 0)
		{
			int j = a[top];
			display_t(book, j);
			//cout << book[a[top]].author << "\n";
			pop();
		}
	}
}

void table()
{
	Books book[arrSize];
	book[0] = { 0, "ORWELL", "1984", 1949, "SECKER", 328, 978849 };
	book[1] = { 1, "REMARQUE", "THREE COMRADES", 1937, "LITTLE", 496, 978597 };
	book[2] = { 2, "BRADBURY", "FAHRENHEIT 451", 1953, "BALLANTINE", 256, 978148 };
	book[3] = { 3, "RAND", "ATLAS SHRUGGED", 1957, "HOUSE", 1168, 978886 };
	book[4] = { 4, "SALINGER", "THE CATCHER IN THE RYE", 1951, "SANTILIANA", 277, 978963 };
	book[5] = { 5, "TOLSTOY", "ANNA KARENINA", 1878 , "MESSENGER", 864, 978154 };
	book[6] = { 6, "MARQUEZ", "ONE HUNDRED YEARS OF SOLITUDE", 1967,"SUDAMERICANA", 480, 978892 };
	head();
	for (int i = 0; i < arrSize; i++)
	{
		display_t(book, i);
	}

}

void menu()
{
	cout << "Press 'Enter' to continue\n";
	getchar();
	system("CLS");
	cout << "To push a row in stack enter 1\n";
	cout << "To pop a row from the stack enter 2\n";
	cout << "To print the top of the stack enter 3\n";
	cout << "To print the stack enter 4\n";
	cout << "Enter 0 to exit! \n";
	table();
	
}

void display()
{	
	
	Stack s1;
	string input;
	
	do
	{
		menu();
		cout << "Here's the table\n";
		
		getline(cin, input);
		if (input == "1")
		{
			string bar;
			cout << "Enter the number of the row you want to push\n";
			cout << "Enter '.' to escape the loop.\n";
			do
			{
				cout << "Enter: ";
				getline(cin, bar);
				if (bar != ".")
				{
					int bar_int = stoi(bar);
					s1.push(bar_int);
				}
			} while (bar != ".");
		}
		if (input == "2") s1.pop();
		if (input == "3") s1.print(0); //print top
		if (input == "4") s1.print(1); //print stack
	} while (input != "0");
}

int main()
{
	display();
}