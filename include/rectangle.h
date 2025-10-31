#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle final : public Figure {
public:
    Rectangle();
    Rectangle(double w, double h);
    
    Rectangle(const Rectangle& other);
    Rectangle& operator=(const Rectangle& other);
     
    Rectangle(Rectangle&& other) noexcept;
    Rectangle& operator=(Rectangle&& other) noexcept;

    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    bool operator==(const Figure& other) const override;

private:
    void read(std::istream& is) override;
    double width;
    double height;
};

#endif