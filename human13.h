#pragma once
#include <string>
#include <sstream>

class human {

public:

    human(std::string last_name, std::string name, std::string second_name) {

        this->last_name = last_name;

        this->name = name;

        this->second_name = second_name;

    }

    // виртуальный деструктор

    virtual ~human() = default;  

    std::string get_full_name() const {

        std::ostringstream full_name;

        full_name << this->last_name << " "

            << this->name << " "

            << this->second_name;

        return full_name.str();

    }

    // Виртуальные методы для полиморфизма

    virtual std::string get_role() const {

        return "Человек";

    }

    virtual std::string get_info() const {

        return get_full_name();

    }

private:

    std::string name;

    std::string last_name;

    std::string second_name;

};