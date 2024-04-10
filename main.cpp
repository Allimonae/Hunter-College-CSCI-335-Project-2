/**
 * CSCI 335 Project 2
 * Allison Lee
 * main.cpp will be is a testing function that will convert an input file into the format shown in testinput_in_integer_format.txt
*/

#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include <fstream>

int main(){
    std::vector<int> *instructions = new std::vector<int>;

    std::ifstream file("testinput.txt");
    if (file.fail()){
        std::cerr << "File cannot be opened for reading" << std::endl;
        exit(1);
    }
    std::string line;
    std::string instr, token;
    while(file >> instr >> token){
        if (instr == "insert"){
            instructions->push_back(stoi(token));
        }
        else if (instr == "pop"){
            instructions->push_back(-1);
        }
    }

    heapMedian(instructions);
    std::cout << "\n\n";
    vectorMedian(instructions);

    delete instructions;
}