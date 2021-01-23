#pragma once

#include <iostream>
#include <string>
#include <cassert>
#include <vector>

#include "binary_tree_node.h"


class BinarySearchTree
{
public:
    BinarySearchTree(int val);

    BinarySearchTree(std::vector<int> vec);

    ~BinarySearchTree();

    /* @brief Returns the root of the Binary Search Tree object
    *
    * Time complexity: O(1)
    * 
    * @return Returns the pointer of the root
    */
    BinaryTreeNode* get_root();

    /* @brief Searches for the target value in the tree
    *
    * Time Complexity:
    * 
    * @param target - The target integer value to find
    * @return Boolean value. True if value is found, false if not
    */
    bool find(int target);


// ///////////////// add description below this
    /* @brief Finds the median point in a list of nodes/points
    *
    * Upon return, all points in the list before the median index will be to the 'left' of
    * the median point (along the given axis), while all following points are to the 'right'
    *
    * @param list - The list of points. The order of the points in the list may change
    * @param n_points - The length of 'list'
    * @param axis - The dimension (0: x, 1: y) to find the median of
    * @return Index of the median point in 'list'
    */
    bool findNR(int val);

    /* @brief Finds the median point in a list of nodes/points
    *
    * Upon return, all points in the list before the median index will be to the 'left' of
    * the median point (along the given axis), while all following points are to the 'right'
    *
    * @param list - The list of points. The order of the points in the list may change
    * @param n_points - The length of 'list'
    * @param axis - The dimension (0: x, 1: y) to find the median of
    * @return Index of the median point in 'list'
    */
    BinaryTreeNode* insert(int val);

    /* @brief Finds the median point in a list of nodes/points
    *
    * Upon return, all points in the list before the median index will be to the 'left' of
    * the median point (along the given axis), while all following points are to the 'right'
    *
    * @param list - The list of points. The order of the points in the list may change
    * @param n_points - The length of 'list'
    * @param axis - The dimension (0: x, 1: y) to find the median of
    * @return Index of the median point in 'list'
    */
    BinaryTreeNode* insertNR(int val);

    /* @brief Finds the median point in a list of nodes/points
    *
    * Upon return, all points in the list before the median index will be to the 'left' of
    * the median point (along the given axis), while all following points are to the 'right'
    *
    * @param list - The list of points. The order of the points in the list may change
    * @param n_points - The length of 'list'
    * @param axis - The dimension (0: x, 1: y) to find the median of
    * @return Index of the median point in 'list'
    */
    static bool isSame(BinaryTreeNode* p, BinaryTreeNode* q);

    /* @brief Finds the median point in a list of nodes/points
    *
    * Upon return, all points in the list before the median index will be to the 'left' of
    * the median point (along the given axis), while all following points are to the 'right'
    *
    * @param list - The list of points. The order of the points in the list may change
    * @param n_points - The length of 'list'
    * @param axis - The dimension (0: x, 1: y) to find the median of
    * @return Index of the median point in 'list'
    */
    void inorder_print(BinaryTreeNode* node);

    /* @brief Finds the median point in a list of nodes/points
    *
    * Upon return, all points in the list before the median index will be to the 'left' of
    * the median point (along the given axis), while all following points are to the 'right'
    *
    * @param list - The list of points. The order of the points in the list may change
    * @param n_points - The length of 'list'
    * @param axis - The dimension (0: x, 1: y) to find the median of
    * @return Index of the median point in 'list'
    */
    void preorder_print(BinaryTreeNode* node);

    /* @brief Finds the median point in a list of nodes/points
    *
    * Upon return, all points in the list before the median index will be to the 'left' of
    * the median point (along the given axis), while all following points are to the 'right'
    *
    * @param list - The list of points. The order of the points in the list may change
    * @param n_points - The length of 'list'
    * @param axis - The dimension (0: x, 1: y) to find the median of
    * @return Index of the median point in 'list'
    */
    void postorder_print(BinaryTreeNode* node);

    /* @brief Finds the median point in a list of nodes/points
    *
    * Upon return, all points in the list before the median index will be to the 'left' of
    * the median point (along the given axis), while all following points are to the 'right'
    *
    * @param list - The list of points. The order of the points in the list may change
    * @param n_points - The length of 'list'
    * @param axis - The dimension (0: x, 1: y) to find the median of
    * @return Index of the median point in 'list'
    */
    void print(std::string traversal = "inorder");

    /* @brief Finds the median point in a list of nodes/points
    *
    * Upon return, all points in the list before the median index will be to the 'left' of
    * the median point (along the given axis), while all following points are to the 'right'
    *
    * @param list - The list of points. The order of the points in the list may change
    * @param n_points - The length of 'list'
    * @param axis - The dimension (0: x, 1: y) to find the median of
    * @return Index of the median point in 'list'
    */
    void pretty_print();

private:
    BinaryTreeNode* m_root;

    BinaryTreeNode* insert_recursive_helper(BinaryTreeNode* node, int val);
    bool find_recursive_helper(BinaryTreeNode* node, int target);
    void delete_tree(BinaryTreeNode* node);

};
