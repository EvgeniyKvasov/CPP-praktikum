#include <iostream>
#include <fmt/core.h>
#include <vector>

using namespace std;

// Шаблонная функция для вычисления среднего арифметического

template<typename T>

double average(const T arr[], int size) {

    double sum = 0;

    for (int i = 0; i < size; ++i) {

        sum += arr[i];

    }

    return sum / size;

}

// Шаблонная функция Print

template<typename Container>

void Print(const Container& cont, const string& delimiter) {

    bool first = true;

    for (const auto& elem : cont) {

        if (!first) {

            cout << delimiter;

        }

        cout << elem;

        first = false;

    }

    cout << endl;

}

// Шаблонная функция maxOfTwo

template<typename T>

T maxOfTwo(T a, T b) {

    return (a < b) ? b : a;

}

// Концепт Sortable

template<typename T>

concept Sortable = requires(T a, T b) {

    { a < b } -> convertible_to<bool>;

    { a > b } -> convertible_to<bool>;

};

// Функция is_sorted

template<Sortable T>

bool is_sorted(const vector<T>& v) {

    for (size_t i = 1; i < v.size(); ++i) {

        if (v[i] < v[i - 1]) {

            return false;

        }

    }

    return true;

}

int main()
{
    
    system("chcp 1251");

    fmt::print("Практическое занятие 14. Использование шаблонных функций и классов.\n");

    fmt::print("Выберите контрольное задание (1-4):\n");

    int op;

    cin >> op;

    switch (op) {

    case 1: {

        fmt::print("Задание 1. Шаблонная функция обработки массива.\n");

        // Массив типа int

        int intArr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

        int intSize = sizeof(intArr) / sizeof(intArr[0]);

        fmt::print("Массив int: среднее = {:.2f}\n", average(intArr, intSize));

        // Массив типа long

        long longArr[] = { 10L, 20L, 30L, 40L, 50L };

        int longSize = sizeof(longArr) / sizeof(longArr[0]);

        fmt::print("Массив long: среднее = {:.2f}\n", average(longArr, longSize));

        // Массив типа double

        double doubleArr[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };

        int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);

        fmt::print("Массив double: среднее = {:.2f}\n", average(doubleArr, doubleSize));

        // Массив типа char (тут будут учитываться номера символов ASCII)

        char charArr[] = { 'A', 'B', 'C', 'D', 'E' };

        int charSize = sizeof(charArr) / sizeof(charArr[0]);

        fmt::print("Массив char: среднее = {:.2f}\n", average(charArr, charSize));

        break;

    }

    case 2: {

        fmt::print("Задание 2. Шаблонная функция вывода данных в поток.\n");

        vector<int> data = { 1, 2, 3 };

        Print(data, ", ");

        break;

    }

    case 3: {

        fmt::print("Задание 3. Шаблонная функция maxOfTwo с ограничением.\n");

        fmt::print("maxOfTwo(5, 10) = {}\n", maxOfTwo(5, 10));

        fmt::print("maxOfTwo(2.1, 3.5) = {}\n", maxOfTwo(2.1, 3.5));

        break;

    }

    case 4: {

        fmt::print("Задание 4. Шаблонная функция для сортировки.\n");

        vector<int> v1 = { 1, 2, 3, 4, 5 };

        vector<int> v2 = { 1, 3, 2, 4, 5 };

        Print(v1, ", "); fmt::print("{}\n", is_sorted(v1) ? "отсортирован" : "не отсортирован");

        Print(v2, ", "); fmt::print("{}\n", is_sorted(v2) ? "отсортирован" : "не отсортирован");

        vector<string> v3 = { "a", "b", "c", "d" };

        vector<string> v4 = { "a", "c", "b", "d" };

        Print(v3, ", "); fmt::print("{}\n", is_sorted(v3) ? "отсортирован" : "не отсортирован");

        Print(v4, ", "); fmt::print("{}\n", is_sorted(v4) ? "отсортирован" : "не отсортирован");

        break;

    }

    }

    return 0;

}

