#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

unsigned long long DICTIONARY_SIZE = 65536;
unsigned long long MAX_CODE = 65535;

struct DictionaryEntry {
    string key;
    string value;
};


vector<DictionaryEntry> dictionary;
int nextValue = 256;

unsigned long long myHash(string s) {
    // simple hash function that sums the ascii values of the characters in the string
    unsigned long long h = 0;
    for (char c : s) {
        h = h + c;
    }
    return h % DICTIONARY_SIZE;
}

int findInDictionary(string key) {
    unsigned long long h = myHash(key);
	cout << "finding " << key << endl;
    for (unsigned long long i = 0; i < 20000; i++) {
		cout << "checking " << i << endl;
        if (dictionary[i].key == key) {
            return i;
        }
    }
	cout << "found nothing" << endl;
    return -1;
}

void addToDictionary(string key, string value) {
	cout << "girdi" << key << value << endl;
    dictionary.push_back(DictionaryEntry{ key, value });
	cout << "added " << key << " " << value << endl;
}

void compress(string inputFileName, string outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    if (!inputFile || !outputFile) {
        cout << "Error opening input or output file" << endl;
        return;
    }
    // load ascii characters
    for (int i = 0; i < 256; i++) {
        DictionaryEntry entry;
        entry.key = (char)i;
        entry.value = (char)i;
        dictionary.push_back(entry);
    }
    //compress
    string inputString = "", currentString = "";
	char c;
    inputFile >> noskipws;
    while (inputFile.get(c)) {
        inputString += c;
    }
    for (char c : inputString) {
        currentString += c;
        int currentValue = findInDictionary(currentString);
        if (currentValue == -1) {
            outputFile << findInDictionary(currentString.substr(0, currentString.size() - 1)) << ' ';
            addToDictionary(currentString, to_string(nextValue++));
            currentString = c;
        }
    }
    outputFile << findInDictionary(currentString);
    inputFile.close();
    outputFile.close();
}

void decompress(string inputFileName, string outputFileName) {
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);
    if (!inputFile || !outputFile) {
        cout << "Error opening input or output file" << endl;
        return;
    }
    // load ASCII characters
    for (int i = 0; i < 256; i++) {
        DictionaryEntry entry;
        entry.key = to_string(i);
        entry.value = (char)i;
        dictionary.push_back(entry);
    }
    // Decompress
    int previousKey;
    inputFile >> previousKey;
    string previousString = dictionary[previousKey].value;
    outputFile << previousString;
    int currentKey;
    while (inputFile >> currentKey) {
        string currentString;
        if (currentKey >= dictionary.size() || currentKey < 0) {
            currentString = previousString + previousString[0];
        }
        else {
            currentString = dictionary[currentKey].value;
        }
        outputFile << currentString;
        addToDictionary(previousString + currentString[0], to_string(nextValue++));
        previousString = currentString;
    }
    inputFile.close();
    outputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cout << "Hmm... Something is wrong. Are you calling with the correct arguments?" << endl;
        cout << "Usage(c): hw5.exe lzw c data.txt data.lzw" << endl;
        cout << "Usage(d): hw5.exe lzw d data.lzw data2.txt" << endl;
        return 0;
    }

    string mode = argv[1];
    string operation = argv[2];
    string inputFileName = argv[3];
    string outputFileName = argv[4];

    if (mode != "lzw") {
        cout << "Usage: hw5.exe lzw c data.txt data.lzw" << endl;
        cout << "Usage: hw5.exe lzw d data.lzw data2.txt" << endl;
        return 0;
    }

    if (operation == "c") {
		compress(inputFileName, outputFileName);
    }
    else if (operation == "d") {
		decompress(inputFileName, outputFileName);
    }
    else {
        cout << "Invalid operation" << endl;
    }
    return 0;
}


