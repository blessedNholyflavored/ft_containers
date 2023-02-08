/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:39:22 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/02/08 17:39:24 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft{

template <class T, class Container = ft::vector<T> > 
class stack
{
    public:
    typedef Container container_type; // correspond a ce que je recois ds ma classee soit ici : vector
    typedef typename Container::value_type value_type; 
    typedef typename Container::size_type size_type;
	typedef typename Container::reference reference;
	typedef typename Container::const_reference const_reference;

    private:
    Container c;

    public:

    explicit stack (const container_type& container = container_type()) : c(container) { }
    ~stack() { }

    bool empty() const { return (c.empty()) ;}
    size_type size() const { return (c.size()); }
    value_type& top() {return (c.back()) ;}
    const value_type& top() const { return (c.back()) ;}
    void push (const value_type& val) {return (c.push_back(val)) ; }
    void pop() { return (c.pop_back()) ;}


    
    friend bool operator==(const stack<T, Container> &left, const stack<T, Container> &right) {
        return left.c == right.c;
    }

	friend bool operator!=(const stack<T, Container> &left, const stack<T, Container> &right) {
        return left.c != right.c;
	}
    
    friend bool operator<(const stack<T, Container> &left, const stack<T, Container> &right) {
        return left.c < right.c;
	}

    friend bool operator>(const stack<T, Container> &left, const stack<T, Container> &right) {
        return left.c > right.c;
	}

    friend bool operator>=(const stack<T, Container> &left, const stack<T, Container> &right) {
        return left.c >= right.c;
	}

    friend bool operator<=(const stack<T, Container> &left, const stack<T, Container> &right) {
        return left.c <= right.c;
	}
};


}

#endif

