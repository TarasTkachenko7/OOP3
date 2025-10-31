#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus final : public Figure {
public:
    Rhombus();
    Rhombus(double d1, double d2);
    
    Rhombus(const Rhombus& other);
    Rhombus& operator=(const Rhombus& other);
    
    Rhombus(Rhombus&& other) noexcept;
    Rhombus& operator=(Rhombus&& other) noexcept;

    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    bool operator==(const Figure& other) const override;

private:
    void read(std::istream& is) override;
    double diag1;
    double diag2;
};

#endif