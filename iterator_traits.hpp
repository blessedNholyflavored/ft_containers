/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:34:40 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/01/13 15:34:41 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
#define ITERATOR_TRAITS_HPP
#include <cstddef>
#include <iostream>


namespace ft{
    
    // ci dessous les 5 types diterators possibles en c++
    struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag : public input_iterator_tag { };
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };
    
    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*,class Reference = T&>
    class iterator {
    public:
        typedef T         value_type;
        typedef Distance  difference_type;
        typedef Pointer   pointer;
        typedef Reference reference;
        typedef Category  iterator_category;
    };

    template <class Iterator>
    class iterator_traits
    {
        public:
      	typedef typename Iterator::value_type			value_type;
        typedef typename Iterator::difference_type		difference_type;
        typedef typename Iterator::pointer				pointer;
        typedef typename Iterator::reference			reference;
        typedef typename Iterator::iterator_category	iterator_category;

        //basique???
    };

    template <class T>
    class iterator_traits<T*>
    {
        public:
        typedef T                               value_type;
        typedef std::ptrdiff_t                  difference_type;
        typedef T*                              pointer;
        typedef T&                              reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits<const T*>
    {
        public:
        typedef T                               value_type;
        typedef std::ptrdiff_t                  difference_type;
        typedef const T*                        pointer;
        typedef const T&                        reference;
        typedef std::random_access_iterator_tag iterator_category;
    };

    // T cest le type diterateur


}
#endif
