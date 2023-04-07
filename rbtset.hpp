/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtset.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:18:49 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/04/07 18:46:50 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTSET_HPP
#define RBTSET_HPP

#include <iostream>
#include <iomanip>      // std::setw
#include "pair.hpp"
#include "vector_reverse_iterator.hpp"

# define reset "\033[00m"

# define italic "\033[3m"
# define bold "\033[1m"
# define underline "\033[4m"

# define white "\033[37m"
# define reed "\033[31m"
# define green "\033[32m"
# define yellow "\033[33m"
# define blue "\033[34m"
#define RED     "\033[31m"      
#define BOLDWHITE   "\033[1m\033[37m"
#define nullptr NULL




//UNE CLASSE NODE avec les valeurs + une classe rbtset qui a la root et le pointeur sur le node 
namespace ft
{
    

template <typename T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
class rbtreeset
{
   		typedef T 					        										value_type;
        typedef Compare             												value_compare;
        typedef Allocator           												allocator_type;
			// typedef V 					          value_type;

    public: 
		template <class V>
		struct TreeNode
		{
			// typedef value_type&			      reference;
			// typedef const value_type&	    const_reference;
			// typedef value_type*			      pointer;
			// typedef const value_type*	    const_pointer;
			 typedef TreeNode<value_type>*	pointer_node;

		TreeNode(value_type *value = value_type()) :  _left(0), _right(0), _parent(0), _colour(1), _value(value) {}
		TreeNode(const T& value) : _value(value._value)
		{
			_colour = value._colour;
			_parent = value._parent;
			_left = value._left;
			_right = value._right;
			_value = value._value;
		}
		
		~TreeNode(void) {}


			pointer_node        _left;
			pointer_node        _right;
			pointer_node        _parent;
			int                 _colour;
			value_type          *_value;

		};
      
        //rebind sinon, probleme d'init de variable entre genre int int et pair 
		typedef std::size_t															size_type;
        typedef TreeNode<value_type>	 											node;
        typedef node* 																NodePtr;
  		typedef typename allocator_type::template rebind<node>::other 				Node_allocator;
		typedef T		Key;
    
        NodePtr _root;
        NodePtr TNULL;

    private:
        value_compare _comp;
        Node_allocator _nodealloc;
        allocator_type _alloc;
        size_t _size;
        size_type _c;
        
//-------------------------------------------------------------------------
// constructeurs
    public:
    rbtreeset() 
    {
        TNULL = newnode();
        TNULL->_colour = 0;
		TNULL->_parent = NULL;
		TNULL->_left = NULL;
		TNULL->_right = NULL;
        _root = newnode();
        _size = 0;
		_c = 0; // pour pas perdre la memoire de root
        _root->_left = TNULL;
        _root->_right = TNULL;
        _root->_colour = 0;
        _root->_parent = NULL;
    }

    ~rbtreeset()    
    {
		//destroyNODE(TNULL);
    }
/////////////////////////////// aller

  
  	size_type get_size(void) const 
    { 
		// std::cout << "ma size ds rbtset : " << _size << std::endl;
    	return (_size);
    }

   
   
		allocator_type get_allocator(void) const { return (_alloc); }

		Node_allocator get_alloc(void) const { return (_nodealloc); }

	
//-------------------------------------------------------------------------
// modifiers


    NodePtr newnode(const value_type &v = value_type())
    {
      NodePtr tmp = _nodealloc.allocate(1);
      value_type	*test;
      test = _alloc.allocate(1);
      _alloc.construct(test, v);
      _nodealloc.construct(tmp, test);
      return tmp;
    }   

  
// ////////////les fonctions du tree
  int search(const T &val) const
		{
			NodePtr current = _root;
			while (current && current != NULL && current != TNULL)
			{
				if (current->_value->first == val.first) 
          return 1;
        if (current->_value->first > val.first)
					current = current->_left;
				else 
					current = current->_right;
			}
			return 0;
		}

Key	searchRetVal(const Key &key) const
	{
		NodePtr tmp = _root;
		while (tmp && tmp != TNULL)
    	{
			if (*tmp->_value == key)
				return *tmp->_value;
			if (*tmp->_value > key)
				tmp = tmp->_left;
			else
                tmp = tmp->_right;
        }
		return (0);
	}

	NodePtr	getRoot(void)
	{
		return _root;
	}

