#include <iostream>
#include <fmt/core.h>

using namespace std;

int main()
{
    system("chcp 1251");

    fmt::print("Задание 1. Определение суперпростого числа.\n");

    fmt::print("Введи число:\n");

    int p;

    cin >> p; 

    //сначала проверим является ли число вообще простым

    if (p < 2) {

        fmt::print("Число {} не является простым.\n", p);

        return 0;
    }

    for (int i = 2; i <= sqrt(p); i++) {

        if (p % i == 0) {

            fmt::print("Число {} не является простым.\n", p);

            return 0;
        }
    }

    fmt::print("Число {} простое.\n", p);


    // если все ок, то ище позицию супер чисел среди всех простых чисел

    int k = 0;

    for (int i = 2; i <= p; i++) {

        int j;

        for (j = 2; j <= sqrt(i); j++) {

            if (i % j == 0) {

                break;

            }
        }

        if (j > sqrt(i)) {

            k++;
        }
    }

    if (k < 2) {

        fmt::print("Число {} не является суперпростым .\n", p);

        return 0;
    }

    for (int i = 2; i <= sqrt(k); i++) {

        if (k % i == 0) {

            fmt::print("Число {} не является суперпростым.\n", p);

            return 0;
        }
    }

    fmt::print("Число {} суперпростое .\n", p);

    fmt::print("Позиция суперпростого числа {} равна {}.\n", p, k);

    return 0;
}



