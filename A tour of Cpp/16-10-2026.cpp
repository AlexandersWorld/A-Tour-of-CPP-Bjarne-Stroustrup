#include "16-10-2026.h"
#include <iostream>

void CppTour10162026::use(Container& c)
{
    const int sz = c.size();
    
    for (int i=0; i!=sz; ++i)
            std::cout << c[i] << '\n';
}
