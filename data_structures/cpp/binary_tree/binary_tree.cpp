#include "binary_tree.h"


// Source:
// http://cslibrary.stanford.edu/110/BinaryTrees.html
// http://math.hws.edu/eck/cs225/s03/binary_trees/
// https://www.bogotobogo.com/cplusplus/binarytree.php
// https://www.cs.umd.edu/class/summer2015/cmsc132/lectures/lecture13/Trees.pdf

// For more interesting details on assert.
// https://en.cppreference.com/w/cpp/error/assert


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


struct BinaryTreeNode
{
public:
    // int data;
    // BinaryTreeNode* left;
    // BinaryTreeNode* right;

    BinaryTreeNode(int val, BinaryTreeNode* left, BinaryTreeNode* right)
        : data{val}, left{left}, right{right}
    {
    }

    // The below 2 constructors are delegated
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


class BinarySearchTree
{
public:
    BinarySearchTree(int val)
        : m_root{new BinaryTreeNode{val}}
    {
    }

    // initialize tree using a vector of elements
    BinarySearchTree(std::vector<int> vec)
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

    ~BinarySearchTree()
    {
        delete_tree(m_root);
    }

    BinaryTreeNode* get_root()
    {
        return m_root;
    }

    void inorder_print(BinaryTreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        inorder_print(node->left);
        std::cout << node->data << " ";
        inorder_print(node->right);
    }

    void preorder_print(BinaryTreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        std::cout << node->data << " ";
        preorder_print(node->left);
        preorder_print(node->right);
    }

    void postorder_print(BinaryTreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        postorder_print(node->left);
        postorder_print(node->right);
        std::cout << node->data << " ";
    }

    // std::vector<int> inorder_traversal(BinaryTreeNode* node)
    // {
    //     if (node == nullptr)
    //     {
    //         return;
    //     }
    // }

    // std::vector<int> preorder_traversal(BinaryTreeNode* node)
    // {
    //     if (node == nullptr)
    //     {
    //         return;
    //     }
    // }

    // std::vector<int> postorder_traversal(BinaryTreeNode* node)
    // {
    //     if (node == nullptr)
    //     {
    //         return;
    //     }
    // }

    BinaryTreeNode* insert(int val)
    {
        return insert_recursive_helper(m_root, val);
    }

    // insert non-recursive
    BinaryTreeNode* insertNR(int val)
    {
        // return insert_recursive_helper(m_root, val);
    }

    bool find(int target)
    {
        return find_recursive_helper(m_root, target);
    }

    // find non-recursive
    bool findNR(int val)
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

    void print(std::string traversal = "inorder")
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

    void pretty_print()
    {
    }

private:
    BinaryTreeNode* m_root;

    BinaryTreeNode* insert_recursive_helper(BinaryTreeNode* node, int val)
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

    bool find_recursive_helper(BinaryTreeNode* node, int target)
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
                return find_recursive_helper(node->right, target);
            }
            else
            {
                return find_recursive_helper(node->left, target);
            }
        }
    }

    void delete_tree(BinaryTreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }

        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }
};


int main()
{
    BinarySearchTree bst{5};

    bst.insert(4);
    bst.insert(4);
    bst.insert(6);
    bst.insert(3);
    bst.insert(7);

    // std::cout << bst.find(6) << '\n';
    // std::cout << bst.find(9) << '\n';
    // std::cout << bst.find(4) << '\n';
    // std::cout << bst.find(3) << '\n';
    // std::cout << bst.findNR(6) << '\n';
    // std::cout << bst.findNR(9) << '\n';
    // std::cout << bst.findNR(4) << '\n';
    // std::cout << bst.findNR(3) << '\n';
    bst.print();
    // bst.print("inorder");
    bst.print("preorder");
    bst.print("postorder");

    std::cout << '\n';

    BinarySearchTree bst_vec{{5, 4, 4, 6, 3, 7}};
    bst_vec.print();
    bst_vec.print("preorder");
    bst_vec.print("postorder");

    std::cout << '\n';
    
    std::vector<int> vec{5, 4, 4, 6, 3, 7};
    BinarySearchTree bst_vec2{vec};
    bst_vec2.print();
    bst_vec2.print("preorder");
    bst_vec2.print("postorder");
    return 0;
}
