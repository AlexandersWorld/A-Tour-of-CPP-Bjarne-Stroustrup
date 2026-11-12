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

class CppTour11122026
{
public:
};
