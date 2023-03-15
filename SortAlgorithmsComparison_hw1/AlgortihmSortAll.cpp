#include "AlgortihmSortAll.h"

AlgorithmSortAll::AlgorithmSortAll(int k):SelectionAlgorithm(k)
{
	int temp;
	this->ptr;
	cin >> n;
	this->ptr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ptr[i] = temp;
	}
}

int AlgorithmSortAll::select()
{
	insertionSort(this->ptr, this->n);
	int kth = this->ptr[k - 1];
	delete[] this->ptr;
	this->ptr = 0;
	return kth;
}

void AlgorithmSortAll::insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}





