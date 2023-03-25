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
#include "lexicographical.hpp"
#include "iterator_traits.hpp"
#include "rbt.hpp"

namespace ft {
template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<std::pair<const Key, T> > > 
class map
{

     template <class U, class V>
class rbt_iterator  //: public rbtree
{
  public:
  typedef U                                     value_type;
  typedef value_type*                           pointer;
  typedef value_type&                           reference;
  typedef std::ptrdiff_t                        difference_type;
  typedef std::bidirectional_iterator_tag       iterator_category;


  private:
      typedef V node_pointer;
      node_pointer               _node;

  public:
   rbt_iterator() : _node(NULL) { }
  rbt_iterator(node_pointer p) : _node(p) { }
  rbt_iterator(const rbt_iterator& ref) : _node(ref._node) { }
  ~rbt_iterator() { }

  rbt_iterator& operator=(const rbt_iterator& ref) {
    if (this != &ref) 
    {
      _node = ref._node;
    }
    return (*this);
  }

  node_pointer base() const 
  {
      return (_node);
  }
  
  reference    operator*()  const 
  {
      return (*_node->_value);
  }

  pointer      operator->() const
    { 
        return (_node->_value);
    }


  operator rbt_iterator<const U, V>() const
  {
    return rbt_iterator<const U, V>(_node);
  }


  rbt_iterator& operator++() 
  {
    //node_pointer tmp = NULL;
    if (!_node ) //|| _node == TNULL)
    {
      return (*this);
    }
    if (_node->_right != NULL) //  && _node->_right != getNull())
    {
      //  std::cout << "tets++: " << _node->_right->_value.first << "\n";
      _node = _node->_right;
      while (_node->_left != NULL ) //&& _node->_left != getNull()) //TNULL)
      {
       // std::cout << "pas ici stp\n";
        _node = _node->_left;
      }
      // this->_node = tmp;
      // return(*this);        
    }
    else// if (_node->_parent != NULL)
    {
        node_pointer tmp = _node->_parent;
        while (tmp != NULL && _node == tmp->_right)
        {
          //_node = tmp;
          tmp = tmp->_parent;
        }
        _node = tmp;    
        //return *this;
    }
    return (*this);
  }
  
  rbt_iterator operator++(int) {
    rbt_iterator tmp(*this);
    ++(*this);
    return (tmp);
  }

  rbt_iterator& operator--() 
  {
    node_pointer tmp = NULL;

      if (_node->_left != NULL)
      {
        tmp = _node->_left;
        while (tmp && tmp->_right)
        {
          tmp = tmp->_right;
        }
        this->_node = tmp;
        return(*this);        
      }
      else if (_node->_parent != NULL)
      {
          tmp = _node->_parent;
          while (tmp && _node == tmp->_left)
          {
            _node = tmp;
            tmp = tmp->_parent;
          }
          _node = tmp;
      }
      return (*this);  
  }
  
  rbt_iterator operator--(int) {
    rbt_iterator tmp(*this);
    --(*this);
    return (tmp);
  }


  bool operator==(const rbt_iterator& lhs) {
    return (lhs._node == _node);
  }
  bool operator!=(const rbt_iterator& lhs) {
    return (!(lhs._node == _node));
  }

};

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
     class value_compare 
    {   
        friend class map; // askip faut mettre ca ds la norme iso 
        protected:
            Compare _comp; // le comparateur stocke
           // value_compare(Compare c) : _comp(c) { } // compare deux valeurs de type value_type

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
	typedef rbtree<value_type, key_type, key_compare, type_allocator> 		rbtree;

    typedef TreeNode<value_type> 												node;
	typedef typename rbtree::NodePtr 									        NodePtr;
    //rebind is for allocating memory for a type that differs from the element type of the container being implemented. 

    public:
    typedef value_type&                                     reference;
    typedef const value_type&                               const_reference;
    typedef typename Allocator::pointer                     pointer;
    typedef typename Allocator::const_pointer               const_pointer;
	typedef std::ptrdiff_t							    	difference_type;
	typedef size_t 								            size_type;


    // typedef typename rbtree::iterator                       iterator;
    // typedef typename rbtree::const_iterator                 const_iterator;
    // typedef typename rbtree::reverse_iterator               reverse_iterator;
	// typedef typename rbtree::const_reverse_iterator         const_reverse_iterator;

