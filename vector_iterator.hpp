/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 15:34:44 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/01/13 15:34:45 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <iostream>
#include <cstddef>

//std::iterator is a base class for std::iterator_traits. 
//They are both classes. 
//Whereas std::random_access_iterator_tag is a struct.
namespace ft{
    template <class Iterator>
class vector_iterator : public ft::iterator<ft::random_access_iterator_tag, Iterator> //j'herite des iterateurs random access (car vector et non pas bidirectionnel pour map), de la class iterator que jai creer
{

    public:
	typedef Iterator		                                            iterator_type;
    typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
    typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
    typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
    typedef typename ft::iterator_traits<Iterator>::reference           reference;
    typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
    
    protected:
        Iterator _it;
    
    public:
    //les constructeurs
    //vector_iterator(void) : _it() { }
    explicit vector_iterator( const Iterator& it ) : _it(it) { }
    vector_iterator(vector_iterator  &test) : _it(test.base()) { }
    ~vector_iterator() { }

    // template pr lui donner un type
    template <typename type>
        vector_iterator(const vector_iterator <type> &x) : _it(x.base()) { }

    iterator_type base() const
    {
        return _it;
    }

    vector_iterator	&operator=(const vector_iterator &content)
    {
        _it = content._it;
        return *this;
    }

    reference operator*() const 
    {
        return *_it;
    }
    
    pointer operator->() 
    {
        return _it;
    }

    reference operator[](const difference_type& n) const
    {
        return this->_it[n];
    }

    vector_iterator& operator++()
    {
        _it++; 
        return (*this);
    }  
       
    vector_iterator& operator--()
    {
        --_it; 
        return (*this);
    }  
    
    vector_iterator operator++(int) 
    { 
        vector_iterator tmp = *this; 
        ++(*this); 
        return (tmp);
    }

    vector_iterator operator--(int) 
    { 
        vector_iterator tmp = *this; 
        --(*this); 
        return (tmp);
    }

    vector_iterator operator+(const difference_type& n) const
    {
        return vector_iterator(_it + n);
    }
    vector_iterator operator-(const difference_type& n) const
    {
        return vector_iterator(_it - n);
    }

    vector_iterator &operator+=(const difference_type& n)
	{
		_it += n;
		return *this;
	}

    vector_iterator &operator-=(const difference_type& n)
    {
		_it -= n;
		return *this;
	}
 

};

//https://en.cppreference.com/w/cpp/language/operators
template <typename L, typename R>
    bool operator==(const vector_iterator<L> &left, const vector_iterator<R> &right) {
        return left.base() == right.base();
    }

	template<typename L, typename R>
		bool operator!=(const vector_iterator<L> &left, const vector_iterator<R> &right) {
			return left.base() != right.base();
	}
    
    template<typename L, typename R>
		bool operator<(const vector_iterator<L> &left, const vector_iterator<R> &right) {
			return left.base() < right.base();
	}

    template<typename L, typename R>
		bool operator>(const vector_iterator<L> &left, const vector_iterator<R> &right) {
			return left.base() > right.base();
	}

    template<typename L, typename R>
		bool operator>=(const vector_iterator<L> &left, const vector_iterator<R> &right) {
			return left.base() >= right.base();
	}

    template<typename L, typename R>
		bool operator<=(const vector_iterator<L> &left, const vector_iterator<R> &right) {
			return left.base() <= right.base();
	}

// cest pa des booleans lesoperateurs arithmetik
    template<typename L, typename R>
    typename vector_iterator <L>::difference_type operator-(const vector_iterator<L> &left, const vector_iterator<R> &right)
    {
        return (left.base() - right.base());
    }

    template <typename L>
    vector_iterator <L> operator+(const vector_iterator<L> &left, typename vector_iterator<L>::difference_type n)
    {
        return (vector_iterator<L>(left.base() + n));
    }

}

#endif


