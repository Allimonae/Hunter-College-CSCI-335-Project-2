/**
 * CSCI 335 Project 2
 * Allison Lee
 * myVector.cpp, containing the function void vectorMedian (const std::vector<int> * instructions)
*/

#include "myVector.hpp"

/**
 * @post: inserts a number and maintains sorted ascending order of vector
 * @param: a vector of integers nums
 * @param: an integer num to be inserted into nums
*/
void vectorInsert(std::vector<int>& nums, int num){
    bool inserted = false;
    // Traverse through nums, if there is an element greater than nums, 
    // for(auto it = nums.begin(); it != nums.end(); ++it){
    //     std::cout << "hey";
    //     if (*it > num){
            
    //         nums.insert(it, num);
    //         inserted = true;
    //         break;
    //     }
    // }

    if (!inserted){
        //std::cout << num << " ";
        nums.push_back(num);
        std::cout << nums.size();
    }
}

/**
 * @post: pops median and returns it
 * @param: a vector of integers nums
 * @return: median of vector
*/
int vectorMedian(std::vector<int>);

