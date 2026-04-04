#include <iostream>
#include <fmt/core.h>

class Time {

public:

    int h, m, s;

    //нулевой конструктор

    Time() : h(0), m(0), s(0) {}

    //коструктор с параметрами
    
    Time(int hours, int minutes, int seconds) {

        int total = hours * 3600 + minutes * 60 + seconds;

        h = total / 3600;

        m = (total % 3600) / 60;

        s = total % 60;
    }

    void print() const { 
        
        fmt::print("{}:{}:{}\n", h, m, s); 
    
    }
    
    Time add(const Time& t) const {

        return Time(0, 0, (h*3600 + m*60 + s) + (t.h*3600 + t.m*60 + t.s));

    }
};

int main() {

    system("chcp 1251");

    fmt::print("Задание 1. Класс Time.\n");

    fmt::print("Заданные времена t1 и t2:\n");

    const Time t1(2, 70, 90);

    const Time t2(1, 30, 45);

    t1.print();

    t2.print();

    Time t3;
    
    t3 = t1.add(t2);

    fmt::print("Сумма t1 и t2:\n");

    t3.print();
}