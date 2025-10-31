#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "figure.h"

class Trapezoid final : public Figure {
public:
    Trapezoid();
    Trapezoid(double a, double b, double h);
    
    Trapezoid(const Trapezoid& other);
    Trapezoid& operator=(const Trapezoid& other);
    
    Trapezoid(Trapezoid&& other) noexcept;
    Trapezoid& operator=(Trapezoid&& other) noexcept;

    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    bool operator==(const Figure& other) const override;

private:
    void read(std::istream& is) override;
    double base1;
    double base2;
    double height;
};

#endif