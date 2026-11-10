#pragma once
#include <array>
#include <bitset>
#include <iostream>
#include <mutex>
#include <vector>

using namespace std;

mutex m;

void f()
{
    unique_lock<mutex> lck {m}; // acquire the mutex m
    // ... manipulate shared data ...
}

class Y
{
public:
    virtual void do_something();
    Y();
    virtual ~Y();
};

class X : public Y
{
    int my_i;
public:
    X(int i){my_i(i);}
    X();
    virtual void do_something() override;
};
struct Z : public X
{
public:
    virtual void do_something() override;
};

void f(int i, int j) // X* vs. unique_ptr<X>
{
    X* p = new X; // allocate a new X
    unique_ptr<X> sp {new X}; // allocate a new X and give its pointer to unique_ptr
    // ...
    if (i<99) throw Z{}; // may throw an exception
    if (j<77) return; // may return early
    
    p->do_something(); // may throw an exception
    sp->do_something(); // may throw an exception
    // ...
    delete p; // destoy p*
}

unique_ptr<X> make_X(int i)
    // make an X and immediately give it to a unique_ptr
{
    // ...check i, etc. ...
    return unique_ptr<X>{new X{i}};
}

struct  S
{
    int i;
    string s;
    double d;
    S(int inI, string inS, double inD) : i(inI),
        s(inS), d(inD) {}
    
    S();
    ~S();
    // ...
};

template<typename T, typename... Args>
unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>{new T{std::forward<Args>(args)...}};
}

shared_ptr<S> p1 {new S{1,"Anakin Skywalker",4.65}};
auto p2 = make_shared<S>(2, "Vader", 7.62);
auto p3 = std::make_unique<S>(3, "Atlantis", 11.3);

constexpr int element_count {3};

array<int, element_count> a1 {1,2,3};

vector<int> a2 {1,2,3};

void f(int* p, int sz); // C-style interface

void g()
{
    array<int, 10> a;
    f(a, a.size()); // error: no conversion
    f(&a[0], a.size()); // C-Style use
    f(a.data(), a.size()); // C-Style use
    
    auto p = find(a.begin(), a.end(), 777); // C++/STL-style use
}

bitset<9> bs1 {"110001111"};
bitset<9> bs2 {399};

bitset<9> bs3 = ~bs1; // complement: bs3=="001110000"
bitset<9> bs4 = bs1&bs3; // all zeros
bitset<9> bs5 = bs1 << 2; // shift left: bs5 = "000111100"

void binary(int i)
{
    bitset<8*sizeof(int)> b = i; // assume 8-bit byte
    cout << b.to_string() << '\n';
}

void binary2(int i)
{
    bitset<8*sizeof(int)> b = i; // assume 8-bit byte
    cout << b << '\n';
}

class CppTour11092026
{
public:
};
