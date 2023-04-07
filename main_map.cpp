/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:17:13 by ldinaut           #+#    #+#             */
/*   Updated: 2023/04/07 17:52:22 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"
#include <map>
#include <iostream>
#include <iomanip>

#ifndef STD
# define NAMESPACE ft
#else
# define NAMESPACE std
#endif

int	main(void)
{
	std::cout << "\t\t----- MAP TEST START -----\n" << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t-- insert 6 pairs in map --\n" << std::endl;
	NAMESPACE::map<int, int> ft;
	ft.insert(NAMESPACE::make_pair(5, 8));
	ft.insert(NAMESPACE::make_pair(1, 3));
	ft.insert(NAMESPACE::make_pair(7, 10));
	ft.insert(NAMESPACE::make_pair(3, 9));
	ft.insert(NAMESPACE::make_pair(4, 11));
	ft.insert(NAMESPACE::make_pair(54, 110));

	std::cout << "------ TREE ------\n" << std::endl;
	ft._rbtree.print_rec(ft._rbtree.getRoot());
	std::cout << "------      ------\n" << std::endl;
	std::cout << "\n";

	std::cout << "\t-- test iterator map --\n" << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "begin->first: " << ft.begin()->first << "\n";
	std::cout << "begin->second: " << ft.begin()->second << "\n";
	std::cout << "\n";
	std::cout << "\n";

	NAMESPACE::map<int,int>::iterator E2 = ft.end();
	E2--;
	std::cout << "end->first: " << ft.end()->first << "\n";
	std::cout << "end->second: " << ft.end()->second << "\n";
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "end-- ->first: " << E2->first << "\n";
	std::cout << "end-- ->second: " << E2->second << "\n";
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "ft equal_range test (first->first): " << ft.equal_range(7).first->first << "\n";
	std::cout << "ft equal_range test (first->second): " << ft.equal_range(7).first->second << "\n";
	std::cout << "ft equal_range test (second->first): " << ft.equal_range(7).second->first << "\n";
	std::cout << "ft equal_range test (second->second): " << ft.equal_range(7).second->second << "\n";
	
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "\t-- test iterator operator --\n" << std::endl;
	std::cout << "-- [++] --\n" << std::endl;
	NAMESPACE::map<int,int>::iterator my = ft.begin();
	std::cout << "test: " << my->first << "\n";
	my++;
	my++;
	++my;
	my++;
	my++;
	std::cout << "test ++ : " << my->first << "\n";
	std::cout << "-- [--] --\n" << std::endl;
	std::cout << "test: " << my->first << "\n";
	my--;
	my--;
	--my;
	my--;
	my--;
	std::cout << "test -- : " << my->first << "\n";
	std::cout << "\n";
	std::cout << "\n";
	my = ft.begin();
	my++;
	std::cout << "my = " << my->first << "\n";
	std::cout << "Erase iterator my\n";
	ft.erase(my);
	my = ft.begin();
	std::cout << "my = " << my->first << "\n";

	std::cout << "------ TREE ------\n" << std::endl;
	ft._rbtree.print_rec(ft._rbtree.getRoot());
	std::cout << "------      ------\n" << std::endl;

	std::cout << "\t-- test upper/lowerbound --\n" << std::endl;

	NAMESPACE::map<int,int>::iterator itlow2,itup2;
	itlow2 = ft.lower_bound(10000);
	std::cout << "lowerbond->first: " << itlow2->first << "\n";
	std::cout << "lowerbound->second: " << itlow2->second << "\n";
	itlow2 = ft.upper_bound(-10);
	std::cout << "upperbound->first: " << itlow2->first << "\n";
	std::cout << "upperbound->second: " << itlow2->second << "\n";

	std::cout << "\n";
	std::cout << "\n";

	NAMESPACE::map<int, int>::iterator pa = ft.begin();
	NAMESPACE::map<int, int>::iterator po = ft.begin();
	NAMESPACE::map<int, int>::iterator la = ft.end();

	pa++;
	std::cout << "\t-- insert more pairs in map --\n" << std::endl;

	ft.insert(pa, NAMESPACE::make_pair(6, 6));
	ft.insert(pa, NAMESPACE::make_pair(7, 7));
	ft.insert(pa, NAMESPACE::make_pair(8, 8));
	ft.insert(pa, NAMESPACE::make_pair(9, 9));
	ft.insert(pa, NAMESPACE::make_pair(16, 16));
	ft.insert(pa, NAMESPACE::make_pair(26, 26));
	ft.insert(pa, NAMESPACE::make_pair(36, 36));
	ft.insert(pa, NAMESPACE::make_pair(46, 46));
	ft.insert(pa, NAMESPACE::make_pair(243, 243));
	while (po != la)
	{
		std::cout << "map[" << po->first << "] = " << po->second << "\n";
		po++;
	}

	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\n";
	po = ft.begin();
	la = ft.end();
	std::cout << "\t-- test operator= and erase --\n" << std::endl;

	ft[243] = 24;
	ft.erase(7);

	while (po != la)
	{
		std::cout << "map[" << po->first << "] = " << po->second << "\n";
		po++;
	}
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t-- test copy constructor --\n" << std::endl;

	NAMESPACE::map<int, int> cpy;
	cpy = ft;
	NAMESPACE::map<int, int>::iterator s1 = cpy.begin();
	NAMESPACE::map<int, int>::iterator f1 = cpy.end();

	while (s1 != f1)
	{
		std::cout << "first: " << s1->first <<  "\tsecond: " << s1->second << "\n";
		s1++;
	}
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "\t-- test find method --\n" << std::endl;
	std::cout << "\n";

	NAMESPACE::map<int, int>::iterator toto;
	toto = cpy.find(16);
	std::cout << "find key 16 result = "<< toto->first << std::endl;
	std::cout << "\n";
	std::cout << "\n";

	std::cout << "\t-- test clear method --\n" << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	
	std::cout << "is copy container empty ? " << std::endl;
	cpy.empty() ? std::cout << "yes!!!!\n" : std::cout << "noooo\n";
	std::cout << "copy containers size = " << cpy.size() << std::endl;
	std::cout << "\n";
	cpy.clear();
	std::cout << "\n";
	std::cout << "is copy container empty ? " << std::endl;
	cpy.empty() ? std::cout << "yes!!!! clear worked :)\n" : std::cout << "noooo clear failed :(\n";
	std::cout << "copy containers size = " << cpy.size() << std::endl;
	std::cout << "\n";
	std::cout << "\n";
	std::cout << "\t\t----- MAP TEST END -----\n" << std::endl;

}
