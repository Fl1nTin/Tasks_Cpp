#include <string>

//Завершите функцию, которая принимает строковый параметр и переворачивает каждое слово в строке.
//Все пробелы в строке должны быть сохранены.

std::string reverse_words(std::string str)
{
    int letter = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i + 1] == ' ') 
        {
            int k = i;

            while (k >= letter)
            {
                std::swap(str[letter++], str[k--]);
            }

            letter = i + 2;
        }
    }

    return str;
}