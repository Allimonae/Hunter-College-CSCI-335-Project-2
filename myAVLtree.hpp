/**
 * CSCI 335 Project 2
 * Allison Lee
 * myAVLtree.hpp, containing your implementation of an AVL tree data structure
*/

#ifndef MY_AVLTREE_CPP
#define MY_AVLTREE_CPP

#include <iostream>
#include <algorithm>
#include <vector>

class AvlTree{
public:
    // Default constructor
    AvlTree() : root{nullptr}
    {
    }

    // Move constructor
    AvlTree(AvlTree &&rhs) : root{rhs.root}
    {
        rhs.root = nullptr;
    }

    // Destructor
    ~AvlTree()
    {
        makeEmpty();
    }

    /**
     * Find the smallest item in the tree.
     */
    const int &findMin() const
    {
        return findMin(root)->element;
    }

    /**
     * Find the largest item in the tree.
     */
    const int &findMax() const
    {
        return findMax(root)->element;
    }

    /**
     * Test if the tree is logically empty.
     * Return true if empty, false otherwise.
    */
    bool isEmpty() const
    {
        return root == nullptr;
    }

    /**
     * Make the tree logically empty.
     */
    void makeEmpty()
    {
        makeEmpty(root);
    }

    /**
     * Insert x into the tree;
     */
    void insert(const int &x)
    {
        insert(x, root);
    }

    /**
     * Insert x into the tree;
     */
    void insert(int &&x)
    {
        insert(std::move(x), root);
    }

    /**
     * Remove x from the tree. Nothing is done if x is not found.
     */
    void remove(const int &x)
    {
        remove(x, root);
    }

    /*
    Returns size of tree
    */
    int getSize() const
    {
        return size;
    }

    /**
     * print every element inorder
    */
    void print(){
        inorder(root);
    }

private:
    struct AvlNode
    {
        int element;
        AvlNode *left;
        AvlNode *right;
        int height;
        int count; // MODIFICATION FOR DUPLICATES

        AvlNode(const int &ele, AvlNode *lt, AvlNode *rt, int h = 0, int c = 1)
            : element{ele}, left{lt}, right{rt}, height{h}, count{c} {}
    };

    int size = 0; // keep count of inserts and removes
    AvlNode *root;

    /*
    MODIFICATION/Helper function: Recursively adds up the count of each node
    */
    // int size(AvlNode *&t)
    // {
    //   if (t == nullptr)
    //     return 0;
    //   return t->count + size(t->left) + size(t->right);
    // }

    /**
     * internal method for print
     * Traverses the tree inorder
    */
    void inorder(AvlNode* root) {
        if (root != nullptr) {
            inorder(root->left);
            std::cout << root->element << " ";
            inorder(root->right);
        }
    }
    /**
     * Internal method to insert into a subtree.
     * x is the item to insert.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */

    void insert(const int &x, AvlNode *&t)
    {
        if (t == nullptr)
        {
        t = new AvlNode{x, nullptr, nullptr};
        size++; // Increment size of tree
        }

        else if (x < t->element)
        insert(x, t->left);
        else if (t->element < x)
        insert(x, t->right);

        else // MODIFICATION: If x is equal to the current node's element
        {
        t->count++; // Increment the count for duplicates
        size++;     // Increment size of tree
        }

        balance(t);
    }

    /**
     * Internal method to remove from a subtree.
     * x is the item to remove.
     * t is the node that roots the subtree.
     * Set the new root of the subtree.
     */
    void remove(const int &x, AvlNode *&t)
    {
        if (t == nullptr)
        return; // Item not found; do nothing
        if (x < t->element)
        remove(x, t->left);
        else if (t->element < x)
        remove(x, t->right);
        else if (t->count > 1) // MODIFICATION:  If there are multiple occurrences of x
        {
        t->count--; // Decrement the count for duplicates
        size--;     // Increment size of tree
        }
        else if (t->left != nullptr && t->right != nullptr) // Two children
        {
        t->element = findMin(t->right)->element;
        remove(t->element, t->right);
        }
        else
        {
        AvlNode *oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
        size--; // Increment size of tree
        }

        balance(t);
    }

    static const int ALLOWED_IMBALANCE = 1;

