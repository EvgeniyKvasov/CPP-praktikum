#include <iostream>
#include <fmt/core.h>

using namespace std;

bool f1(string input) {

	string cleaned;  

	
	for (char c : input) {
		if (c == ' ' || c == '-') {

			continue;  
		}
		if (isdigit(c)) {

			cleaned += c;  
		}
		else {

			return false;  
		}
	}

	
	if (cleaned.length() != 11) {

		return false;
	}

	
	for (int i = 0; i < 9; i++) {

		if (i + 2 < 9 && cleaned[i] == cleaned[i + 1] && cleaned[i] == cleaned[i + 2]) {

			return false;
		}
	}

	
	int sum = 0;

	for (int i = 0; i < 9; i++) {

		int digit = cleaned[i] - '0';

		int position = 9 - i;

		sum += digit * position;
	}

	
	string control_digit = cleaned.substr(9, 2);

	
	string temp;

	if (sum < 100) {

		temp = to_string(sum);

		if (sum < 10) {

			temp = "0" + temp; 
		}
	}
	else if (sum == 100 || sum == 101) {

		temp = "00";
	}
	else if (sum > 101) {

		int new_sum = sum % 101;

		if (new_sum < 100) {

			temp = to_string(new_sum);

			if (new_sum < 10) {

				temp = "0" + temp;
			}
		}
		else if (new_sum == 100) {

			temp = "00";
		}
	}

	
	return temp == control_digit;
}

double f2(double k) {

	if (k < 0) {

		return (-pow(-k, 1.0 / 3));
	}

	return pow(k, 1.0 / 3);
}

double f2(double x, double y, int i, int j) {

	if (x == 0) return 0;

	x = y;

	for (int i = 0; i < j; i++) {

		x = (2 * x + y / (x * x)) / 3;

		}

	return x;
}

double f3(double a) {

	return (sqrt(3) / 4) * a * a;
}

double f3(double b, double c, double d) {

	if (b + c <= d || b + d <= c || c + d <= b) {

		fmt::print("Ошибка: Треугольник с такими сторонами не существует!\n");

		return -1;
	}

	double p = (b + c + d) / 2;  

	return sqrt(p * (p - b) * (p - c) * (p - d));

}

int f4(int n) {

	if (n == 1) return 5;

	else return(5 * n + f4(n - 1));

}

void f5(int num) {

	if (num > 0) {

		f5(num / 2);  

		fmt::print("{}", num % 2);

	}
}

int main()
{

	system("chcp 1251");

	fmt::print("Выберите номер задания из 1-5.\n");

	int op;

	cin >> op;

	switch (op) {

	case 1: {

		fmt::print("Задание 1. Проверка номера СНИЛС.\n");

		fmt::print("Введи номер СНИЛС для проверки:\n");

		cin.ignore();

		string number;

		getline(cin, number);

		if (f1(number)) {

			fmt::print("TRUE - Номер СНИЛС валидный!\n");

		}
		else {

			fmt::print("FALSE - Номер СНИЛС невалидный!\n");
		}

		break;

	}

	case 2: {

		fmt::print("Задание 2. Применение итерации реализации функции.\n");

		fmt::print("Выберите вариант вычисления кубического корня (1 - стандартно через формулу pow; 2 - через итерацию):\n");

		int op1;

		cin >> op1;

		switch (op1) {

		case 1: {
		
			fmt::print("Рассчет кубического корня по стандартной фукнции pow.\n");

			fmt::print("Введи число:\n");

			double k;

			cin >> k;

			double result = f2(k);

			fmt::print("Кубический корень из числа {} по стандартной фукнции pow равен {}:\n", k, result);

			break;
		}

		case 2: {

			fmt::print("Рассчет кубического корня через итерацию.\n");

			fmt::print("Рассчет кубического корня через итерацию (формулу Ньютона).\n");

			fmt::print("Введи число итераций:\n");

			double j;

			cin >> j;

			fmt::print("Введи число:\n");

			double x;

			cin >> x;

			double result1 = f2(x);

			fmt::print("Кубический корень из числа {} по формуле Ньютона через итераций {} равен {}:\n", x, j, result1);

			break;
		}

		}

		break;

	}

	case 3: {

		fmt::print("Задание 3. Работа с различными треугольниками.\n");

		fmt::print("Выберите тип треуголника (1 - равносторонний; 2 - разносторонний):\n");

		int op2;

		cin >> op2;

		switch (op2) {

		case 1: {

			fmt::print("Рассчитаем площадь равностороннего треугольника.\n");

			fmt::print("Введи сторону:\n");

			double a;

			cin >> a;

			if (a <= 0) {

				fmt::print("Ошибка: cторона должна быть положительным числом!\n");

			}
			else {

				double s = f3(a);

				fmt::print("Площадь равностороннего треугольника со стороной {} равна: {}.\n", a, s);
			}

			break;

		}

		case 2: {

			fmt::print("Рассчитаем площадь разностороннего треугольника.\n");

			fmt::print("Введи стороны:\n");

			double b, c, d;

			cin >> b >> c >> d;

			if (b <= 0 || c <= 0 || d <= 0) {

				fmt::print("Ошибка: cтороны должны быть положительными числами!\n");

			}
			else {

				double s1 = f3(b, c, d);

				if (s1 > 0) {

					fmt::print("Площадь разностороннего треугольника со сторонами {}, {} и {} равна: {}.\n", b, c, d, s1);
				}

			}


			break;


		}

		}

		break;

	}

	case 4: {

		fmt::print("Задание 4. Рекурсивная функция суммы ряда.\n");

		fmt::print("Введи число:\n");

		int n;

		cin >> n;

		int sum = f4(n);

		fmt::print("Суммая ряда:\n");

		fmt::print("{}\n", sum);

		break;

	}

	case 5: {

		fmt::print("Задание 5. Применение рекурсии для перевода целого числа в двоичный код.\n");

		fmt::print("Введи число:\n");

		int num;

		cin >> num;

		fmt::print("Число {} в двоичном виде: ", num);

		if (num == 0) {

			fmt::print("0");

		}

		else {

			f5(num);

		}

		break;

	}

	}
}



