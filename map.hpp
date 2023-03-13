/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:22:43 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/02/09 16:22:45 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <functional>   // std::less
#include <iostream>
#include "pair.hpp"
#include "iterator_traits.hpp"
#include "vector_reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include "iterator_traits.hpp"
#include "rbt.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > 
class map
{
    public:
    typedef Key 								key_type; //1er parametre
    typedef T 									mapped_type; // deuxieme param
    typedef ft::pair<key_type, mapped_type> 	value_type; // pair ?????????/
    //typedef ft::pair<const key_type, const mapped_type> 	const_value_type; pair ?????????
    typedef Compare 							key_compare; // troisieme param
    typedef Allocator 							allocator_type; //4emeeee

    public:

    /*std::map::value_compare is a function object that compares objects of type std::map::value_type 
    (key-value pairs) by comparing of the first components of the pairs. */
    // en gros c pour savoir, apres comparaison, quel est l'element sera entre en premier entre first et second ds map
     class value_compare : public std::binary_function<value_type, value_type, bool>
    {   
        friend class map; // askip faut mettre ca ds la norme iso 
        protected:
            Compare _comp; // le comparateur stocke
            value_compare(Compare c) : _comp(c) { } // compare deux valeurs de type value_type

        public:
            typedef bool		result_type;
            typedef value_type	first_argument_type;
            typedef value_type	second_argument_type;

        //constructeurs???????
        value_compare() : _comp(Compare()) { }
        ~value_compare(void) { } 


        bool operator()(const value_type& x, const value_type& y) const
        { 
            return _comp(x.first, y.first);
        }
    };

    // typedef node<value_type>												node_type;
	// typedef node<value_type>												*node_ptr;

    private:
    typedef typename allocator_type::template rebind<value_type>::other type_allocator;
	typedef rbtree<value_type, value_compare, type_allocator> 		rbtree;

    typedef TreeNode<value_type> 												node;
	typedef typename rbtree::NodePtr 									        NodePtr;
    //rebind is for allocating memory for a type that differs from the element type of the container being implemented. 

    public:
    typedef value_type&                                     reference;
    typedef const value_type&                               const_reference;
    typedef typename Allocator::pointer                     pointer;
    typedef typename Allocator::const_pointer               const_pointer;
    //typedef typename rbtree::reverse_iterator               reverse_iterator;
	//typedef typename rbtree::const_reverse_iterator         const_reverse_iterator;
    typedef typename rbtree::iterator                       iterator;
    //typedef typename rbtree::const_iterator                 const_iterator;

	typedef std::ptrdiff_t							    	difference_type;
	typedef size_t 								            size_type;


    //   /// This turns a red-black tree into a [multi]map. 
    //   typedef typename _Alloc::template rebind<value_type>::other 
    //     _Pair_alloc_type;
    //   typedef _Rb_tree<key_type, value_type, _Select1st<value_type>,
	// 	       key_compare, _Pair_alloc_type> _Rep_type;
    public:
    rbtree          _rbtree;

    private:
    value_compare   _value_compare;
    key_compare     _key_compare;
    allocator_type  _alloc;

    public :
    // map() {} 
    //explicit map(const Compare& comp = Compare(),const Allocator& = Allocator())
	explicit map(void) : _rbtree(rbtree()), _value_compare(value_compare()), _key_compare(key_compare()), _alloc(allocator_type()) {}
    
    //explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _value_compare(value_compare()), _key_compare(key_compare()), _rbtree(rbtree()),  _alloc(alloc) { } // _comp(comp)
    // template< class InputIt >
    // map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) 
    //{
        /*: Constructs an empty map using the specified comparison object and allocator, and inserts ele-
        ments from the range [first, last).
        Complexity: Linear in N if the range [first, last) is already sorted using comp and otherwise N
        log N, where N is last - first.*/
    // }
    map( const map& other ) 
    {
        *this = other;
    }
    
    ~map() { }


//A map object of the same type (i.e., with the same template parameters, key, T, Compare and Alloc).
// ????????????????????????
    map& operator=( const map& other )
    {
        _alloc = other._alloc;
		_value_compare = other._value_compare;
		_key_compare = other._key_compare;
    }

// iterators:

		iterator begin() 
        {
            return (_rbtree.begin());
        }
		//const_iterator begin() const {return rbtree.begin();}

		iterator end() {return (_rbtree.end());}
	//	const_iterator end() const {return _tree.end();}

	//	reverse_iterator rbegin() { return (_tree.rbegin()); }
		//const_reverse_iterator rbegin() const { return _tree.rbegin(); }

	//	reverse_iterator rend() { return (_tree.rend()); }
	//	const_reverse_iterator rend() const { return _tree.rend(); }

// 23.3.1.2 element access:
// faut verifier si la cle exist ou pas
// T& operator[](const key_type& x)
    // return (*((insert(make_pair(x, T()))).first)).second.


// // modifiers:


    ft::pair<iterator, bool> insert(const value_type &value) 
    { 
        NodePtr tmp = _rbtree.test(_rbtree.getroot());
        tmp = _rbtree.getNull();
        _rbtree.insert(value);
        iterator it(_rbtree.search(value));
        tmp = _rbtree.test(_rbtree.getroot());
        tmp = _rbtree._end;
        return (ft::make_pair<iterator, bool>(it, true));
    }

    // iterator insert(iterator position, const_reference value)
	// 	{
	// 		(void)position;
	// 		_rbtree.insert(value);
	// 		return (iterator(_rbtree.search(value)));
	// 	}

    // iterator insert(iterator position, const value_type& x);
    // template <class InputIterator>
    // void insert(InputIterator first, InputIterator last);
    // void erase(iterator position);
    // size_type erase(const key_type& x);
    // void erase(iterator first, iterator last);
    // void swap(map<Key,T,Compare,Allocator>&);
    // void clear();


// // observers:
    // key_compare key_comp() const;
    // value_compare value_comp() const

// 23.3.1.3 map operations:
    // iterator find(const key_type& x);

	iterator find (const key_type& x)
    {
        NodePtr n = _rbtree.search(ft::make_pair(x, mapped_type()));
        if (n)
            return (iterator(n));
        return end();
    }


    // const_iterator find(const key_type& x) const;
    // size_type count(const key_type& x) const;
    // iterator lower_bound(const key_type& x);
    // const_iterator lower_bound(const key_type& x) const;
    // iterator upper_bound(const key_type& x);
    // const_iterator upper_bound(const key_type& x) const;
    // pair<iterator,iterator>  equal_range(const key_type& x);
    // pair<const_iterator,const_iterator>  equal_range(const key_type& x) const;
};
// template <class Key, class T, class Compare, class Allocator>
// bool operator==(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator< (const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator!=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator> (const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator>=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// template <class Key, class T, class Compare, class Allocator>
// bool operator<=(const map<Key,T,Compare,Allocator>& x,
// const map<Key,T,Compare,Allocator>& y);
// 
// specialized algorithms:
    template <class Key, class T, class Compare, class Allocator>
    void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y)
    {
        x.swap(y);
    }
}



#endif