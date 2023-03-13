/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbt.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:18:49 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/02/13 16:18:50 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBT_HPP
#define RBT_HPP

#include <iostream>
#include <iomanip>      // std::setw
// #include "rbt_iterator.hpp"
// #include "map.hpp"
#include "pair.hpp"


#define RED     "\033[31m"      
#define BOLDWHITE   "\033[1m\033[37m"
#define nullptr NULL



// typedef enum colour 
// { 
//     red, 
//     black, 
// } t_colour;

//UNE CLASSE NODE avec les valeurs + une classe rbt qui a la root et le pointeur sur le node 
namespace ft
{
    
template <class T>
class TreeNode 
{
    public:
    typedef T 					          value_type;
    typedef value_type&			      reference;
    typedef const value_type&	    const_reference;
    typedef value_type*			      pointer;
    typedef const value_type*	    const_pointer;
    typedef TreeNode<value_type>*	pointer_node;

  TreeNode(void) : _left(NULL), _right(NULL), _parent(NULL), _colour(0), _value() {}
  TreeNode(const T& value) : _left(NULL), _right(NULL), _parent(NULL), _colour(1),  _value(value) {}
  ~TreeNode(void) {}


TreeNode& operator=(const TreeNode& rhs)
  {
    if (this == &rhs)
      return (*this);
    this->_left = rhs._left;
    this->_right = rhs._right;
    this->_parent = rhs._parent;
    this->_colour = rhs._colour;
    this->_value = rhs._value;
    return *this;
  }

    pointer_node        _left;
    pointer_node        _right;
    pointer_node        _parent;
    int                 _colour;
    value_type           _value;

};

template <class T, class Compare, class Allocator>
  class rbtree;
  
  template <typename T>
  class rbt_iterator 
  {
    public:
    typedef T                                     value_type;
    typedef value_type*                           pointer;
    typedef value_type&                           reference;
    typedef std::ptrdiff_t                        difference_type;
    typedef std::bidirectional_iterator_tag       iterator_category;


    private:
        typedef ft::TreeNode<T>*  node_pointer;
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
        return (_node->_value);
    }

    pointer      operator->() const
      { 
          return (&operator*());
      }
    

