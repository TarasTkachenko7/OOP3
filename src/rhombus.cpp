#include "rhombus.h"
#include <iostream>

Rhombus::Rhombus() : diag1(0), diag2(0) {}

Rhombus::Rhombus(double d1, double d2) : diag1(d1), diag2(d2) {}

Rhombus::Rhombus(const Rhombus& other) 
    : diag1(other.diag1), diag2(other.diag2) {}

Rhombus& Rhombus::operator=(const Rhombus& other) {
    if (this != &other) {
        diag1 = other.diag1;
        diag2 = other.diag2;
    }
    return *this;
}

Rhombus::Rhombus(Rhombus&& other) noexcept 
    : diag1(std::move(other.diag1)), diag2(std::move(other.diag2)) {
    other.diag1 = 0;
    other.diag2 = 0;
}

Rhombus& Rhombus::operator=(Rhombus&& other) noexcept {
    if (this != &other) {
        diag1 = std::move(other.diag1);
        diag2 = std::move(other.diag2);
        other.diag1 = 0;
        other.diag2 = 0;
    }
    return *this;
}

std::pair<double, double> Rhombus::center() const {
    return {diag1 / 2, diag2 / 2};
}

double Rhombus::area() const {
    return diag1 * diag2 / 2;
}

void Rhombus::print(std::ostream& os) const {
    os << "Rhombus(diag1=" << diag1 << ", diag2=" << diag2 << ")";
}

void Rhombus::read(std::istream& is) {
    std::cout << "Enter diagonal1 and diagonal2: ";
    is >> diag1 >> diag2;
}

bool Rhombus::operator==(const Figure& other) const {
    if (typeid(*this) != typeid(other)) return false;
    
    if(auto p = dynamic_cast<const Rhombus*>(&other))
        return diag1 == p->diag1 && diag2 == p->diag2;
    return false;
}