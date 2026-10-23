#pragma once
#include <complex>
#include <list>
#include <vector>

#include "22-10-2026.h"

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

void user(Vector<int>& vi, std::list<double>& Id, std::vector<std::complex<double>>& vc)
{
    int x = sum(vi, 0); // the sum of a vector of ints (add ints)
    double d = sum(vi, 0.0); // the sum of a vector of ints (add doubles)
    double dd = sum(Id, 0.0); // the sum of a list of doubles
    auto z = sum(vc, std::complex<double>{}); // the sum of a vector of complex<double>
                                                            // the initial value is {0.0,0.0}
}

void fct(int n, const std::string& s)
{
    Less_than<std::string> Its {"Bucks"}; // Its(s) will compare s to "Backus" using < (s<"Backus")
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

void f(const Vector<int>& vec, const std::list<std::string>& lst, int x, const std::string& s)
{
    std::cout << "number of values less than " << x
        << ": " << count(vec, Less_than<int>{x})
        << '\n';
    std::cout << "number of values less than " << s
        << ": " << count(lst, Less_than<std::string>{s})
        << '\n';
}

class CppTour10232026
{
public:
};
