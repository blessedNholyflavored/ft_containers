/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:18:42 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/02/13 11:18:45 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft{
template <class T1, class T2> 
class pair
{
    public:
    typedef T1 first_type;
    typedef T2 second_type;

    first_type first;
    second_type second;


    //constructeurs!!!!!!!!1
    //default
    pair() : first(), second() { }
    //copy
    template<class U, class V> 
    pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) { }
    //init
    pair (const first_type& a, const second_type& b) : first(a), second(b) { }
    ~pair(void) { }

    //operator=
    pair& operator= (const pair& pr)
    {
        this->first = pr.first;
        this->second = pr.second;
        return (*this);
    }
    // tout le reste c du c++11
};

template <class T1,class T2>
  pair<T1,T2> make_pair (T1 x, T2 y)
  {
    return ( pair<T1,T2>(x,y));
  }


template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first==rhs.first && lhs.second==rhs.second;
    }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    { 
        return !(lhs==rhs); 
    }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
    }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(rhs<lhs);
    }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return rhs<lhs;
    }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return !(lhs<rhs);
    }
}



#endif