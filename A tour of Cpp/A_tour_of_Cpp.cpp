#include <iostream> //include ("import") the declarations for the I/O (input/output) stream library
#include <complex>
#include <vector>

#include "06-10-2026.h"
#include "09-10-2026.h"
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

void copy_fct()
{
    int v1[10] {0,1,2,3,4,5,6,7,8,9};
    int v2[10]; //to become a copy of v1
    
    for (auto i = 0; i != 10; ++i)
    {
        v2[i] = v1[i];
    }
}

void print()
{
    int v[] {0,1,2,3,4,5,6,7,8,9};
    
    for (auto x: v) // same as below.
            cout << x << '\n';
    cout << "------" << '\n';
    for (auto x: {0,1,2,3,4,5,6,7,8,9}) // using x value as copy and print it. copy can be read and modified without effecting the original value.
            cout << x << '\n';
    cout << "------" << '\n';
    for (auto& x : v) // using value by reference, that means passing the actual value, it can be read/modified that modify reflects to the original value.
        cout << x << '\n';
    cout << "------" << '\n';
    
    //Notes
    /*
     * Reference are similar to a pointer
     * except you don't need to use * to access the value referred
     * Also a reference cannot be made to refer to a different object after its initialization
     */
}   

void sort(vector<double>& v) // Reference are particular useful for specifying function arguments like in this example
{
    //By using a reference, we ensure that for a call sort(my_vec) we do not copy my_vec and that it really is my_vec
    // that is sorted and not a copy of it
    
    for (auto i = 0; i != v.size() - 1; ++i)
    {
        const double _temp = v[i]; // 5
        v[i] = v[i + 1]; // 2
        v[i + 1] = _temp; // 5
        
        //out put [2, 5]
    }
}

double sum(const vector<double>& v) // When we don't want to modify an argument, but still don't want the cost of copying, we use const reference like this example
{
    double r {0};
    
    for (const double x : v)
        r += x;
    
    return r;
}

bool accept()
{
    cout << "Do you want to proceed (y or n)?\n"; // write question << operand means ("put to")
    
    char answer {0};
    cin >> answer; // read answer, >> operand means ("get from")
    
    if (answer == 'y')
        return true;
    return false;
}

int main()
{
    
    print();
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
    
    CppTour10062026* cpp_tour10062026 = new CppTour10062026(); // if class const we not allow to change anything inside the class
    
    //cpp_tour10062026->dmv = 10; // Error when trying to change a const value
    //cpp_tour10062026->var = 20; // this is allowed to change as it's a regular int
    
    //constexpr double max1 = 1.4 * square(cpp_tour10062026->dmv); // Ok if square(17) is a constant expression
    //constexpr double max2 = 1.4 * square(cpp_tour10062026->var); // error: var is not a constant expression
    const double max3 = 1.4 * square(cpp_tour10062026->var); // Ok, may be evaluated at run time
    
    vector<double> v {1.2, 3.4, 4.5}; // v is not a const
    const double s1 = cpp_tour10062026->sum(v); // OK: evaluated at run time
    //constexpr double s2 = cpp_tour10062026->sum(v); // error: sum(v) not const expression
    
    char a[6]; // array of 6 characters;
    char* ptr; // pointer to character;
    
    ptr = &a[3]; // ptr points to a's fourth element;
    char x = *ptr; // *ptr1 is the object (value) that ptr points to (e.g a's fourth element)
    
    double* pd = nullptr;
    //Link<Record>* lst {nullptr}; // pointer to a Link to a Record
    //int x {nullptr}; // error: nullptr is a pointer not an integer
    
    const bool bAccepted = accept();
    if (bAccepted)
    {
        cout << "accepted";
    }
    else
    {
        cout << "not accepted";
    }
}

int count_x(char* p, char x)
    // count the number of occurrences of x in p[]
    // p is assumed to point to a zero-terminated array of char (or to nothing)
{
    /*
     * Note how we can move a pointer to point to the next element of an array using ++
     * And that we can leave out the initializer in a for-statement if we don't need it.
     */
   
    /*
    if (p == nullptr) return 0;
    int count {0};
    for (; p != nullptr; ++p)
    {
        if (*p == x)
                count++;
    }
    */
    
    int count {0};
    while (p)
    {
        if (*p == x)
                ++count;
        ++p;
    }
    return count;
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
   
