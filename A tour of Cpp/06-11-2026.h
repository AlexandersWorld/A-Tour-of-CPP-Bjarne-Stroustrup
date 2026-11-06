#pragma once
#include <map>
#include <string>

using namespace std;

struct Greater_than
{
    int val;
    Greater_than(int v) : val{v} {}
    bool operator()(const pair<string, int>& r) { return r.second > val;}
};

void f(std::map<std::string, int>& m)
{
    auto p = find_if(m.begin(), m.end(), Greater_than{42});
    
    auto p2 = find_if(m.begin(), m.end(), [](const pair<string, int>& r)
    {
        return r.second > 42;
    });
}

namespace Estd 
{
    using namespace std;
    
    template<typename C>
    void sort(C& c)
    {
        sort(c.begin(), c.end());
    }
    
    template<typename C, typename Pred>
    void sort(C& c, Pred p)
    {
        sort(c.begin(), c.end(), p);
    }
}

class CppTour11062026
{
public:
};
