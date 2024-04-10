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
void insert(std::vector<int>& nums, int num){
    auto it = std::lower_bound(nums.begin(), nums.end(), num);
    nums.insert(it, num);
}

/**
 * @post: pops median from vector nums of size n and returns it
 * @param: a vector of integers nums
 * @param: size of vector
 * @return: median of vector
*/
int popMedian(std::vector<int>& nums, int n){
    if(n % 2 == 1){
        int med = nums[n/2];
        nums.erase(nums.begin() + n/2);
        std::cout << "med" << med << std::endl;
        return med;
    }
    else{
        return nums[n/2 - 1];
    }
}

void vectorMedian(const std::vector<int> * instructions){
    if (instructions == nullptr){
        return;
    }

    int size = 0;
    std::vector<int> vec = *instructions;
    std::vector<int> sortedVec;
    
    for(auto it = vec.begin(); it != vec.end(); ++it){
        if (*it == -1){
            std::cout << popMedian(sortedVec, size) << std::endl;
            size--;
        }
        else{
            insert(sortedVec, *it);
            size++;
        }
    }

    for(auto it = sortedVec.begin(); it != sortedVec.end(); ++it){
        std::cout << *it << " ";
    }
}

