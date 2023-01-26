/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:43:24 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/01/13 14:43:26 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "vector_iterator.hpp"
#include "vector_reverse_iterator.hpp"
#include <stdexcept>      // std::out_of_range

namespace ft{

template < class T, class Alloc = std::allocator<T> > 
class vector
{
    
    public:
        typedef T                                   value_type;
        typedef Alloc                               allocator_type;
        typedef typename Alloc::reference           reference;
        typedef typename Alloc::const_reference     const_reference;
        typedef typename Alloc::pointer             pointer;
        typedef typename Alloc::const_pointer       const_pointer;        
        typedef ft::vector_iterator<pointer> 		iterator;
		typedef ft::vector_iterator<const_pointer> 	const_iterator;
        typedef ft::vector_reverse_iterator<iterator> 		reverse_iterator;
		typedef ft::vector_reverse_iterator<const_iterator> const_reverse_iterator;
		typedef std::ptrdiff_t 						difference_type;
        typedef std::size_t                              size_type;
    
    private :
        allocator_type _alloc;
        value_type *_arr; // pointer sur le premier block de memoire 
        size_type _size; // nb dobj ds le vecteur
        size_type _capacity; // distance enter first et last? 
    public:
    // constructeurs    
    //default 
    explicit vector(const allocator_type& alloc = allocator_type())
    {
        this->_alloc = alloc; 
        this->_arr = _alloc.allocate(0);
        this->_size = 0;
        this->_capacity = 0;
    }
    //fill
    explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
    {
        this->_size = n;
        this->_capacity = n;
        this->_alloc = alloc;
        this->_arr = _alloc.allocate(n);
        for (size_type i = 0; i < n; i++)
				this->_alloc.construct(&this->_arr[i], val);
    }
    
    //range : template <class InputIterator>         vector (InputIterator first, InputIterator last,                 const allocator_type& alloc = allocator_type());

    // copy
    vector(const vector& copy)
    {
        this->_alloc = copy._alloc;
        this->_size = copy._size;
        this->_capacity = copy._capacity; // isize?
        this->_arr = _alloc.allocate(_capacity); //._arr; // check icic
        for (size_type i = 0; i < _size; i++)
			this->_alloc.construct(&this->_arr[i], copy._arr[i]);    
    }

    // destructeurs
    ~vector()
    {
       // clear();
        for (size_t i = 0; i < _size; i++){
            _alloc.destroy(&_arr[i]);
        }
        if (_arr != NULL)
            _alloc.deallocate(_arr, _capacity);
        // for (size_type i = 0; i < size(); i++)
		// 		_alloc.destroy(&_arr[i]);
		// 	_alloc.deallocate(_arr, capacity());
    }

   


    //operateurs assignations
    vector & operator=( const vector & copy )
    {
        this->_alloc = copy._alloc;
        this->_arr = copy._arr;
        this->_size = copy._size;
        this->_capacity = copy._capacity;
        return (*this);
    }
    

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

    // ELEMENT ACCESSSSSS
    reference operator[](size_type n)
    { 
        return this->_arr[n]; 
    }

    const_reference operator[](size_type n) const 
    {
        return this->_arr[n];
    }
 
    reference front()
    {
        return (this->_arr[0]);
    }

    const_reference front() const
    {
        return (this->_arr[0]);
    }

    reference back() 
    {
        return(this->_arr[_size - 1]);
    }

    const_reference back() const
    {
        return(this->_arr[_size - 1]);
    }
    
    reference at (size_type n)
    {
        if (n >= _size)
            throw std::out_of_range("error out of range");
        return this->_arr[n];
    }
    
    const_reference at (size_type n) const
    {
        if (n >= _size)
            throw std::out_of_range("error out of range");
        return this->_arr[n];
    }

    

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
    // iterators
    iterator begin(void) 
    { 
        return iterator(_arr); 
    }

    iterator end(void) 
    { 
        return iterator(_arr + _size);
    }

    const_iterator cbegin(void) const
    { 
        return const_iterator(_arr); 
    }

    const_iterator cend(void) const
    { 
        return const_iterator(_arr + _size); 
    }

    reverse_iterator rbegin(void)
    { 
        return reverse_iterator(end());
    }
	
    reverse_iterator rend(void) 
    { 
        return reverse_iterator(begin());
    }

	const_reverse_iterator rbegin() const 
    {
         return const_reverse_iterator(end());
    }
	
    const_reverse_iterator rend() const 
    {
        return const_reverse_iterator(begin()); 
    }

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//// MODIFIERS
    void clear()
    {
        for (size_t i = 0; i < _size; i++)
            _alloc.destroy(&_arr[i]);
        _size = 0;
    }

    void push_back(const T& x)
	{
		if (_capacity == 0)
			reserve(1);
		else if (_size >= _capacity)
			reserve(_capacity * 2);
		_alloc.construct(&_arr[_size], x);
		_size++;
	}


