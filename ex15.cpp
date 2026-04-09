#include <iostream>
#include <fmt/core.h>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Структура StudentGrade

struct StudentGrade {

    string name;

    char grade;

};

// Функция поиска максимального чётного числа

int FindMaxEven(const vector<int>& v) {

    int maxEven = -1;

    bool found = false;

    for (int num : v) {

        if (num % 2 == 0) {

            if (!found || num > maxEven) {

                maxEven = num;

                found = true;

            }

        }

    }

    if (!found) {

        throw runtime_error("Чётных чисел нет");

    }

    return maxEven;

}

int main()
{
    
    system("chcp 1251");

    fmt::print("Практическое занятие 15. Использование STL.\n");

    fmt::print("Выберите контрольное задание (1-2):\n");

    int op;

    cin >> op;

    switch (op) {

    case 1: {

        fmt::print("Задание 1. Организация хранения данных в контейнере.\n");

        // Контейнер map: имя -> оценка

        map<string, char> grades;

        // Список студентов без оценок

        string students[] = { "Иванов", "Петров", "Сидоров" };

        // выводим список студентов без оценок

        fmt::print("Список студентов:\n");

        for (const string& name : students) {

            fmt::print("{}\n", name);

        }

        // Присваиваем оценки каждому студенту

        for (const string& name : students) {

            char grade;

            fmt::print("Введите оценку для {}: ", name);

            cin >> grade;

            grades[name] = grade;

        }

        // Выводим список студентов с оценками

        fmt::print("Список студентов с оценками:\n");

        for (const auto& p : grades) {

            fmt::print("{}: {}\n", p.first, p.second);

        }

        break;

    }

    case 2: {

        fmt::print("Задание 2. Поиск максимального чётного числа в векторе.\n");

        vector<int> v = { 1, 3, 5, 4, 11, 7, 13 };

        fmt::print("Вектор: ");

        for (int num : v) {

            fmt::print("{} ", num);

        }

        fmt::print("\n");

        try {

            int result = FindMaxEven(v);

            fmt::print("Максимальное чётное число: {}\n", result);

        }

        catch (const runtime_error& e) {

            fmt::print("Ошибка: {}\n", e.what());

        }

        break;

    }

    }

    return 0;

}

