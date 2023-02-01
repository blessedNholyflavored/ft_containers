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
#include <stdexcept>      // std::out_of_range
#include "lexicographical.hpp"


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
 
    ft::vector<int> test; 
    test.push_back(13);
    test.push_back(14);
    test.push_back(15);
    test.push_back(16);
    test.push_back(17);
    test.push_back(19);
    test.push_back(321);
    test.push_back(23);
    test.push_back(180);

//    ft::vector<int>::iterator iter = test.end() - 4;
//    std::cout << "LOL --> " << *iter << std::endl;

//  //  std::cout <<"at > " << test.begin() << std::endl;
  
//        std::cout <<"at > " << test.at(2) << std::endl;
  ft::vector<int>::iterator it = test.begin();
    for (it = test.begin(); it != test.end(); ++it)
        std::cout << BOLDWHITE << " " << *it ;
    std::cout<< std::endl;


    
    std::cout << YELLOW << "test de back" << std::endl;
        std::cout << BOLDWHITE << "back : " << test.back() << std::endl;

    std::cout << YELLOW << "test de at" << std::endl;
        std::cout <<BOLDWHITE <<  "at de 2 : " << test.at(2) << std::endl;

    std::cout << YELLOW << "test de at avec et sans exception" << std::endl;
	try
	{
		std::cout << BOLDWHITE << "at(2) : " <<test.at(2) << std::endl;
		std::cout << BOLDWHITE << "at(4) : " <<test.at(4) << std::endl;
		std::cout << BOLDWHITE << "at(16) donc exception : " <<test.at(16) << std::endl;
	}
    catch(const std::exception& e)
	{
		std::cerr << RED<< e.what() << std::endl;
	}




    std::cout << YELLOW << "test de front" << std::endl;
        std::cout <<BOLDWHITE << "front :  " << test.front() << std::endl;

    std::cout << YELLOW << "test de operator[]" << std::endl;
        std::cout <<BOLDWHITE << "operator[] de 4:  " << test[4] << std::endl;

    std::cout << YELLOW << "test de size()" << std::endl;
        std::cout <<BOLDWHITE << "size():  " << test.size() << std::endl;
    std::cout << YELLOW << "test de capacity()" << std::endl;
        std::cout <<BOLDWHITE << "capacity():  " << test.capacity() << std::endl;
    std::cout << YELLOW << "test de max_size()" << std::endl;
        std::cout <<BOLDWHITE << "max_size():  " << test.max_size() << std::endl;  
    

    std::cout << YELLOW << "test de erase()" << std::endl;
     ft::vector<int> myvector;
  for (int i=1; i<=10; i++) myvector.push_back(i);
    for (it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << BOLDWHITE << " " << *it;
    std::cout<< std::endl;

  // erase the 6th element
  std::cout << "on supprime le 6eme element" << std::endl;
  myvector.erase (myvector.begin()+5);

  // erase the first 3 elements:
  std::cout << "on supprime les trois premiers elements" << std::endl;
  myvector.erase (myvector.begin(),myvector.begin() + 3);

  std::cout << "myvector contient:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

    std::cout << YELLOW << "test de popback()" << std::endl;

  myvector.pop_back();
    for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << BOLDWHITE << ' ' << myvector[i];
  std::cout << '\n';


    std::cout << YELLOW << "test de resize() avec (5), (8, 100) et (12)" << std::endl;
    myvector.resize(5);
    myvector.resize(8, 100);
    myvector.resize(12);
    for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << BOLDWHITE << ' ' << myvector[i];

    std::cout << '\n';
    std::cout << YELLOW << "test de empty()" << std::endl;
    std::cout <<BOLDWHITE << "empty():  " << myvector.empty() << std::endl;

    ft::vector<int> first;
    ft::vector<int> second;
    ft::vector<int> third;

    first.assign (7,100);             // 7 ints with a value of 100

    ft::vector<int>::iterator ite = first.begin()+1;

    second.assign (ite,first.end() - 1); // the 5 central values of first

    std::cout << YELLOW << "Size of first (7,100) : " << int (first.size()) << '\n';
       for (unsigned i=0; i<first.size(); ++i)
    std::cout << BOLDWHITE << ' ' << first[i];
    std::cout << std::endl;
    std::cout << YELLOW << "Size of second (ite,first.end() - 1): " << int (second.size()) << '\n';
    for (unsigned i=0; i<second.size(); ++i)
    std::cout << BOLDWHITE << ' ' << second[i];
    std::cout << std::endl;
    

    std::cout << YELLOW << "test de insert 1" << std::endl;
//  ft::vector<int> vec =  {1,2,3,4,5};
     myvector.insert(myvector.begin(), 10);//Inserting 10 to the myvectortor
	 for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << BOLDWHITE << ' ' << myvector[i];


 ft::vector<int> myvector5;
  
  for (int i=1; i<=10; i++) myvector5.push_back(i);
    std::cout << YELLOW << "test de insert2" << std::endl;
//  ft::vector<int> vec =  {1,2,3,4,5};
     myvector5.insert(myvector5.begin(), 2, 6);//Inserting 10 to the myvectortor
	 for (unsigned i=0; i<myvector5.size(); ++i)
    std::cout << BOLDWHITE << ' ' << myvector5[i];
	



  return 0;

 }
