/**
 * CSCI 335 Project 2
 * Allison Lee
 * myHeap.hpp, containing the prototypes* of the functions in myHeap.cpp
*/

#ifndef MY_HEAP_CPP
#define MY_HEAP_CPP

#include <iostream>
#include <vector>
#include <queue>

/**
 * @post: inserts a number and maintains sorted ascending order of vector
 * @param: a vector of integers nums passed by reference
 * @param: an integer num to be inserted into nums
*/
void heapInsert(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large, int num);
void heapBalance(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large);
/**
 * @post: pops median and returns it
 * @param: a vector of integers nums
 * @return: median of vector
*/
int heapPopMedian(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large);

void heapMedian(const std::vector<int> * instructions);

#endif