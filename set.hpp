/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:22:43 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/04/07 18:48:32 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <functional>   // std::less
#include <iostream>
#include "pair.hpp"
#include "iterator_traits.hpp"
#include "vector_reverse_iterator.hpp"
#include "vector_iterator.hpp"
#include "lexicographical.hpp"
#include "iterator_traits.hpp"
#include "rbtset.hpp"

namespace ft {
template< class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class set
{

     template <class U, class V>
class rbt_iterator  //: public rbtree
{
  public:
typedef V node_pointer;
  typedef U                                     value_type;
  typedef value_type*                           pointer;
  typedef value_type&                           reference;
  typedef std::ptrdiff_t                        difference_type;
  typedef ft::bidirectional_iterator_tag       iterator_category;



  public:
   rbt_iterator() : _node(NULL), _null(NULL) { }
  rbt_iterator(node_pointer p, node_pointer null = NULL) : _node(p), _null(null) { }
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
   //     if (_node->_value->first == 24)
    //        std::cout << _node->_parent->_parent->_parent->_parent->_parent->_parent->_parent->_parent->_parent << "\n";
        if (_node && _node->_parent == NULL)
        {
            _node = _node->_right;
            while (_node && _node != _null && _node->_left != _null && _node->_left != NULL)
                _node = _node->_left;
            return *this;
        }
        if (_node->_right != _null && _node->_left != _null && !_node->_parent)
            return *this;
        if (_node == NULL)
        {
            if (_node->_parent == 0 || _node->_parent->_left == _node)
                return *this;
        }
        if (_node->_right != NULL && _node->_right != _null)
        {
            _node = _node->_right;
            while (_node->_left != NULL && _node->_left != _null && _node != _null)
                _node = _node->_left;
            return *this;

        }
        else if (_node->_parent && _node == _node->_parent->_left)
            _node = _node->_parent;
        else
        {
            while (_node->_parent && _node == _node->_parent->_right && _node != _null)
                _node = _node->_parent;
            _node = _node->_parent;
            return *this;
        }
        return *this;
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
    private:
      node_pointer               _node;
      node_pointer               _null;


};

    public:
    typedef T   								key_type; //1er parametre
    typedef T 									mapped_type; // deuxieme param
    typedef T 	value_type; // pair ?????????/
    //typedef ft::pair<const key_type, const mapped_type> 	const_value_type; pair ?????????
    typedef Compare 							key_compare; // troisieme param
    typedef Allocator 							allocator_type; //4emeeee

    public:

    /*std::set::value_compare is a function object that compares objects of type std::set::value_type 
    (key-value pairs) by comparing of the first components of the pairs. */
    // en gros c pour savoir, apres comparaison, quel est l'element sera entre en premier entre first et second ds set
    class value_compare 
    {   
        friend class set; // askip faut mettre ca ds la norme iso 
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
            return _comp(x, y);
        }
    };

    private:


	// typedef	typename ft::rbtree<value_type, mapped_type, key_type, key_compare, allocator_type>::template TreeNode<key_type> Node;


    //rebind is for allocating memory for a type that differs from the element type of the container being implemented. 

    public:
    // typedef TreeNode<value_type>* 												        NodePtr;//
	typedef typename ft::rbtreeset<value_type, key_compare, allocator_type>::template TreeNode<value_type>* 		NodePtr;
	typedef typename ft::rbtreeset<value_type, key_compare, allocator_type>::template TreeNode<value_type>   		Node;
	typedef rbtreeset<value_type, key_compare, allocator_type> 		rbtree;
    typedef typename allocator_type::template rebind<Node>::other                       type_allocator;
    typedef typename allocator_type::reference                                          reference;
    typedef typename allocator_type::const_reference                                    const_reference;
    typedef typename allocator_type::pointer                                            pointer;
    typedef typename allocator_type::const_pointer                                      const_pointer;
	typedef std::ptrdiff_t							    	                            difference_type;
	typedef size_t 								                                        size_type;

    //iterator
	typedef rbt_iterator< const value_type, NodePtr> 						            const_iterator;
	typedef const_iterator							                iterator;
    typedef ft::vector_reverse_iterator<iterator>			                            reverse_iterator;
	typedef ft::vector_reverse_iterator<const_iterator>	                                const_reverse_iterator;

