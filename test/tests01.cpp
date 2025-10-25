#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"
#include <gtest/gtest.h>
#include <vector>
#include <memory>

// ------------------- Rectangle -------------------
TEST(RectangleTest, AreaAndCenter) {
    Rectangle r(4, 5);
    EXPECT_DOUBLE_EQ(r.area(), 20);
    auto [cx, cy] = r.center();
    EXPECT_DOUBLE_EQ(cx, 2);
    EXPECT_DOUBLE_EQ(cy, 2.5);
}

TEST(RectangleTest, Equality) {
    Rectangle r1(4, 5);
    Rectangle r2(4, 5);
    Rectangle r3(3, 5);
    EXPECT_TRUE(r1 == r2);
    EXPECT_FALSE(r1 == r3);
}

// ------------------- Trapezoid -------------------
TEST(TrapezoidTest, AreaAndCenter) {
    Trapezoid t(3, 7, 4);
    EXPECT_DOUBLE_EQ(t.area(), 20);
    auto [cx, cy] = t.center();
    EXPECT_DOUBLE_EQ(cx, 2.5);
    EXPECT_DOUBLE_EQ(cy, 2);
}

TEST(TrapezoidTest, Equality) {
    Trapezoid t1(3, 7, 4);
    Trapezoid t2(3, 7, 4);
    Trapezoid t3(4, 7, 4);
    EXPECT_TRUE(t1 == t2);
    EXPECT_FALSE(t1 == t3);
}

// ------------------- Rhombus -------------------
TEST(RhombusTest, AreaAndCenter) {
    Rhombus rh(6, 8);
    EXPECT_DOUBLE_EQ(rh.area(), 24);
    auto [cx, cy] = rh.center();
    EXPECT_DOUBLE_EQ(cx, 3);
    EXPECT_DOUBLE_EQ(cy, 4);
}

TEST(RhombusTest, Equality) {
    Rhombus rh1(6, 8);
    Rhombus rh2(6, 8);
    Rhombus rh3(5, 8);
    EXPECT_TRUE(rh1 == rh2);
    EXPECT_FALSE(rh1 == rh3);
}

// ------------------- Polymorphic Array -------------------
TEST(FigureArrayTest, TotalArea) {
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Rectangle>(4, 5));
    figures.push_back(std::make_unique<Trapezoid>(3, 7, 4));
    figures.push_back(std::make_unique<Rhombus>(6, 8));

    double total = 0;
    for(auto& f : figures)
        total += f->area();

    EXPECT_DOUBLE_EQ(total, 20 + 20 + 24);
}

// ------------------- Deletion -------------------
TEST(FigureArrayTest, DeleteFigure) {
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Rectangle>(4, 5));
    figures.push_back(std::make_unique<Rhombus>(6, 8));

    figures.erase(figures.begin() + 1);  // удаляем Rhombus
    EXPECT_EQ(figures.size(), 1);
    EXPECT_DOUBLE_EQ(figures[0]->area(), 20);
}

// ------------------- Operator<< (basic check) -------------------
TEST(FigureTest, OutputOperator) {
    Rectangle r(4, 5);
    std::ostringstream os;
    os << r;
    EXPECT_NE(os.str().find("Rectangle(width=4, height=5)"), std::string::npos);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