    //ASSIGN
   
    // template <class InputIterator>  
    //void assign (InputIterator first, InputIterator last)
    // {
        
    // }
    // void assign (size_type n, const value_type& val)
    // {
        
    // }

    //POP BACK
    void pop_back()
    {
			iterator it = end() - 1;
			erase(it);
	}
    //INSERT


    //ERASE
    /*Erases the specified elements from the container.
1) Removes the element at pos.
2) Removes the elements in the range [first, last).
Invalidates iterators and references at or after the point of the erase, including the end() iterator.

The iterator pos must be valid and dereferenceable. Thus the end() iterator (which is valid, but is not dereferenceable) cannot be used as a value for pos.

The iterator first does not need to be dereferenceable if first == last: erasing an empty range is a no-op.

*/
    iterator erase (iterator position)
    	{
		size_type dist = position - begin();
		for (size_type i = dist; i < _size - 1; i++)
		{
			_alloc.destroy(_arr + i);
			_alloc.construct(_arr + i, *(_arr + i + 1));
		}
		_size--;
		_alloc.destroy(_arr + _size - 1);
		return (iterator(_arr + dist));
	}
    
    iterator erase (iterator first, iterator last)   
    {
        while (first != last)
				erase(--last);
			return (last);
    }

    //SWAP
    void swap(vector& x)
    {
        pointer	tmp_arr = x._arr;
        size_t	tmp_size = x._size;
        size_t	capacity = x._capacity;
        Alloc	tmp_alloc = x._alloc;

        x._arr = _arr;
        x._size = _size;
        x._capacity = _capacity;
        x._alloc = _alloc;

        _arr = tmp_arr;
        _size = tmp_size;
        _capacity = capacity;
        _alloc = tmp_alloc;
    }

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

    //SIZE
    size_type size() const
    {
        return this->_size;
    }

    //MAX SIZE
    size_type max_size() const
    {
        return this->_alloc.max_size();
    }

    //CAPACITY
    size_type capacity() const
    {
        return this->_capacity;
    }

    //EMPTY
    bool empty() const
    {
        return (cbegin() == cend());
    }


    //RESIZE --> change le nombre delement dans le vector ac une nouvelle size de notre choix alors que reserve c capacity
    // sachant que soit on resize plus petit que la taille actuel et ca supp les derniers elements
    // soit on resize plus grand et ca fout des 0
    // soit on resize plusgrand avec un chiffre passe en paramentre genre alue type et ca complete ac ce chiffre la au lieu de 0
    void resize (size_type n, value_type val = value_type())
    {
        if (n >size())
        {
            reserve(std::max(_size * 2, n));
            while(_size < n)
            {
                _alloc.construct(&_arr[_size], val);
                _size++;
            }
            _size = n;
        }
        else if (n < size())
			erase(begin() + n, end());
		_size = n;
    }


    //RESERVE
/*
if no reallocations happen or if the type of the elements has either a non-throwing 
move constructor or a copy constructor, there are no changes in the container in case of exception 
(strong guarantee).
Otherwise, the container is guaranteed to end in a valid state (basic guarantee).
The function throws length_error if n is greater than max_size.
*/
    void reserve (size_type n)
    {
        if (n > _alloc.max_size())
            throw std::length_error("n is greater than max_size");
        if (capacity() < n)
        {
            // si n > a capacity, on reallocate en augmentant la capacity to n
            // sinon pas de reallocate et capacity est pas affecte
            vector reserv = *this;
            size_type tmp_size = _size;
            size_type tmp_capacity = _capacity;
            pointer old_arr = _arr;
            clear();
            _capacity = n;
            if (_capacity)
                _arr = _alloc.allocate(_capacity);
            _size = tmp_size;
            for (size_type i = 0; i < _size; i++) {
                _alloc.construct(&_arr[i], reserv[i]);
            }
            _alloc.deallocate(old_arr, tmp_capacity);
        }
    }
};



// non member fonctions
template <class T, class Allocator>
bool operator==(const vector<T,Allocator>& first, const vector<T,Allocator>& last)
{
    if (first.size() != last.size())
        return false;
    for (size_t i = 0; i < first.size(); i++)
    {
        if (first[i] != last[i])
            return false;
    }
    return true;
}

template <class T, class Allocator>
bool operator!=(const vector<T,Allocator>& first,const vector<T,Allocator>& last)
{
    return !(first == last);
}


}

// dans classe vector, il faut creer une classe iterator 
// elle meme aura besoin dune classe iterator_traits qui permet de faire fonctionner
// les iterateurs valu tue, difference, pointer, reference etc...

//conteneurs de sequences: vector qui permet de gerer sa memoire intelligemment
//conteneurs associatifs : map qui fournisse valeurs par leur cle respective (genre un annuaire telephnique : nom correspond a un numero)
// adaptateurs de conteneurs : stacl qui simplifie les conteneurs de sequences

#endif