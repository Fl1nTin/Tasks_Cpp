#include <string>
#include <vector>

//Завершите решение так, чтобы оно разбило строку на пары из двух символов.
//Если строка содержит нечетное количество символов, 
//то отсутствующий второй символ последней пары должен быть заменен символом подчеркивания('_').

std::vector<std::string> solution(const std::string& s)
{
    std::vector<std::string> str;

    for (int i = 0; i < s.size(); i += 2)
    {
        std::string tempStr = s.substr(i, 2);

        if (i == s.size() - 1 % 2 != 0)
            str.push_back(tempStr + "_");
        else
            str.push_back(tempStr);
    }

    return str;
}