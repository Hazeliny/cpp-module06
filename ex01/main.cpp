/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 11:48:51 by linyao            #+#    #+#             */
/*   Updated: 2025/02/08 12:30:18 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
    Data dt;
    dt.commodity = "computer";
    dt.price = 3500;
    Data *dtptr;
    uintptr_t pint;
    
    std::cout << "Original dt: " << dt.commodity << " & " << dt.price << std::endl;
    std::cout << "Original Data* of dt is " << &dt << std::endl << std::endl;
    
    std::cout << "Serialize &dt into uintptr_t..." << std::endl << std::endl;
    pint = Serializer::serialize(&dt);
    std::cout << "Serialized uintptr_t of dt: " << pint << std::endl << std::endl;
    
    std::cout << "Then deserialize uintptr_t into Data*..." << std::endl << std::endl;
    
    dtptr = Serializer::deserialize(pint);
    std::cout << "Deserialized Data* of uintptr_t: " << dtptr << std::endl << std::endl;
    std::cout << "Serialized and deserialized dtptr: " << dtptr->commodity << " & " << dtptr->price << std::endl;
}
