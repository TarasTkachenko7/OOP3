#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid : public Figure {
public:
    Trapezoid();
    Trapezoid(double a, double b, double h);

    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    bool operator==(const Figure& other) const override;

protected:
    void read(std::istream& is) override;

private:
    double base1;
    double base2;
    double height;
};

#endif
