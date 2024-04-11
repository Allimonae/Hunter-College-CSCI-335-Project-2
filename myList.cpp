/**
 * CSCI 335 Project 2
 * Allison Lee
 * myList.cpp, containing the function void listMedian (const std::vector<int> * instructions)
*/

#include "myList.hpp"
#include <algorithm>

/**
 * @param:  a list of integers nums passed by reference
 * @param:  an integer num to be inserted into nums
 * @post:   implements linear search to insert a number into nums vector
 *          maintains sorted ascending order of vector
*/
void listInsert(std::list<int>& nums, int num){
    auto it = nums.begin();
    while (it != nums.end() && *it < num) {
        ++it;
    }
    nums.insert(it, num);
}

/**
 * @param:  a list of integers nums
 * @return: if odd return middle number
 *          if even return lesser of two middle numbers
 * @post:   find and remove the median element from a doubly linked list using the slow and fast pointer technique.
*/
int listPopMedian(std::list<int>& nums){
    auto slow = nums.begin();
    auto fast = nums.begin();

    while (fast != nums.end() && std::next(fast) != nums.end() && std::next(std::next(fast)) != nums.end()) {
        ++slow;                 // Move slow pointer one step
        std::advance(fast, 2);  // Move fast pointer two steps
    }

    int med = *slow;
    nums.erase(slow);
    return med;
}

/**
 * @param:  a vector of instructions
 * @post:   processes a vector of instructions, where each element represents either an integer value or -1. 
 *          For each non-negative integer, it inserts it into a separate list sortedList while maintaining the sorted order. 
 *          When encountering -1, it pops the median from the sortedList and pushes it into a vector vec. 
 *          Finally, it prints the elements of vec to the standard output.
*/
void listMedian(const std::vector<int> * instructions){
    std::vector<int> vec;

    if (instructions == nullptr){
        return;
    }

    std::list<int> sortedList;
    
    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if (*it == -1){
            vec.push_back(listPopMedian(sortedList));
        }
        else {
            listInsert(sortedList, *it);
        }
    }

     for (auto it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << " ";
    }
}

