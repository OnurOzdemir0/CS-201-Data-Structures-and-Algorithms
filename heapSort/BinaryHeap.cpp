#include <iostream>
#include "BinaryHeap.h"
#include <vector>


using namespace std;

BinaryHeap::BinaryHeap(int capacity) {
	this->heap = new int[capacity];
	this->size = 0;
	this->capacity = capacity;
}

BinaryHeap::~BinaryHeap() {
	// delete the nodes in the heap using a while loop
	int current = 0;
	while (current < this->size) {
		
		if (current * 2 + 1 < this->size) {
			
			if (this->heap[current * 2 + 1] != NULL) {
				this->heap[current * 2 + 1] = NULL;
			}
		}
		if (current * 2 + 2 < this->size && current * 2 + 2 != current * 2 + 1) {
			
			if (this->heap[current * 2 + 2] != NULL) {
				this->heap[current * 2 + 2] = NULL;
			}
		}
		current = current * 2 + 1; 
		if (current < this->size) {
			if (current * 2 + 2 < this->size && current * 2 + 2 != current * 2 + 1) {
				current = current * 2 + 2;
			}
		}
	}
	delete[] this->heap;
}


void BinaryHeap::insert(int value) {
    if (size < capacity) {
        heap[size] = value;
        percolateUp(size);
        size++;
    }
}

int BinaryHeap::deleteMin() {
    if (size < 1) {
        return -1;
    }
    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;
    percolateDown(0);
    return min;
}

int BinaryHeap::getMin() {
    if (size < 1) {
        return -1; 
    }
    return heap[0];
}

void BinaryHeap::percolateDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int minIndex = index;
    if (leftChild < size && heap[leftChild] < heap[minIndex]) {
        minIndex = leftChild;
    }
    if (rightChild < size && heap[rightChild] < heap[minIndex]) {
        minIndex = rightChild;
    }
    if (minIndex != index) {
        swap(index, minIndex);
        percolateDown(minIndex);
    }
}

void BinaryHeap::percolateUp(int index) {
    int parent = (index - 1) / 2;
    if (parent >= 0 && heap[parent] > heap[index]) {
        swap(parent, index);
        percolateUp(parent);
    }
}

void BinaryHeap::swap(int index1, int index2) {
    int temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;
}


