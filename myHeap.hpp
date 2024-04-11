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
 * @param:  a maxHeap small containing elements less than or equal to median
 * @param:  a minHeap large containing elements greater than median
 * @param:  an integer num to be inserted into nums
 * @post:   insert a new element num into two heaps (small and large) representing the lower and upper halves of the data stream, 
 *          while ensuring that the median of the data stream is maintained.
*/
void heapInsert(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large, int num);

/**
 * @param:  a maxHeap small containing elements less than or equal to median
 * @param:  a minHeap large containing elements greater than median
 * @post: Balance the sizes of two heaps (small and large) such that the difference in size between them is at most 1. 
*/
void heapBalance(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large);

/**
 * @param:  a maxHeap small containing elements less than or equal to median
 * @param:  a minHeap large containing elements greater than median
 * @return: top element in small
 * @post:   remove and return the median element from the data stream, which is stored in the small heap. 
 *          Ensures that the heaps remain balanced after the removal of the median element.
*/
int heapPopMedian(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large);

/**
 * @param:  a vector of instructions
 * @post:   processes a vector of instructions, where each element represents either an integer value or -1. 
 *          For each non-negative integer, it inserts it into either a max heap small or min heap large while maintaining the sorted order. 
 *          When encountering -1, it pops the median from the small heap and pushes it into another vector vec. 
 *          Finally, it prints the elements of vec to the standard output.
*/
void heapMedian(const std::vector<int> * instructions);

#endif