#include <iostream>
#include <fmt/core.h>
#include <string>

using namespace std;

//класс исключения

class TriangleError {

public:

    TriangleError(const string& msg) : message(msg) {}

    void printMessage() const { fmt::print("Ошибка: {}\n", message); }

private:

    string message;

};

//класс треугольника

class Triangle {

private:

    double a, b, c;

public:

    //конструктор треугольника

    Triangle(double side1, double side2, double side3) {

        //проверка на существование

        if (side1 <= 0 || side2 <= 0 || side3 <= 0) {

            throw TriangleError("cтороны должны быть положительными числами!");

        }

        if (side1 >= side2 + side3 || side2 >= side1 + side3 || side3 >= side1 + side2) {

            throw TriangleError("cтороны не образуют треугольник! Сторона не может быть больше суммы двух других!");

        }

        a = side1;

        b = side2;

        c = side3;

    }

    //формула Герона

    double getTriangle() {

        double p = (a + b + c) / 2;

        return sqrt(p * (p - a) * (p - b) * (p - c));

    }

    //печать на экран

    void printTriangle() {
    
        fmt::print("Стороны треугольника: {}, {}, {}\n", a, b, c);

    }

};

//исключения для класса Time

class TimeError {

public:

    TimeError(const string& msg) : message(msg) {}

    void printMessage() const { fmt::print("Ошибка: {}\n", message); }

private:

    string message;

};

class Time {

public:

    int h, m, s;

    //нулевой конструктор

    Time() : h(0), m(0), s(0) {}

    //коструктор с параметрами 

    //сюда добавим проверку на отрицателньые значения

    Time(int hours, int minutes, int seconds) {

        if (hours < 0 || minutes < 0 || seconds < 0) {

            throw TimeError("часы, минуты и секунды не могут быть отрицательными!");

        }

        int total = hours * 3600 + minutes * 60 + seconds;

        h = total / 3600;

        m = (total % 3600) / 60;

        s = total % 60;
    }

    void print() const {

        fmt::print("{}:{}:{}\n", h, m, s);

    }

    Time add(const Time& t) const {

        return Time(0, 0, (h * 3600 + m * 60 + s) + (t.h * 3600 + t.m * 60 + t.s));

    }
};

int main()
{

    system("chcp 1251");

    fmt::print("Практическое занятие 9. Выберите контрольное задание (1-2):\n");

    int op;

    cin >> op;

    switch (op) {

    case 1: {

        fmt::print("Задание 1. Безопасная реализация класса Triangle.\n");

        double a, b, c;

        fmt::print("Введите стороны треугольника:\n");

        cin >> a >> b >> c;

        try {

            Triangle t(a, b, c);

            t.printTriangle();

            fmt::print("Площадь треугольника со сторонами {}, {} и {} равна: {:.1f}.\n", a, b, c, t.getTriangle());

        }

        catch (TriangleError& error){

            error.printMessage();

            return 1;

        }

        break;

    }

    case 2: {

        fmt::print("Задание 2. Безопасная реализация класса Time.\n");

        fmt::print("Заданные времена t1 и t2:\n");

        try {

            const Time t1(2, 70, 90);

            const Time t2(1, 30, 45);

            t1.print();

            t2.print();

            Time t3;

            t3 = t1.add(t2);

            fmt::print("Сумма t1 и t2:\n");

            t3.print();

        }

        catch (TimeError& error) {

            error.printMessage();

            return 1;

        }

        break;

    }

    }

    return 0; 
    
}

