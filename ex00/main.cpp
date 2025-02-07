/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:25:56 by linyao            #+#    #+#             */
/*   Updated: 2025/02/07 16:26:00 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char** av)
{
	if (ac != 2 || av[1][0] == '\0')
	{
		std::cout << "Error: Arguments must not be empty" << std::endl;
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}
