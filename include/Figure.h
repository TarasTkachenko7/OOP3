#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <string>
#include <utility>

class Figure {
public:
    Figure() = default;
    virtual ~Figure() = default;

    virtual std::pair<double, double> center() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual bool operator==(const Figure& other) const = 0;
    virtual operator double() const { return area(); }

    friend std::ostream& operator<<(std::ostream& os, const Figure& fig);
    friend std::istream& operator>>(std::istream& is, Figure& fig);

protected:
    virtual void read(std::istream& is) = 0;
};

#endif
