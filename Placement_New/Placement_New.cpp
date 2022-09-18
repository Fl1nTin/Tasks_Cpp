#include <iostream>

//При создании шаблонных классов контейнеров разумно стараться минимизировать требования к типам шаблонных параметров.
//Поэтому, реализуйте класс Array не полагаясь на то, что для типа T определен оператор присваивания и конструктор по умолчанию.
//Конструктор копирования у типа T есть.
//Используйте placement new и явный вызов деструктора, чтобы создавать и уничтожать объекты.

template <typename T>
class Array
{
    int size;
    T* arr;

public:
    explicit Array(int size, const T& value = T())
    {
        this->size = size;
        arr = static_cast<T*>(operator new[](size * sizeof(T)));

        for (int i = 0; i < size; i++)
            new (arr + i) T(value);
    }
    Array()
    {
        size = 0;
        arr = nullptr;
    }

    ~Array()
    {
        operatorDelete();
    }

    Array(const Array& a)
    {
        size = a.size;
        arr = static_cast<T*>(operator new[](size * sizeof(T)));

        for (int i = 0; i < size; i++)
            new (arr + i) T(a[i]);
    }

    Array& operator=(const Array& a)
    {
        if (this == &a)
            return *this;

        operatorDelete();

        size = a.size;
        arr = static_cast<T*>(operator new[](size * sizeof(T)));
        for (int i = 0; i < size; i++)
            new (arr + i) T(a[i]);

        return *this;
    }

    int getSize()const
    {
        return size;
    }

    T& operator[](int index)
    {
        return *(arr + index);
    }

    const T& operator[](int index) const
    {
        return *(arr + index);
    }

    void operatorDelete()
    {
        for (int i = 0; i < size; i++)
            arr[i].~T();
        operator delete[](arr);
    }
};