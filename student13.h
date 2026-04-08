#pragma once
#include "human.h"
#include <string>
#include <vector>

class student : public human {

public:

    student(std::string last_name, std::string name, std::string second_name,

        std::vector<int> scores) : human(last_name, name, second_name) {

        this->scores = scores;

    }

    float get_average_score() const {

        unsigned int count_scores = (unsigned int)this->scores.size();

        unsigned int sum_scores = 0;

        for (unsigned int i = 0; i < count_scores; ++i) {

            sum_scores += this->scores[i];

        }

        return (float)sum_scores / (float)count_scores;

    }

    // Переопределение виртуальных методов

    std::string get_role() const override {

        return "Студент";

    }

    std::string get_info() const override {

        return get_full_name() + " (ср.балл: " + std::to_string(get_average_score()) + ")";

    }

private:

    std::vector<int> scores;

};