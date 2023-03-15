#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <iomanip>
#include <sstream>


//#include "decompression.h"

using namespace std;


template <typename Iterator, typename Compare>
void sort(Iterator first, Iterator last, Compare comp)
{
    if (first == last)
        return;

    for (Iterator i = first; i != last; ++i)
        for (Iterator j = i + 1; j != last; ++j)
            if (comp(*j, *i))
                iter_swap(i, j);
}

vector<int> RrotationVectorGenerator(string inputStr)
{
	vector<int> rotations(inputStr.length());   //create a vector in the size of th input string
    
	iota(rotations.begin(), rotations.end(), 0); // the iota function fills the vector with the numbers 0 to the length of the string https://en.cppreference.com/w/cpp/algorithm/iota 
    
    sort(rotations.begin(), rotations.end(),                                              
        [&inputStr](int i, int j) {return inputStr.substr(i) < inputStr.substr(j); });

    return rotations;
}

string sumLastCharacters(string input, vector<int> sortedLast) // 
{
    string bwt;
    
    for (int index = 0; index < sortedLast.size(); index++) {
		int key = sortedLast[index] - 1;  //find the index of the last character of the rotation
        if (key < 0)  
            key = key + input.length();  
        bwt += input[key];
    }
    return bwt;
}

void compression(string in, string out)
{
	ifstream input(in);
	ofstream output(out);

	string inputStr;
	string bwt;

	getline(input, inputStr, '\0'); //read the whole file into a string

	vector<int> sortedLast = RrotationVectorGenerator(inputStr); //generate the vector of sorted rotations

	bwt = sumLastCharacters(inputStr, sortedLast); //find the last character of the sorted rotations

	output << bwt; //write the bwt to the output file

	input.close();
	output.close();
}






void welcome(int argc, char* argv[]) 
{
    if (argc != 5) {
        cout << "Hmm... Something is wrong. Are you calling with the correct arguments?" << endl;
        cout << "Usage(c): hw.exe bwt c data.txt data.bwt" << endl;
        cout << "Usage(d): hw.exe bwt d data.lzw data2.txt" << endl;
    }

    string mode = argv[1];
    string operation = argv[2];
    string in = argv[3];
    string out = argv[4];
    if (mode == "bwt")
    {
        cout << "---- ---- ---- ---- ---- ---- ---- ----" << endl << "| Welcome to Onur Compression Services |" << endl << "|            BWT Selected              |" << endl << "---- ---- ---- ---- ---- ---- ---- ----" << endl;
        if (operation == "c")                                   //compress 
        {
            cout << "|            Compressing...            |" << endl;

            //check if inputfilename is a txt file      
            if (in.substr(in.length() - 4) == ".txt") // checking if the last four chars (length - 4) are equal to ".txt"
            {
                compression(in, out);   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                cout << "|          Done compressing!           |" << endl << "---- ---- ---- ---- ---- ---- ---- ----" << endl;        //very important output decoration cout, better than jawa awt
            }
            else
            {
                cout << "Your file is not a .txt file" << endl;                                                                         //error 
            }
        }                                                       //compression code ends


        else if (operation == "d")                              //decompress 
        {
            cout << "|            Decompressing...          |" << endl;
            
//			invert(in, out); ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            

            cout << "|          Done decompressing!         |" << endl << "---- ---- ---- ---- ---- ---- ---- ----" << endl;            //very important output decoration cout
        }

    }
}

int main(int argc, char* argv[])
{
    welcome(argc, argv);
    return 0;
}
