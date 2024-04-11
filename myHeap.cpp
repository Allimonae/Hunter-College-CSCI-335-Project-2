/**
 * CSCI 335 Project 2
 * Allison Lee
 * myHeap.cpp, containing the function void heapMedian (const std::vector<int> * instructions)
*/

#include "myHeap.hpp"
#include <algorithm>

/**
 * @post: perform binary serach insertion into a sorted vector
 * @param: a vector of integers nums
 * @param: an integer num to be inserted into nums
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
 * @post: pops median from vector nums of size n and returns it
 * @param: a vector of integers nums
 * @param: size of vector
 * @return: median of vector
*/
//******n is simply size of nums, fix
int heapPopMedian(std::priority_queue<int>& small, std::priority_queue<int, std::vector<int>, std::greater<int>>& large){
    int med = small.top();
    small.pop();
    // Balance the heaps
    heapBalance(small, large);
    return med;
}

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

