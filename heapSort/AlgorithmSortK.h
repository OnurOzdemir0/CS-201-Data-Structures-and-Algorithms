#ifndef ALGORITHM_SORT_K
#define ALGORITHM_SORT_K
#include "SelectionAlgorithm.h"

#include <iostream>

using namespace std;

class AlgorithmSortK : public SelectionAlgorithm  //derived class
{
private:
    void kSort(int arr[], int n);
    void printArray(int arr[], int n);
protected:
    int n;
    int* ptr;
public:
    AlgorithmSortK(int);
    int select();
};

#endif // ALGORITHM_SORT_K