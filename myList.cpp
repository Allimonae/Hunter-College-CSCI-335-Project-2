/**
 * CSCI 335 Project 2
 * Allison Lee
 * myList.cpp, containing the function void listMedian (const std::vector<int> * instructions)
*/

#include "myList.hpp"
#include <algorithm>

/**
 * @post: perform binary serach insertion into a sorted vector
 * @param: a vector of integers nums
 * @param: an integer num to be inserted into nums
*/
void listInsert(std::list<int>& nums, int num){
    auto it = nums.begin();
    while (it != nums.end() && *it < num) {
        ++it;
    }
    nums.insert(it, num);
}

/**
 * @post: pops median from vector nums of size n and returns it
 * @param: a vector of integers nums
 * @param: size of vector
 * @return: median of vector
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

