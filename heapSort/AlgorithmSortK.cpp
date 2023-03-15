#include "AlgorithmSortK.h"

AlgorithmSortK::AlgorithmSortK(int k) : SelectionAlgorithm(k)
{
	// same code as AlgorithmSortAll
	int temp;
	this->ptr;
	cin >> n;
	this->ptr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ptr[i] = temp;
	}
}

int AlgorithmSortK::select()
{
	// same code as AlgorithmSortAll
	kSort(this->ptr, this->n);
	int kth = this->ptr[k - 1];
	delete[] this->ptr;
	this->ptr = 0;
	return kth;
}

void AlgorithmSortK::kSort(int arr[], int n)
{
	int x = 0;
	int key, j;
	for (int i = 1; i < n; i++)
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
