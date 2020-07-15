#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void load_matrix(int n, double **a);
void write_in_file(int n, double **matrix);
int invmatr(int n, double **a, double **b);
int check(int n, double **a, double **b);
void display(int rows, int cols, double **matrix);

int main() 
{
	setlocale(LC_ALL, "Russian");
	int i, j, n;
	cout << "������� ������ ������� N: ";
	cin >> n;

	double **a = new double*[n];
	double **b = new double*[n];
	for (i = 0; i < n; i++)
	{
		a[i] = new double[n] {};
		b[i] = new double[n] {};
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			b[i][j] = 0;
			if (i == j) b[i][j] = 1;
		}
	}
	load_matrix(n, a);
	cout << "����������� ������� �: " << endl;
	display(n, n, a);
	if (invmatr(n, a, b))
	{
		cout << "������� ������� ��������? [1/0]  " << check(n, a, b) << endl;
	}
	else
	{
		cout << "������� ������� ��������? [1/0]   0" << endl;
	}

	getchar();
	getchar();

	return 0;
}
void load_matrix(int n, double **a)
{
	int i, j;
	string file_path = "C:/Users/�������/source/repos/��������� ������� ������� ������/��������� ������� ������� ������/matrix.txt";
	ifstream in(file_path);

	if (!in) {
		cout << "Cannot open file.\n";
		return;
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				in >> a[i][j];
			}
		}
		cout << "������� ���������." << endl;
	}
	in.close();
}
void write_in_file(int n, double **matrix)
{
	int i, j;
	string file_path = "C:/Users/�������/source/repos/��������� ������� ������� ������/��������� ������� ������� ������/inv_matrix.txt";
	ofstream outfile(file_path);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			outfile << matrix[i][j] << ' ';
		}
		outfile << endl;
	}
	cout << "�������� ������� ��������� � ���� inv_matrix.txt" << endl;
	return;
}
int invmatr(int n, double **a, double **b)
{
	int i, j, k, result;
	double K;

	double **matrix = new double*[n];
	for (i = 0; i < n; i++)
	{
		matrix[i] = new double[2*n] {};
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix[i][j] = a[i][j];
			matrix[i][j + n] = b[i][j];
		}
	}

	cout << "�������, ��������� ����� ���������� �������� ������� � ���������:" << endl;
	display(n, 2 * n, matrix);

	//������ ��� (��������� ������� ������ ����)
	for (k = 0; k < n; k++) //k-����� ������
	{
		for (i = 0; i < 2 * n; i++) //i-����� �������
			if (a[k][k] != 0) matrix[k][i] = matrix[k][i] / a[k][k]; //������� k-������ �� ������ ���� !=0 ��� �������������� ��� � �������
			else return result = 0;
			
		for (i = k + 1; i < n; i++) //i-����� ��������� ������ ����� k
		{
			if (matrix[k][k] != 0) K = matrix[i][k] / matrix[k][k]; //�����������
			else return result = 0;
			for (j = 0; j < 2 * n; j++) //j-����� ������� ��������� ������ ����� k
				matrix[i][j] = matrix[i][j] - matrix[k][j] * K; //��������� ��������� ������� ���� ������� �����, ���������������� � �������
		}
	}

	cout << "��������������� ������� ����� ��������� ������� ������ ���� (������ ���): " << endl;
	display(n, 2 * n, matrix);

	//�������� ��� (��������� �������� ������� ����)
	for (k = n - 1; k > -1; k--) //k-����� ������
	{
		for (i = 2 * n - 1; i > -1; i--) //i-����� �������
			if (matrix[k][k] != 0) matrix[k][i] = matrix[k][i] / matrix[k][k]; 
			else return result = 0;
		for (i = k - 1; i > -1; i--) //i-����� ��������� ������ ����� k
		{
			if (matrix[k][k] != 0) K = matrix[i][k] / matrix[k][k];
			else return result = 0;
			for (j = 2 * n - 1; j > -1; j--) //j-����� ������� ��������� ������ ����� k
				matrix[i][j] = matrix[i][j] - matrix[k][j] * K;
		}
	}

	cout << "��������������� ������� ����� ��������� �������� ������� ���� (�������� ���): " << endl;
	display(n, 2 * n, matrix);

	// �������� �� ����� �������
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			b[i][j] = matrix[i][j + n];

	// ������ �������� �������
	cout << "�������� �������: " << endl;
	display(n, n, b);
	return result = 1;
}
int check(int n, double **a, double **b)
{
	int i, j, k;
	bool flagE = true;
	double **mul = new double*[n];
	for (i = 0; i < n; i++)
	{
		mul[i] = new double[n] {};
	}
	
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			mul[i][j] = 0;
			for (k = 0; k < n; k++)
			{
				mul[i][j] += a[i][k] * b[k][j];
			}
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i != j)
			{
				if (abs(mul[i][j]) > 0.001) flagE = false;
			}
			else
			{
				if (abs(mul[i][j] - 1) > 0.001) flagE = false;
			}
		}
	}

	cout << "��������� ��������� �������� � �������� ������:" << endl;
	display(n, n, mul);

	if (flagE == false) return 0;
	if (flagE == true)
	{
		write_in_file(n, b);
		return 1;
	}

}

void display(int rows, int cols, double **matrix)
{
	int i, j;
	
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}