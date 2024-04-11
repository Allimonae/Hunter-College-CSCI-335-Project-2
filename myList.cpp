/**
 * CSCI 335 Project 2
 * Allison Lee
 * myList.cpp, containing the function void listMedian (const std::vector<int> * instructions)
*/

#include "myList.hpp"
#include <algorithm>

/**
 * @post:   linear search through linked list
 * @param:  a linked list of integers nums passed by reference
 * @param:  an integer num to be inserted into nums
*/
void listInsert(std::list<int>& nums, int num){
    auto it = nums.begin();
    while (it != nums.end() && *it < num) {
        ++it;
    }
    nums.insert(it, num);
}

/**
 * @post:   removes median from list and returns it 
 * @param:  a list of integers nums
 * @return: if odd retrun middle number
 *          if even return lesser of two middle numbers
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
 * @post:   creates a linked list and follows the instructions, inserting numbers and popping the median 
 *          for each -1, removes the median from its container and print it out, followed by a space.
 * @param:  a formated vector of integers providing instructions
 *          any number other than -1 means insert number to ADT
 *          -1 means pop median from ADT
*/
void listMedian(const std::vector<int> * instructions){
    if (instructions == nullptr){
        return;
    }

    std::vector<int> vec = *instructions;
    std::list<int> sortedList;
    
    for(auto it = vec.begin(); it != vec.end(); ++it){
        if (*it == -1){
            std::cout << listPopMedian(sortedList) << " ";
        }
        else{
            listInsert(sortedList, *it);
        }
    }
}

