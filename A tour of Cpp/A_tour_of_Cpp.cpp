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

void print(int a, double b)
{
    cout << a << "\n" << b << "\n";
}

void user()
{
    print(5,2.5);
    print(23.2,1);
}

int main()
{
    Player p;
    p.Health = 100;
    p.Mana = 200;
    float value = 200;
    float* PtrValue = &value;
    
    user();
    cout << "Hello World\n";
    print_square(1.234); // print: the square of 1.234 is 1.52276
    
    cout << sizeof(int) << '\n'; // int guarantee to hold 4 Bytes that is 32 bits.
    cout << sizeof(double) << '\n';  // double guarantees so 8 Bytes and 64 bits.
    cout << sizeof(char) << '\n'; // char or character is a natural size to hold a character 1 Byte that is equal to 8 bits.
    
    int num = 2 + 2;
    int num2 = +2;
    
    int num3  = 2 - 5;
    int num4 = -2;
    int num5 = 5*5;
    int num6 = 2/5;
    int num7 = 52 % 2;
    
    int bitwise = 16 & 2; //AND operator for bits check/keep bits that both have
    int bitwise2 = 20 | 2; // OR operator for bits Turn bits on combine flags
    int bitwise3 = 20^2; // XOR operator for bits Toggle/find differences
    int bitwise4 = ~20; // NOT operator for bits Flip every bit.
    
    print(bitwise, bitwise2);
    print(bitwise3, bitwise4);
}

//Function examples:
// Elem* next_elem(); // no argument; return a pointer to Elem (an Elem*)
//void exit(int); // int argument; return nothing
//double sqrt(double); // double argument; return a double
   
