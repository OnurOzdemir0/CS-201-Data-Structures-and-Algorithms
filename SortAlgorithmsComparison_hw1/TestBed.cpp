#include "TestBed.h"
#include "AlgortihmSortAll.h"
#include "AlgortihmSortK.h"

#include <ctime>
    
TestBed::TestBed(){}

TestBed::~TestBed() {
    delete algorithm;
}

void TestBed::execute() 
{
    // Time stamp before the computations
    clock_t start = clock();
    cout << "Operation Started" << endl;
    int a = algorithm->select();

    cout << "Kth element after sort: " << a << endl;

    // Time stamp after the computations
    clock_t end = clock();
    double cpu_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;

    cout << "Time:" << cpu_time << endl;
}

void TestBed::setAlgorithm(int type, int k) 
{
    if(type == 1) {
        algorithm = new AlgorithmSortAll(k);
        cout << "Algorithm type: 1" << endl;
    }

    else if (type == 2) {
        algorithm = new AlgorithmSortK(k);
        cout << "Algorithm type: 2" << endl;       
    }

    else {
        cout << "Error: invalid algorithm type!" << endl;
    }
}

