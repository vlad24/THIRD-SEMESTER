#pragma once

template <typename W>

//! A template class which can count zero elements in it, and have basic functions for getting and setting

class Array
{
    friend class ArrayTester;
public:
    //! A constructor that creates an array with set size and since creation considers zero to be a zero element
    Array(int size, W zero);
    int countZeroes();
    void set(int position, W value);
    W get(int position) const;
    ~Array();
private:
    W* array;
    W zeroElement;
    int length;
};

template <typename W>
Array<W>::Array(int size, W zero)
{
    array = new W[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = zero;
    }
    zeroElement = zero;
    length = size;
}

template <typename W>
int Array<W>::countZeroes()
{
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        if ((array[i]) == zeroElement)
           counter++;
    }
    return counter;
}

template <typename W>
void Array<W>::set(int position, W value)
{
    if ((position < length) && (position >= 0))
    {
        array[position] = value;
    }
}

template <typename W>
W Array<W>::get(int position) const
{
    if ((position < length) && (position >= 0))
        return array[position];
    else
        return zeroElement;
}

template <typename W>
Array<W>::~Array()
{
    delete[] array;
}
