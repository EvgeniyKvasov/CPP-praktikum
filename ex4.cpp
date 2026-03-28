#include <iostream>
#include <fmt/core.h>

using namespace std;

int Myroot(double a, double b, double c, double& x1, double& x2) {

    // Проверим, что уравнение является квадратным 
    if (a == 0) {

        fmt::print("Предупреждение: уравнение не является квадратным!\n");

        if (b == 0) {

            if (c == 0) {

                fmt::print("Уравнение имеет бесконечно много корней!\n");

                return -1;
            }
            return -1;
        }
        else {

            x1 = -c / b;

            x2 = x1;

            return 0;
        }
    }

    double D = b * b - 4 * a * c;

    fmt::print("Дискриминант равен {}\n", D);

    if (D < 0) {

        return -1;
    }

    else if (D == 0) {

        x1 = -b / (2 * a);

        x2 = x1;

        return 0;
    }
    else {

        x1 = (-b + sqrt(D)) / (2 * a);

        x2 = (-b - sqrt(D)) / (2 * a);

        return 1;
    }
}

bool Input(int& a, int& b) {

    fmt::print("Введите два числа:\n");

    cin >> a >> b;


    if (cin.fail()) {

        return false;
    }

    return true;

}


int main() {

    system("chcp 1251");

    fmt::print("Лабораторная 4. Выберите задание (1 или 2):\n");

    int op;

    cin >> op;

    switch (op) {

    case 1: {

        fmt::print("Задание 1. Вычисление корней квадратного уравнения.\n");

        double a, b, c, x1, x2;
        
        fmt::print("Введите коэффициенты уравнения (a b c):\n");

        cin >> a >> b >> c;

        int result = Myroot(a, b, c, x1, x2);

        
        fmt::print("Результат: ");

        if (result == -1) {

            if (a == 0 && b == 0 && c == 0) {

                fmt::print("Уравнение имеет бесконечно много корней\n");
            }
            else {

                fmt::print("Корней уравнения нет\n");
            }
        }
        else if (result == 0) {

            fmt::print("Корень уравнения один: x1 = x2 = {}\n", x1);
        }
        else {

            fmt::print("Корни уравнения: x1 = {}, x2 = {}\n", x1, x2);
        }

        break;
    }

    case 2: {
        fmt::print("Задание 2. Реализация ввода данных.\n");

        int a, b;

        if (Input(a, b) == false) // if(!Input(a,b))
        {
            cerr << "error";

            return 1;
        }

        int s = a + b;

        fmt::print("Сумма: {}", s);

        return 0;

        break;
    }

    }

    return 0;
}