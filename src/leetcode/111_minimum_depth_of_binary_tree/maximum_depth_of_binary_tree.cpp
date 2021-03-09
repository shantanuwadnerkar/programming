#include <iostream>
#include <queue>

#include "binary_tree.h"

int maxDepthDFS(BinaryTreeNode* node)
{
    if (node == nullptr)
    {
        return 0;
    }
    
    return (1 + std::max(maxDepthDFS(node->left), maxDepthDFS(node->right)));
}

int maxDepthBFS(BinaryTreeNode* node)
{
    std::queue<BinaryTreeNode*> q;
    q.push(node);
    int res;
    BinaryTreeNode* temp_node;

    while (!q.empty())
    {
        res++;
        for (int i=0, n=q.size(); i<n; i++)
        {
            temp_node = q.front();
            q.pop();

            if (temp_node->left != nullptr)
            {
                q.push(temp_node->left);
            }
            
            if (temp_node->right != nullptr)
            {
                q.push(temp_node->right);
            }
        }
    }
    return res;
}

int main()
{

    BinarySearchTree bst{{5, 4, 4, 6, 3, 7}};

    std::cout << maxDepthDFS(bst.get_root()) << '\n';
    std::cout << maxDepthBFS(bst.get_root()) << '\n';
    return 0;
}
