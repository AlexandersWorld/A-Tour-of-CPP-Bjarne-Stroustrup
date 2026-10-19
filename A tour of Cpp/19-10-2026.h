#pragma once
#include <iostream>
#include <mutex>

using namespace std;

std::mutex mtx;
int shared_data = 0;

class CppTour10192026
{
public:
    static void thread_function()
    {
        cout << "Hello from thread!\n";
    }
    
    static void increment()
    {
        mtx.lock();
        ++shared_data;
        mtx.unlock();
    }
};
