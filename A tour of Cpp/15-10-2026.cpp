#include "15-10-2026.h"

void CppTour10152026::f(complex z)
{
    complex a {2.3}; // construct {2.3,0.0} from 2.3
    complex b {complex{1}/a};
    complex c { a+z*complex{1,2.3}};
    
    if (c != b)
        c = -(b/a)+complex{2}*b;
}
