#include "trapezoid.h"
#include <iostream>

Trapezoid::Trapezoid() : base1(0), base2(0), height(0) {}

Trapezoid::Trapezoid(double a, double b, double h) : base1(a), base2(b), height(h) {}

Trapezoid::Trapezoid(const Trapezoid& other) 
    : base1(other.base1), base2(other.base2), height(other.height) {}

Trapezoid& Trapezoid::operator=(const Trapezoid& other) {
    if (this != &other) {
        base1 = other.base1;
        base2 = other.base2;
        height = other.height;
    }
    return *this;
}

Trapezoid::Trapezoid(Trapezoid&& other) noexcept 
    : base1(std::move(other.base1)), base2(std::move(other.base2)), height(std::move(other.height)) {
    other.base1 = 0;
    other.base2 = 0;
    other.height = 0;
}

Trapezoid& Trapezoid::operator=(Trapezoid&& other) noexcept {
    if (this != &other) {
        base1 = std::move(other.base1);
        base2 = std::move(other.base2);
        height = std::move(other.height);
        other.base1 = 0;
        other.base2 = 0;
        other.height = 0;
    }
    return *this;
}

std::pair<double, double> Trapezoid::center() const {
    return {(base1 + base2) / 4, height / 2};
}

double Trapezoid::area() const {
    return (base1 + base2) * height / 2;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Trapezoid(base1=" << base1 << ", base2=" << base2 << ", height=" << height << ")";
}

void Trapezoid::read(std::istream& is) {
    std::cout << "Enter base1, base2 and height: ";
    is >> base1 >> base2 >> height;
}

bool Trapezoid::operator==(const Figure& other) const {
    if (typeid(*this) != typeid(other)) return false;
    
    if(auto p = dynamic_cast<const Trapezoid*>(&other))
        return base1 == p->base1 && base2 == p->base2 && height == p->height;
    return false;
}