#pragma once
#include <utility>

using namespace std;

template<typename Forward_iterator, typename T, typename Compare>
    pair<Forward_iterator, Forward_iterator>
    equal_range(Forward_iterator first, Forward_iterator last, const T& val, Compare cmp);

class CppTour11112026
{
public:
};
