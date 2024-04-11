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
 * @param:  a vector of integers nums passed by reference
 * @param:  an integer num to be inserted into nums
 * @post:   implements binary search to insert a number into nums vector
 *          maintains sorted ascending order of vector
*/
void vectorInsert(std::vector<int>& nums, int num);

/**
 * @param:  a vector of integers nums
 * @return: if odd return middle number
 *          if even return lesser of two middle numbers
 * @post:   erases median from vector and returns it 
*/
int vectorPopMedian(std::vector<int>& nums);

/**
 * @param:  a vector of instructions
 * @post:   processes a vector of instructions, where each element represents either an integer value or -1. 
 *          For each non-negative integer, it inserts it into a separate vector sortedVec while maintaining the sorted order. 
 *          When encountering -1, it pops the median from the sortedVec and pushes it into another vector vec. 
 *          Finally, it prints the elements of vec to the standard output.
*/
void vectorMedian (const std::vector<int> * instructions);

#endif