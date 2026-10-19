
using namespace std;
#include "12-10-2026.h"

double CppTour12092026::read_and_sum(int s)
{
    Vector v(s);
    for (int i=0; i!=v.size(); ++i)
        cin >> v[i];
    
    double sum {0};
    for (int i=0; i!=v.size(); ++i)
        sum += v[i];
    return sum;
}
