#include <iostream>
#include <fmt/core.h>
#include "dot.h"

using namespace std;

// класс треугольник с композицией

class TriangleComposition {

private:

    Dot a, b, c;  

public:
  

    TriangleComposition(double x1, double y1, double x2, double y2, double x3, double y3): a(x1, y1), b(x2, y2), c(x3, y3) {}

    double sideAB() { 
        
        return a.distanceTo(b); 
    
    }

    double sideBC() { 
        
        return b.distanceTo(c); 
    
    }

    double sideCA() { 
        
        return c.distanceTo(a); 
    
    }

    double perimeter() {

        return sideAB() + sideBC() + sideCA();

    }

    double area() {

        double p = perimeter() / 2;

        return sqrt(p * (p - sideAB()) * (p - sideBC()) * (p - sideCA()));

    }

    void printSides() {

        fmt::print("Стороны: {:.2f}, {:.2f}, {:.2f}.\n", sideAB(), sideBC(), sideCA());

    }

    void printPerimeter() {

        fmt::print("Периметр: {:.2f}.\n", perimeter());

    }

    void printArea() {

        fmt::print("Площадь: {:.2f}.\n", area());

    }
};

// класс треугольник с аггрегацией

class TriangleAggregation {

private:

    Dot& a, b, c;

public:

    TriangleAggregation(Dot& dot1, Dot& dot2, Dot& dot3) : a(dot1), b(dot2), c(dot3) {}

    double sideAB() { 
        
        return a.distanceTo(b);
    
    }

    double sideBC() { 
        
        return b.distanceTo(c); 
    
    }

    double sideCA() { 
        
        return c.distanceTo(a); 

    }

    double perimeter() {

        return sideAB() + sideBC() + sideCA();

    }

    double area() {

        double p = perimeter() / 2;

        return sqrt(p * (p - sideAB()) * (p - sideBC()) * (p - sideCA()));

    }

    void printSides() {

        fmt::print("Стороны: {:.2f}, {:.2f}, {:.2f}.\n", sideAB(), sideBC(), sideCA());

    }

    void printPerimeter() {

        fmt::print("Периметр: {:.2f}.\n", perimeter());

    }

    void printArea() {

        fmt::print("Площадь: {:.2f}.\n", area());

    }
};

int main() {

    system("chcp 1251");

    fmt::print("Контрольное задание 1. Класс Triangle.\n");

    fmt::print("Класс с композиицией:\n");

    // точки создаются внутри класса треугольник

    TriangleComposition t1(0, 0, 3, 0, 0, 4);

    t1.printSides();

    t1.printPerimeter();

    t1.printArea();

    fmt::print("Класс с аггрегацией:\n");

    // точки создаются независимо от класса треугольник

    Dot p1(0, 0);

    Dot p2(3, 0);

    Dot p3(0, 4);

    TriangleAggregation t2(p1, p2, p3);

    t2.printSides();

    t2.printPerimeter();

    t2.printArea();

    return 0;

}