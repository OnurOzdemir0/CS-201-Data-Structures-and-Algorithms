//===============================================================================================
// Name        : testInputGenerator.cpp
// Author      : Emre Sefer & Hasan Sozer & Gunes Buyukgonenc
// Version     : 5.0
// Update	   : use of steady_clock and default_random_engine instead of srand for randomization
// Copyright   : (c) 2022 Ozyegin University
// Description : Generates test input data for Homeworks 1 and 4 that are assigned
//               in the context of the course CS201, Data Structures
//               and Algorithms.
// Parameters:"
//
//		Algorithm type     : must be 1, 2, 3 or 4
//		Selection index (k): an integer between 0 and N
//		Input size (n)     : an integer greater than 0
//		Input range        : an integer greater than 0
//===============================================================================================

#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include <sstream>

using namespace std;

void printUsage() {
	cout << endl << "Parameters:" << endl;
	cout << "Algorithm type     : must be 1, 2, 3 or 4" << endl;
	cout << "Selection index (k): an integer between 0 and N" << endl;
	cout << "Input size (n)     : an integer greater than 0" << endl;
	cout << "Input range        : an integer greater than 0" << endl;
}

int testInputs(int algorithmType, int selectionIndex, int inputSize, int inputRange) {

	if (algorithmType < 1 || algorithmType > 4 || selectionIndex < 0 || selectionIndex >= inputSize || inputRange < 1) {
		cout << endl << "ERROR: Wrong value(s) of parameters!" << endl;
		return -1;
	}

	return 0;
}

string generateFileName(int type, int k, int n) {
	auto fileName = ostringstream();
	fileName << "test" << type << "_" << k << "_" << n << ".txt";
	
	return fileName.str();
}

int main() {

	int algorithmType, selectionIndex, inputSize, inputRange;

	cout << "Enter the type: ";
	cin >> algorithmType;
	cout << "Enter the selectionIndex (k): ";
	cin >> selectionIndex;
	cout << "Enter the inputSize (n): ";
	cin >> inputSize;
	cout << "Enter the inputRange: ";
	cin >> inputRange;

	if (testInputs(algorithmType, selectionIndex, inputSize, inputRange) < 0) {
		printUsage();
		return -1;
	}

	auto seed = chrono::steady_clock::now().time_since_epoch().count();
	auto randomEngine = default_random_engine(seed);

	auto fileName = generateFileName(algorithmType, selectionIndex, inputSize);
	auto txtFile = ofstream(fileName);

	txtFile << algorithmType << endl;
	txtFile << selectionIndex << endl;
	txtFile << inputSize << endl;

	for (int i = 0; i < inputSize; ++i)
		txtFile << randomEngine() % inputRange << endl;

	txtFile.close();

	return 0;
}