    public:
    rbtree         _rbtree;

    private:
    value_compare   _value_compare;
    Compare         _comp;
    type_allocator  _trollalloc;
    allocator_type  _alloc;
    size_t          _size;
	size_t	        _flag;
    NodePtr         _end;


    public :
    // set() {} 
    //explicit set(const Compare& comp = Compare(),const Allocator& = Allocator())
	//explicit set(void) : _rbtree(rbtree()), _value_compare(value_compare()), _comp(key_compare()), _alloc(allocator_type()), _size(0), _flag(0) {} //_trollalloc(type_allocator())
    
explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
    {
        _alloc = alloc;
        _comp = comp;
        _flag = 0;
        _size = 0;
        _end = _rbtree.newnode();

    }

    //explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _value_compare(value_compare()), _comp(key_compare()), _rbtree(rbtree()),  _alloc(alloc) { } // _comp(comp)
    template< class InputIt >
    set( InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = allocator_type()) 
    {
        _comp = comp;
        _alloc = alloc;
        _value_compare = value_compare();
        _size = 0;
        _flag = 0;
        _end = _rbtree.newnode();

       // deleteEndNode(_end);
        insert(first, last);
        /*: Constructs an empty set using the specified comparison object and allocator, and inserts ele-
        ments from the range [first, last).
        Complexity: Linear in N if the range [first, last) is already sorted using comp and otherwise N
        log N, where N is last - first.*/
        setEndNode(_end);
    }
    set( const set& other ) 
    {
        _comp = other._comp;
        _alloc = other._alloc;
        _size = 0;
        _flag = 0;
        _end = _rbtree.newnode();
        //_value_compare = other.value_compare();
        
        *this = other;
    }
    
    void    Mr_Propre(NodePtr node)
    {
        if (!node || node == _rbtree.TNULL)
            return;
        Mr_Propre(node->_right);
        Mr_Propre(node->_left);
        _rbtree.destroyNODE(node);
    }
    
    ~set()
    {
        //clear();
        _rbtree.destroyNODE(_end);
        deleteEndNode(_end);
        Mr_Propre(_rbtree._root);
        _rbtree.destroyNODE(_rbtree.TNULL);
    }

//A set object of the same type (i.e., with the same template parameters, key, T, Compare and Alloc).
// ????????????????????????
    set& operator=( const set& other )
    {
        _alloc = other._alloc;
		_value_compare = other._value_compare;
		_comp = other._comp;
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
            if (!_rbtree.get_size())
                return (iterator(_end, _rbtree.TNULL));
            iterator it(_rbtree.minTree(_rbtree._root), _rbtree.TNULL);
            return it;
				// return (iterator(minimum(_root)));
		}

		const_iterator begin(void) const
		{
            if (!_rbtree.get_size())
                return (const_iterator(_end, _rbtree.TNULL));
			NodePtr tmp = _rbtree.minTree(_rbtree._root);
            const_iterator it(tmp, _rbtree.TNULL);
            return it;
				// return (iterator(minimum(_root)));
		}

		iterator end(void)
		{        
			return iterator(_end, _rbtree.TNULL);
        // le fils droit de la node la plus grande
		}

		const_iterator end(void) const
		{        
				return const_iterator(_end, _rbtree.TNULL);
        // le fils droit de la node la plus grande
		}

		reverse_iterator rbegin() 
        {
            return (reverse_iterator(_end));
        }
		
        const_reverse_iterator rbegin() const 
        {
            return const_reverse_iterator((_end, _rbtree.TNULL));
        }

	    reverse_iterator rend() 
        { 
            return reverse_iterator(_rbtree.minTree(_rbtree._root));
        }

		const_reverse_iterator rend() const 
        { 
			return const_reverse_iterator(_rbtree.minTree(_rbtree._root), _rbtree.TNULL);
        }


// capacity

    size_type size() const
    {
		//std::cout << "ma size ds rbt : "  << std::endl;
        return (_rbtree.get_size());
    }

    size_type max_size() const
    {
        return (_rbtree.getmaxsize()); //get_allocator()); // .max_size());
    }