    rbt_iterator& operator++() 
    {
      //node_pointer tmp = NULL;
      if (!_node)
        return (*this);
      if (_node->_right != NULL && _node->_right != getNull())
      {
        _node = _node->_right;
        while (_node->_left != NULL) //TNULL)
        {
          _node = _node->_left;
        }
        //this->_node = tmp;
        //return(*this);        
      }
      else //if (_node->_parent != NULL)
      {
          node_pointer tmp = _node->_parent;
          while (tmp != NULL && _node == tmp->_right)
          {
            _node = tmp;
            tmp = tmp->_parent;
          }
          _node = tmp;
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


// template <class T>
template <class T, class Compare, class Allocator = std::allocator<TreeNode<T> > >
class rbtree
{
    public: 
        typedef T 					        value_type;
        typedef value_type&			    reference;
        typedef const value_type&	  const_reference;
        typedef Compare             value_compare;

  			typedef typename Allocator::template rebind<TreeNode<value_type> >::other allocator_type;
        //sinon, probleme d'init de variable entre genre int int et pair 
			  typedef std::size_t								size_type;

        //typedef Allocator           allocator_type;
        typedef typename allocator_type::pointer			pointer;
        typedef typename allocator_type::const_pointer			const_pointer;

        typedef ft::TreeNode<value_type> node;
        typedef node* NodePtr;

        //iterator
	      typedef rbt_iterator<T>							iterator;
			// typedef constIterTree<T> 						const_iterator;
			// typedef ft::reverse_iterator<iterator>			reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
    
    public:
        NodePtr _end;

    private:
        NodePtr TNULL;
        value_compare _comp;
        NodePtr _root;
        allocator_type _alloc;
        size_type _size;
//-------------------------------------------------------------------------
// constructeurs
    public:
    rbtree() 
    {
        _alloc = Allocator();
        TNULL = newnode();

        // TNULL->_colour = 0;
        _comp = Compare();
        _alloc = Allocator();
        _size = 0;
        _root = TNULL;
        _end = newnode();
        _root->_left = TNULL;
        _root->_right = TNULL;
    }

    rbtree(rbtree const &copy)
    {
      *this = copy;
    }

    // rbtree	&operator=(const rbtree &rhs)
		// 	{
		// 		(void)rhs;
		// 		return (*this);
		// 	}

    NodePtr newnode()
    {
      NodePtr ptr = _alloc.allocate(1);
      _alloc.construct(ptr, node());
      return (ptr);
    }

      NodePtr newnode(NodePtr p)
			{
				NodePtr n = _alloc.allocate(1);
				_alloc.construct(n, p);
				return (n);
			}

  	size_type get_size(void) const 
    { 
      return (_size);
    }

    NodePtr getroot(void) const 
    { 
        return (_root);
    }
    NodePtr getNull(void) const 
    { 
        return (TNULL);
    }

    ~rbtree()    
    {
       clear(_root);
    }
//-------------------------------------------------------------------------
// modifiers

    void clear(NodePtr root)
    {
        if (root == NULL || root == TNULL)
        {
            return;
        }
        clear(root->_left);
        clear(root->_right);
       // deletetest(root);
        //   deleteNodeHelper(root, _value);
        _root = NULL;
    }

    // void deletetest(NodePtr n)
    // {
    //     _alloc.destr
    // }

      iterator begin(void)
			{
				iterator it = minimum(_root);
				return it;
			}

      iterator end(void)
			{        
				return iterator(_end);
        // le fils droit de la node la plus grande
			}

    NodePtr test(NodePtr node)
    {
      while(node && node != TNULL && node->_right != TNULL)
      {
        node = node->_right;
      }
      return (node);
    }

  
// les fonctions du tree
  NodePtr search(value_type val)
		{
			NodePtr current = _root;
			while (current != NULL)
			{
				if (_comp(val, current->_value))
					current = current->_left;
				else if (_comp(current->_value, val))
					current = current->_right;
				else
					return current;
			}
			return NULL;
		}



  void leftRotate( NodePtr x ) 
  {
    NodePtr y;
    y = x->_right;
    x->_right = y->_left;
    if ( y->_left != NULL )
        y->_left->_parent = x;
    y->_parent = x->_parent;
    if ( x->_parent == NULL ) 
      _root = y;
    else
        if ( x == (x->_parent)->_left )
            x->_parent->_left = y;
        else
            x->_parent->_right = y;
    y->_left = x;
    x->_parent = y;
  }

  void rightRotate(NodePtr x) {
    NodePtr y = x->_left;
    
    x->_left = y->_right;
    if (y->_right != NULL) {
      y->_right->_parent = x;
    }
    y->_parent = x->_parent;
    if (x->_parent == NULL) {
      this->_root = y;
    } else if (x == x->_parent->_right) {
      x->_parent->_right = y;
    } else {
      x->_parent->_left = y;
    }
    y->_right = x;
    x->_parent = y;
  }

    void deleteFix(NodePtr x) {
    NodePtr s;
    while (x != _root && x->_colour == 0) {
      if (x == x->_parent->_left) {
        s = x->_parent->_right;
        if (s->_colour == 1) {
          s->_colour = 0;
          x->_parent->_colour = 1;
          leftRotate(x->_parent);
          s = x->_parent->_right;
        }

        if (s->_left->_colour == 0 && s->_right->_colour == 0) {
          s->_colour = 1;
          x = x->_parent;
        } else {
          if (s->_right->_colour == 0) {
            s->_left->_colour = 0;
            s->_colour = 1;
            rightRotate(s);
            s = x->_parent->_right;
          }

          s->_colour = x->_parent->_colour;
          x->_parent->_colour = 0;
          s->_right->_colour = 0;
          leftRotate(x->_parent);
          x = _root;
        }
      } else {
        s = x->_parent->_left;
        if (s->_colour == 1) {
          s->_colour = 0;
          x->_parent->_colour = 1;
          rightRotate(x->_parent);
          s = x->_parent->_left;
        }

        if (s->_right->_colour == 0 && s->_right->_colour == 0) {
          s->_colour = 1;
          x = x->_parent;
        } else {
          if (s->_left->_colour == 0) {
            s->_right->_colour = 0;
            s->_colour = 1;
            leftRotate(s);
            s = x->_parent->_left;
          }

          s->_colour = x->_parent->_colour;
          x->_parent->_colour = 0;
          s->_left->_colour = 0;
          rightRotate(x->_parent);
          x = _root;
        }
      }
    }
    x->_colour = 0;
  }

    NodePtr minimum(NodePtr node) 
    {
      if (_size == 0)
        return TNULL;
      while (node->_left != NULL) 
      {
          node = node->_left;
      }
      return node;
    }

  void rbTransplant(NodePtr u, NodePtr v) {
    if (u->_parent == NULL) {
      _root = v;
    } else if (u == u->_parent->_left) {
      u->_parent->_left = v;
    } else {
      u->_parent->_right = v;
    }
    if (v != NULL)
    v->_parent = u->_parent;

  }


  void deleteNodeHelper(NodePtr node, int key) {
    NodePtr z = TNULL;
    NodePtr x, y;
    while (node != TNULL) {
      if (node->_value.first == key) {
        z = node;
      }

      if (node->_value.first < key) {
        node = node->_right;
      } else {
        node = node->_left;
      }
    }


    if (z == TNULL) {
      std::cout << "Key not found in the tree" << std::endl;
      return;
    }
    y = z;
    int y_original_color = y->_colour;
    if (z->_left == TNULL) {
      x = z->_right;
      rbTransplant(z, z->_right);
    } else if (z->_right == TNULL) {
      x = z->_left;
      rbTransplant(z, z->_left);
    } else {
      y = minimum(z->_right);
      y_original_color = y->_colour;
      x = y->_right;
      if (y->_parent == z) {
        x->_parent = y;
      } else {
        rbTransplant(y, y->_right);
        y->_right = z->_right;
        y->_right->_parent = y;
      }

      rbTransplant(z, y);
      y->_left = z->_left;
      y->_left->_parent = y;
      y->_colour = z->_colour;
    }
    delete z;
    if (y_original_color == 0) {
      deleteFix(x);
    }
  }


  // For balancing the tree after insertion
  void insertFix(NodePtr k) {
    NodePtr u;
    while (k->_parent->_colour == 1) {
      if (k->_parent == k->_parent->_parent->_right) {
        u = k->_parent->_parent->_left;
        if (u->_colour == 1) {
          u->_colour = 0;
          k->_parent->_colour = 0;
          k->_parent->_parent->_colour = 1;
          k = k->_parent->_parent;
        } else {
          if (k == k->_parent->_left) {
            k = k->_parent;
            rightRotate(k);
          }
          k->_parent->_colour = 0;
          k->_parent->_parent->_colour = 1;
          leftRotate(k->_parent->_parent);
        }
      } else {
        u = k->_parent->_parent->_right;

        if (u->_colour == 1) {
          u->_colour = 0;
          k->_parent->_colour = 0;
          k->_parent->_parent->_colour = 1;
          k = k->_parent->_parent;
        } else {
          if (k == k->_parent->_right) {
            k = k->_parent;
            leftRotate(k);
          }
          k->_parent->_colour = 0;
          k->_parent->_parent->_colour = 1;
          rightRotate(k->_parent->_parent);
        }
      }
      if (k == _root) {
        break;
      }
    }
    _root->_colour = 0;
  }


 NodePtr _create_node(const value_type &value) {
        pointer cpy = _alloc.allocate(1);
        _alloc.construct(cpy, value_type(value));
        // NodePtr n = _alloc_node.allocate(1);
        // _alloc_node.construct(n, node(cpy, NULL, NULL, NULL));
        _size++;
        return (cpy);
    }


  void insert(value_type key) 
  {
    NodePtr node = newnode();
    node->_parent = nullptr;
    node->_value = key;
    node->_left = TNULL;
    node->_right = TNULL;
    node->_colour = 1;

    NodePtr y = nullptr;
    NodePtr x = this->_root;

    while (x != TNULL) {
      y = x;
      if (node->_value.first < x->_value.first) {
        x = x->_left;
      } else {
        x = x->_right;
      }
    }

    node->_parent = y;
    if (y == nullptr) {

      _root = node;
    } else if (node->_value.first < y->_value.first) {
      y->_left = node;
    } else {
      y->_right = node;
    }

    if (node->_parent == nullptr) {
      node->_colour = 0;
      return;
    }

    if (node->_parent->_parent == nullptr) {
      return;
    }

    insertFix(node);
  }




void printHelper(NodePtr root, std::string indent, bool last) {
    if (root != TNULL) {
      std::cout << indent;
      if (last) {
        std::cout << "R----";
        indent += "   ";
      } else {
        std::cout << "L----";
        indent += "|  ";
      }

    //   std::string sColor = root->_colour ? "RED" : "BLACK";
    //   sColor = "RED" ? RED : BOLDWHITE;
    //   std::cout  << root->_value << "(" << sColor << ")" << std::endl;
      if (root->_colour)
        std::cout  << RED << root->_value.first  << std::endl;
      else if  (!root->_colour)
        std::cout  << BOLDWHITE << root->_value.first  << std::endl;

      printHelper(root->_left, indent, false);
      printHelper(root->_right, indent, true);
    }
  }

 void printTree() {
    if (_root) {
      printHelper(this->_root, "", true);
    }
  }


// void    real_print(ft::TreeNode<int> *ptr, int space, ft::rbtree<int> test)
// {
//       if (!ptr || ptr == test.getNull())
//             return;
//     space += 4;
//     real_print(ptr->_right, space, test);
//     std::cout
//             << (ptr->_colour == 0 ? "\033[90m" : "\033[31m") << std::setw(space)
//             << ptr->_value << "\033[0m" << std::endl;
//     // getwchar();
//     real_print(ptr->_left, space, test);
// }

//     void deleteNode (int i)
//     {
//         deleteNodeHelper(this->_root, i);
//     }
};


}

#endif