    // Assume t is balanced or within one of being balanced
    void balance(AvlNode *&t)
    {
        if (t == nullptr)
        return;

        if (height(t->left) - height(t->right) > ALLOWED_IMBALANCE)
        if (height(t->left->left) >= height(t->left->right))
            rotateWithLeftChild(t);
        else
            doubleWithLeftChild(t);
        else if (height(t->right) - height(t->left) > ALLOWED_IMBALANCE){
            if (height(t->right->right) >= height(t->right->left)){
                rotateWithRightChild(t);
            }
            else {
                doubleWithRightChild(t);
            }
            t->height = max(height(t->left), height(t->right)) + 1;
        }
    }

    /**
     * Internal method to find the smallest item in a subtree t.
     * Return node containing the smallest item.
     */
    AvlNode *findMin(AvlNode *t) const
    {
        if (t == nullptr)
        return nullptr;
        if (t->left == nullptr)
        return t;
        return findMin(t->left);
    }

    /**
     * Internal method to find the largest item in a subtree t.
     * Return node containing the largest item.
     */
    AvlNode *findMax(AvlNode *t) const
    {
        if (t != nullptr)
        while (t->right != nullptr)
            t = t->right;
        return t;
    }

    /**
     * Internal method to test if an item is in a subtree.
     * x is item to search for.
     * t is the node that roots the tree.
     */
    bool contains(const int &x, AvlNode *t) const
    {
        if (t == nullptr)
        return false;
        else if (x < t->element)
        return contains(x, t->left);
        else if (t->element < x)
        return contains(x, t->right);
        else
        return true; // Match
    }
    /****** NONRECURSIVE VERSION*************************
         bool contains( const Comparable & x, AvlNode *t ) const
        {
            while( t != nullptr )
                if( x < t->element )
                    t = t->left;
                else if( t->element < x )
                    t = t->right;
                else
                    return true;    // Match

            return false;   // No match
        }
    *****************************************************/

    /**
     * Internal method to make subtree empty.
     */
    void makeEmpty(AvlNode *&t)
    {
        if (t != nullptr)
        {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        }
        t = nullptr;
    }

    // Avl manipulations
    /**
     * Return the height of node t or -1 if nullptr.
     */
    int height(AvlNode *t) const
    {
        return t == nullptr ? -1 : t->height;
    }

    int max(int lhs, int rhs) const
    {
        return lhs > rhs ? lhs : rhs;
    }

    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for case 1.
     * Update heights, then set new root.
     */
    void rotateWithLeftChild(AvlNode *&k2)
    {
        AvlNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for case 4.
     * Update heights, then set new root.
     */
    void rotateWithRightChild(AvlNode *&k1)
    {
        AvlNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->right), k1->height) + 1;
        k1 = k2;
    }

    /**
     * Double rotate binary tree node: first left child.
     * with its right child; then node k3 with new left child.
     * For AVL trees, this is a double rotation for case 2.
     * Update heights, then set new root.
     */
    void doubleWithLeftChild(AvlNode *&k3)
    {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    }

    /**
     * Double rotate binary tree node: first right child.
     * with its left child; then node k1 with new right child.
     * For AVL trees, this is a double rotation for case 3.
     * Update heights, then set new root.
     */
    void doubleWithRightChild(AvlNode *&k1)
    {
        rotateWithLeftChild(k1->right);
        rotateWithRightChild(k1);
    }
};

/**
 * @param:  a avl tree small containing elements less than or equal to median
 * @param:  a avl tree large containing elements greater than median
 * @param:  an integer num to be inserted into nums
 * @post:   insert a new element num into two trees (small and large) representing the lower and upper halves of the data stream, 
 *          while ensuring that the median of the data stream is maintained.
*/
void treeInsert(AvlTree& small, AvlTree& large, int num);

/**
 * @param:  a avl tree small containing elements less than or equal to median
 * @param:  a avl tree large containing elements greater than median
 * @return: max element in small
 * @post:   remove and return the median element from the data stream, which is stored in the small tree. 
 *          Ensures that the trees remain balanced after the removal of the median element.
*/
int treePopMedian(AvlTree& small, AvlTree& large);

/**
 * @param:  a vector of instructions
 * @post:   processes a vector of instructions, where each element represents either an integer value or -1. 
 *          For each non-negative integer, it inserts it into either a tree small or tree large while maintaining the sorted order. 
 *          When encountering -1, it pops the median from the small tree and pushes it into another vector vec. 
 *          Finally, it prints the elements of vec to the standard output.
*/
void treeMedian(const std::vector<int> * instructions);

#endif