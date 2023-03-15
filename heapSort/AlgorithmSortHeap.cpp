#include <iostream>
#include "AlgorithmSortHeap.h"
#include "BinaryHeap.h"

AlgorithmSortHeap::AlgorithmSortHeap(int k) : SelectionAlgorithm(k) {
    this->k = k;
	cout << "AlgorithmSortHeap::AlgorithmSortHeap(int k)" << endl;
}

int AlgorithmSortHeap::select()
{
	BinaryHeap heap((2 * k) + 1); //heap has one left, one right, and one parent, which is max 2k+1
    int num = 0;
    int count = 0;
    while (cin >> num) {
        heap.insert(num);
    }

    for (int i = 0; i < k; i++) {
        heap.deleteMin();
    }
    int result = heap.getMin();
    return result;
}



