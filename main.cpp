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
#include "stack.hpp"

#define RED     "\033[31m"      
#define BOLDGREEN   "\033[1m\033[32m"      
#define YELLOW  "\033[33m"      
#define BOLDWHITE   "\033[1m\033[37m"
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define RESET   "\033[0m"

int main()
{
    std::cout << YELLOW << "test de begin" << std::endl;
    ft::vector<int> fdp; 
    fdp.push_back(123);
    fdp.push_back(13);
   

    ft::vector<int> test; 
    test.push_back(13);
    test.push_back(14);
    test.push_back(15);
    test.push_back(16);
    test.push_back(17);
    test.push_back(19);
    test.push_back(321);
    test.push_back(23);
    test.push_back(1880);
    test.push_back(180);



  ft::vector<int>::iterator it = test.begin();
    for (it = test.begin(); it != test.end(); ++it)
        std::cout << BOLDWHITE<< " " << *it ;
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

    std::cout << YELLOW << "test de assign()" << std::endl;

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
    

    std::cout << YELLOW << "test de swap()" << std::endl;

    ft::vector<int> foo (3,100);   // three ints with a value of 100
    ft::vector<int> bar (5,200);   // five ints with a value of 200

    std::cout << "AVANT SWAP ->foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
        std::cout << BOLDWHITE << ' ' << foo[i];
    std::cout << '\n';

    std::cout << YELLOW << "AVANT SWAP ->bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
        std::cout << BOLDWHITE << ' ' << bar[i];
    std::cout << '\n';

    foo.swap(bar);

    std::cout << YELLOW << "foo contains:";
    for (unsigned i=0; i<foo.size(); i++)
        std::cout << BOLDWHITE << ' ' << foo[i];
    std::cout << '\n';

    std::cout << YELLOW << "bar contains:";
    for (unsigned i=0; i<bar.size(); i++)
        std::cout << BOLDWHITE << ' ' << bar[i];
    std::cout << '\n';

    std::cout << std::endl;

     std::cout << YELLOW << "test des insert" << std::endl;

	ft::vector<int> vct(10);
	ft::vector<int> vct2;
	ft::vector<int> vct3;


    for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;

    std::cout << YELLOW << "jinsert 42 a end() puis jinsert 2x 21 au begin" << std::endl;
	vct2.insert(vct2.end(), 42);
	vct2.insert(vct2.begin(), 2, 21);
    std::cout << BOLDCYAN << ' ' << vct2[0];
    std::cout << BOLDCYAN << ' ' << vct2[1];
    std::cout << BOLDWHITE << ' ' << vct2[2];
 
 	std::cout << std::endl;

    std::cout << YELLOW <<"jinsert 42 a end() - 2" << std::endl;
	vct2.insert(vct2.end() - 2, 42);
    std::cout << BOLDWHITE << ' ' << vct2[0];
    std::cout << BOLDCYAN << ' ' << vct2[1];
    std::cout << BOLDWHITE << ' ' << vct2[2];
    std::cout << BOLDWHITE << ' ' << vct2[3];
	std::cout << std::endl;

    std::cout <<YELLOW << "jinsert 2x 84 a end()" << std::endl;
	vct2.insert(vct2.end(), 2, 84);
	std::cout << BOLDWHITE << ' ' << vct2[0];
    std::cout << BOLDWHITE << ' ' << vct2[1];
    std::cout << BOLDWHITE << ' ' << vct2[2];
    std::cout << BOLDWHITE << ' ' << vct2[3];
    std::cout << BOLDCYAN << ' ' << vct2[4];
    std::cout << BOLDCYAN << ' ' << vct2[5];

	std::cout << std::endl;

	vct2.resize(4);
    std::cout << YELLOW <<"je resize mon vector a size 4" << std::endl;
	 for (unsigned i=0; i<vct2.size(); ++i)
    std::cout << BOLDWHITE << ' ' << vct2[i];
	std::cout << std::endl;

    std::cout <<YELLOW << "pour info, ce quil y a dans le vector 1" << std::endl;
    for (unsigned i=0; i<vct.size(); ++i)
    std::cout << BOLDWHITE << ' ' << vct[i];
	std::cout << std::endl;
    std::cout << YELLOW <<"jinsert a begin() + 2 ce quil y a dans le " << BOLDCYAN << "vector1" << YELLOW << " du first au last" << std::endl;
	vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
	vct.clear();
	std::cout << BOLDWHITE << ' ' << vct2[0];
    std::cout << BOLDWHITE << ' ' << vct2[1];
    std::cout << BOLDCYAN << ' ' << vct2[2];
    std::cout << BOLDCYAN << ' ' << vct2[3];
    std::cout << BOLDCYAN << ' ' << vct2[4];
    std::cout << BOLDCYAN << ' ' << vct2[5];
   	std::cout << BOLDCYAN << ' ' << vct2[6];
    std::cout << BOLDCYAN << ' ' << vct2[7];
    std::cout << BOLDCYAN << ' ' << vct2[8];
    std::cout << BOLDCYAN << ' ' << vct2[9];
    std::cout << BOLDCYAN << ' ' << vct2[10];
    std::cout << BOLDCYAN << ' ' << vct2[11];
    std::cout << BOLDWHITE << ' ' << vct2[12];
    std::cout << BOLDWHITE << ' ' << vct2[13];  

	std::cout << std::endl;

    std::cout << YELLOW <<"jinsert 0 1 2 3 4 dans le " <<BOLDCYAN << "vect3"<< YELLOW <<" puis jinsert a begin() + 1, 2x 111" << std::endl;
	for (int i = 0; i < 5; ++i)
		vct3.insert(vct3.end(), i);
	vct3.insert(vct3.begin() + 1, 2, 111);
	std::cout << BOLDWHITE << ' ' << vct3[0];
    std::cout << BOLDCYAN << ' ' << vct3[1];
    std::cout << BOLDCYAN << ' ' << vct3[2];
    std::cout << BOLDWHITE << ' ' << vct3[3];
    std::cout << BOLDWHITE << ' ' << vct3[4];
    std::cout << BOLDWHITE << ' ' << vct3[5];
    std::cout << BOLDWHITE << ' ' << vct3[6];

	std::cout << std::endl;
	std::cout << std::endl;
    std::cout<< YELLOW <<  "TEST de reverse iterator" << std::endl;

ft::vector<int> vector_reverse;
  for (int i=0; i<10; i++) vector_reverse.push_back(i);

    std::cout<< YELLOW <<  "voila ce quil ya dans le vector for now" << std::endl;
    for (unsigned i=0; i<vector_reverse.size(); ++i)
    std::cout << BOLDWHITE << ' ' << vector_reverse[i];
    std::cout << std::endl;

  typedef ft::vector<int>::iterator iter_type;
                                                         
  iter_type from (vector_reverse.begin());                                                                             
  iter_type until (vector_reverse.end());                      
  ft::vector_reverse_iterator<iter_type> rev_until (from);                                                    
  ft::vector_reverse_iterator<iter_type> rev_from (until); 
  ft::vector<int>::const_reverse_iterator rev_const_until(vector_reverse.rend());
  ft::vector<int>::const_reverse_iterator rev_const_from(vector_reverse.rbegin());


  std::cout << YELLOW << "reverse iterator:" << BOLDWHITE;
  int i = 0;
  while (i != 10 && (rev_from != rev_until))
        std::cout << ' ' << *rev_from++;
  std::cout << '\n';

  std::cout << YELLOW << "const reverse iterator:" << BOLDWHITE;
  while (rev_const_from != rev_const_until)
    std::cout << ' ' << *rev_const_from++;


	return (0);
}