    //iterator
	typedef rbt_iterator<value_type, NodePtr>							      iterator;
	typedef rbt_iterator< const value_type, NodePtr> 						const_iterator;
    typedef ft::vector_reverse_iterator<iterator>			reverse_iterator;
	typedef ft::vector_reverse_iterator<const_iterator>	const_reverse_iterator;


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
    template< class InputIt >
    map( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) 
    {
        _key_compare = comp;
        _alloc = alloc;
        _value_compare = value_compare();
        _rbtree = rbtree();
        insert(first, last);
        /*: Constructs an empty map using the specified comparison object and allocator, and inserts ele-
        ments from the range [first, last).
        Complexity: Linear in N if the range [first, last) is already sorted using comp and otherwise N
        log N, where N is last - first.*/
    }
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
        if (_rbtree.get_size())
				clear();
		insert(other.begin(), other.end());
        return *this;
    }

    allocator_type get_allocator() const 
    { 
        return (_rbtree.get_allocator());
    }


// iterators:

		// iterator begin() 
        // {
            // return (_rbtree.begin());
        // }

        iterator begin(void)
		{
            iterator it(_rbtree.minTree(_rbtree._root));
            return it;
				// return (iterator(minimum(_root)));
		}

		const_iterator begin(void) const
		{
			NodePtr tmp = _rbtree.minTree(_rbtree._root);
            const_iterator it(tmp);
            return it;
				// return (iterator(minimum(_root)));
		}

		iterator end(void)
		{        
			return iterator(_rbtree.getend());
        // le fils droit de la node la plus grande
		}

		const_iterator end(void) const
		{        
				return const_iterator(_rbtree.getend());
        // le fils droit de la node la plus grande
		}

		reverse_iterator rbegin() 
        {
            return (_rbtree.rbegin());
        }
		
        const_reverse_iterator rbegin() const 
        {
            return _rbtree.rbegin();
        }

	    reverse_iterator rend() 
        { 
            return (_rbtree.rend()); 
        }

		const_reverse_iterator rend() const 
        { 
            return _rbtree.rend();
        }


// capacity

    size_type size() const
    {
        return (_rbtree.get_size());
    }

    size_type max_size() const
    {
        return (_rbtree.getmaxsize()); //get_allocator()); // .max_size());
    }

    bool empty() const
    {
        return (_rbtree.get_size() == 0);
    }

// 23.3.1.2 element access:
// faut verifier si la cle exist ou pas
   // T& operator[](const key_type& x)
    // return (*((insert(make_pair(x, T()))).first)).second.

    mapped_type& operator[] (const key_type& k) 
    {
      ft::pair<iterator, bool> p = insert(ft::make_pair(k, mapped_type()));
      return (p.first->second);
    }


    mapped_type& at(const key_type& k) 
    {
      iterator it = find(k);
      if (it == end())
        throw std::out_of_range("ft::map::at");
      return (it->second);
    }
    
    const mapped_type& at(const key_type& k) const 
    {
      const_iterator it = find(k);
      if (it == end())
        throw std::out_of_range("ft::map::at");
      return (it->second);
    }
// // modifiers:


    ft::pair<iterator, bool> insert(const value_type &value) 
    { 
        // NodePtr tmp = _rbtree.test(_rbtree._root);
        // tmp = _rbtree.TNULL; // getNull();
       _rbtree.deleteEndNode(_rbtree._end);
        _rbtree.insertNode(value);
        iterator it(_rbtree.searchRetNode(value.first));
        // tmp = _rbtree.test(_rbtree._root);
        // tmp = _rbtree._end;
        _rbtree.setEndNode(_rbtree._end);
        return (ft::make_pair<iterator, bool>(it, true));
    }

    iterator insert(iterator position, const_reference value)
    {
        (void)position;
       _rbtree.deleteEndNode(_rbtree._end);
        _rbtree.insertNode(value);
        iterator it(_rbtree.searchRetNode(value.first));
        _rbtree.setEndNode(_rbtree._end);
        return (it);
    }


    template<class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
        for (; first != last; first++)
            insert(*first);
    }
    
  
  
    NodePtr RetEnd(NodePtr node, NodePtr end)
    {
            if (node == 0)
                    return (0);
            while (node != _rbtree.TNULL && node && node->_right && node->_right != _rbtree.TNULL && node->_right != end)
                    node = node->_right;
            return (node);
    }
  
  void    deleteEnd(NodePtr end)
        	{
                	NodePtr tmp_max = RetEnd(_rbtree._root, end);
                	if (tmp_max != 0)
                	        tmp_max->_right = 0;
        	}



