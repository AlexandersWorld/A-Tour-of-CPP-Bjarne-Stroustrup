#include "06-10-2026.h"

double CppTour10062026::sum(const std::vector<double>& vector)
{
    double temp {0};
    for (const double v : vector)
    {
        temp += v;
    }
    return temp;
}