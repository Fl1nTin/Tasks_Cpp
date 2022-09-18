#include <iostream>
#include <string>
#include <algorithm>

//Ваша задача - создать функцию, которая может принимать в качестве аргумента любое целое неотрицательное число
//и возвращать его с цифрами в порядке убывания.
//По сути, нужно переставить цифры так, чтобы получилось максимально возможное число.

uint64_t descendingOrder(uint64_t a)
{
    std::string str = std::to_string(a);
    std::sort(str.rbegin(), str.rend());
    return std::stoull(str);
}