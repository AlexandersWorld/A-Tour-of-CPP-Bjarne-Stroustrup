#include "30-10-2026.h"

#include <iostream>

vector<int> CppTour10302026::read_ints(istream& is)
{
    vector<int> res;
    int i;
    while (is>>i)
        res.push_back(i);
    return res;
    
    while (cin)
    {
        for (int i; cin>>i;)
        {
            // ...use the integer...
        }
        
        if (cin.eof())
        {
            // .. all is well we reached the end-of-file...
        }
        else if (cin.fail())
        {
            cin.clear(); // a potentially recoverable error
            char ch; // reset the state to good()
            if (cin>>ch)
            {
                switch (ch)
                {
                case '{':
                    // .. start nested structure ...
                    break;
                case '}':
                    // ... end nested  structure ...
                    break;
                default:
                    cin.setstate(ios_base::failbit); // add fail() to cin's state 
                }
            }
        }
        // ...
    }
    
    cout << 123 << ',' << hex << 123 << ',' << oct << 123 << '\n';
    constexpr double d = 123.456;
    cout << d  << "; " // use the default format for d
        << scientific << d << "; "  // use 1.123e2 style format for d
        << hexfloat << d << "; "  // use hexadecimal notation for d
        << fixed << d << "; " // use 123.456 style format for f
        << defaultfloat << d << '\n'; // use the default format for d
    
    // output: 123.456; 1.234560e+002; 0x1.edd2f2p+6; 123.456000; 123.456
    
    cout.precision(8);
    cout << 1234.56789 << '' << 1234.56789 << '' << 123456 << '\n';
    
    cout.precision(4);
    cout << 1234.56789 << '' << 1234.56789 << '' << 123456 << '\n';
    
    //  output: 1234.5679 1234.5679 123456
    // 1235 1235 123456
    
    ofstream ofs("target"); // "o" for "output"
    if (!ofs)
        error("couldn't open 'source' for reading");
}

void CppTour10302026::test()
{
    ostringstream oss;
    oss << "{temperature," << scientific << 123.456789 << "}";
    cout << oss.str() << '\n';
}
