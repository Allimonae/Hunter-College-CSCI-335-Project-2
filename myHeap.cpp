/**
 * CSCI 335 Project 2
 * Allison Lee
 * myHeap.cpp, containing the function void heapMedian (const std::vector<int> * instructions)
*/

#include "myHeap.hpp"
#include <algorithm>

/**
 * @param:  a maxHeap small containing elements less than or equal to median
 * @param:  a minHeap large containing elements greater than median
 * @param:  an integer num to be inserted into nums
 * @post:   insert a new element num into two heaps (small and large) representing the lower and upper halves of the data stream, 
 *          while ensuring that the median of the data stream is maintained.
*/
void heapInsert(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large, int num){
    // If both heaps are empty or the number is less than or equal to the current median, insert it into the max heap
    if (small.empty() || num >= small.top()) {
        large.push(num);
    } else { // Otherwise, insert it into the min heap
        small.push(num);
    }
    // Balance the heaps
    heapBalance(small, large);
}
/**
 * @param:  a maxHeap small containing elements less than or equal to median
 * @param:  a minHeap large containing elements greater than median
 * @post: Balance the sizes of two heaps (small and large) such that the difference in size between them is at most 1. 
*/
void heapBalance(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large){
    // If the size difference between the heaps is greater than 1, balance them
    while (small.size() > large.size() + 1) {
        large.push(small.top());
        small.pop();
    }
    while (large.size() > small.size()) {
        small.push(large.top());
        large.pop();
    }
}

/**
 * @param:  a maxHeap small containing elements less than or equal to median
 * @param:  a minHeap large containing elements greater than median
 * @return: top element in small
 * @post:   remove and return the median element from the data stream, which is stored in the small heap. 
 *          Ensures that the heaps remain balanced after the removal of the median element.
*/
int heapPopMedian(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large){
    int med = small.top();
    small.pop();
    // Balance the heaps
    heapBalance(small, large);
    return med;
}

/**
 * @param:  a vector of instructions
 * @post:   processes a vector of instructions, where each element represents either an integer value or -1. 
 *          For each non-negative integer, it inserts it into either a max heap small or min heap large while maintaining the sorted order. 
 *          When encountering -1, it pops the median from the sortedVec and pushes it into another vector vec. 
 *          Finally, it prints the elements of vec to the standard output.
*/
void heapMedian(const std::vector<int> * instructions){
    std::vector<int> vec;
    
    if (instructions == nullptr){
        return;
    }

    std::priority_queue<int> small; // max heap to store values smaller than or equal to median
    std::priority_queue<int, std::vector<int>, std::greater<int>> large; // min heap to store values greater than median

    for(auto it = instructions->begin(); it != instructions->end(); ++it){
        if (*it == -1){
            vec.push_back(heapPopMedian(small, large));
        }
        else {
            heapInsert(small, large, *it);
        }
    }
    
    for (auto it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << " ";
    }
}

