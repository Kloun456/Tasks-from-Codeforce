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