    bool empty() const
    {
        if (_rbtree.get_size() == 0)
            return true;
        else
            return false;
    }

// 23.3.1.2 element access:
// faut verifier si la cle exist ou pas
   // T& operator[](const key_type& x)
    // return (*((insert(make_pair(x, T()))).first)).second.

    mapped_type& operator[] (const key_type& k) 
    {
    //   ft::pair<iterator, bool> p = insert(ft::make_pair(k, mapped_type()));
    //   return (p.first->second);
        insert(ft::make_pair(k, mapped_type()));
        deleteEndNode(_end);
        NodePtr tmp = _rbtree.searchRetNode(k);
        setEndNode(_end);
        return (tmp->_value->second);
        // return (_rbtree.searchRetNode(k)->_value->second);
    }


    mapped_type& at(const key_type& k) 
    {
      iterator it = find(k);
      if (it == end())
        throw std::out_of_range("ft::set::at");
      return (it->second);
    }
    
    const mapped_type& at(const key_type& k) const 
    {
      const_iterator it = find(k);
      if (it == end())
        throw std::out_of_range("ft::set::at");
      return (it->second);
    }
// // modifiers:


    ft::pair<iterator, bool> insert(const value_type &value) 
    { 
        // NodePtr tmp = _rbtree.test(_rbtree._root);
        // tmp = _rbtree.TNULL; // getNull();
        deleteEndNode(_end);
        if(_rbtree.searchRetNode(value) && _rbtree.get_size())
        {
            iterator it (_rbtree.searchRetNode(value), _rbtree.TNULL);
            setEndNode(_end);
            return (ft::make_pair<iterator, bool>(it, false));
        }
        _rbtree.insertNode(value);
        iterator it (_rbtree.searchRetNode(value), _rbtree.TNULL);
        // tmp = _rbtree.test(_rbtree._root);
        // tmp = _end;
        setEndNode(_end);
        _size++;
        return (ft::make_pair<iterator, bool>(it, true));
    }

    iterator insert(iterator position, const value_type &value)
    {
        (void)position;
        return (insert(value).first);
    }


