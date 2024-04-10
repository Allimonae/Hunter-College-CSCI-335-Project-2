/**
 * CSCI 335 Project 2
 * Allison Lee
 * myList.hpp, containing the prototypes* of the functions in myList.cpp
*/

#ifndef MY_LIST_CPP
#define MY_LIST_CPP

#include <iostream>
#include <vector>
#include <list>

/**
 * @post: inserts a number and maintains sorted ascending order of vector
 * @param: a vector of integers nums passed by reference
 * @param: an integer num to be inserted into nums
*/
void listInsert(std::list<int>& nums, int num);
/**
 * @post: pops median and returns it
 * @param: a vector of integers nums
 * @return: median of vector
*/
int listPopMedian(std::list<int>& instructions);

void listMedian(const std::vector<int> * instructions);

#endif