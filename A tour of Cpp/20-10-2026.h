#pragma once
#include <iosfwd>
#include <vector>

#include "08-10-2026.h"

enum class Kind { circle, triangle, smiley };

class Shape
{
public:
    virtual Point center() const = 0;
    virtual void move(Point to) = 0;
    
    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;
    
    virtual ~Shape() {}
};

class Circle : public Shape
{
public:
    Circle(Point p, int rr);
    
    Point center() const { return x;}
    void move(Point to) { x=to; }
    
    void draw() const;
    void rotate(int) {}
    
private:
    Point x;
    int r;
};

class Smiley : public Circle
{
public:
    Smiley(Point p, int r) : Circle(p, r), mouth{nullptr} {}
    
    void move(Point to) override;
    void draw() const override;
    void rotate(int) override;
    
    void add_eye(Shape* s) { eyes.push_back(s); }
    void set_mouth(Shape* s);
    virtual void wink(int i);
    
    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes)
            delete p;
    }
    
private:
    std::vector<Shape*> eyes;
    Shape* mouth;
};


class CppTour10202026
{
public:
    Shape* read_shape(std::istream& is)
    {
        switch (k)
        {
        case Kind::circle:
            return new Circle{p, r};
        case Kind::triangle:
            return new Triangle{p1,p2,p3};
        case Kind::smiley:
            Smiley* ps = new Smiley{p, r};
            ps->add_eye(e1);
            ps->add_eye(e2);
            ps->set_mouth(m);
            return ps;
        }
    }
    void rotate_all(std::vector<Shape*>& v, int angle);
    void use();
};