    template<class InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
        while (first != last)
        {   
            insert(*first);
            first++;
        }
        // for (; first != last; first++)
        // {
        //     insert(*first);
        // }
    }


    void	erase (iterator first, iterator last)
    {
        int f = 0;
        if (first == begin() && last == end())
        {
            clear();
            return ;
        }
        if (last == this->end())
        {
            f = 1;
            last--;
        }
        deleteEndNode(_end);
        if (f == 1)
        {
            while (first != last)
            {
                NodePtr tmp = _rbtree.searchRetNode(((*first)));
                if (!tmp)
                {
                    setEndNode(_end);
                    return;
                }
                _rbtree.deleteNode(_rbtree._root, (*first));
                _size--;
                first++;
                _rbtree.destroyNODE(tmp);
                // _alloc.destroy(tmp->_value);
                // _alloc.deallocate(tmp->_value, 1);
                // _trollalloc.destroy(tmp);
                // _trollalloc.deallocate(tmp, 1);
            }
            NodePtr tmp = _rbtree.searchRetNode(((*first)));
            if (!tmp)
            {
                setEndNode(_end);
                return;
            }
            _rbtree.deleteNode(_rbtree._root, (*first));
            _size--;
            _rbtree.destroyNODE(tmp);
            // _alloc.destroy(tmp->_value);
            // _alloc.deallocate(tmp->_value, 1);
            // _trollalloc.destroy(tmp);
            // _trollalloc.deallocate(tmp, 1);
        }
        else
        {
            last--;
            if (_flag == 1)
                last--;
            NodePtr tmp_first = _rbtree.searchRetNode(((*first)));
            while (last != first)
            {
                NodePtr tmp = _rbtree.searchRetNode(((*last)));
                if (!tmp)
                {
                    setEndNode(_end);
                    return;
                }
                _rbtree.deleteNode(_rbtree._root, (*last));
                --last;
                _size--;
                _rbtree.destroyNODE(tmp);
                //_alloc.destroy(tmp->_value);
                //_alloc.deallocate(tmp->_value, 1);
                // _trollalloc.destroy(tmp);
                // _trollalloc.deallocate(tmp, 1);
            }
            _rbtree.deleteNode(_rbtree._root, *tmp_first->_value);
            _rbtree.destroyNODE(tmp_first);
            //_alloc.destroy(tmp_first->_value);
            //_alloc.deallocate(tmp_first->_value, 1);
            // _trollalloc.destroy(tmp_first);
            // _trollalloc.deallocate(tmp_first, 1);
            _size--;
            _flag = 0;
        }
        setEndNode(_end);
    }

   void	erase(iterator position)
    {
        deleteEndNode(_end);
        if (!_rbtree.searchRetNode((*position)))
        {
            setEndNode(_end);
            return;
        }
        NodePtr tmp = _rbtree.searchRetNode((*position));
        _rbtree.deleteNode(_rbtree._root, _rbtree.searchRetVal((*position)));
        _rbtree.destroyNODE(tmp);
      //  _rbtree.get_allocator().destroy(tmp->_value);
      //  _rbtree.get_allocator().deallocate(tmp->_value, 1);
       // _rbtree.get_alloc().destroy(tmp);
        // _rbtree.get_alloc().deallocate(tmp, 1);
        _size--;
        setEndNode(_end);

        //  _rbtree.deleteNode((*position).first, (*position).second);
        //  _size--;
    }



    // Deletes the element with the key value x from the set, if one exists. Returns 1 if x existed in the set, 0 otherwise.
    size_type erase(const key_type& x)
    {   
        deleteEndNode(_end);
        if (!_rbtree.searchRetNode(x))
        {
            setEndNode(_end);
            return (0);
        }
        NodePtr tmp = _rbtree.searchRetNode(x);
        _rbtree.deleteNode(_rbtree._root, x);
        _rbtree.destroyNODE(tmp);
        // _alloc.destroy(tmp->_value);
        // _alloc.deallocate(tmp->_value, 1);
        // _trollalloc.destroy(tmp);
        // _trollalloc.deallocate(tmp, 1);
        _size--;
        setEndNode(_end);
        return (1);
    }

    // Providing the iterators first and last point to the same set and last is reachable from first, all elements in the range (first, last) will be deleted from the set. Returns an iterator pointing to the element following the last deleted element, or end() if there were no elements after the deleted range.

    void swap(set& other)
    {
		NodePtr tmp_tnull = _rbtree.TNULL;
		key_compare tmp_comp = _comp;
		type_allocator tmp_alloc = _trollalloc;
		allocator_type tmp_alloc1 = _alloc;
		size_type tmp_size = _size;
        rbtree  tmp_tree = _rbtree;
        NodePtr tmp_end = _end;

        _end = other._end;
        _rbtree = other._rbtree;
		this->_trollalloc = other._trollalloc;
		this->_size = other._size;
		this->_comp = other._comp;
		this->_rbtree.TNULL = other._rbtree.TNULL;
		this->_alloc = other._alloc;

        other._end = tmp_end;
        other._rbtree = tmp_tree;
		other._trollalloc = tmp_alloc;
		other._size = tmp_size;
		other._comp = tmp_comp;
		other._rbtree.TNULL = tmp_tnull;
		other._alloc = tmp_alloc1;



	}
    
    void clear()
    {
		// _rbtree.clear();   
                deleteEndNode(_end);
            while (_rbtree.get_size())// && _rbtree.get_size() != 3)
                erase(*_rbtree._root->_value);
            // if (_rbtree.get_size() <= 3)
            // {
            //     if (_rbtree._root->_left)
            //         erase(_rbtree._root->_left->_value->first);
            //     if (_rbtree._root->_right)
            //         erase(_rbtree._root->_right->_value->first);
            //     erase(_rbtree._root->_value->first);
            // }
            _size = 0;	      
    }

// // observers:
  
		key_compare	  key_comp() const { return (this->_comp); }

		value_compare value_comp() const { return (value_compare(this->_value_compare)); }

