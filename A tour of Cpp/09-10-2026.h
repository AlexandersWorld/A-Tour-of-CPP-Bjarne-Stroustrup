#pragma once

struct Vector
{
    int sz; // number of elements;
    double* elem; // pointer to elements;
};

class CppTour10092026
{
public:
    
    void f(Vector v, Vector& rv, Vector* pv);
    double read_and_sum(int s);
    void vector_init(Vector& v, int s);
    Vector v; // defined vector structure
};
