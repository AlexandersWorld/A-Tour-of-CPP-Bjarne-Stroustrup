#pragma once
#include <complex>
#include <list>
#include <vector>

#include "20-10-2026.h"
#include "22-10-2026.h"

using namespace std;

template<typename Container, typename Value>
Value sum(const Container& c, Value v)
{
    for (auto x : c)
        v+=x;
    return v;
}

template<typename T>
class Less_than
{
    const T val; // value to compare against
public:
    Less_than(const T& v) : val(v){}
    bool operator()(const T& x) const { return x < val; } // call operator
};

void user(Vector<int>& vi, list<double>& Id, vector<complex<double>>& vc)
{
    int x = sum(vi, 0); // the sum of a vector of ints (add ints)
    double d = sum(vi, 0.0); // the sum of a vector of ints (add doubles)
    double dd = sum(Id, 0.0); // the sum of a list of doubles
    auto z = sum(vc, complex<double>{}); // the sum of a vector of complex<double>
                                                            // the initial value is {0.0,0.0}
}

void fct(int n, const string& s)
{
    Less_than<string> Its {"Bucks"}; // Its(s) will compare s to "Backus" using < (s<"Backus")
    Less_than<int> Iti {42}; // It(i) will compare i to 42 using < (i < 42)
    bool b1 = Iti(n); // true if n<42
    bool b2 = Its(s); // true if s<"Backus"
}

template<typename C, typename P>
int count(const C& c, P pred)
{
    int cnt = 0;
    for (const auto& x : c)
        if (pred(x))
            ++cnt;
    return cnt;
}

void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    cout << "number of values less than " << x
        << ": " << count(vec, Less_than<int>{x})
        << '\n';
    cout << "number of values less than " << s
        << ": " << count(lst, Less_than<string>{s})
        << '\n';
    
    cout << "number of values less than " << x
        << ": " << count(vec, [&](int a) { return a< x; })
        << '\n';
    cout << "number of values less than " << s
        << ": " << count(lst, [&](const string& a) { return a<s; })
        << '\n';
}

template<typename C, typename Oper>
void for_all(C& c, Oper op) // assume that C is a container of pointers
{
    for (auto& x : c)
        op(*x); // pass op() a reference to each element pointed to
}

void user()
{
    vector<unique_ptr<Shape>> v;
    while (cin)
        v.push_back(CppTour10202026::read_shape(cin));
    for_all(v, [](Shape& s) {s.draw(); });
    for_all(v, [](Shape& s) {s.rotate(45); });
}

template<typename C>
using Element_Type = typename C::value_type; // the type of C's elements

template<typename Container>
void algo(Container& c)
{
    Vector<Element_Type<Container>> vec; // keep results here
}

template<typename Key, typename Value>
class Map
{
    
};

template<typename Value>
using String_map = Map<string, Value>;

String_map<int> m; // m is a Map<string, int>

class CppTour10232026
{
public:
};
