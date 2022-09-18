#include <string>

//Получив строку, заменить каждую букву на ее позицию в алфавите.
//Если что-то в тексте не является буквой, игнорируйте это и не возвращайте.

std::string alphabet_position(const std::string& text)
{
    std::string str{ " abcdefghijklmnopqrstuvwxyz" };
    std::string result = "";

    for (char c : text)
    {
        c = tolower(c);
        for (size_t k = 1; k < str.length(); k++)
        {
            if (c == str[k])
            {
                if (result != "")
                    result += " ";

                result += std::to_string(str.find(c));
                break;
            }
        }
    }

    return result;
}