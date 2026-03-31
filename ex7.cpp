#include <iostream>
#include <fmt/core.h>
#include <cmath>
#include <tuple>

using namespace std;

//структура для задачи 1 - время

struct Time {

    int hours;

    int minutes;

    int seconds;

    Time add(Time t) {

        Time result;

        int total = hours * 3600 + minutes * 60 + seconds +  t.hours * 3600 + t.minutes * 60 + t.seconds;

        result.hours = total / 3600;

        total %= 3600;

        result.minutes = total / 60;

        result.seconds = total % 60;

        return result;
    }

    Time subtract(Time t) {

        Time result;

        int total = hours * 3600 + minutes * 60 + seconds - (t.hours * 3600 + t.minutes * 60 + t.seconds);

        if (total < 0) total = 0;

        result.hours = total / 3600;

        total %= 3600;

        result.minutes = total / 60;

        result.seconds = total % 60;

        return result;
    }
};

// струтура для задачи 2 - хранение корней

struct QuadraticSolution {

    double root1;

    double root2;

    bool hasRoots;

};

//функция для решения квдаратного уравнения

QuadraticSolution solveEquation0(double a, double b, double c) {

    QuadraticSolution sol;

    sol.hasRoots = true;

    if (a == 0) {

        fmt::print("Это не квадратное уравнение!\n");

        sol.hasRoots = false;

        sol.root1 = sol.root2 = 0;

        return sol;
    }

    double d = b * b - 4 * a * c;

    if (d >= 0) {

        sol.root1 = (-b + sqrt(d)) / (2 * a);

        sol.root2 = (-b - sqrt(d)) / (2 * a);

    }
    else {

        fmt::print("Дискриминант отрицательный! Действительных корней нет.\n");

        sol.hasRoots = false;

        sol.root1 = sol.root2 = 0;
    }

    return sol;

}

//кортеж дя задачи 3

tuple<double, double, bool> solveEquation1(double a, double b, double c) {

    double root1 = 0, root2 = 0;

    bool hasRoots = false;

    if (a == 0) {

        fmt::print("Это не квадратное уравнение!\n");

        return make_tuple(root1, root2, hasRoots);

    }

    double d = b * b - 4 * a * c;

    if (d >= 0) {

        root1 = (-b + sqrt(d)) / (2 * a);

        root2 = (-b - sqrt(d)) / (2 * a);

        hasRoots = true;
    }
    else {

        fmt::print("Дискриминант отрицательный! Действительных корней нет.\n");

    }

    return make_tuple(root1, root2, hasRoots);
}

int main() {

    system("chcp 1251");

    fmt::print("Лабораторная 7.\n");

    fmt::print("Выберите задачу (1-3):\n");

    int op;

    cin >> op;

    switch (op) {

    case 1: {

        fmt::print("Задание 1. Структура Time.\n");

        Time t;

        fmt::print("Введите часы: ");

        cin >> t.hours;

        fmt::print("Введите минуты: ");

        cin >> t.minutes;

        fmt::print("Введите секунды: ");

        cin >> t.seconds;

        int seconds = t.hours * 3600 + t.minutes * 60 + t.seconds;

        fmt::print("Количество секунд: {}\n", seconds);

        Time t2;

        fmt::print("\nВведите второе время для проверки функций:\n");

        fmt::print("Введите часы: ");

        cin >> t2.hours;

        fmt::print("Введите минуты: ");

        cin >> t2.minutes;

        fmt::print("Введите секунды: ");

        cin >> t2.seconds;

        Time sum = t.add(t2);

        Time diff = t.subtract(t2);

        fmt::print("\nСумма: {}:{}:{}\n", sum.hours, sum.minutes, sum.seconds);

        fmt::print("Разность: {}:{}:{}\n", diff.hours, diff.minutes, diff.seconds);

        break;

    }

    case 2: {

        fmt::print("Задание 2. Решение квадратного уравнения.\n");

        double a, b, c;

        fmt::print("Введите a, b, c: ");

        cin >> a >> b >> c;

        QuadraticSolution result = solveEquation0(a, b, c);

        if (result.hasRoots) {

            fmt::print("Корни: {} и {}\n", result.root1, result.root2);

        }

        break;

    }

    case 3: {

        fmt::print("Задание 3. Решение квадратного уравнения (кортеж).\n");

        double a, b, c;

        fmt::print("Введите a, b, c: ");

        cin >> a >> b >> c;

        auto result = solveEquation1(a, b, c);

        double x1 = get<0>(result);

        double x2 = get<1>(result);

        bool hasRoots = get<2>(result);

        if (hasRoots) {

            fmt::print("Корни: {} и {}\n", x1, x2);

        }

        break;

    }

    }

}


