#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle() : width(0), height(0) {}
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

std::pair<double, double> Rectangle::center() const {
    return {width / 2, height / 2};
}

double Rectangle::area() const {
    return width * height;
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle(width=" << width << ", height=" << height << ")";
}

bool Rectangle::operator==(const Figure& other) const {
    if(auto p = dynamic_cast<const Rectangle*>(&other))
        return width == p->width && height == p->height;
    return false;
}

void Rectangle::read(std::istream& is) {
    std::cout << "Enter width and height: ";
    is >> width >> height;
}
