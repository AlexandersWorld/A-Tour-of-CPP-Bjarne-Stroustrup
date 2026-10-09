#include "09-10-2026.h"
#include "iostream"

using namespace  std;

void CppTour10092026::f(Vector v, Vector& rv, Vector* pv)
{
    int i1 = v.sz; // access through name
    int i2 = rv.sz; // access through reference
    int i3 = pv->sz; // access through a pointer
}

double CppTour10092026::read_and_sum(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
    Vector v;
    vector_init(v, s); //allocate s elements for v
    for (int i = 0; i!=s; ++i)
        cin >> v.elem[i]; // read into elements
    
    double sum {0};
    for (int i=0; i!=s; ++i)
        sum+=v.elem[i]; // take the sum of the elements
    return sum;
}

void CppTour10092026::vector_init(Vector& v, int s)
{
    v.elem = new double[s]; // allocate an array of s doubles
    v.sz = s;
}
