#include <iostream> //include ("import") the declarations for the I/O (input/output) stream library
#include <complex>
#include <vector>
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
    //print(23.2,1);
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

void some_function() // function that doesn't return a value
{
    double d = 2.2; // initialize floating-point number
    int i = 7; // initialize integer
    double d1 {2.0}; // universal based on curly-brace-delimited
    double d2 {5.0}; // universal based on curly-brace-delimited
    int i1 {25}; // universal form to initialize a variable in C++
    d = d+i; // assign sum to d
    //i = d*i; // assign product to i (truncating the double d*i to an int)
    
    complex<double> z = 1; // a complex number wiith double-precision floating-point scalars
    complex<double> z2 {d1, d2};
    complex<double> z3 = {1,2}; // the = is optional with {...}
    
    vector<int> v {1,2,3,4,5,6};
    
    int y = 12;
    int x = 20;
    
    //int i2 = 7.2; // becomes 7 (surprise?)
    //int i3 {7.3}; // error: floating-point to integer conversion
    //int i4 = {7.2}; // error: floating-point to integer conversion (the = is redundant)
    
    auto b {true}; // a bool
    auto ch {'x'}; // a char
    auto i6 {123}; // an int
    auto d5 {1.2}; // a double
    auto z23 = sqrt(y); // z has the type of whatever sqrt(y) returns
    
    x += y; // x = x+y;
    ++x; // increment: x = x+1;
    x -= y; // x = x-y;
    --x; // decrement: x = x-1;
    x *= y; // scaling: x = x*y;
    x /= y; //scaling: x = x*y;
    x %=y; // x = x%y;
    
    vector<int> vec; // vec is global (a global vector of integers)
    
    struct Record
    {
        string name; // name is a member (a string member)
    };
    
    void fct(int arg); // fct is global (a global function)
    {
        string motto {"Who dares win"}; //motto is local
        auto p = new Record {"Hume"}; // p points to an unnamed Record (created by new)
    }
}

//Function examples:
// Elem* next_elem(); // no argument; return a pointer to Elem (an Elem*)
//void exit(int); // int argument; return nothing
//double sqrt(double); // double argument; return a double
   
