#pragma once
#include <mutex>

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

class CppTour11092026
{
public:
};
