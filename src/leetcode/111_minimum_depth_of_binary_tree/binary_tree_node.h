#pragma once

#include <iostream>


struct BinaryTreeNode
{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val, BinaryTreeNode* left, BinaryTreeNode* right)
        : data{val}, left{left}, right{right}
    {
    }

    BinaryTreeNode(int val)
        : BinaryTreeNode(val, nullptr, nullptr)
    {
    }

    BinaryTreeNode()
        : BinaryTreeNode(0, nullptr, nullptr)
    {
    }

    ~BinaryTreeNode()
    {
    }
};