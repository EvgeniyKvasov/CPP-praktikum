#include <iostream>
#include <fmt/core.h>
#include <string>

using namespace std;

int main()
{
    system("chcp 1251");

    fmt::print("Здесь 4 задачи. Выбери ту, кторая тебе нужна:\n");

    int op;

    cin >> op;

    switch (op) {


    case 1:

    {


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

        break;

    }
    case 2:
    {

        fmt::print("Задание 2. Проверка номера СНИЛС.\n");

        fmt::print("Введи номер СНИЛС для проверки:\n");

        cin.ignore(); //иначе считаестя выбор задачи и завершится без ввода СНИЛС

        string number;

        getline(cin, number);

        //проверим что пользователь вводит именно 11 цифр

        if (number.size() == 11) {

            for (int i = 0; i < 9; i++) {

                if (number[i] == number[i + 1] && number[i] == number[i + 2]) {

                    fmt::print("Номер СНИЛС некорректный: больше двух одинаковых цифр подряд!\n");

                    return 0;
                }
            }

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

        //переменная для хранения вычисленного control_digit

        string temp;

        //проверяем сумму согласно условиям задания

        //Если сумма меньше 100, то контрольное число равно самой сумме.

        if (sum < 100) {

            temp = to_string(sum);

        }

        //Если сумма равна 100 или 101, то контрольное число равно 00.

        else if (sum == 100 || sum == 101) {

            temp = "00";
        }

        //Если сумма больше 101, то вычисляется остаток от деления суммы на 101.

        else if (sum > 101) {

            int new_sum = sum % 101;

            fmt::print("Остаток от деления {}\n", new_sum);

            //Если остаток меньше 100, то контрольное число равно остаток.

            if (new_sum < 100) {

                temp = to_string(new_sum);

            }

            else if (new_sum == 100) {

                temp = "00";

            }


        }

        // в конце сравниваем

        if (temp == control_digit) {

            fmt::print("TRUE\n");
        }
        else {

            fmt::print("FALSE\n");
        }

        break;

    }

    case 3:

    {

        fmt::print("Задание 3. Размен монет.\n");

        fmt::print("Введи число монет:\n");

        int m;

        cin >> m;

        fmt::print("Число монет: {}.\n", m);

        int coins[4]{ 10, 5, 2, 1 };

        fmt::print("Номиналы монет России:\n");

        for (int i = 0; i < 4; i++) {

            fmt::print("{} ", coins[i]);
        }

        fmt::print("\n");

        fmt::print("Выдаем {} снаименьшим возможным количеством монет:\n", m);

        //создаем переменную для хранения результатов

        int temp1;

        //перебираем враианыт размена

        for (int i = 0; i < 4; i++) {

            if (m >= coins[i]) {

                temp1 = m / coins[i];

                fmt::print("{} x {}\n", coins[i], temp1);

                m = m % coins[i];
            }
        }

        break;

    }

    case 4:

    {

        fmt::print("Задание 4. Стрельба по мишени.\n");

        fmt::print("Введи количество очков, которое хочешь набрать:\n");

        int x, y, b;

        cin >> b;

        fmt::print("Ведем стрельбу пока не наберем {} очков.\n", b);

        //переменная для очков до начала стрельбы

        int t = 0;

        //переменная для выстрелов до начала стрельбы

        int s = 0;

        //дял определения уровня стрелка (50 очков)

        string l;

        while (t < b) {



            fmt::print("Введи данные выстрела в видепары чисел координат x = , y = :\n");

            cin >> x; cin >> y;

            fmt::print("Координаты выстрела x = {}, y = {}.\n", x, y);

            //переменная для хранения заработанных очков

            int count;

            //вычисляем расстояние от центра мишени

            double d = sqrt(x * x + y * y);

            if (d >= 0 && d < 1) {

                count = 10;

                fmt::print("Попадание! +10 очков.\n");

            }

            else if (d >= 1 && d < 2) {

                count = 5;

                fmt::print("Попадание! +5 очков.\n");
            }

            else if (d >= 2 && d < 3) {

                count = 1;

                fmt::print("Попадание! +1 очков.\n");
            }

            else {

                count = 0;

                fmt::print("Промах! +0 очков.\n");
            }

            t = t + count;

            fmt::print("Всего набрано: {}/{}\n", t, b);

            s = s + 1;

            // определяем уровень стрелка - снайпер, стрелок, новичок (для количества очков 50)

            if (s <= 5) {

                l = "Снайпер";

            }

            else if (s <= 10) {

                l = "Стрелок";

            }

            else {

                l = "Новичок";


            }


        }

        fmt::print("Поздравляю! Цель достигнута! Набрано {} очков. За количество выстрелов {}. Ваш уровень как стрелка {}!\n", t, s, l);

        break;
    }
    }
}



