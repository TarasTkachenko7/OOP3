#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle : public Figure {
public:
    Rectangle();
    Rectangle(double w, double h);

    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    bool operator==(const Figure& other) const override;

protected:
    void read(std::istream& is) override;

private:
    double width;
    double height;
};

#endif
