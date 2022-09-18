#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

//Реализуйте функцию, которая принимает в качестве аргумента последовательность 
//и возвращает список элементов без элементов с одинаковым значением рядом друг с другом 
//и с сохранением исходного порядка элементов.

template <typename T> std::vector<T> uniqueInOrder(const std::vector<T>& iterable)
{
    std::vector<T> uniqueVec;
    unique_copy(iterable.begin(), iterable.end(), std::back_inserter(uniqueVec));

    return uniqueVec;
}
std::vector<char> uniqueInOrder(const std::string& iterable)
{
    std::vector<char> uniqueCh;
    unique_copy(iterable.begin(), iterable.end(), std::back_inserter(uniqueCh));

    return uniqueCh;
}