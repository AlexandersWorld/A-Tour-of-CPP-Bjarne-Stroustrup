#include <iostream> //include ("import") the declarations for the I/O (input/output) stream library
using namespace std; //make names from std visible without std::

double square(double x)
{
    return x * x;
}

void print_square(double x)
{
    cout << "the square of " << x << " is " << square(x) << "\n"; 
}

struct Player
{
    float Health;
    float Mana;
};

int main()
{
    Player p;
    p.Health = 100;
    p.Mana = 200;
    float value = 200;
    float* PtrValue = &value;
    
    cout << "Hello World\n";
    print_square(1.234); // print: the square of 1.234 is 1.52276
}

//Function examples:
/*
 *  Elem* next_elem(); // no argument; return a pointer to Elem (an Elem*)
 *  void exit(int); // int argument; return nothing
 *  double sqrt(double); // double argument; return a double
 * *\