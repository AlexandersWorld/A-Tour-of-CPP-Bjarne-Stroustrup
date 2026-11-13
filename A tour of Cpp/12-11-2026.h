#pragma once
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>

#include "20-10-2026.h"

using namespace std;
using namespace chrono;
using namespace placeholders;

double cube(double);

auto cube2 = bind(cube, 2);

void f(int, const string&);
auto g = bind(f, 2,_1);

f(2, "hello");
g("hello");

int pow(int, int);
double pow(double, double);

auto pow2 = bind(pow, _1, 2);
auto pow2 = bind((double(*)(double, double))pow,_1,2);

void user(Shape* p)
{
    p->draw();
    auto draw = mem_fn(&Shape::draw);
    draw(p);
}

void draw_all(vector<Shape*>& v)
{
    for_each(v.begin(), v.end(), mem_fn(&Shape::draw));
    
    for_each(v.begin(), v.end(), [](Shape* p) { p->draw(); }); // lambda approach
}

void do_work()
{
    // do something
}

void f()
{
    auto t0 = high_resolution_clock::now();
    do_work();
    auto t1 = high_resolution_clock::now();

    std::cout << duration_cast<milliseconds>(t1-t0).count() << "msec\n";
}

int f1(double);
function<int(double)> fct {f1}; // initialize to f1
int f2(int);

void user2()
{
    fct = [](double d) { return round(d); }; // assign lambda to fct
    fct = f1; // assign function to fct
    fct = f2; // error: incorrect argument type
}

int round1(double x) { return static_cast<int>(floor(x+0.5)); } // conventional 4/5 rounding

function<int(double)> f5; // f can hold anything that can be called with a double and return an int

enum class Round_style { truncate, round };

struct Round // function object carrying a state
{
    Round_style s;
    Round(Round_style ss) : s(ss) {}
    int operator()(double x) const { return static_cast<int>((s==Round_style::round) ? (x+.5) : x); }
};

void t1()
{
    f = round;
    cout << f(7.6) << '\n'; // call through f to the function round
    
    f = Round(Round_style::truncate);
    cout << f(7.6) << '\n'; // call the function object
    
    Round_style style = Round_style::round;
    f = [style](double x) { return static_cast<int>((style==Round_style::round) ? x+.5 : x);};
    
    cout << f(7.6) << '\n'; // call the lambda
    
    vector<double> v {7.6};
    f = Round(Round_style::round);
    std::transform(v.begin(), v.end(), v.begin(), f); // pass algorithm
    
    cout << v[0] << '\n';
}

template<typename C>
using Value_type = typename C::value_type; // C's value type
template<typename C>
using Iterator_type = typename C::iterator; // C's iterator
template<typename Iter>
using Iterator_category = typename std::iterator_traits<Iter>::iterator_category; // Iter's category

template<typename Ran> // for random-access iterators
void sort_helper(Ran beg, Ran end, random_access_iterator_tag) // we can subscript into [beg:end]
{
    sort(beg, end);
}

template<typename For> // for forward iterators
void sort_helper(For beg, For end, forward_iterator_tag) // we can traverse [beg:end)
{
    vector<Value_type<For>> v {beg, end}; // initialize a vector from [beg:end)
    sort(v.begin(), v.end());
    copy(v.begin(), v.end(), beg); // copy the elements back
}

template<typename C>
void sort(C& c)
{
    using Iter = Iterator_type<C>;
    sort_helper(c.begin, c.end(), Iterator_type<Iter>{});
}

bool b1 = is_arithmetic<int>(); // yes, int is an arithmetic type
bool b2 = is_arithmetic<string>(); // no, std::string is not an arithmetic type
bool b3 = is_class<Round>(); // yes, it's a structure therefore a class

template<typename Scalar>
class complex
{
    Scalar re, im;
    
public:
    static_assert(is_arithmetic<Scalar>(), "Sorry, I only support complex of arithmetic types");
};

template<typename T>
constexpr bool Is_arithmetic()
{
    return std::is_arithmetic<T>::value;
}

class CppTour11122026
{
public:
};
