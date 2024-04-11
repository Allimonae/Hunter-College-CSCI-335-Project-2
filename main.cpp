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
    
    // std::vector<int> vec = {14667, 3074, 11294, 26952, 11167, 8956, 9292, 15789, 10697, 3350, 30176};
    // AvlTree small;
    // AvlTree large;

    // for (auto it = vec.begin(); it != vec.end(); ++it){
    //     treeInsert(small, large, *it);
    // }
    
    // std::cout << "small: "; 
    // small.print(); 
    // std::cout << std::endl;
    // std::cout << "large: "; 
    // large.print(); 
    // std::cout << std::endl;
    // std::cout << treePopMedian(small, large);

    auto beg = std::chrono::high_resolution_clock::now();
 
    treeMedian(instructions);
 
    
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - beg);
    std::cout << "\nElapsed Time: " << duration.count() << " microseconds";
    

    delete instructions;
}