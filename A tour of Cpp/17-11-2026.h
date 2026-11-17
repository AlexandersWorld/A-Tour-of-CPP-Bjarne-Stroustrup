#pragma once
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <valarray>
#include <vector>

using namespace std;

void f(valarray<double>& a1, valarray<double>& a2)
{
    valarray<double> a = a1*3.14+a2/a1; // numeric array operators *,+,/ and =
    a2 += a1 * 3.4;
    a = abs(a);
    double d = a2[7];
}

void f2(); // function

struct F // function object
{
    void operator()(); // F's call operator
};

void user()
{
    thread t1 {f}; // f() executes in separate thread
    thread t2 {F()}; // F()() executes in separate thread
    
    t1.join(); // wait for t1
    t2.join(); // wait for t2
}

void f3(vector<double>& v); // function do something with v

struct F2
{
    vector<double>& v;
    F2(vector<double>& vv) : v(vv) {}
    void operator()(); // application operator
};

int main()
{
    vector<double> some_vec {1,2,3,4,5,6,7,8,9};
    vector<double> vec2 {10,11,12,13,14};
    
    thread t1 {f3, ref(some_vec)}; // f2(some_vec) executees in a separate thread
    thread t2 {F2(vec2)}; // F(vec2)() executes in a separate thread
    
    t1.join();
    t2.join();
}

void f4(const vector<double>& v, double* res); // take input from v; place result in *res

class F3
{
public:
    F3(const vector<double>& vv, double *p) : v{vv}, res{p} {}
    
private:
    const vector<double>& v; // source of input
    double* res; // target for output
};

int main2()
{
    vector<double> some_vec;
    vector<double> vec2;
    
    double res1;
    double res2;
    
    thread t1 {f,cref(some_vec), &res1}; // f(some_vec, &res1) executes in a separate thread
    thread t2 {F3{vec2, &res2}};
    
    t1.join();
    t2.join();
    
    cout << res1 << '' << res2 << '\n'; 
}

mutex m; // controlling mutex
int sh; // shared data

void f5()
{
    unique_lock<mutex> lck {m}; // acquire mutex
    sh += 7; // manipulate shared data
    // release mutex implicitly
}

void f6()
{
    unique_lock<mutex> lck1 {m1, defer_lock}; // defer_lock: don't  yet try to acquire the mutex
    unique_lock<mutex> lck2 {m2, defer_lock}; // defer_lock: don't  yet try to acquire the mutex
    unique_lock<mutex> lck3 {m3, defer_lock}; // defer_lock: don't  yet try to acquire the mutex
    
    lock(lck1,lck2, lck3); // acquire all three locks
}

class Message
{
    
};

queue<Message> mqueue; // the queue of messages
condition_variable mcond; // the variable communicating events
mutex mmutex; // the locking mechanism

void consumer()
{
    while (true)
    {
        unique_lock<mutex> lck {mmutex}; // acquire mmutex
        while (mcond.wait(lck)) /* do nothing */; // release lck and wait;
        
        auto m = mqueue.front(); // get t he message
        mqueue.pop();
        lck.unlock(); // release lck
    }
}

void producer()
{
    while (true)
        Message m;
        // ... fill the message ...
        unique_lock<mutex> lck {mmutex}; // protect operations
        mqueue.push(m);
        mcond.notify_one(); // notify
    
    // release lock(at the end of scope)
}

class CppTour11172026
{
public:
};
