#pragma once
#include <algorithm>
#include <fstream>
#include <vector>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Entry
{
    string name;
    int number;
    
    bool operator<(const Entry& x, const Entry& y) // less than
    {
        return x.name < y.name; // order Entries by their names
    }
};

template<typename T>
class Vec : public vector<T>
{
    using vector<T>::vector; // use the constructors from vector (under the same Vec)
    
    T& operator[](int i) // range check
        { return vector<T>::at(i); }
    
    const T& operator[](int i) const
        {return vector<T>::at(i); } // range check const objects
};

void checked(Vec<Entry>& book)
{
    try
    {
        book[book.size()] = {"Joe", 9999999}; // will throw an exception
    }
    catch (out_of_range)
    {
        cout << "range error\n";
    }
}

list<Entry> phone_book = {
    {"David Hume", 1234566},
    {"Carl Seagan", 999999},
    {"Matt Daemon", 123455566}
};

// more elegant
int get_number(const string& s)
{
    for (const auto& x : phone_book)
        if (x.name ==s)
            return x.number;
    return 0; // use 0 to represent "number not found"
}

// less elegant
int get_number2(const string& s)
{
    for (auto p = phone_book.begin(); p!= phone_book.end(); ++p)
        if (p->name == s)
            return p->number;
    return 0; // use 0 to represent "number not found"
}

void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q)
{
    phone_book.insert(p, ee); // add ee before the element referred to by p
    phone_book.erase(q); // remove the element referred to by q
}

map<string, int> phone_book2 {
   {"David Backhan", 99999},
    {"Karl Popper", 12345656},
    {"Bertrand Arthur William Russel", 2903829}
};

int get_number3(const string& s)
{
    return phone_book2[s];
}

unordered_map<string, int> phone_book3
{
    {"David Backhan", 99999},
  {"Karl Popper", 12345656},
  {"Bertrand Arthur William Russel", 2903829}
};

int get_number4(const string& s)
{
    return phone_book3[s];
}

struct  Record
{
    string name;
    int product_code;
};

struct Rhash // a hash function for Record
{
    size_t operator()(const Record& r) const
    {
        return hash<string>()(r.name)^hash<int>()(r.product_code);
    }
};

void f2(vector<Entry>& vec, list<Entry>& lst)
{
    sort(vec.begin(), vec.end()); // use < for order
    unique_copy(vec.begin(), vec.end(), lst.begin()); // don't copy adjacent equal elements
}

list<Entry> f3(vector<Entry>& vec)
{
    list<Entry> res;
    sort(vec.begin(), vec.end());
    unique_copy(vec.begin(), vec.end(), back_inserter(res));
    return res;
}

bool has_c(const string& s, char c) // does s contain the character c ?
{
    auto p = find(s.begin(), s.end(), c);
    if (p!=s.end())
        return true;
    else
        return false;
}

bool has_c2(const string& s, char c)
{
    return find(s.begin(), s.end(), c)!=s.end(); 
}

template<typename T>
using Iterator = typename T::iterator;

template<typename C, typename V>
vector<Iterator<C>> find_all(C& c, V v) // find all occurrences of v in c
{
    vector<Iterator<C>> res;
    for (auto p = c.begin(); p!=c.end(); ++p)
        if (*p==v)
            res.push_back(p);
    return res;
}

void test()
{
    string m {"Mary had a little lamb"};
    
    for (auto p : find_all(m ,'a'))
        if (*p!='a')
            cerr << "string bug!\n";
    
    list<double> Id {1.1, 2.2, 3.3, 1.1};
    for (auto p : find_all(Id, 1.1))
        if (*p!=1.1)
            cerr << "list bug!\n";
    
    vector<string> vs {"red", "blue", "green", "green", "orange", "green"};
    for (auto p : find_all(vs, "red"))
        if (*p!="red")
            cerr << "vector bug!\n";
    
    for (auto p : find_all(vs,"green"))
        *p = "vert";
}

ostream_iterator<string> oo {cout};
istream_iterator<string> ii {cin};

int main()
{
    *oo = "Hello, "; // meaning cout <<"Hello, "
    ++oo;
    *oo = "world!\n"; // meaning cout <<"world!\n" 
    
    string from, to;
    cin >> from >> to; // get resource and target file names
    
    ifstream is {from}; // input stream for file "from"
    istream_iterator<string> ii {is}; // input iterator for stream
    istream_iterator<string> eos {}; // input sentinel
    
    ofstream os {to}; // output stream file "to"
    ostream_iterator<string> oo {os, "\n"};
    
    vector<string> b {ii, eos}; // b is a vector initialized from input
    sort(b.begin(), b.end()); // sort the buffer
    
    unique_copy(b.begin(), b.end(), oo); // copy buffer to output, discard replicated values
    
    return !is.eof() || !os; // return error state
}

int main2()
{
    string from, to;
    cin >> from >> to; // get resource and target file
    
    ifstream is {from}; // input stream for file "from"
    ofstream os {to};
    
    set<string> b {istream_iterator<string>{is}, istream_iterator<string>{}}; // read input
    copy(b.begin(), b.end(), ostream_iterator<string>{os, "\n"});
    
    return is.eof() || !os;
}

unordered_set<Record, Rhash> my_set; // set of Recoreds using Rhash for lookup

class CppTour11032026
{
public:
};
