#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"

class Rhombus : public Figure {
public:
    Rhombus();
    Rhombus(double d1, double d2);

    std::pair<double, double> center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    bool operator==(const Figure& other) const override;

protected:
    void read(std::istream& is) override;

private:
    double diag1;
    double diag2;
};

#endif
