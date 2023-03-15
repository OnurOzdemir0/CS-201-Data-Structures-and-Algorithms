#ifndef ALGORITHM_SORT_ALL
#define ALGORITHM_SORT_ALL
#include "SelectionAlgorithm.h"

#include <iostream>

using namespace std;

class AlgorithmSortAll: public SelectionAlgorithm {
    private:
        void insertionSort(int arr[], int n);
        void printArray(int arr[], int n);
    protected: 
        int n;
        int *ptr;
    public:
        AlgorithmSortAll(int k);
        int select() override;
};

#endif // ALGORITHM_SORT_ALL

