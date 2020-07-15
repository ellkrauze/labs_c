#include <iostream>
#include <string>
#include <time.h>

using namespace std;
//const int size = 20;

class BST
{
	struct node
	{
		int data;
		node *left;
		node *right;
		//int countsKeys(node *t);
		//int compare(node *t, node *temp);
		int getHeight(node *t);
	};

	node *root;
	node *invroot;
	node *rootCopied;
	node *saveroot;
	
	node *makeEmpty(node *t) //очистка
	{
		if (t == NULL)
			return NULL;
		else
		{
			makeEmpty(t->left);
			makeEmpty(t->right);
			delete t;
		}
		return NULL;
	}

	node *insert(int x, node *t) //заполнение дерева
	{
		if (t == NULL)
		{
			t = new node;
			t->data = x;
			t->left = t->right = NULL;
		}
		else
		{
			if (x < t->data) t->left = insert(x, t->left);
			if (x > t->data) t->right = insert(x, t->right);
		}
		return t;
	}

	node *copy(node *t) //копирование дерева
	{
		if (t == NULL)
			return t;
		node *temp = new node();
		temp->data = t->data;
		temp->left = copy(t->left);
		temp->right = copy(t->right);
		return temp;
	}

	node *insert_invert(int x, node *t) 
	{
		if (t == NULL)
		{
			t = new node;
			t->data = x;
			t->right = t->left = NULL;
		}
		else
		{
			if (x > t->data) t->left = insert_invert(x, t->left);
			if (x < t->data) t->right = insert_invert(x, t->right);
		}
		return t;
	}

	node* find(node* t, int x)
	{
		if (t == NULL)
			return NULL;
		else if (x < t->data) 
		{
			cout << t->data << endl;
			return find(t->left, x);
		}
		else if (x > t->data)
		{
			cout << t->data << endl;
			return find(t->right, x);
		}
		else
		{
			cout << t->data << endl;
			return t;
		}
	}

	void inorder(node* t)
	{
		if (t == NULL)
			return;
		inorder(t->left);
		cout << t->data << " ";
		inorder(t->right);
	}

	int countsKeys(node *t)
	{
		int count1 = 0;
		int count2 = 0;
		if (t == NULL)
			return NULL;
		if (t->left != NULL)
		{
			count1++;
			countsKeys(t->left);
		}
		if (t->right != NULL)
		{
			count2++;
			countsKeys(t->right);
		}
		return (count1 + count2 + 1);
	}

	int max(int lh, int rh)
	{
		if (lh > rh)
			return lh;
		else return rh;
	}

	int getHeight(node *t)
	{
		if (t == NULL)
			return 0;

		// find the height of each subtree
		int lh = getHeight(t->left);
		int rh = getHeight(t->right);

		return 1 + max(lh, rh);
	}
	void rec_NumberOfNodes(node *t, int &k)
	{
		if (t != nullptr)
		{
			k++;
			rec_NumberOfNodes(t->left, k);
			rec_NumberOfNodes(t->right, k);
		}
	}

	int numberOfNodes(node *t)
	{
		if (t == nullptr)
			return 0;
		int k = 0;
		rec_NumberOfNodes(t, k);
		return k;
	}

public:
	BST()
	{
		root = NULL;
	}

	~BST()
	{
		root = makeEmpty(root);
		/*if(saveroot == NULL){
			saveroot = root;
		}*/
	}

	void Copy()
	{
		rootCopied = copy(root);
	}
	void invert(int x)
	{
		root = insert_invert(x, root);
	}
	void insert(int x)
	{
		root = insert(x, root);
	}

	void display()
	{
		/*if (choice == 1)
		{
			inorder(root);
			cout << endl;
		}
		if (choice == 0)
		{
			
		}*/
		inorder(root);
		cout << endl;
	}

	void search(int x)
	{ 
		saveroot = find(root, x);
		if (!saveroot) cout << "None. Element's not found\n" << endl;
		getchar();
	}

	int height()
	{
		int hei;
		hei = getHeight(root);
		return hei;
	}
	
	int Nodes()
	{
		int nodes;
		nodes = numberOfNodes(root);
		return nodes;
	}
};

void comparison(BST t, BST t1, int he, int he1, int nods, int nods1 )
{
	cout << "Amount of nodes in tree 1: " << nods << endl;
	cout << "Amount of nodes in tree 2: " << nods1 << endl;
	cout << "\nHight of three 1: " << he << endl;
	cout << "Hight of three 1: " << he1 << endl;
}

void menu()
{
	cout << "Press 'Enter' to continue\n";
	getchar();
	//system("CLS");
	cout << "To fill the tree enter 1\n";
	cout << "To get the height of the tree enter 2\n";
	cout << "To get the number of the keys enter 3\n";
	cout << "To copy the tree enter 4\n";
	cout << "To compare trees enter 5\n";
	cout << "To find the element enter 6\n";
	cout << "To print the first tree in order enter 7\n";
	cout << "To print the iverted tree in order enter 8\n";
	cout << "To print the second tree enter 9 \n";
	cout << "Enter 0 to exit! \n";

}

void input()
{
	BST t;
	BST t1;
	BST t_inv;
	

	string input;
	int keys = 0;
	do
	{
		menu();
		getline(cin, input);
		if (input == "1")
		{
			int x, y;
			srand(time(NULL));
			for (int i = 0; i < 20; i++)
			{
				x = rand() % 100;
				y = rand() % 100;
				t.insert(x);
				t_inv.invert(x);
				t1.insert(y);
			}
		}
		if (input == "2") t.height();
		if (input == "3")
		{
			cout << "The number of keys is " << t.Nodes() << endl;
		}
		if (input == "4")
		{
			t.Copy();
			cout << "Trees are copied successfully\n";
		}
		if (input == "5")
		{
			int he = t.height();
			int he1 = t1.height();
			int nods = t.Nodes();
			int nods1 = t1.Nodes();
			comparison(t,t1,he,he1,nods,nods1);
		}
		if (input == "6")
		{
			cout << "Enter the element you want to find\n";
			int x;
			cin >> x;
			cout << "The path is: \n";
			t.search(x); 
		}
		if (input == "7") t.display();
		if (input == "8") t_inv.display();
		if (input == "9") t1.display();
	} while (input != "0");


}

int main()
{
	input();
}