	NodePtr searchRetNode(const Key &key) const
	{
		NodePtr tmp = _root;
		while (tmp != NULL && tmp->_value && tmp != TNULL)
                {
			if (tmp && _comp(*tmp->_value, key))
                               tmp = tmp->_right;
			else if (tmp && _comp(key, *tmp->_value))
				tmp = tmp->_left;
			else
				break ;
                }
		if (tmp && *tmp->_value == key)
			return tmp;
		return (0);
	}

 

	void	leftRotate(NodePtr node)
	{
		 NodePtr tmp;

		 if (!node->_right)
			 node->_right = TNULL;
		 tmp = node->_right;
		 node->_right = tmp->_left;
		 if(tmp->_left != NULL && tmp->_left != TNULL)
		 {
			 tmp->_left->_parent = node;
		 }
		 tmp->_parent = node->_parent;
		 if (node->_parent == NULL)
			 _root = tmp;
		 else if (node == node->_parent->_left)
			 node->_parent->_left = tmp;
		 else
			 node->_parent->_right = tmp;
		 tmp->_left = node;
		 node->_parent = tmp;
	}

  void	rightRotate(NodePtr node)
	{
		NodePtr tmp;


		tmp = node->_left;
		node->_left = tmp->_right;
		if (tmp && tmp->_right != NULL && tmp->_right != TNULL)
		{
			tmp->_right->_parent = node;
		}
		tmp->_parent = node->_parent;
		if (node->_parent == NULL)
		{
			_root = tmp;
		}
		else if (node == node->_parent->_right)
		{
			node->_parent->_right = tmp;
		}
		else
			node->_parent->_left = tmp;
		tmp->_right = node;
		node->_parent = tmp;
	}



     	void	insertionFix(NodePtr newN)
	{
		NodePtr tmp;
		
		while(newN->_parent->_colour == 1)
		{
			if (newN->_parent == newN->_parent->_parent->_left)
			{
				tmp = newN->_parent->_parent->_right;
				if (tmp && tmp->_colour == 1)
				{
					tmp->_colour = 0;
					newN->_parent->_colour = 0;
					newN->_parent->_parent->_colour = 1;
					newN = newN->_parent->_parent;
				}
				else
				{
					if (newN == newN->_parent->_right)
					{
						newN = newN->_parent;
						leftRotate(newN);
					}
					newN->_parent->_colour = 0;
					newN->_parent->_parent->_colour = 1;
					rightRotate(newN->_parent->_parent); 
				}
			}
			else
			{
				tmp = newN->_parent->_parent->_left;
				if (tmp && tmp->_colour == 1)
				{
					tmp->_colour = 0;
					newN->_parent->_colour = 0;
					newN->_parent->_parent->_colour = 1;
					newN = newN->_parent->_parent;
				}
				else
				{
					if (newN == newN->_parent->_left)
					{
						newN = newN->_parent;
						rightRotate(newN);
					}
					newN->_parent->_colour = 0;
					newN->_parent->_parent->_colour = 1;
					leftRotate(newN->_parent->_parent);

				}
			}
			if (newN == _root)
			{
				break ;
			}
		}
		_root->_colour = 0;
	}

void	insertNode(const value_type &node)
	{
		NodePtr newN = newnode(node);
		if (_root)
			_root->_parent = NULL;
		/*newN->key = k;*/
		newN->_parent = NULL;
		newN->_left = NULL;
		newN->_right = NULL;
		newN->_colour = 1;

		NodePtr x = _root;
		NodePtr y = NULL;

		while (x != NULL && x != TNULL)
		{
			y = x;
			if (newN->_value && newN->_value == x->_value && _size > 0)
				return ;
			if (newN->_value && _comp(*newN->_value, *x->_value))
			{
				x = x->_left;
			}
			else
				x = x->_right;
		}
		newN->_parent = y;
		if (_size == 0 || y == NULL)
		   {
			if (_c == 0)
				destroyNODE(_root);
			_c = 1;
			newN->_colour = 0;
			_root = newN;
			_root->_colour = 0;
			_root->_parent = NULL;
		}
		else if (newN->_value && _comp(*newN->_value, *y->_value))
		{
			y->_left = newN;
		}
		else if (newN->_value && _comp(*y->_value, *newN->_value))
		{
			y->_right = newN;
		}
		else
		{
			 y->_right = newN;
			 newN->_left = TNULL;
			 newN->_right = TNULL;
			 newN->_colour = 1;
		}
		_size++;
		if (newN->_parent == NULL)
		{
			return;
		}
		if (newN->_parent->_parent == NULL)
		{
			return;
		}
		insertionFix(newN);
	}
	void	SetCorrect(NodePtr node)
	{
		if (node == NULL || node == TNULL)
			return ;
		if (node->_left && node->_left != TNULL && node->_left->_parent != node)
			std::cout << "SOUCIS A GAUCHE\n";
		if (node->_right && node->_right != TNULL && node->_right->_parent != node)
			std::cout << "SOUCIS A DROITE\n";
		SetCorrect(node->_left);	
		SetCorrect(node->_right);	
	}


