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
 * @param:  a list of integers nums passed by reference
 * @param:  an integer num to be inserted into nums
 * @post:   implements linear search to insert a number into nums vector
 *          maintains sorted ascending order of vector
*/
void listInsert(std::list<int>& nums, int num);

/**
 * @param:  a list of integers nums
 * @return: if odd return middle number
 *          if even return lesser of two middle numbers
 * @post:   find and remove the median element from a doubly linked list using the slow and fast pointer technique.
*/
int listPopMedian(std::list<int>& instructions);

/**
 * @param:  a vector of instructions
 * @post:   processes a vector of instructions, where each element represents either an integer value or -1. 
 *          For each non-negative integer, it inserts it into a separate list sortedList while maintaining the sorted order. 
 *          When encountering -1, it pops the median from the sortedList and pushes it into a vector vec. 
 *          Finally, it prints the elements of vec to the standard output.
*/
void listMedian(const std::vector<int> * instructions);

#endif