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
 * @post: inserts a number and maintains sorted ascending order of vector
 * @param: a vector of integers nums passed by reference
 * @param: an integer num to be inserted into nums
*/
void insert(std::vector<int>& nums, int num);
/**
 * @post: pops median and returns it
 * @param: a vector of integers nums
 * @return: median of vector
*/
int popMedian(std::vector<int>& nums, int n);

void vectorMedian (const std::vector<int> * instructions);

#endif