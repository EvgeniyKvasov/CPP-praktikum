#include <iostream>
#include <fmt/core.h>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

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

    Time() : h(0), m(0), s(0) {}

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

    // сложение объектов Time

    Time operator + (const Time& t) const {

        int total = (h * 3600 + m * 60 + s) + (t.h * 3600 + t.m * 60 + t.s);

        return Time(0, 0, total);

    }

    // вычитание объектов Time

    Time operator - (const Time& t) const {

        int total = (h * 3600 + m * 60 + s) - (t.h * 3600 + t.m * 60 + t.s);

        return Time(0, 0, total);

    }

    // сложение объекта Time и переменной вещественного типа

    Time operator + (double hours) const {

        int total = (h * 3600 + m * 60 + s) + (hours * 3600);

        return Time(0, 0, total);

    }

    // сравнение двух объектов Time

    bool operator==(const Time& t) const {

        return (h * 3600 + m * 60 + s) == (t.h * 3600 + t.m * 60 + t.s);

    }

    bool operator<(const Time& t) const {

        return (h * 3600 + m * 60 + s) < (t.h * 3600 + t.m * 60 + t.s);

    }

    bool operator>(const Time& t) const {

        return (h * 3600 + m * 60 + s) > (t.h * 3600 + t.m * 60 + t.s);

    }

};

// сложение переменной вещественного типа и объект Time

Time operator + (double hours, const Time& t) {

    int total = (hours * 3600) + (t.h * 3600 + t.m * 60 + t.s);

    return Time(0, 0, total);

}

class Point {

private:

    double x, y;

public:

    Point(double xCoord = 0, double yCoord = 0) : x(xCoord), y(yCoord) {}

    double distance() const {

        return sqrt(x * x + y * y);

    }

    // перегрузка операторов сравнения

    bool operator<(const Point& other) const {

        return distance() < other.distance();

    }

};

// перегрузка операторов поток вывода

ostream& operator<<(ostream& out, const Point& p) {

    printf("(%.2f)", p.distance());

    return out;

}


int main()
{

    system("chcp 1251");

    fmt::print("Практическое занятие 11.\n");

    fmt::print("Выберите контрольное задаие (1-2):\n");

    int op;

    cin >> op;

    switch (op) {

    case 1: {

        fmt::print("Задание 1. Перегрузка операторов в классе Time.\n");

        fmt::print("Заданные времена t1 и t2:\n");

        try {

            const Time t1(2, 70, 90);

            const Time t2(1, 30, 45);

            t1.print();

            t2.print();

            // сложение объектов Time

            Time t3 = t1 + t2;

            fmt::print("Сумма t1 и t2:\n");

            t3.print();

            // вычитание объектов Time

            Time t4 = t1 - t2;

            fmt::print("Разность t1 и t2:\n");

            t4.print();

            // сложение объекта Time и переменной вещественного типа

            Time t5 = t1 + 1.2;

            fmt::print("Сумма t1 и 1.2:\n");

            t5.print();

            // сложение переменной вещественного типа и объект Time

            Time t6 = 1.2 + t2;

            fmt::print("Сумма 1.2 и t2:\n");

            t6.print();

            // сравнение двух объектов Time

            fmt::print("Сравнение t1 и t2:\n");

            if (t1 == t2) {

                fmt::print("t1 равно t2\n");

            }

            else if (t1 < t2) {

                fmt::print("t1 меньше t2\n");

            }

            else {

                fmt::print("t1 больше t2\n");

            }

        }

        catch (TimeError& error) {

            error.printMessage();

            return 1;

        }
        
        break;

    }

    case 2: {

        fmt::print("Задание 2. Реализация сортировки точек в векторе.\n");

        vector<Point> v;

        v.push_back(Point(1, 2));

        v.push_back(Point(10, 12));

        v.push_back(Point(21, 7));

        v.push_back(Point(4, 8));

        sort(v.begin(), v.end()); 

        fmt::print("Вывод отсортированных точек:\n");
      
        for (auto& point : v) {

            cout << point << '\n';

        }

        break;

    }

    }

    return 0;

}

