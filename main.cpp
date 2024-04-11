/**
 * CSCI 335 Project 2
 * Allison Lee
 * main.cpp will is a testing function that will convert an input file into the format shown in testinput_in_integer_format.txt
*/

#include "myVector.hpp"
#include "myList.hpp"
#include "myHeap.hpp"
#include "myAVLtree.hpp"
#include <fstream>
#include <chrono>

int main(){
    // Reads from a file and populates a dynamic vector based on the instructions provided in the file
    std::vector<int> *instructions = new std::vector<int>;

    std::ifstream file("input1.txt");
    if (file.fail()){
        std::cerr << "File cannot be opened for reading" << std::endl;
        exit(1);
    }
    std::string line;
    std::string instr, token;

    // Each "insert" operation adds the provided value to the vector, and each "pop" operation adds a (-1) to the vector.
    while(file >> instr >> token){
        if (instr == "insert"){
            instructions->push_back(stoi(token));
        }
        else if (instr == "pop"){
            instructions->push_back(-1);
        }
    }

    auto beg = std::chrono::high_resolution_clock::now();
 
    vectorMedian(instructions);
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
    std::cout << "\nElapsed Time: " << duration.count() << " microseconds";

    delete instructions;
}