/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:18:27 by linyao            #+#    #+#             */
/*   Updated: 2025/02/07 00:27:37 by linyao           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    *this = src;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &src)
{
    this->_c = src._c;
    this->_i = src._i;
    this->_f = src._f;
    this->_d = src._d;
    this->_impChar = src._impChar;
    this->_impInt = src._impInt;
    return (*this);
}

bool ScalarConverter::isChar(std::string const &s)
{
    if (s.length() == 1) {return true;}
    for (char ch : s)
    {
        if (!isdigit(ch))
        {
            _impChar = true;
            return false;
        }
    }
//    long value = std::stol(s);
    int num;
    s2i(s.c_str(), &num, 0);
    if (num >= 0 && num <= 255)
    {
        _impChar = false;
        return true;
    }
    else
    {
        _impChar = true;
        return false;
    }
}

 bool ScalarConverter::isInt(std::string const &s)
 {
    
 }
 
 bool ScalarConverter::isFloat(std::string const &s)
 {
    
 }
 
 bool ScalarConverter::isDouble(std::string const &s)
 {
    
 }

void ScalarConverter::convC(std::string const &s)
{
    if (s.length() == 1 && !isdigit(s[0]))
    {
        _c = s[0];
        _i = static_cast<int>(_c);
        _f = static_cast<float>(_c);
        _d = static_cast<double>(_c);
    }
    else
    {
        int num;
        s2i(s.c_str(), &num, 0);
        if (num >= 0 && num <= 255)
            _c = static_cast<char>(num);
        else
            _impChar = true;
    }  
}

void ScalarConverter::convI(std::string const &s)
{}

void ScalarConverter::convF(std::string const &s)
{}

void ScalarConverter::convD(std::string const &s)
{
}

void ScalarConverter::convert(std::string const &str)
{
    int i;
    _impChar = false;
    _impInt = false;
    typeOfInput type[4] = {isChar, isInt, isFloat, isDouble};
    typeToConv conv[4] = {ScalarConverter::convC, ScalarConverter::convI, ScalarConverter::convF, ScalarConverter::convD};
    if (!std::string(str).compare("nanf") || !std::string(str).compare("nan"))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return ;
    }
    for (i = 0; i < 4; i++)
    {
        if (type[i](str))
        {
            conv[i](str);
            break ;
        }
    }
    if (i > 3)
        std::cout << "Error: invalid input" << std::endl;
    else
    {
        if (!_impChar && std::isprint(_c))
            std::cout << "char: '" << _c << "'" << std::endl;
        else if (!_impChar)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (!_impInt)
            std::cout << "int: " << _i << std::endl;
        else
            std::cout << "int: impossible" << std::endl;
        std::cout << "float: '" << std::fixed << std::setprecision(4) << _f << "f" << std::endl;
        std::cout << "double: '" << std::fixed << std::setprecision(4) << _d << std::endl;
    }
}

std::string s2i(char const *s, int *i, int base)
{
    char *end;
    long l;
    errno = 0;
    l = strtol(s, &end, base);
    if ((errno == ERANGE && l == std::numeric_limits<long int>::max()) || l > std::numeric_limits<int>::max())
        return ("OVERFLOW");
    if ((errno == ERANGE && l == std::numeric_limits<long int>::min()) || l < std::numeric_limits<int>::min())
        return ("UNDERFLOW");
    if (*s == '\0' || *end != '\0')
        return ("INCONVERTIBLE");
    *i = l;
    return ("OK");
}