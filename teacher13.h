#pragma once
#include "human.h"
#include <string>

class teacher : public human {

public:

    teacher(std::string last_name, std::string name, std::string second_name,

        unsigned int work_time) : human(last_name, name, second_name) {

        this->work_time = work_time;

    }

    unsigned int get_work_time() const {

        return this->work_time;

    }

    // Переопределение виртуальных методов

    std::string get_role() const override {

        return "Преподаватель";

    }

    std::string get_info() const override {

        return get_full_name() + " (часы: " + std::to_string(get_work_time()) + ")";

    }

private:

    unsigned int work_time;

};