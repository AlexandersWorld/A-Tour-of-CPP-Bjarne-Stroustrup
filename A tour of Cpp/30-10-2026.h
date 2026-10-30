#pragma once
#include <iosfwd>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct Entry
{
    string name;
    int number;
};

template<typename Target=string, typename Source=string>
Target to(Source arg) // convert Source to Target
{
    stringstream interpreter;
    Target result;
    
    if (!(interpreter << arg) // write arg into stream
        || !(interpreter >> result) // read result from stream
        || !(interpreter >> std::ws).eof()) // stuff left in stream?
        throw runtime_error{"to<>() failed"};
    
    return result;
}

class CppTour10302026
{
public:
    
    vector<int> read_ints(istream& is);
    ostream& operator<<(ostream& os, const Entry& e)
    {
        return os << "{\"" << e.name << "\", " << e.number << "}";
    }
    
    void test();
    
    istream& operator>>(istream& is, Entry& e)
        // read { "name", number } pair. Note: formatted with { "", and }
    {
        char c, c2;
        if (is>>c && c=='{' && is>>c2 && c2=='"') { // start with a { "
            string name; // the default value of a string is the empty string: ""
            while (is.get(c) && c!="") // anything before a " is part of the name
                name+=c;
            
            if (is>>c && c==',') {
                int number = 0;
                if (is>>number>>c && c=='}')
                { // read the number and a
                    e = {name, number}; // assign to the entry
                    return is; 
                }
            }
        }
        is.state_base::failbit); // register the failure in the stream
        return is;
    }
};
