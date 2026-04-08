#include <iostream>
#include <fmt/core.h>
#include <vector>
#include "human13.h"
#include "student13.h"
#include "teacher13.h"

using namespace std;

class Vehicle {

public:

    virtual ~Vehicle() = default;

    virtual void move() const = 0;

    virtual string type() const = 0;

};

class Car : public Vehicle {

public:

    void move() const override {

        fmt::print("Car is driving on the road.\n");

    }

    string type() const override {

        return "Car";

    }

};

class Boat : public Vehicle {

public:

    void move() const override {

        fmt::print("Boat is sailing on water.\n");

    }

    string type() const override {

        return "Boat";

    }

};

class Plane : public Vehicle {

public:

    void move() const override {

        fmt::print("Plane is flying in the sky.\n");

    }

    string type() const override {

        return "Plane";

    }

};

int main()
{
    
    system("chcp 1251");

    fmt::print("Практическое занятие 13. Применение полиморфизма.\n");

    fmt::print("Выберите контрольное задание (1-2):\n");

    int op;

    cin >> op;

    switch (op) {

    case 1: {

        fmt::print("Задание 1. Иерархия транспортных средств.\n");

        vector<unique_ptr<Vehicle>> vehicles;

        vehicles.push_back(make_unique<Car>());

        vehicles.push_back(make_unique<Boat>());

        vehicles.push_back(make_unique<Plane>());

        for (const auto& v : vehicles) {

            fmt::print("{} : ", v->type());

            v->move();

        }

        break;

    }

    case 2: {

        fmt::print("Задание 2. Полиморфизм в системе классов учебного центра.\n");

        // Вектор указателей на базовый класс

        vector<human*> persons;

        // Создание объектов

        vector<int> scores;

        scores.push_back(5);

        scores.push_back(4);

        scores.push_back(5);

        scores.push_back(3);

        scores.push_back(5);

        persons.push_back(new student("Иванов", "Иван", "Иванович", scores));

        persons.push_back(new teacher("Петрова", "Мария", "Сергеевна", 150));

        persons.push_back(new student("Сидоров", "Петр", "Алексеевич", scores));

        persons.push_back(new teacher("Сергеев", "Дмитрий", "Сергеевич", 40));

        // Полиморфный вызов

        fmt::print("Результат полиморфного вызова:\n");

        for (const auto* p : persons) {

            fmt::print("{}: {}\n", p->get_role(), p->get_info());

        }

        // Освобождение памяти

        for (auto* p : persons) {

            delete p;

        }

        break;

    }

    }

    return 0;

}
