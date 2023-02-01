/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isintegral.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:02:08 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/01/30 14:02:09 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISINTEGRAL_HPP
#define ISINTEGRAL_HPP
#include "enableif.hpp"
#include <iostream>

namespace ft
{
//default
    template <class T>
	struct is_integral
	{
		static const bool value = false;
	};

//puis
	template <>
	struct is_integral<bool>
	{
		static const bool value = true; 
	};

	template <>
	struct is_integral<char>
	{
		static const bool value = true; 
	};
    template <>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<short>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<long long>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };
    template <>
    struct is_integral<unsigned long long>
    {
        static const bool value = true;
    };

}

#endif
	

