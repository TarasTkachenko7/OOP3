#include "rectangle.h"
#include <iostream>

Rectangle::Rectangle() : width(0), height(0) {}

Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

Rectangle::Rectangle(const Rectangle& other) 
    : width(other.width), height(other.height) {}

Rectangle& Rectangle::operator=(const Rectangle& other) {
    if (this != &other) {
        width = other.width;
        height = other.height;
    }
    return *this;
}

Rectangle::Rectangle(Rectangle&& other) noexcept 
    : width(std::move(other.width)), height(std::move(other.height)) {
    other.width = 0;
    other.height = 0;
}

Rectangle& Rectangle::operator=(Rectangle&& other) noexcept {
    if (this != &other) {
        width = std::move(other.width);
        height = std::move(other.height);
        other.width = 0;
        other.height = 0;
    }
    return *this;
}

std::pair<double, double> Rectangle::center() const {
    return {width / 2, height / 2};
}

double Rectangle::area() const {
    return width * height;
}

void Rectangle::print(std::ostream& os) const {
    os << "Rectangle(width=" << width << ", height=" << height << ")";
}

void Rectangle::read(std::istream& is) {
    std::cout << "Enter width and height: ";
    is >> width >> height;
}

bool Rectangle::operator==(const Figure& other) const {
    if (typeid(*this) != typeid(other)) return false;
    
    if(auto p = dynamic_cast<const Rectangle*>(&other))
        return width == p->width && height == p->height;
    return false;
}