#include <iostream>
#include <fmt/core.h>
#include <string>

using namespace std;

int main()
{
    system("chcp 1251");

    /*

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

    */

    fmt::print("Задание 2. Проверка номера СНИЛС.\n");

    fmt::print("введи номер СНИЛС дял проверки:\n");

    string number;

    getline(cin, number);

    //проверим что пользователь вводит именно 11 цифр

    if (number.size() == 11) {

        fmt::print("СНИЛС: {}\n", number);

    }

    else {

        fmt::print("Номер СНИЛС {} некорректный!\n", number);

        return 0;
    }

    fmt::print("Все произведения и их сумма:\n");

    //умножаем кажду цифру на позицию и суммируем все произвдения

    int sum = 0;

    for (int i = 0; i < 9; i++) {

        int digit = number[i] - '0';

        int position = 9 - i;

        int k = digit * position;

        fmt::print("{} * {} = {}\n", digit, position, k);

        sum = sum + k;

    }

    fmt::print("Общая сумма равна {}\n", sum);

    //создаем переменную куда внесем контрольное число

    string control_digit = number.substr(9, 2);

    fmt::print("Контрольное число равно = {}\n", control_digit);

    //проверяем сумму согласно условиям задания

    //Если сумма меньше 100, то контрольное число равно самой сумме.
 
    if (sum < 100) {

        control_digit = sum;

        fmt::print("TRUE\n");
    }
    else {

        fmt::print("FALSE\n");

    }

    //Если сумма равна 100 или 101, то контрольное число равно 00.

    if (sum == 100 || sum == 101) {

        control_digit = sum;

        fmt::print("TRUE\n");
    }
    else {

        fmt::print("FALSE\n");

    }

    //Если сумма больше 101, то вычисляется остаток от деления суммы на 101.

    if (sum > 101) {

        sum = sum % 101;

        fmt::print("Остаток от деления {}\n", sum);

        //Если остаток меньше 100, то контрольное число равно остаток.

        if (sum < 100) {

            control_digit = sum;

            fmt::print("TRUE\n");
        }

        //Если остаток равен 100, то контрольное число равно 00.

        if (sum == 100) {

            control_digit = '00';

            fmt::print("TRUE\n");
        }
        else {

            fmt::print("FALSE\n");

        }
    }
  
}



