#include "20-10-2026.h"

#include <iostream>

void Smiley::draw() const
{
    Circle::draw();
    for (auto p : eyes)
        p->draw();
    mouth->draw();
}

void CppTour10202026::rotate_all(std::vector<Shape*>& v, int angle)
{
    for (auto p : v)
        p->rotate(angle);
}

void CppTour10202026::use()
{
    std::vector<Shape*> v;
    while (std::cin)
        v.push_back(read_shape(std::cin));
    draw_all(v);
    rotate_all(v, 45);
    for (auto p : v)
        delete p;
}
