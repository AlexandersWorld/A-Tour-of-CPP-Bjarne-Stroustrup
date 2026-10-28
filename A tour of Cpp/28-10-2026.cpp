#include "28-10-2026.h"

#include <fstream>
#include <regex>

void CppTour10282026::print(const string& s)
{
    string s1 {"Annemarie"};
    string s2 {"Annemarie Stroustrup"};
    
    printf("For people who like printf: %s\n", s.c_str());
    cout << "For people who likes streams: " << s << '\n';
    
    regex pat(R"(\w{2}\s*\d{5}(-\d{4})?)");
    
    int lineno = 0;
    for (string line; getline(cin, line);) // read into line buffer
    {
        ++lineno;
        smatch matches; // matched strings go here
        if (regex_search(line, matches, pat)) // search for pat in line
            cout << lineno << ": " << matches[0] << '\n';
    }
}

void CppTour10282026::use()
{
    ifstream in("file.txt"); // input file
    if (!in) // check that the file was opened
        cerr << "no file\n";
    
    regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"};
    
    int lineno = 0;
    for (string line; getline(in,line);)
    {
        ++lineno;
        smatch matches; // matched strings go here
        if (regex_search(line, matches, pat))
        {
            cout << lineno << ": " << matches[0] << '\n'; // the complete match
            if (1 < matches.size() && matches[1].matched)
                cout << "\t: " << matches[1] << '\n'; // submatch
        }
    }
}

bool CppTour10282026::is_identifier(const string& s)
{
    regex pat {"[_[:alpha:]]\\w*"}; // underscore or letter
                                        // followed by zero or more underscores, letters, or digits
    return regex_match(s, pat);
}

bool CppTour10282026::is_identify(const string& s)
{
    regex pat {R"([_[:alpha:]]\w*)"};
    return regex_match(s, pat);
}
