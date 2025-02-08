/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: linyao <linyao@student.42barcelona.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:18:27 by linyao            #+#    #+#             */
/*   Updated: 2025/02/08 01:05:05 by linyao           ###   ########.fr       */
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

char ScalarConverter::_c;
int ScalarConverter::_i;
float ScalarConverter::_f;
double ScalarConverter::_d;
bool ScalarConverter::_impChar;
bool ScalarConverter::_impInt;

bool isChar(std::string const &s)
{
    if (s.length() == 1 && !isdigit(s[0]))
        return true;
    return false;
}

 bool isInt(std::string const &s)
 {
    if (isValidHex(s) || isValidOct(s) || isValidDec(s))
    {
        for (size_t i = 0; i < s.length(); ++i)
        {
            if (s[i] == '.')
                return false;
        }
        return true;
    }
    return false;
 }
 
 bool isFloat(std::string const &s)
 {
    size_t i;
    if (isValidHex(s) || isValidOct(s) || isValidDec(s))
    {
        for (i = 0; i < s.length(); ++i)
        {
            if (s[i] == '.')
                break ;
        }
        if (i < s.length() && (s[s.length() - 1] == 'f' || s[s.length() - 1] == 'F'))
            return true;
        else
            return false;
    }
    return false;
 }
 
 bool isDouble(std::string const &s)
 {
    size_t i;
    if (isValidHex(s) || isValidOct(s) || isValidDec(s))
    {
        for (i = 0; i < s.length(); ++i)
        {
            if (s[i] == '.')
                break ;
        }
        if (i < s.length() && (s[s.length() - 1] == 'f' || s[s.length() - 1] == 'F'))
            return false;
        else if (i < s.length())
            return true;
        else
            return false;
    }
    return false;
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
    else if (isValidHex(s) || isValidOct(s) || isValidDec(s))
    {
        int num;
        double d;
        std::string res = s2i(s.c_str(), &num, &d);
        if (num >= 0 && num <= 255 && res == "OK(int)")
            _c = static_cast<char>(num);
//        else if (res == "OK(int)")
        else
            _impChar = true;
        if (res != "OVERFLOW" && res != "UNDERFLOW" && res != "INCONVERTIBLE")
        {
            _i = num;
            _f = static_cast<float>(d);
            _d = d;
        }
        else
        {
            _impChar = true;
            _impInt = true;
        }
    }
    else
    {
        _impChar = true;
        _impInt = true;
    }
}

void ScalarConverter::convI(std::string const &s)
{
    if (isValidHex(s) || isValidOct(s) || isValidDec(s))
    {
        int num;
        double d;
        std::string res = s2i(s.c_str(), &num, &d);
        if (num >= 0 && num <= 255 && res == "OK(int)")
            _c = static_cast<char>(num);
        else
            _impChar = true;
        if (res != "OVERFLOW" && res != "UNDERFLOW" && res != "INCONVERTIBLE")
        {
            _i = num;
            _f = static_cast<float>(d);
            _d = d;
        }
        else
        {
            _impChar = true;
            _impInt = true;
        }
    }
    else
    {
        _impChar = true;
        _impInt = true;
    }
}

void ScalarConverter::convF(std::string const &s)
{
    if (isValidHex(s) || isValidOct(s) || isValidDec(s))
    {
        int num;
        double d;
        std::string res = s2i(s.c_str(), &num, &d);
        if (num >= 0 && num <= 255 && res == "OK(int)")
            _c = static_cast<char>(num);
        else
            _impChar = true;
        if (res != "OVERFLOW" && res != "UNDERFLOW" && res != "INCONVERTIBLE")
        {
            _i = num;
            _f = static_cast<float>(d);
            _d = d;
        }
        else
        {
            _impChar = true;
            _impInt = true;
        }
    }
    else
    {
        _impChar = true;
        _impInt = true;
    }
}

void ScalarConverter::convD(std::string const &s)
{
    if (isValidHex(s) || isValidOct(s) || isValidDec(s))
    {
        int num;
        double d;
        std::string res = s2i(s.c_str(), &num, &d);
        if (num >= 0 && num <= 255 && res == "OK(int)")
            _c = static_cast<char>(num);
        else
            _impChar = true;
        if (res != "OVERFLOW" && res != "UNDERFLOW" && res != "INCONVERTIBLE")
        {
            _i = num;
            _f = static_cast<float>(d);
            _d = d;
        }
        else
        {
            _impChar = true;
            _impInt = true;
        }
    }
    else
    {
        _impChar = true;
        _impInt = true;
    }
}