   void	erase(iterator position)
    {
        _rbtree.erase(position.base());
    }

    // Deletes the element with the key value x from the map, if one exists. Returns 1 if x existed in the map, 0 otherwise.
    size_type erase(const key_type& x)
    {     
        deleteEnd(_rbtree._end);
        if (!_rbtree.searchRetNode(x))
        {
            _rbtree.setEndNode(_rbtree._end);
            return (0);
        }
        NodePtr tmp = _rbtree.searchRetNode(x);
        _rbtree.deleteNode(_rbtree._root, x);
        _rbtree.get_allocator().destroy(tmp->_value);
        _rbtree.get_allocator().deallocate(tmp->_value, 1);
        // _rbtree.get_alloc().destroy(tmp);
        // _rbtree.get_alloc().deallocate(tmp, 1);
        //_size--;
        _rbtree.setEndNode(_rbtree._end);
        return (1);

    }

    // Providing the iterators first and last point to the same map and last is reachable from first, all elements in the range (first, last) will be deleted from the map. Returns an iterator pointing to the element following the last deleted element, or end() if there were no elements after the deleted range.
    void	erase (iterator first, iterator last)
    {
        iterator	res;
        
        for (; first != last; )
        {
            res = first;
            first++;
            erase(res);
        }
    }

    void swap(map& other)
    {
		std::cout << "dedede" <<std::endl;
        _rbtree.swap(other._rbtree);
    }
    
    void clear()
    {
		_rbtree.clear();         
    }




// // observers:
  
		key_compare	  key_comp() const { return (this->_key_compare); }

		value_compare value_comp() const { return (value_compare(this->_key_compare)); }



// 23.3.1.3 map operations:

	iterator find (const key_type& x)
    {
        NodePtr n = _rbtree.searchRetNode(x);
        if (n)
            return (iterator(n));
        return end();
    }


    const_iterator find(const key_type& x) const
    {
        NodePtr n = _rbtree.searchRetNode(x);
        if (n)
            return (const_iterator(n));
        return end();
    }

    size_type count(const key_type& x) const
    {
        if (find(x) != end())
            return (1);
        return (0);
    }
    
    iterator lower_bound(const key_type& x)
    {
        for (iterator tmp = begin(); tmp != end(); tmp++)
            if (!(key_comp()(tmp->first, x)))
                return tmp;
        return end();
    }
    
    const_iterator lower_bound(const key_type& x) const
    {
          for (const_iterator tmp = begin(); tmp != end(); tmp++)
            if (!(key_comp()(tmp->first, x)))
                return tmp;
        return end();
    }

    iterator upper_bound(const key_type& x)
    {
        for (iterator tmp = begin(); tmp != end(); tmp++)
            if ((key_comp()(x, tmp->first)))
                return tmp;
        return end();
    }
    const_iterator upper_bound(const key_type& x) const
    {
        for (const_iterator tmp = begin(); tmp != end(); tmp++)
            if ((key_comp()(x, tmp->first)))
                return tmp;
        return end();
    }
    pair<iterator,iterator>  equal_range(const key_type& x)
    {
    	return ft::make_pair(lower_bound(x), upper_bound(x));
    }
    
    pair<const_iterator,const_iterator>  equal_range(const key_type& x) const
    {
    	return ft::make_pair(lower_bound(x), upper_bound(x));
    }

    //template <class Key, class T, class Compare, class Allocator>
    friend void swap(map<Key,T,Compare,Allocator>& x, map<Key,T,Compare,Allocator>& y)
    {
        x.swap(y);
    }

};


// non membres
template <class Key, class T, class Compare, class Allocator>
bool operator==(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
{
    if(x.size() != y.size())
        return false;
    return (ft::equal(x.begin(), x.end(), y.begin()));
}

template <class Key, class T, class Compare, class Allocator>
bool operator< (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class Key, class T, class Compare, class Allocator> 
bool operator!=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
{
		return !(x == y);
}

template <class Key, class T, class Compare, class Allocator>
bool operator> (const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
{
		return y < x;
}

template <class Key, class T, class Compare, class Allocator>
bool operator>=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
{
		return !(x < y);
}

template <class Key, class T, class Compare, class Allocator>
bool operator<=(const map<Key,T,Compare,Allocator>& x, const map<Key,T,Compare,Allocator>& y)
{
		return !(x > y);
}

    
}



#endif