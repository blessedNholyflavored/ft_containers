/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enableif.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkhamlac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:54:13 by lkhamlac          #+#    #+#             */
/*   Updated: 2023/01/30 13:54:17 by lkhamlac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLEIF_CPP
#define ENABLEIF_CPP

namespace ft{
    template<bool B, class T = void>
    struct enable_if 
    {

    };
 
    template<class T>
    struct enable_if<true, T> 
    { 
        typedef T type; 
    };
}

#endif

/*Si nous souhaitons par exemple qu'une fonction f() 
ne soit utilisable que pour un type T qui 
soit trivialement copiable. */