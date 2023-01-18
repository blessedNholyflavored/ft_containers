/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:58:41 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/01/18 13:58:42 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include "iterator_traits.hpp"
#include "vector_iterator.hpp"
#include <iostream>


#define RED     "\033[31m"      
#define BOLDGREEN   "\033[1m\033[32m"      
#define YELLOW  "\033[33m"      
#define BOLDWHITE   "\033[1m\033[37m"


int main()
{
    // std::cout << YELLOW << "test de begin" << std::endl;
    // ft::vector<int> fdp; 
    // //myvector{ 1, 2, 3, 4, 5 };
    // fdp.push_back(123);
    // fdp.push_back(13);
   
    // ft::vector<int>::iterator it = fdp.begin();
    // for (it = fdp.begin(); it != fdp.end(); ++it)
    //     std::cout << BOLDWHITE << " " << *it;
 
    ft::vector<int> marine; 
    marine.push_back(13);
    marine.push_back(14);
    marine.push_back(15);
    marine.push_back(16);
    marine.push_back(17);
    marine.push_back(19);
    marine.push_back(18);

//    ft::vector<int>::iterator iter = marine.end() - 4;
   // std::cout << "LOL --> " << *iter << std::endl;

   //std::cout << marine.back() << std::endl;
    std::cout <<"at > " << marine.at(10) << std::endl;
   

 }
