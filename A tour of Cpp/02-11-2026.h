#pragma once
#include <vector>
#include <string>
#include <iosfwd>
#include <fstream>

using namespace std;

struct Entry
{
    string name;
    int number;
};

template<typename T>
class Vector
{
    T* elem; // pointer to first element
    T* space; // pointer to first unused (and uninitialized) slot
    T* last; // pointer to last slot
    
public:
    int size(); // number of elements (space-element)
    int capacity(); // number of slots available for elements (last-element)
    
    void reserve(int newsz); // increase capacity to newsz
    
    void push_back(const T& t);    // copy t into Vector
    void push_back(T&& t); // move t into Vector
    
};

template<typename T>
void Vector<T>::push_back(const T& t)
{
    if (capacity()<size()+1) // make sure we have space for t
        reserve(size()==0?8:2*size()); // double the capacity
    new(space) {t}; // initialize *space to t
    ++space;
}

vector<Entry> phone_book = {
    {"David Hume", 123456},
    {"Karl Popper", 234567},
    {"Bertrand Arthur Willian Russell", 345678}
};

class CppTour11202026
{
public:
    void print_book(const vector<Entry>& book);
    
    ostream& operator<<(ostream& os, const Entry& e)
    {
        return os << "{\"" << e.name << "\", " << e.number << "}";
    }
    
};
