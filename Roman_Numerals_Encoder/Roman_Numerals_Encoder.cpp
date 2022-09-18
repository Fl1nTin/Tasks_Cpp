#include <string>

//Создайте функцию, принимающую положительное целое число в качестве параметра и возвращающую строку,
//содержащую представление этого целого числа римскими цифрами.

std::string solution(int number)
{
    std::string str[]{ "M", "CM", "D","CD", "C","XC","L","XL","X","IX","V","IV","I" };
    int num[]        { 1000, 900, 500, 400, 100, 90,  50, 40,  10,  9,  5,   4,  1 };
    std::string result;

    for (int i = 0; i < 13; i++)
    {
        while (number - num[i] >= 0)
        {
            result += str[i];
            number -= num[i];
        }
    }

    return result;
}