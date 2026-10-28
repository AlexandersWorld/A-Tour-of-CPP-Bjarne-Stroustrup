#include "27-10-2026.h"

void CppTour10272026::use()
{
    auto addr = compose("dmr", "bell-labs.com");
}

string CppTour10272026::compose(const string& name, const string& domain)
{
    return name + '@' + domain;
}

void CppTour10272026::m2(string& s1, string& s2)
{
    s1 = s1 + '\n'; // append newline
    s2 += '\n'; // append newline
}

void CppTour10272026::m3()
{
    string name = "Niels Stroustrup";
    string s = name.substr(6, 10); // s = Stroustrup // So cut first 5 letters and 1 space of (starting from 0) and give me the 10 left
    name.replace(0,5, "nicholas"); // name became nicolas Stroustrup // change the first 5 letters (Niels); to "nicholas" start from 0 to 5th letter.
    name[0] = toupper(name[0]); // name becames "Nicholas Stroustrup" // get the fist letter and reassign it to the same Uppercased letter.
    
    name[2];
    char a = name.at(2);
}