    void	deletionFix(NodePtr x)
	{
		 NodePtr tmp;
		 while (x && x != _root && x->_colour == 0)	 
		 {
			 if (x == x->_parent->_left)
			 {
				tmp = x->_parent->_right;
				if (!tmp)
					tmp = TNULL;
				if (tmp && tmp->_colour == 1)
				{
					tmp->_colour = 0;
					x->_parent->_colour = 1;
					leftRotate(x->_parent);
					tmp = x->_parent->_right;
				}
				if (tmp && tmp->_right && tmp->_left && tmp->_left->_colour == 0 && tmp->_right->_colour == 0)
				{
					tmp->_colour = 1;
					x = x->_parent;
				}
				else
				{
					if (tmp && tmp->_right && tmp->_left && tmp->_right->_colour == 0)
					{
						tmp->_left->_colour = 0;
						tmp->_colour = 1;
						rightRotate(tmp);
						tmp = x->_parent->_right;
					}
					tmp->_colour = x->_parent->_colour;
					x->_parent->_colour = 0;
					if (!tmp->_right)
						tmp->_right = TNULL;
					tmp->_right->_colour = 0;
					leftRotate(x->_parent);
					x = _root;
				}
			 }
			else
			{
				tmp = x->_parent->_left;
				if (!tmp)
					tmp = TNULL;
				if (tmp->_colour == 1)
				{
					tmp->_colour = 0;
					x->_parent->_colour = 1;
					rightRotate(x->_parent);
					tmp = x->_parent->_left;
				}
				if (tmp->_left && tmp->_right && tmp->_right->_colour == 0 && tmp->_left->_colour == 0)
				{
					tmp->_colour = 1;
					x = x->_parent;
				}
				else
				{
					if (tmp->_left && tmp->_left->_colour == 0)
					{
						tmp->_right->_colour = 0;
						tmp->_colour = 1;
						leftRotate(tmp);
						tmp = x->_parent->_left;
					}
					tmp->_colour = x->_parent->_colour;
					x->_parent->_colour = 0;
					if (!tmp->_left)
						tmp->_left = TNULL;
					tmp->_left->_colour = 0;
					rightRotate(x->_parent);
					x = _root;
				}
			 }
		 }
		 if (x)
		 	x->_colour = 0;
	}

  
	void	ptrswap(NodePtr  x, NodePtr y)
	{
		if (y == NULL)
		{
			y = TNULL;
		}
		if (x->_parent == NULL)
		{
			_root = y;
		}
		else if (x == x->_parent->_left)
		{
			x->_parent->_left = y;
		}
		else
		{
			x->_parent->_right = y;
		}
		y->_parent = x->_parent;
	}

    NodePtr minTree(NodePtr node)  const
    {
      	if (_size == 0 || node == NULL)
        {
			return (0);
		}
		while (node->_left != NULL && node->_left != TNULL) 
		{
			node = node->_left;
		// std::cout << "test minimum: " << node->_value.first << "\n";
		}
      return node;
    }

	size_type getmaxsize() const
	{
		//	return (std::numeric_limits<size_type>::max() / (sizeof(value_type)));

		return (_nodealloc.max_size());
	}
   


    NodePtr maxTree(NodePtr node) 
    {
      while (node && node != TNULL && node->_right != TNULL)//&& node->_left != TNULL) 
      {
          node = node->_right;
        // std::cout << "test minimum: " << node->_value.first << "\n";
      }
      return node;
    }

