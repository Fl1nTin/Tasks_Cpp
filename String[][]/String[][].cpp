#include <string>

//Вам требуется реализовать оператор[] для класса String.
//Однако оператор должен реализовывать нестандартное поведение - оператор нужно реализовать таким образом, 
//чтобы для объекта *char класса String можно было писать String[i][j] и это выражение возвращало подстроку начинающуюся 
//в позиции i(считая с 0) и заканчивающуюся в позиции j(не включая).

class String {
    size_t size;
    char* str;

    class Proxy
    {
        const String& tempStr;
        int begin;

    public:
        Proxy(const String& str, int begin) : tempStr(str), begin(begin) {}

        String operator[](int index)const
        {
            return String(tempStr.str + begin, size_t(index - begin));
        }
    };

public:
    String(const char* str = "")
    {
        size = strlen(str) + 1;
        this->str = new char[size];
        for (size_t i = 0; i < size; i++)
        {
            this->str[i] = str[i];
        }
        this->str[size - 1] = '\0';
    }

    String(char ch, size_t size) : size(size), str(new char[size + 1])
    {
        for (size_t i = 0; i < size; i++)
        {
            str[i] = ch;
        }
        str[size] = '\0';
    }

    String(const char* chars, size_t size)
    {
        this->size = size;
        str = new char[size];
        for (size_t i = 0; i < size; i++)
        {
            str[i] = chars[i];
        }
    }

    ~String()
    {
        delete[] str;
    }

    String(const String& other)
    {
        size = other.size;
        str = new char[size + 1];
        for (size_t i = 0; i < size; i++)
        {
            str[i] = other.str[i];
        }
        str[size] = '\0';
    }

    String& operator=(const String& other)
    {
        if (this == &other)
            return *this;

        delete[] str;

        size = other.size;
        str = new char[size];

        for (size_t i = 0; i < size; i++)
        {
            str[i] = other.str[i];
        }

        return *this;
    }

    Proxy operator[](int index)const
    {
        return Proxy(*this, index);
    }
};