#include <iostream>
#include <fmt/core.h>

using namespace std;

void inputArray(int n, int mas[]) {

    for (int i = 0; i < n; i++) {

        fmt::print("mas[{}] = ", i);

        cin >> mas[i];

    }
}

void printArray(int n, int mas[]) {

    fmt::print("Исходный массив: ");

    for (int i = 0; i < n; i++) {

        fmt::print("{} ", mas[i]);

    }

    fmt::print("\n");
}

void sumArray(int n, int mas[]) {

    int s = 0;

    for (int i = 0; i < n; i++) {

        s += mas[i];

    }

    fmt::print("Сумма элементов массива {}\n", s);
}

void mediumArray(int n, int mas[]) {

    int s = 0;

    for (int i = 0; i < n; i++) {

        s += mas[i];

    }

    double m = double(s) / n;

    fmt::print("Среднее арифметическое элементов массива {}\n", m);
}

void minusArray(int n, int mas[]) {

    int s = 0;

    for (int i = 0; i < n; i++) {

        if (mas[i] < 0) {

            s += mas[i];

        }
    }

    fmt::print("Сумма отрицательных элементов массива {}\n", s);

}

void plusArray(int n, int mas[]) {

    int s = 0;

    for (int i = 0; i < n; i++) {

        if (mas[i] > 0) {

            s += mas[i];

        }
    }

    fmt::print("Сумма положительных элементов массива {}\n", s);

}

void plusNechetArray(int n, int mas[]) {

    int s = 0;

    for (int i = 0; i < n; i += 2) {

        s += mas[i];

    }

    fmt::print("Сумма элементов с нечетными индексами {}\n", s);

}

void plusChetArray(int n, int mas[]) {

    int s = 0;

    for (int i = 1; i < n; i += 2) {

        s += mas[i];

    }

    fmt::print("Сумма элементов с четными индексами {}\n", s);

}

void minmaxArray(int n, int mas[]) {

    int min = mas[0];

    int minIndex = 0;

    for (int i = 1; i < n; i++) {

        if (mas[i] < min) {

            min = mas[i];

            minIndex = i;

        }
    }

    fmt::print("Минимальный элемент массива {} и его индекс {}\n", min, minIndex);

    int max = mas[0];

    int maxIndex = 0;

    for (int i = 1; i < n; i++) {

        if (mas[i] > max) {

            max = mas[i];

            maxIndex = i;

        }
    }

    fmt::print("Максимальный элемент массива {} и его индекс {}\n", max, maxIndex);

    int start, end;

    if (minIndex < maxIndex) {

        start = minIndex;

        end = maxIndex;
    }
    else {

        start = maxIndex;

        end = minIndex;
    }

    double temp = 1;

    for (int i = start + 1; i < end; i++) {

        temp = temp * mas[i];
    }

    if (end - start <= 1) {

        fmt::print("Нет элементов между минимальным и максимальным\n");

    }
    else {

        fmt::print("Произведение элементов между минимумом и максимумом {}\n", temp);

    }
}

void sortArray(int n, int mas[]) {

    int min = 0;

    int buf = 0;

    for (int i = 0; i < n; i++) {

        min = i;

        for (int j = i + 1; j < n; j++) {

            if (mas[j] < mas[min]) {

                min = j;
            }
        }
        if (i != min) {

            buf = mas[i];

            mas[i] = mas[min];

            mas[min] = buf;
        }
    }

    fmt::print("Отсортированный массив: ");

    for (int i = 0; i < n; i++) {

        fmt::print("{} ", mas[i]);
    }
}


int main()
{
    system("chcp 1251");

    fmt::print("Лабораторная 5.\nВыберите номер задачи (1-4):\n");

    int op;

    cin >> op;

    switch (op) {

    case 1: {

        fmt::print("Задание 1. Передача массива в функцию\n");

        int n;

        fmt::print("Введи размерность массива:\n");

        cin >> n;

        int* mas = new int[n];

        inputArray(n, mas);

        printArray(n, mas);

        sumArray(n, mas);

        mediumArray(n, mas);

        minusArray(n, mas);

        plusArray(n, mas);

        plusNechetArray(n, mas);

        plusChetArray(n, mas);

        minmaxArray(n, mas);

        sortArray(n, mas);

        break;
    }
    case 2: {

        fmt::print("Задание 2. Возврат массива из функции\n");

        break;
    }
    case 3: {

        fmt::print("Задание 3. Реализация алгоритмов поиска методом транспозиции\n");

        break;
    }
    case 4: {

        fmt::print("Задание 4. Передача параметров в программу\n");

        break;
    }

    }
    
}

