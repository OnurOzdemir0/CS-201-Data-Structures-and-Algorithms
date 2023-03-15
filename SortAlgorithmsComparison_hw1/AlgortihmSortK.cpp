#include "AlgortihmSortK.h"

AlgorithmSortK::AlgorithmSortK(int k): SelectionAlgorithm(k) 
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

/*	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	cout << arr[k - 1]; */
	
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
