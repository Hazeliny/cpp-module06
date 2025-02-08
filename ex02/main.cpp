/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 12:59:51 by linyao            #+#    #+#             */
/*   Updated: 2025/02/08 13:22:27 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BaseABC.hpp"

int main()
{
    srand(time(0));
    Base *b = generate();
    identify(b);
    identify(*b);
    delete b;
    std::cout << "*---------------------------*" << std::endl;

    b = generate();
    identify(b);
    identify(*b);
    delete b;
    std::cout << "*---------------------------*" << std::endl;

    b = generate();
    identify(b);
    identify(*b);
    delete b;
    
    return 0;
}
