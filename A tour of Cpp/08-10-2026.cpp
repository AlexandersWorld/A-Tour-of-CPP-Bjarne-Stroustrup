#include "08-10-2026.h"

#include <iostream>
using namespace std;

bool CppTour10082026::accept2()
{
    cout << "Do you want to proceed (y or n)?\n"; // write questions << operand means ("put to")
    
    char answer {0};
    cin >> answer; // read answer >> operand means ("get from")
    
    switch (answer)
    {
    case 'y':
        return true;
    case 'n':
        return false;
    default:
        cout << "I'll take that for a no.\n";
        return false;
    }
}

void CppTour10082026::action()
{
    while (true)
    {
        cout << "enter action:\n"; // request action from terminal
        string act;
        cin >> act; // rear characters
        Point delta {0,0}; // Point holds an {x,y} pair
        
        for (char ch : act)
        {
            switch (ch)
            {
            case 'u': //up
            case 'n': // north
                ++delta.y;
                break;
                
            case 'r': //right
            case 'e': //east
                ++delta.x;
                break;
            // ... more actions ... //
            default:
                cout << "I freeze!\n";
            }
            //move(current+delta*scale);
            //update_display();
        }
    }
}
