#include <iostream>
#include "human.h"
#include "student.h"
#include "teacher.h"
#include <fmt/core.h>
#include <vector>

using namespace std;

int main() {

    system("chcp 1251");

    fmt::print("Тестирование класса student\n");

    vector<int> scores;

    scores.push_back(5);

    scores.push_back(4);

    scores.push_back(5);

    scores.push_back(3);

    scores.push_back(5);

    student* stud = new student("Иванов", "Иван", "Иванович", scores);

    fmt::print("Студент: {}\n", stud->get_full_name());

    fmt::print("Средний балл: {:.2f}\n", stud->get_average_score());

    delete stud;

    fmt::print("\nТестирование класса teacher\n");

    teacher* tch = new teacher("Сергеев", "Дмитрий", "Сергеевич", 40);

    fmt::print("Преподаватель: {}\n", tch->get_full_name());

    fmt::print("Количество часов: {}\n", tch->get_work_time());

    delete tch;

    return 0;
}