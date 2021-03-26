#include "Tasks.h"
#include <iostream>
#include <string>

using namespace std;

template <class X> void Filling_matrix_NULL(X **a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = 0;
		}
	}
}

template <class X> void Filling_matrix_rand(X** a, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand()%10;
		}
	}
}

template <class X> void Filling_Array(X *a , X n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

}

int Max_array(int *arr, const int &n, int &i1)
{
	int max;
	max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (max < arr[i])
		{
			i1 = i;
			max = arr[i];
		}
			
	}
	return max;
}

int Max(int x1, int x2, int x3)
{
	int max;
	max = x1;
	if (max < x2)
	{
		max = x2;
		if (max < x3)
			max = x3;
	}
	else if (max < x3)
	{
		max = x3;
	}
	return max;
}

void competition(const int &n)
{
	int n1 = 0, k;
	int* score = new int[n];
	cout << "Enter k: ";
	cin >> k;
	cout << "Enter scores:\n";
	Filling_Array(score, n);
	for (int i = 0; i < n; i++)
	{
		if (score[i] >= score[k-1])
			n1++;
	}
	cout << "Quantity participant: " << n1 << endl;

	delete[] score;
}

void Lock(int n)
{
	int s = 0;
	int* start = new int[n];
	int* secret = new int[n];
	cout << "Enter start position:\n";
	Filling_Array(start, n);
	cout << "Enter secret combination:\n";
	Filling_Array(secret, n);
	for (int i = 0; i < n; i++)
	{
		if (abs(secret[i] - start[i]) <= 5)
		{
			s += abs(secret[i] - start[i]);
		}
		else
		{
			s += 10 - abs(secret[i] - start[i]);
		}
	}
	cout << "\nResult: " << s << endl;

	delete[] start;
	delete[] secret;
}

void Azbuka_Borze(char* ch)
{
	int i = 0, k = 0, j;
	cout << "Enter combination:\n";
	while (i < 200)
	{
		ch[i] = getchar();
		if (ch[i] == '\n')
			break;
		i++;
	}
	// 0 передается как «.», 1 как «-.», 2 как «--»
	int* mass = new int[i] {0};
	cout << "\nResult:\n";
	for (j = 0, k = 0; k < i; k++, j++)
	{
		if (ch[j] == '.')
			mass[k] = 0;
		else if (ch[j] == '-')
		{
			if (ch[j + 1] == '.')
			{
				mass[k] = 1;
				j++;
			}
			else
			{
				mass[k] = 2;
				j++;
			}

		}
	}
	for (int j = 0; j < k - 2; j++)
		cout << mass[j];

	delete[] mass;
}

void Egor_Trenning(int n)
{
	int chest = 0, biceps = 0, back = 0;
	int* exercise = new int[n];
	cout << "Enter exercise:\n";
	for (int i = 1; i <= n; i++)
	{
		cin >> exercise[i];
	}
	for (int i = 1; i <= n; i++)
	{
		if (i % 3 == 1)
		{
			chest += exercise[i] * n;
		}
		else if (i % 3 == 2)
		{
			biceps += exercise[i] * n;
		}
		else
		{
			back += exercise[i] * n;
		}
	}
	if (biceps > back && biceps > chest)
		cout << "\nBiceps";
	else if (back > biceps && back > chest)
		cout << "\nBack:";
	else
		cout << "\nChest";

	delete[] exercise;
}

void Crossword_of_Japan(const int& n)  // 18 min
{
	int n1 = 0, nc = 0, j = 0;
	char* symbol = new char[n];
	cout << "Enter symbol: ";
	for (int i = 0; i < n; i++)
		cin >> symbol[i];
	for (int i = 0; i < n; i++)
	{
		if (symbol[i] == 'B' && symbol[i + 1] != 'B')
		{
			n1++;
		}
	}
	int* q = new int[n1] {0};
	for (int i = 0; i < n; i++)
	{
		if (symbol[i] == 'B')
		{
			q[j] += 1;
		}
		else
			j++;
	}
	cout << "Quantity group: " << n1 << endl;
	for (int i = 0; i < n1; i++)
		cout << q[i] << "\t";

	delete[] symbol;
}

void Raven(const int& n)
{
	int* chisl = new int[n];
	int* otvet = new int[n] {0};
	cout << "Enter digits: ";
	for (int i = 0; i < n; i++)
		cin >> chisl[i];
	for (int i = n - 1; i >= 0; i--)
	{
		if (i == n - 1)
			otvet[i] = chisl[i];
		else if (i % 2 == 0)
		{
			otvet[i] = chisl[i];
			for (int j = n - 1; j > i; j--)
			{
				if (j % 2 == 0)
					otvet[i] -= otvet[j];
				else
					otvet[i] += otvet[j];
			}
		}
		else
		{
			otvet[i] = chisl[i];
			for (int j = n - 1; j > i; j--)
			{
				if (j % 2 == 0)
					otvet[i] += otvet[j];
				else
					otvet[i] -= otvet[j];
			}
		}
	}
	cout << "Result: ";
	for (int i = 0; i < n; i++)
		cout << otvet[i] << "\t";

	delete[] chisl;
	delete[] otvet;
}
void Black_Jack(const int& n)
{
	int q = 0;
	int balls[13] = { 2,3,4,5,6,7,8,9,10,10,10,10,11 };
	for (int m = 0; m < 4; m++)
	{
		for (int i = 0; i < 13; i++)
		{
			if (10 + balls[i] == n)
			{
				q++;
			}
		}
	}
	if (n == 20)
		q--;
	cout << "Quantity variants: " << q << endl;
} // 12 min

void Taxi(const int& n)
{
	int q = 1, s = 0, s1 = 0, max = 0;
	bool b = true;
	int* group = new int[n];
	cout << "Enter group:\n";
	for (int i = 0; i < n; i++)
		cin >> group[i];

	for (int i = 0; i < n; i++)
	{
		s += group[i];
	}
	q = s % 4 + s / 4;
	cout << "\nQuantity: " << q << endl;

	delete[] group;
}

void Ahaha(const int& n)
{
	int n1, x, s = 0, j;
	for (int i = 0; i < n; i++)
	{
		cin >> n1;
		for (j = 1; j <= n1; j++)
		{
			cin >> x;
			s += x;
		}
		if (s > n1 - s)
		{
			n1 = s / 2 * 2;
			s = 1;
		}
		else
		{
			n1 = n1 - s;
			s = 0;
		}
		cout << "Result:\nn: " << n1 << endl;
		while (n1--)
			cout << s << "\t";
		cout << endl;
	}
}
