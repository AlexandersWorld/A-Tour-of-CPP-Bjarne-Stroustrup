#pragma once

enum Type { str, num };

union Value
{
    char* s;
    int i;
};
struct Entry
{
    char* name;
    Type t;
    //char* s; // use s if t==str
    //int i; // use i if t==num
    Value v;
};

void f(Entry* p)
{
    if (p->t == str)
    {
        cout << p->v.s;
    }
}

class Vector
{
public:
    Vector(int s) : elem { new double[s] }, sz{s} {} // construct a Vector
    double& operator[](int i) { return elem[i]; } // alement access: subscripting
    int size() { return sz; }
private:
    double* elem; // pointer to the elements
    int sz; // the number of elements
};

class CppTour12092026
{
public:
    
private:
    double read_and_sum(int s);
};
