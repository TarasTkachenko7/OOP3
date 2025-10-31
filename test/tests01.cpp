#include "rectangle.h"
#include "trapezoid.h"
#include "rhombus.h"
#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include <sstream>

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

TEST(RectangleTest, CopyAndMove) {
    Rectangle r1(4, 5);
    
    // Копирование
    Rectangle r2 = r1;
    EXPECT_TRUE(r1 == r2);
    
    // Перемещение
    Rectangle r3 = std::move(r1);
    EXPECT_TRUE(r2 == r3);
    // После перемещения r1 должен быть в валидном состоянии
    EXPECT_DOUBLE_EQ(r1.area(), 0); // Обнулился
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

// ------------------- Polymorphic Behavior -------------------

TEST(FigureTest, VirtualAreaThroughBasePointer) {
    Rectangle r(4, 5);
    Figure* f = &r;
    
    // Виртуальный вызов должен работать
    EXPECT_DOUBLE_EQ(f->area(), 20);
}

// ------------------- Operator double() -------------------
TEST(FigureTest, DoubleConversion) {
    Rectangle r(4, 5);
    EXPECT_DOUBLE_EQ(static_cast<double>(r), 20);
    
    Rhombus rh(6, 8);
    EXPECT_DOUBLE_EQ(static_cast<double>(rh), 24);
}

// ------------------- Input/Output Operators -------------------
TEST(FigureTest, InputOperator) {
    std::istringstream iss("4 5");
    Rectangle r;
    iss >> r;
    
    EXPECT_DOUBLE_EQ(r.area(), 20);
}

TEST(FigureTest, OutputOperatorAllTypes) {
    Rectangle r(4, 5);
    Trapezoid t(3, 7, 4);
    Rhombus rh(6, 8);
    
    std::ostringstream os1, os2, os3;
    os1 << r;
    os2 << t;
    os3 << rh;
    
    EXPECT_NE(os1.str().find("Rectangle"), std::string::npos);
    EXPECT_NE(os2.str().find("Trapezoid"), std::string::npos);
    EXPECT_NE(os3.str().find("Rhombus"), std::string::npos);
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

TEST(FigureArrayTest, VirtualCallsInLoop) {
    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Rectangle>(4, 5));
    figures.push_back(std::make_unique<Trapezoid>(3, 7, 4));
    figures.push_back(std::make_unique<Rhombus>(6, 8));
    
    // Все эти вызовы должны работать полиморфно
    for(size_t i = 0; i < figures.size(); ++i) {
        auto center = figures[i]->center();  // виртуальный
        double area = figures[i]->area();    // виртуальный
        EXPECT_GT(area, 0); // Площадь должна быть положительной
    }
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

// ------------------- Edge Cases -------------------
TEST(FigureTest, ZeroDimensions) {
    Rectangle r(0, 5);
    EXPECT_DOUBLE_EQ(r.area(), 0);
    
    Rhombus rh(0, 8);
    EXPECT_DOUBLE_EQ(rh.area(), 0);
    
    Trapezoid t(0, 0, 4);
    EXPECT_DOUBLE_EQ(t.area(), 0);
}

TEST(FigureArrayTest, EmptyArray) {
    std::vector<std::unique_ptr<Figure>> figures;
    EXPECT_TRUE(figures.empty());
    
    double total = 0;
    for(auto& f : figures) {
        total += f->area(); // Не должно выполняться
    }
    EXPECT_DOUBLE_EQ(total, 0);
}

// ------------------- Move Semantics -------------------
TEST(FigureTest, MoveAssignment) {
    Rectangle r1(4, 5);
    Rectangle r2(1, 1);
    
    r2 = std::move(r1); // Перемещающее присваивание
    
    EXPECT_DOUBLE_EQ(r2.area(), 20);
    EXPECT_DOUBLE_EQ(r1.area(), 0); // Источник обнулился
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}