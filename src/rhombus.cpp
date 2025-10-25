#include "rhombus.h"
#include <iostream>

Rhombus::Rhombus() : diag1(0), diag2(0) {}
Rhombus::Rhombus(double d1, double d2) : diag1(d1), diag2(d2) {}

std::pair<double, double> Rhombus::center() const {
    return {diag1 / 2, diag2 / 2};
}

double Rhombus::area() const {
    return diag1 * diag2 / 2;
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus(diag1=" << diag1 << ", diag2=" << diag2 << ")";
}

bool Rhombus::operator==(const Figure& other) const {
    if(auto p = dynamic_cast<const Rhombus*>(&other))
        return diag1 == p->diag1 && diag2 == p->diag2;
    return false;
}

void Rhombus::read(std::istream& is) {
    std::cout << "Enter diagonal1 and diagonal2: ";
    is >> diag1 >> diag2;
}
