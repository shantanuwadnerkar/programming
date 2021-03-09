#include <iostream>
#include <vector>

void print_vector(std::vector<int>& vec);
void print_vector(std::vector<std::vector<int>>& vec);


int main()
{
    // Initialisation
    std::vector<int> vec11;
    std::vector<int> vec12({1, 2, 3});
    std::vector<int> vec13(5);
    std::vector<int> vec14(5, 5); // initialise a vector to 5.
    
    std::vector<std::vector<int>> vec21;
    std::vector<std::vector<int>> vec22({{1, 2, 3}, 
                                        {4, 5, 6}});
    std::vector<std::vector<int>> vec23(3, std::vector<int>(3)); // 4-by-4 matrix, all initialised to 0.
    std::vector<std::vector<int>> vec24(3, std::vector<int>(3, 7)); // 4-by-4 matrix, all initialised to 7.
    
    std::vector<int> vec_temp(5, 3); // first initialise a 1-D vector and then use it to initialise a matrix.
    std::vector<std::vector<int>> vec25(5, vec_temp); // 5-by-5 matrix, all initialised to 3.
    
    std::vector<std::vector<int>> vec26(1, vec_temp); // 1-by-5 matrix, all initialised to 3.

    std::vector<std::vector<int>> vec27(5); // 5-by-0 matrix. Initialize only one dimension.

    // More ways of initialising here: https://www.techiedelight.com/initialize-two-dimensional-vector-cpp/

    // std::cout << "vec11: " << "\n";
    // print_vector(vec11);
    
    // std::cout << "vec12: " << "\n";
    // print_vector(vec12);
    
    // std::cout << "vec13: " << "\n";
    // print_vector(vec13);
    
    // std::cout << "vec14: " << "\n";
    // print_vector(vec14);
    
    // std::cout << "vec21: " << "\n";
    // print_vector(vec21);
    
    // std::cout << "vec22: " << "\n";
    // print_vector(vec22);
    
    // std::cout << "vec23: " << "\n";
    // print_vector(vec23);
    
    std::cout << "vec24: " << "\n";
    print_vector(vec24);

    std::cout << "vec25: " << "\n";
    print_vector(vec25);

    std::cout << "vec26: " << "\n";
    print_vector(vec26);

    vec14.push_back(4); // push more elements.

    return 0;
}


void print_vector(std::vector<int>& vec)
{
    // for (int idx=0; idx<vec.size(); idx++)
    // {
    //     std::cout << vec[idx] << " ";
    //     // std::cout << vec.at(idx) << " "; // another way of accessing elements 
    // }
    // std::cout << "\n" << std::endl;

    // Another way of iterating
    for (std::vector<int>::const_iterator it=vec.cbegin(); it!=vec.cend(); it++)
    {
        std::cout << *it << " ";
        // std::cout << vec.at(idx) << " "; // another way of accessing elements 
    }
    std::cout << "\n" << std::endl;

    // or can also use auto
    // for (auto it=vec.cbegin(); it!=vec.cend(); it++)
    // {
    //     std::cout << *it << " ";
    //     // std::cout << vec.at(idx) << " "; // another way of accessing elements 
    // }
    // std::cout << "\n" << std::endl;
}


void print_vector(std::vector<std::vector<int>>& vec)
{
    for (int i=0; i<vec.size(); i++)
    {
        for (int j=0; j<vec[i].size(); j++)
        {
            // std::cout << vec[i][j] << " ";
            std::cout << vec.at(i).at(j) << " "; // another way of accessing elements.
        }
        std::cout << "\n";
    }
    std::cout << std::endl;

    // Another way of iterating.
    // for (auto it1=vec.cbegin(); it1!=vec.cend(); it1++)
    // {
    //     for (auto it2=(*it1).cbegin(); it2!=(*it1).cend(); it2++)
    //     {
    //         std::cout << *it2 << " ";
    //         // std::cout << vec.at(idx) << " "; // another way of accessing elements.
    //     }
    //     std::cout << "\n";
    // }
    // std::cout << std::endl;
}
