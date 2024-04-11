/**
 * CSCI 335 Project 2
 * Allison Lee
 * myVector.cpp, containing the function void vectorMedian (const std::vector<int> * instructions)
*/

#include "myVector.hpp"
#include <algorithm>

/**
 * @param:  a vector of integers nums passed by reference
 * @param:  an integer num to be inserted into nums
 * @post:   implements binary search to insert a number into nums vector
 *          maintains sorted ascending order of vector
*/
void vectorInsert(std::vector<int>& nums, int num){
    // binary search through sorted vector
    auto it = std::lower_bound(nums.begin(), nums.end(), num);
    nums.insert(it, num);
}

/**
 * @param:  a vector of integers nums
 * @return: if odd return middle number
 *          if even return lesser of two middle numbers
 * @post:   erases median from vector and returns it 
*/
int vectorPopMedian(std::vector<int>& nums){
    if(nums.size() % 2 == 1){
        int med = nums[nums.size()/2];
        nums.erase(nums.begin() + nums.size()/2);
        return med;
    }
    else{
        int med = nums[nums.size()/2 - 1];
        nums.erase(nums.begin() + nums.size()/2 - 1);
        return med;
    }
}

/**
 * @param:  a vector of instructions
 * @post:   processes a vector of instructions, where each element represents either an integer value or -1. 
 *          For each non-negative integer, it inserts it into a separate vector sortedVec while maintaining the sorted order. 
 *          When encountering -1, it pops the median from the sortedVec and pushes it into another vector vec. 
 *          Finally, it prints the elements of vec to the standard output.
*/
void vectorMedian(const std::vector<int> * instructions){
    std::vector<int> vec;

    if (instructions == nullptr){
        return;
    }

    std::vector<int> sortedVec;
    
    for (auto it = instructions->begin(); it != instructions->end(); ++it){
        if (*it == -1){
            vec.push_back(vectorPopMedian(sortedVec));
        }
        else{
            vectorInsert(sortedVec, *it);
        }
    }

    for (auto it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << " ";
    }
}