// 23.3.1.3 set operations:

	iterator find (const key_type& x)
    {
        NodePtr n = _rbtree.searchRetNode(x);
        if (n)
            return (iterator(n));
        return end();
        // if (_rbtree.search(x))
        //     return (iterator(_rbtree.searchRetNode(x), _rbtree.TNULL));
        // else
        //     return end();
    }


    const_iterator find(const key_type& x) const
    {
        NodePtr n = _rbtree.searchRetNode(x);
        if (n)
            return (const_iterator(n, _rbtree.TNULL));
        return end();
    }

    size_type count(const key_type& x) const
    {
        if (find(x) != end())
            return (1);
        return (0);
    }
    
    iterator	lower_bound(const key_type& k)
    {
        iterator first = this->begin();
        iterator last = this->end();

        while (first != last)
        {
            if (!_comp((*first), k))
                break ;
            first++;
        }
        return first;
    }

    const_iterator	lower_bound(const key_type& k) const
    {
        const_iterator first = this->begin();
        const_iterator last = this->end();

        while (first != last)
        {
            if (!_comp((*first), k))
                break ;
            first++;
        }
        return first;
    }

    iterator	upper_bound(const key_type& k)
    {
        iterator first = this->begin();
        iterator last = this->end();

        while (first != last)
        {
            if (_comp(k, (*first)))
            {
                break ;
            }
            first++;
        }
        _flag = 1;
        return first;
    }

    const_iterator	upper_bound(const key_type& k) const
    {
        size_type   len = _rbtree.get_size();
        const_iterator first = this->begin();
        const_iterator last = this->end();
        while (first != last && len)
        {
            if (_comp(k, (*first)))
                break ;
            len--;
            first++;
        }
        //std::cout << "VALUE DANS UPPER: " << k << "        " << (*first).first << "\n";
        return first;
    }
    pair<iterator,iterator>  equal_range(const key_type& x)
    {
    	return ft::pair<iterator, iterator>(lower_bound(x), upper_bound(x));
    }
    
    pair<const_iterator,const_iterator>  equal_range(const key_type& x) const
    {
    	return ft::pair<const_iterator, const_iterator>(lower_bound(x), upper_bound(x));
    }

    //template <class T, class Compare, class Allocator>
    friend void swap(set<T,Compare,Allocator>& x, set<T,Compare,Allocator>& y)
    {
        x.swap(y);
    }



    NodePtr RetEnd(NodePtr node, NodePtr end)
	{
		if (node == 0)
			return (0);
		while (node != _rbtree.TNULL && node && node->_right && node->_right != _rbtree.TNULL && node->_right != end)
			node = node->_right;
		return (node);
	}


	void	deleteEndNode(NodePtr end)
	{

		NodePtr tmp_max = RetEnd(_rbtree._root, end);

		if (tmp_max != 0)
			tmp_max->_right = 0;
	}
	
	void	setEndNode(NodePtr end)
	{
		NodePtr tmp_max = RetEnd(_rbtree._root, end);
		if (tmp_max != 0 && _end)
		{
			tmp_max->_right = end;
			end->_parent = tmp_max;
			end->_right = _rbtree.TNULL;
		}
	}

};


// non membres
template <class T, class Compare, class Allocator>
bool operator==(const set<T,Compare,Allocator>& x, const set<T,Compare,Allocator>& y)
{
    if(x.size() != y.size())
        return false;
    return (ft::equal(x.begin(), x.end(), y.begin()));
}

template <class T, class Compare, class Allocator>
bool operator< (const set<T,Compare,Allocator>& x, const set<T,Compare,Allocator>& y)
{
	return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
}

template <class T, class Compare, class Allocator> 
bool operator!=(const set<T,Compare,Allocator>& x, const set<T,Compare,Allocator>& y)
{
		return !(x == y);
}

template <class T, class Compare, class Allocator>
bool operator> (const set<T,Compare,Allocator>& x, const set<T,Compare,Allocator>& y)
{
		return y < x;
}

template <class T, class Compare, class Allocator>
bool operator>=(const set<T,Compare,Allocator>& x, const set<T,Compare,Allocator>& y)
{
		return !(x < y);
}

template <class T, class Compare, class Allocator>
bool operator<=(const set<T,Compare,Allocator>& x, const set<T,Compare,Allocator>& y)
{
		return !(x > y);
}

    
}



#endif
