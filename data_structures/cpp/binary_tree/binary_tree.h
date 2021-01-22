#include <iostream>
#include <string>
#include <cassert>
#include <vector>


struct BinaryTreeNode
{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode();
    BinaryTreeNode(int val);
    BinaryTreeNode(int val, BinaryTreeNode* left, BinaryTreeNode* right);
    ~BinaryTreeNode();
};
