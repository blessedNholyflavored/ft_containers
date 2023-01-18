#include "vector.hpp"
#include "iterator_traits.hpp"
#include "vector_iterator.hpp"
#include <iostream>

// int main()
// {
//     //Iterator begin() { return Iterator(&it[0]); }
//     //Iterator end()   { return Iterator(&it[200]); } 

//     ft::vector<int> fdp;
//     // std::cout << fdp[0] << std::endl;
//     ft::vector<int>::iterator it;
//         fdp.push_back(6);
//     for (it = fdp.begin() it != fdp.end(); ++it)
//         std::cout << *it << std::endl;    
// }



int main()
{

    ft::vector<int> fdp; 
    //myvector{ 1, 2, 3, 4, 5 };
    fdp.push_back(123);
    fdp.push_back(13);
    std::cout << fdp[0] << std::endl;
    std::cout << fdp[1] << std::endl;
    
    ft::vector<int>::iterator it = fdp.begin();
    std::cout << *it << std::endl;

    // for (it = fdp.begin(); it != fdp.end(); ++it)
        // std::cout << " " << *it;
 }