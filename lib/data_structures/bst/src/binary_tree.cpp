#include <bst/binary_tree.h>


// Source:
// http://cslibrary.stanford.edu/110/BinaryTrees.html
// http://math.hws.edu/eck/cs225/s03/binary_trees/
// https://www.bogotobogo.com/cplusplus/binarytree.php
// https://www.cs.umd.edu/class/summer2015/cmsc132/lectures/lecture13/Trees.pdf

// For more interesting details on assert.
// https://en.cppreference.com/w/cpp/error/assert

namespace bst
{
void print_vector(const std::vector<int>& vec)
{
    for (int idx = 0; idx < vec.size(); idx++)
    {
        std::cout << vec[idx] << " ";
    }

    std::cout << '\n';
}

// void print_vector(const std::vector<int>& vec)
// {
//     for (int idx = 0; idx < vec.size(); idx++)
//     {
//         std::cout << vec[idx] << " ";
//     }

//     std::cout << '\n';
// }

BinarySearchTree::BinarySearchTree(int val)
    : m_root{new BinaryTreeNode{val}}
{
}

// initialize tree using a vector of elements
BinarySearchTree::BinarySearchTree(std::vector<int> vec)
    : m_root{new BinaryTreeNode{vec[0]}}
{
    auto it = vec.cbegin();
    it++;

    while (it != vec.cend())
    {
        this->insert(*it);
        it++;
    }
}

BinarySearchTree::~BinarySearchTree()
{
    delete_tree(m_root);
}

BinaryTreeNode* BinarySearchTree::get_root()
{
    return m_root;
}

void BinarySearchTree::inorder_print(BinaryTreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    inorder_print(node->left);
    std::cout << node->data << " ";
    inorder_print(node->right);
}

void BinarySearchTree::preorder_print(BinaryTreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    std::cout << node->data << " ";
    preorder_print(node->left);
    preorder_print(node->right);
}

void BinarySearchTree::postorder_print(BinaryTreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    postorder_print(node->left);
    postorder_print(node->right);
    std::cout << node->data << " ";
}

// std::vector<int> BinarySearchTree::inorder_traversal(BinaryTreeNode* node)
// {
//     if (node == nullptr)
//     {
//         return;
//     }
// }

// std::vector<int> BinarySearchTree::preorder_traversal(BinaryTreeNode* node)
// {
//     if (node == nullptr)
//     {
//         return;
//     }
// }

// std::vector<int> BinarySearchTree::postorder_traversal(BinaryTreeNode* node)
// {
//     if (node == nullptr)
//     {
//         return;
//     }
// }

BinaryTreeNode* BinarySearchTree::insert(int val)
{
    return insert_recursive_helper(m_root, val);
}

// insert non-recursive
BinaryTreeNode* BinarySearchTree::insertNR(int val)
{
    // return insert_recursive_helper(m_root, val);
    // TO DO
}

bool BinarySearchTree::find(int target)
{
    return find_recursive_helper(m_root, target);
}

// find non-recursive
bool BinarySearchTree::findNR(int val)
{
    BinaryTreeNode* runner{m_root};

    while (true)
    {
        if (runner == nullptr)
        {
            return false;
        }
        else if (runner->data == val)
        {
            return true;
        }
        else if (runner->data < val)
        {
            runner = runner->right;
        }
        else
        {
            runner = runner->left;
        }
    }
}

void BinarySearchTree::print(std::string traversal)
{
    assert(traversal == "inorder" || traversal == "preorder" || traversal == "postorder" && "assert msg");
    // convert to switch-case
    if (traversal == "inorder")
    {
        std::cout << "Inorder traversal:\n";
        inorder_print(m_root);
        std::cout << '\n';
    }
    else if (traversal == "preorder")
    {
        std::cout << "Pre-order traversal:\n";
        preorder_print(m_root);
        std::cout << '\n';
    }
    else if (traversal == "postorder")
    {
        std::cout << "Post-order traversal:\n";
        postorder_print(m_root);
        std::cout << '\n';
    }
}

void BinarySearchTree::pretty_print()
{
}

BinaryTreeNode* BinarySearchTree::insert_recursive_helper(BinaryTreeNode* node, int val)
{
    if (node == nullptr)
    {
        return new BinaryTreeNode{val};
    }
    else
    {
        if (node->data < val)
        {
            node->right = insert_recursive_helper(node->right, val);
        }
        else
        {
            node->left = insert_recursive_helper(node->left, val);
        }
        
        return node;
    }
}

bool BinarySearchTree::find_recursive_helper(BinaryTreeNode* node, int target)
{
    if (node == nullptr)
    {
        return false;
    }
    else
    {
        if (node->data == target)
        {
            return true;
        }
        else if (node->data < target)
        {
            return BinarySearchTree::find_recursive_helper(node->right, target);
        }
        else
        {
            return BinarySearchTree::find_recursive_helper(node->left, target);
        }
    }
}

void BinarySearchTree::delete_tree(BinaryTreeNode* node)
{
    if (node == nullptr)
    {
        return;
    }

    delete_tree(node->left);
    delete_tree(node->right);
    delete node;
}

bool BinarySearchTree::isSame(BinaryTreeNode* p, BinaryTreeNode* q)
{
    if (p == nullptr || q == nullptr)
    {
        return (p == q);
    }

    return (p->data == q->data && isSame(p->left, q->left) && isSame(p->right, q->right));
}
} // namespace bst
