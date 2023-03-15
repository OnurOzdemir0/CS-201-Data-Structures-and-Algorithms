#ifndef TESTBED
#define TESTBED

#include <iostream>
#include "SelectionAlgorithm.h"

using namespace std;

class TestBed{
    private:
        SelectionAlgorithm *algorithm;
    public:
        TestBed();
        ~TestBed();
        void setAlgorithm(int type, int k);
        void execute();
};

#endif // TESTBED

