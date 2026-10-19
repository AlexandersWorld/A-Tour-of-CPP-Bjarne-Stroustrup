#pragma once
#include "09-10-2026.h"

class Container
{
public:
    virtual double& operator[](int) = 0; // pure virtual function
    virtual int size() const = 0; // const member function
    virtual ~Container() {} // destructor
};

class Vector_container : public Container // Vector_container implements container
{
    Vector v;
public:
    //Vector_container(int s) : v(s) {} // Vector of s elements
    ~Vector_container() {}
    
    //double& operator[](int i) {return v[i]; }
    //int size() const { return v.size(); }
};

class CppTour10162026 : public Container
{
public:
    virtual double& operator[](int) override;
    virtual int size() const override;
    
    void use(Container& c);
};
