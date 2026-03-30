#include <iostream>
#include <fmt/core.h>
#include <cstring>

using namespace std;

//функции для задачи 1 (некоторые, например printArray, используются  и в последующих задачах)

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

//функция для задачи 2

int* max_vect(int kc, int a[], int b[]) {

    int* result = new int[kc];  

    for (int i = 0; i < kc; i++) {

        if (a[i] > b[i]) {

            result[i] = a[i];   
        }
        else {

            result[i] = b[i];   
        }
    }

    return result;  
}

//фукнция для задачи 3

int searchTransposition(int mas[], int n, int key) {

    for (int i = 0; i < n; i++) {

        if (mas[i] == key) {

            if (i > 0) {
               
                int temp = mas[i];

                mas[i] = mas[i - 1];

                mas[i - 1] = temp;

                return i;
            }
            return i;
        }
    }
    return -1;
}

//функция для задачи 4

void calculate(char flag[], int x, int y) {

    if (strncmp(flag, "-a", 2) == 0) {

        fmt::print("Результат: {} + {} = {}\n", x, y, x + y);

    }
    else if (strncmp(flag, "-m", 2) == 0) {

        fmt::print("Результат: {} * {} = {}\n", x, y, x * y);

    }
}


int main(int argc, char* argv[])
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

        int a[] = { 1,2,3,4,5,6,7,2 };

        int b[] = { 7,6,5,4,3,2,1,3 };

        int kc = sizeof(a) / sizeof(a[0]); 

        printArray(kc, a);

        printArray(kc, b);

        int* c; 

        c = max_vect(kc, a, b); 

        fmt::print("Результат: ");

        for (int i = 0;i < kc; i++) {

            fmt::print("{} ", c[i]);

        }

        fmt::print("\n");

        delete[]c; 

        break;
    }
    case 3: {

        fmt::print("Задание 3. Реализация алгоритмов поиска методом транспозиции\n");

        int mas[] = { 3, 7, 2, 9, 5 };

        int n = 5;

        fmt::print("Массив: ");

        for (int i = 0; i < n; i++) {

            fmt::print("{} ", mas[i]);

        }

        fmt::print("\n");

        int key;

        fmt::print("Введите число для поиска: ");

        cin >> key;

        int index = searchTransposition(mas, n, key);

        if (index != -1) {

            fmt::print("Число {} найдено на позиции {}\n", key, index);

            fmt::print("Массив после поиска: ");

            for (int i = 0; i < n; i++) {

                fmt::print("{} ", mas[i]);

            }

            fmt::print("\n");
        }
        else {

            fmt::print("Число {} не найдено\n", key);
        }

        break;
    }
    case 4: {

        fmt::print("Задание 4. Передача параметров в программу\n");

        char flag[3];

        fmt::print("Введите флаг (-a для суммы, -m для произведения): ");

        cin >> flag;

        if (strncmp(flag, "-a", 2) != 0 && strncmp(flag, "-m", 2) != 0) {

            fmt::print("Ошибка! Флаг должен быть -a или -m\n");

            break;
        }

        int x, y;

        fmt::print("Введите первое число: ");

        cin >> x;

        fmt::print("Введите второе число: ");

        cin >> y;

        calculate(flag, x, y);

        break;
    }

    }
    
}

