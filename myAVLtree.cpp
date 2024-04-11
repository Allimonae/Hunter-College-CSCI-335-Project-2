/**
 * CSCI 335 Project 2
 * Allison Lee
 * myAVLtree.cpp, containing the function void treeMedian (const std::vector<int> * instructions)
*/

#include "myAVLtree.hpp"

/**
 * @param:  a avl tree small containing elements less than or equal to median
 * @param:  a avl tree large containing elements greater than median
 * @param:  an integer num to be inserted into nums
 * @post:   insert a new element num into two trees (small and large) representing the lower and upper halves of the data stream, 
 *          while ensuring that the median of the data stream is maintained.
*/
void treeInsert(AvlTree& small, AvlTree& large, int num){
    // If both heaps are empty or the number is less than or equal to the current median, insert it into the max heap
    if (small.isEmpty() || num >= small.findMax()) {
        large.insert(num);
    } else { // Otherwise, insert it into the min heap
        small.insert(num);
    }

    // Balance the sizes of two trees (small and large) such that the difference in size between them is at most 1. 
    if (small.getSize() > large.getSize() + 1) {
        large.insert(small.findMax());
        small.remove(small.findMax());
    }

    if (large.getSize() > small.getSize()) {
        small.insert(large.findMin());
        large.remove(large.findMin());
    }
}

/**
 * @param:  a avl tree small containing elements less than or equal to median
 * @param:  a avl tree large containing elements greater than median
 * @return: max element in small
 * @post:   remove and return the median element from the data stream, which is stored in the small tree. 
 *          Ensures that the trees remain balanced after the removal of the median element.
*/
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

/**
 * @param:  a vector of instructions
 * @post:   processes a vector of instructions, where each element represents either an integer value or -1. 
 *          For each non-negative integer, it inserts it into either a tree small or tree large while maintaining the sorted order. 
 *          When encountering -1, it pops the median from the small tree and pushes it into another vector vec. 
 *          Finally, it prints the elements of vec to the standard output.
*/
void treeMedian(const std::vector<int> * instructions){
    std::vector<int> vec;

    if (instructions == nullptr){
        return;
    }

    AvlTree small; // AVL tree to store values smaller than or equal to median
    AvlTree large; // AVL tree to store values greater than median

    for (auto it = instructions->begin(); it != instructions->end(); ++it){
        if (*it == -1){
            vec.push_back(treePopMedian(small, large));
        }
        else {
            treeInsert(small, large, *it);
        }
    }
    
    for (auto it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << " ";
    }
}