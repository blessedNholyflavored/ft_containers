/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_reverse_iterator.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:40:31 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/01/18 16:40:32 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_REVERSE_ITERATOR_HPP
#define VECTOR_REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"
#include <iostream>

namespace ft{
    template <class Iterator>
    class vector_reverse_iterator
    {
        public:
        typedef Iterator		                                            iterator_type;
        typedef typename ft::iterator_traits<Iterator>::value_type          value_type;
        typedef typename ft::iterator_traits<Iterator>::difference_type     difference_type;
        typedef typename ft::iterator_traits<Iterator>::pointer             pointer;
        typedef typename ft::iterator_traits<Iterator>::reference           reference;
        typedef typename ft::iterator_traits<Iterator>::iterator_category   iterator_category;
        
        protected : 
        Iterator _it;
    
        public:
        // constructeurs

        vector_reverse_iterator() : _it(NULL) { }
        explicit vector_reverse_iterator( Iterator x ) : _it(x){ }
        template<class U>
        vector_reverse_iterator(  vector_reverse_iterator<U> const& other)  : _it(other.base()){ }
        ~vector_reverse_iterator() { }


        // // operateurs=====================
        // template< class U >
        // vector_reverse_iterator& operator=( const vector_reverse_iterator<U>& other ) 
        // {
        //     _it = other.base();
		// 	return *this;
        //  }

        //base
        iterator_type base() const 
        { 
            return (_it);
        }

        // * et -> 
        reference operator*() const
        {
            iterator_type tmp = _it;
            return *--tmp;
        }
        pointer operator->() const
        {
            iterator_type tmp = _it;
            return (&(*--tmp));
            
        }
        
        reference operator[](const difference_type& n) const
        {
            return this->_it[-n - 1];
        }

        // ++ et -- et tout et tout
        vector_reverse_iterator& operator++()
        {
            --(this->_it);
            //_it++; 
            return (*this);
        }  
        
        vector_reverse_iterator& operator--()
        {
            ++(this->_it);
            return (*this);
        }  
        
        vector_reverse_iterator operator++(int) 
        { 
            vector_reverse_iterator tmp = *this; 
            ++(*this);
            //++(*this); 
            return (tmp);
        }

        vector_reverse_iterator operator--(int) 
        { 
            vector_reverse_iterator tmp = *this; 
            --(*this); 
            // --(*this); 
            return (tmp);
        }

        // += et -=
        vector_reverse_iterator operator+(difference_type n) const
        {
            return vector_reverse_iterator(_it - n);
        }

         vector_reverse_iterator operator-(difference_type n) const
        {
            return vector_reverse_iterator(_it + n);
        }

    	vector_reverse_iterator& operator+=(difference_type n)
		{
			_it -= n;
			return *this;
		}
		vector_reverse_iterator& operator-=(difference_type n)
		{
			_it += n;
			return *this;
		}
    // non member functions iciiiii
    
    };
        template< class Iterator1, class Iterator2 >
        bool operator==( const vector_reverse_iterator<Iterator1>& lhs, const vector_reverse_iterator<Iterator2>& rhs )
        {
            return(lhs.base() == rhs.base());
        }

        template< class Iterator1, class Iterator2 >
        bool operator!=( const vector_reverse_iterator<Iterator1>& lhs,const vector_reverse_iterator<Iterator2>& rhs )
        {
            return(lhs.base() != rhs.base());
        }

        template< class Iterator1, class Iterator2 >
        bool operator<( const vector_reverse_iterator<Iterator1>& lhs,const vector_reverse_iterator<Iterator2>& rhs )
        {
            return(lhs.base() > rhs.base());
        }

        template< class Iterator1, class Iterator2 >
        bool operator<=( const vector_reverse_iterator<Iterator1>& lhs,const vector_reverse_iterator<Iterator2>& rhs )
        {
            return(lhs.base() >= rhs.base());
        }

        template< class Iterator1, class Iterator2 >
        bool operator>( const vector_reverse_iterator<Iterator1>& lhs,const vector_reverse_iterator<Iterator2>& rhs )
        {
            return(lhs.base() < rhs.base());
        }

        template< class Iterator1, class Iterator2 >
        bool operator>=( const vector_reverse_iterator<Iterator1>& lhs, const vector_reverse_iterator<Iterator2>& rhs )
        {
            return(lhs.base() <= rhs.base());
        }

        // operateurs+
        template< class Iter >
        vector_reverse_iterator<Iter> operator+(typename vector_reverse_iterator<Iter>::difference_type n, const vector_reverse_iterator<Iter>& it)
        {
            return(vector_reverse_iterator<Iter>(it.base() - n));
        }

        // operateurs-
        template< class Iterator1, class Iterator2 >
        typename vector_reverse_iterator<Iterator1>::difference_type operator-( const vector_reverse_iterator<Iterator1>& lhs, const vector_reverse_iterator<Iterator2>& rhs)
        {
            return (rhs.base() - lhs.base());
        }
}
#endif