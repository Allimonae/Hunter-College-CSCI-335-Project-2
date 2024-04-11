/**
 * CSCI 335 Project 2
 * Allison Lee
 * myVector.cpp, containing the function void vectorMedian (const std::vector<int> * instructions)
*/

#include "myVector.hpp"
#include <algorithm>

/**
 * @post:   implements binary search to insert a number into nums vector
 *          maintains sorted ascending order of vector
 * @param:  a vector of integers nums passed by reference
 * @param:  an integer num to be inserted into nums
*/
void vectorInsert(std::vector<int>& nums, int num){
    // binary search through sorted vector
    auto it = std::lower_bound(nums.begin(), nums.end(), num);
    nums.insert(it, num);
}

/**
 * @post:   erases median from vector and returns it 
 * @param:  a vector of integers nums
 * @return: if odd retrun middle number
 *          if even return lesser of two middle numbers
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
 * @post:   creates a vector and follows the instructions, inserting numbers and popping the median 
 *          for each -1, removes the median from its container and print it out, followed by a space.
 * @param:  a formated vector of integers providing instructions
 *          any number other than -1 means insert number to ADT
 *          -1 means pop median from ADT
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

