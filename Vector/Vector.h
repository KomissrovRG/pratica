#pragma once
#ifdef VECTOR_H
#define VECTOR_H __declspec(dllexport)
#else
#define VECTOR_H __declspec(dllimport)
#endif
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>

using namespace std;
namespace Vector
{
    template <class T>
    class Vector
    {
    public:

        typedef T* iterator;

        Vector();
        Vector(unsigned int size);
        Vector(unsigned int size, const T& initial);
        Vector(const Vector<T>& v);
        ~Vector();

        void push_back(const T& value);

        T& operator[](unsigned int index);
        Vector<T>& operator=(const Vector<T>&);

    private:
        unsigned int my_size;
        unsigned int my_capacity;
        T* buffer;
    };
}

