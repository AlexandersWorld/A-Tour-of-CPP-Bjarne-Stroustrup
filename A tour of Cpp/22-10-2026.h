#pragma once
#include <iostream>
#include <stdexcept>

template<typename  T>
class Vector
{
private:
    T* elem; // elem points to an array of sz elements of type T
    int sz;
    
public:
    explicit Vector(int s); // constructor: establish invariant, acquire resources
    ~Vector() { delete[] elem; } // destructor: release resources
    
    T& operator[](int i);
    const T& operator[](int i) const;
    int size() const { return sz; }
    

};

template<typename T>
Vector<T>::Vector(int s)
{
    if (s < 0)
        throw Negative_size {};
    elem = new T[s];
    sz = s;
}

template <typename T>
const T& Vector<T>::operator[](int i) const
{
    if (i<0 || size()<=i)
        throw std::out_of_range{"Vector::operator[]"};
    return elem[i];
}

template<typename T>
T* begin(Vector<T>& x)
{
    return x.size() ? &x[0] : nullptr; // pointer to first element or null
}

template<typename T>
T* end(Vector<T>& x)
{
    return begin(x)+x.size(); // pointer to one-past-last element
}

void f2(Vector<std::string>& vs) // Vector of some strings
{
    for (auto& s : vs)
        std::cout << s << '\n';
}

class CppTour10222026
{
public:
};