    int	deleteNode(NodePtr delN, Key const &key)
	{

	(void)delN;
		NodePtr tmp = TNULL;
		NodePtr x;
		tmp = searchRetNode(key);
		NodePtr y;
		if (tmp && *tmp->_value == key)
		{
			_size--;
			y = tmp;
			int y_color = y->_colour;
			if (tmp->_value == _root->_value && _size == 2 && _root->_left && _root->_right)
			{
				_root = tmp->_left;
				_root->_parent = NULL;
				_root->_left = NULL;
				_root->_right = tmp->_right;
				return (1);
			}
			if (tmp->_parent && (tmp->_left == NULL || tmp->_left == TNULL) && (tmp->_right == NULL || tmp->_right == TNULL))
			{
				if (tmp == tmp->_parent->_left)
					tmp->_parent->_left = NULL;
				else
					tmp->_parent->_right = NULL;
				return 1;
			}
			if (tmp->_left == NULL || tmp->_left == TNULL)
			{
				x = tmp->_right;
				ptrswap(tmp, tmp->_right);
			}
			else if (tmp->_right == NULL || tmp->_right == TNULL)
			{
				x = tmp->_left;
				ptrswap(tmp, tmp->_left);
			}
			else
			{
				y = minTree(tmp->_right);
				y_color = y->_colour;
				x = y;
				if (y->_parent == tmp)
				{
					x->_parent = y;
				}
				else
				{
					ptrswap(y, y->_right);
					y->_right = tmp->_right;
					y->_right->_parent = y;
				}
				ptrswap(tmp, y);
				y->_left = tmp->_left;
				y->_left->_parent = y;
				y->_colour = tmp->_colour;
			}
			if (y_color == 0)
			{
				deletionFix(x);
			}
			return (1);
		}
		else	
		{
			return 0;
		}
	}




	void	setNullNode(NodePtr node)
	{
		if (node && _size > 0)
		{
			if (!node->_left || node->_left == TNULL)
			{
				std::cout << "gauche null: " << node->_value->first << "\n";
				node->_left = TNULL;
			}
			else
				setNullNode(node->_left);
			if (!node->_right || node->_right == TNULL)
			{
				std::cout << "droit null: " << node->_value->first << "\n";
				node->_right = TNULL;
			}
			else
				setNullNode(node->_right);
		}
		return ;
	}


	bool	empty()
	{
		if(get_size())
			return (false);
		return (true);
	}
	


void printHelper(NodePtr root, std::string indent, bool last) {
    if (root != NULL) {
      std::cout << indent;
      if (last) {
        std::cout << "R----";
        indent += "   ";
      } else {
        std::cout << "L----";
        indent += "|  ";
      }

      if (root->_colour)
        std::cout  << RED << root->_value->first  << std::endl;
      else if  (!root->_colour)
        std::cout  << BOLDWHITE << root->_value->first  << std::endl;

      printHelper(root->_left, indent, false);
      printHelper(root->_right, indent, true);
    }
  }


void print_rec(NodePtr tmp, int co = 0)
{

if (tmp && tmp != TNULL)
{
    if (tmp->_colour == 1)
        std::cout << reed;
    std::cout << std::string(co * 2, ' ') << tmp->_value->first << std::endl;
    std::cout << reset;
    print_rec(tmp->_left, co + 1);
    print_rec(tmp->_right, co + 1);
}
else
{
    std::cout << std::string(co * 2, ' ') << "END " << std::endl;
}
}


// void    real_print( node *ptr, int space, ft::rbtreeset<value_type, Key, value_compare, Allocator> test)
// {
//       if (!ptr)// || ptr == test.getNull())
//             return;
//     space += 4;
//     real_print(ptr->_right, space, test);
//     std::cout << (ptr->_colour == 0 ? "\033[90m" : "\033[31m") << std::setw(space) << ptr->_value->first << "\033[0m" << std::endl;
//     // getwchar();
//     real_print(ptr->_left, space, test);
// }


 void printTree() {
    if (_root) {
      printHelper(_root, "", true);
    }
  }

	void	setSize(size_t s)
	{
		_size = s;
	}

  	void	destroyNODE(NodePtr node)
	{
		_alloc.destroy(node->_value);
		_alloc.deallocate(node->_value, 1);
		_nodealloc.destroy(node);
		_nodealloc.deallocate(node, 1);
	}


};
}

#endif
