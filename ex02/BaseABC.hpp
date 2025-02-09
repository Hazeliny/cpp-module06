/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BaseABC.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:58:29 by linyao            #+#    #+#             */
/*   Updated: 2025/02/09 15:01:42 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
    public:
        virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);
