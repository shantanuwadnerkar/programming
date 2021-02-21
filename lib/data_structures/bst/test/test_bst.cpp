#include <bst/binary_tree.h>


int main()
{
    bst::BinarySearchTree bst{5};

    // bst.insert(4);
    // bst.insert(4);
    // bst.insert(6);
    // bst.insert(3);
    // bst.insert(7);

    // // std::cout << bst.find(6) << '\n';
    // // std::cout << bst.find(9) << '\n';
    // // std::cout << bst.find(4) << '\n';
    // // std::cout << bst.find(3) << '\n';
    // // std::cout << bst.findNR(6) << '\n';
    // // std::cout << bst.findNR(9) << '\n';
    // // std::cout << bst.findNR(4) << '\n';
    // // std::cout << bst.findNR(3) << '\n';
    // bst.print();
    // // bst.print("inorder");
    // bst.print("preorder");
    // bst.print("postorder");

    // std::cout << '\n';

    // BinarySearchTree bst_vec{{5, 4, 4, 6, 3, 7}};
    // bst_vec.print();
    // bst_vec.print("preorder");
    // bst_vec.print("postorder");

    // std::cout << '\n';
    
    // std::vector<int> vec{5, 4, 4, 6, 3, 7};
    // BinarySearchTree bst_vec2{vec};
    // bst_vec2.print();
    // bst_vec2.print("preorder");
    // bst_vec2.print("postorder");

    // std::cout << "Are bst and bst_vec same? " << BinarySearchTree::isSame(bst.get_root(), bst_vec.get_root()) << '\n';

    return EXIT_SUCCESS;
}
