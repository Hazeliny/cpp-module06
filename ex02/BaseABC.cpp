/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseABC.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:59:31 by linyao            #+#    #+#             */
/*   Updated: 2025/02/08 13:39:50 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseABC.hpp"

Base::~Base(){}

Base * generate(void)
{
    int randomNum = rand() % 3;
    switch (randomNum)
    {
        case 0:
            return (new A);
        case 1:
            return (new B);
        case 2:
            return (new C);
    }
    return (NULL);
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A*" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B*" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C*" << std::endl;
    else
        std::cout << "Unkown type*" << std::endl;
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A&" <<std::endl;
        return ;
    }
    catch (std::exception &e){}
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B&" <<std::endl;
        return ;
    }
    catch (std::exception &e){}
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C&" <<std::endl;
        return ;
    }
    catch (std::exception &e)
    {
        std::cout << "Unkown type&" <<std::endl;
    }
}