void ScalarConverter::convert(std::string const &str)
{
    int i;
    int n;
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
    if (!std::string(str).compare("-inff") || !std::string(str).compare("-inf"))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return ;
    }
    if (!std::string(str).compare("+inff") || !std::string(str).compare("+inf"))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
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
        if (!_impInt)
            std::cout << "float: " << std::fixed << std::setprecision(4) << _f << "f" << std::endl;
        else
            std::cout << "float: " << s2i(str.c_str(), &n, 0) << std::endl;
        if (!_impInt)
            std::cout << "double: " << std::fixed << std::setprecision(4) << _d << std::endl;
        else
            std::cout << "double: " << s2i(str.c_str(), &n, 0) << std::endl;
    }
}

std::string s2i(char const *s, int *i, double *d)
{
    char *end;
    long l;
    errno = 0;
    if (!s || *s == '\0')
        return ("INCONVERTIBLE");
    l = strtol(s, &end, 0);//only for integer in decimal or oct or hex
    std::string str;
    str.assign(s);
    if (*end == '\0' || isValidOct(str) || isValidHex(str))
    {
        if ((errno == ERANGE && l == std::numeric_limits<long int>::max()) || l > std::numeric_limits<int>::max())
            return ("OVERFLOW");
        if ((errno == ERANGE && l == std::numeric_limits<long int>::min()) || l < std::numeric_limits<int>::min())
            return ("UNDERFLOW");
        *i = static_cast<int>(l);
        *d = static_cast<double>(*i);
        return ("OK(int)");
    }
    errno = 0;
    double tmpD = strtod(s, &end);// only for decimal
    if (*end == '\0' || ((*end == 'f' || *end == 'F') && *(end + 1) == '\0'))
    {
        if ((errno == ERANGE && tmpD == std::numeric_limits<long int>::max()) || tmpD > std::numeric_limits<int>::max())
            return ("OVERFLOW");
        if ((errno == ERANGE && tmpD == std::numeric_limits<long int>::min()) || tmpD < std::numeric_limits<int>::min())
            return ("UNDERFLOW");
        *d = tmpD;
        *i = static_cast<int>(tmpD);
        double intPart;
        double fracPart = std::modf(tmpD, &intPart);
        if (fracPart == 0.0)
            return ("OK(int)");
        else
            return ("OK(float/double)");
    }
    return ("INCONVERTIBLE");
}

bool isValidHex(std::string const &str)
{
    if (str.length() < 3)
        return false;
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] != '0' || (str[i + 1] != 'x' && str[i + 1] != 'X'))
        return false;
    i += 2;
    bool hasDecimalPoint = false;
    if (!std::isxdigit(str[i]))
            return false;
    i++;
    for (; i < str.length(); ++i)
    {
        if (std::isxdigit(str[i]))
            continue ;
        else if (str[i] == '.' && !hasDecimalPoint && i < str.length() - 1)
            hasDecimalPoint = true;
        else
            return false;
    }
    return true;
}

bool isValidOct(std::string const &str)
{
    if (str.length() < 2 || (str[0] != '0' && str[0] != '+' && str[0] != '-'))
        return false;
    bool hasDecimalPoint = false;
    size_t i = 0;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (str[i] != '0')
        return false;
    i++;
    if (str[i] < '0' || str[i] >= '7')
            return false;
    i++;
    for (; i < str.length(); ++i)
    {
        if (str[i] >= '0' && str[i] < '7')
            continue ;
        else if ((str[i] == '.' && !hasDecimalPoint && i < str.length() - 1 && 
                (str[str.length() - 1] != 'f' && str[str.length() - 1] != 'F')) || 
                (str[i] == '.' && !hasDecimalPoint && i < str.length() - 2 &&
                (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')))
            hasDecimalPoint = true;
        else if ((str[i] == 'f' || str[i] == 'F') && i == str.length() - 1)
            return true;
        else
            return false;
    }
    return true;
}

bool isValidDec(std::string const &str)
{
    if (str.empty())
        return false;
    size_t i = 0;
    bool hasSign = false;
    if (str[i] == '+' || str[i] == '-')
    {
        hasSign = true;
        i++;
    }
    bool hasDecimalPoint = false, hasDigits = false;
    for (; i < str.length(); ++i)
    {
        if (std::isdigit(str[i]))
            hasDigits = true;
        else if (str[i] == '.' && !hasDecimalPoint && i < str.length() - 1 && hasDigits)
        {
            if (((hasSign && i > 1) || (!hasSign && i > 0)) && std::isdigit(str[i + 1]))
                hasDecimalPoint = true;
        }
        else if ((str[i] == 'f' || str[i] == 'F') && i == str.length() - 1 && hasDigits)
            return true;
        else
            return false;
    }
    return hasDigits;
}
