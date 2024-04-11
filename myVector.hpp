/**
 * CSCI 335 Project 2
 * Allison Lee
 * myVector.hpp, containing the prototypes* of the functions in myVector.cpp
*/

#ifndef MY_VECTOR_CPP
#define MY_VECTOR_CPP

#include <iostream>
#include <vector>

/**
 * @post:   inserts a number into nums vector
 *          maintains sorted ascending order of vector
 * @param:  a vector of integers nums passed by reference
 * @param:  an integer num to be inserted into nums
*/
void insert(std::vector<int>& nums, int num);

/**
 * @post:   erases median from vector and returns it 
 * @param:  a vector of integers nums
 * @return: median of nums
*/
int popMedian(std::vector<int>& nums);

/**
 * @post:   follows the instructions and prints out medians in the order they're popped
 *          for each -1, removes the median from its container and print it out, followed by a space.
 * @param:  a formated vector of integers providing instructions
 *          any number other than -1 means insert number to ADT
 *          -1 means pop median from ADT
*/
void vectorMedian (const std::vector<int> * instructions);

#endif