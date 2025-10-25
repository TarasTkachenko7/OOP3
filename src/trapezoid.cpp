#include "trapezoid.h"
#include <iostream>

Trapezoid::Trapezoid() : base1(0), base2(0), height(0) {}
Trapezoid::Trapezoid(double a, double b, double h) : base1(a), base2(b), height(h) {}

std::pair<double, double> Trapezoid::center() const {
    return {(base1 + base2) / 4, height / 2};
}

double Trapezoid::area() const {
    return (base1 + base2) * height / 2;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid(base1=" << base1 << ", base2=" << base2 << ", height=" << height << ")";
}

bool Trapezoid::operator==(const Figure& other) const {
    if(auto p = dynamic_cast<const Trapezoid*>(&other))
        return base1 == p->base1 && base2 == p->base2 && height == p->height;
    return false;
}

void Trapezoid::read(std::istream& is) {
    std::cout << "Enter base1, base2 and height: ";
    is >> base1 >> base2 >> height;
}
