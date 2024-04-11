/**
 * CSCI 335 Project 2
 * Allison Lee
 * myAVLtree.cpp, containing the function void treeMedian (const std::vector<int> * instructions)
*/

#include "myAVLtree.hpp"

void treeInsert(AvlTree& small, AvlTree& large, int num){
    // If both heaps are empty or the number is less than or equal to the current median, insert it into the max heap
    if (small.isEmpty() || num >= small.findMax()) {
        large.insert(num);
    } else { // Otherwise, insert it into the min heap
        small.insert(num);
    }
    if (small.getSize() > large.getSize() + 1) {
        large.insert(small.findMax());
        small.remove(small.findMax());
    }

    if (large.getSize() > small.getSize()) {
        small.insert(large.findMin());
        large.remove(large.findMin());
    }
}

int treePopMedian(AvlTree& small, AvlTree& large){
    int med = small.findMax();
    small.remove(small.findMax());       // pop from small

    if (small.getSize() < large.getSize()) // check for size
    {
        // move smallest from Large into small and pop it from Large
        small.insert(large.findMin());
        large.remove(large.findMin());
    }
    
    return med;
}

void treeMedian(const std::vector<int> * instructions){
    if (instructions == nullptr){
        return;
    }

    std::vector<int> vec = *instructions;

    AvlTree small;
    AvlTree large;

    for (auto it = instructions->begin(); it != instructions->end(); ++it){
        if (*it == -1){
            std::cout << treePopMedian(small, large) << " ";
        }
        else{
            treeInsert(small, large, *it);
        }

        
    }
}