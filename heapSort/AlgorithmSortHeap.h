//This time I used a whole cpp file to create the algorithm, unlike the other ones.
//So I expect that this file will not be as long as the others.
// We have a select() that returns int.
// We have a AlgorithmSortHeap(in k : int) returns void just like the other ones.
#include "SelectionAlgorithm.h"

class AlgorithmSortHeap : public SelectionAlgorithm {
public:
	AlgorithmSortHeap(int k);
	int select() override;
};


