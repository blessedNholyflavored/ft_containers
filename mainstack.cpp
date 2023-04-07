/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainstack.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 13:57:29 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/04/04 13:57:30 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "pair.hpp"
#include "stack.hpp"

#define RED     "\033[31m"      
#define BOLDGREEN   "\033[1m\033[32m"      
#define YELLOW  "\033[33m"      
#define BOLDWHITE   "\033[1m\033[37m"
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */


int	main(void)
{

	ft::stack<int> st;
	std::cout << BOLDWHITE << "FT Stack size: " << BOLDCYAN << st.size() << std::endl;
	std::cout << BOLDBLACK << "Push_back test IN PROGRESSSSS \n";
    std::cout << BOLDBLUE << "1" << std::endl;
    std::cout << BOLDYELLOW << "3"<< std::endl;
    std::cout << BOLDMAGENTA << "6 "<< std::endl;
    std::cout << BOLDGREEN << "8 "<< std::endl;
	st.push(1);
	st.push(3);
	st.push(6);
	st.push(8);
	std::cout << BOLDWHITE << "FT Stack size: " << BOLDCYAN << st.size() << std::endl;
	std::cout << BOLDWHITE <<  "FT Stack empty: " << BOLDCYAN << st.empty() << std::endl;
	std::cout << BOLDBLACK << "POP test IN PROGRESSSSSSSSSSSSSSSSSSS!!!!!!!!!! \n";
	st.pop();
	std::cout << BOLDWHITE << "FT Stack size: " << BOLDCYAN << st.size() << std::endl;
    std::cout << BOLDWHITE << "my stack top is now " << BOLDCYAN << st.top() << '\n';


}
