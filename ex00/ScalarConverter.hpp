/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:11:58 by linyao            #+#    #+#             */
/*   Updated: 2025/02/07 00:25:00 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <cctype>

class ScalarConverter
{
    private:
        static char _c;
        static int _i;
        static float _f;
        static double _d;
        static bool _impChar;
        static bool _impInt;
        
        ScalarConverter();
        ScalarConverter(ScalarConverter const &src);
        ScalarConverter &operator=(ScalarConverter const &src);
        ~ScalarConverter();

        static void convC(std::string const &s);
        static void convI(std::string const &s);
        static void convF(std::string const &s);
        static void convD(std::string const &s);

        static bool isChar(std::string const &s);
        static bool isInt(std::string const &s);
        static bool isFloat(std::string const &s);
        static bool isDouble(std::string const &s);
        
    public:
        static void convert(std::string const &str);
};

std::string s2i(char const *s, int *i, int base);
void printType(int i);

typedef bool (*typeOfInput)(std::string const &s);
typedef void (*typeToConv)(std::string const &s);
