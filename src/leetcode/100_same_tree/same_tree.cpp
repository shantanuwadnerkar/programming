#include <iostream>

#include "binary_tree_node.h"

bool isSameTree(BinaryTreeNode* p, BinaryTreeNode* q)
{
    if (p == nullptr || q == nullptr)
    {
        return (p == q);
    }

    return (p->data == q->data && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}

int main()
{
    // TODO: add more test cases
    // TODO: Use google_test for testing
    // test cases
    BinaryTreeNode* one{new BinaryTreeNode{1}};
    BinaryTreeNode* two{new BinaryTreeNode{2}};
    BinaryTreeNode* three{new BinaryTreeNode{3}};

    BinaryTreeNode* root_p1{new BinaryTreeNode{1, two, three}};
    BinaryTreeNode* root_q1{new BinaryTreeNode{1, two, three}};
    std::cout << isSameTree(root_p1, root_q1) << '\n';

    BinaryTreeNode* root_p2{new BinaryTreeNode{1, nullptr, two}};
    BinaryTreeNode* root_q2{new BinaryTreeNode{1, two, nullptr}};
    std::cout << isSameTree(root_p2, root_q2) << '\n';

    BinaryTreeNode* root_p3{new BinaryTreeNode{1, one, two}};
    BinaryTreeNode* root_q3{new BinaryTreeNode{1, two, one}};
    std::cout << isSameTree(root_p3, root_q3) << '\n';


    return 0;
}
