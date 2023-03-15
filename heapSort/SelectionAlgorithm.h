#ifndef SELECT_ALGORITHM
#define SELECT_ALGORITHM

#include <iostream>

using namespace std;

class SelectionAlgorithm {
protected:
    int k{};
public:
    SelectionAlgorithm(int k);
    virtual int select() { return 0; };
};


#endif // SELECT_ALGORITHM

// Abstract class for algorithms