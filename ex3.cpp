#include <iostream>
#include <fmt/core.h>

using namespace std;

int main()
{

	system("chcp 1251");

	fmt::print("Выберите номер задания из 1-5.\n");

	int op;

	cin >> op;

	switch (op) {

	case 1: {

		fmt::print("Задание 1. Проверка номера СНИЛС.\n");

		break;

	}

	case 2: {

		fmt::print("Задание 2. Применение итерации реализации функции.\n");

		break;

	}

	case 3: {

		fmt::print("Задание 3. Работа с различными треугольниками.\n");

		break;

	}

	case 4: {

		fmt::print("Задание 4. Рекурсивная функция суммы ряда.\n");

		break;

	}

	case 5: {

		fmt::print("Задание 5. Применение рекурсии для перевода целого числа в двоичный код.\n");

		break;

	}

	}

}


