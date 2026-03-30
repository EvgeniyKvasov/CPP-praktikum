#include <iostream>
#include <fmt/core.h>
#include <fstream>
#include <string>

using namespace std;

void printArray(int n, int mas[]) {

	fmt::print("Исходный массив: ");

	for (int i = 0; i < n; i++) {

		fmt::print("{} ", mas[i]);

	}

	fmt::print("\n");
}

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

int main()
{
   
	system("chcp 1251");
	
	fmt::print("Лабораторная 6.\n");

	fmt::print("Выберите задание (1-2):\n");

	int op;

	cin >> op;

	cin.ignore();

	switch (op) {

	case 1: {

		fmt::print("Задание 1. Запись текста в файл.\n");

		string filename = "stih.txt";

		ofstream out(filename);

		if (!out) {

			fmt::print("Файл открыть невозможно!\n");

			return 1;
		}

		fmt::print("Введите небольшое стихотворение:\n");

		string line;

		while (getline(cin, line) && !line.empty()) {

			out << line << '\n';
		}

		out.close();

		fmt::print("Данные успешно записаны в {}.", filename);

		break;

	}

	case 2: {

		fmt::print("Задание 2. Сохранение данных в текстовый файл.\n");

		int a[] = { 1,2,3,4,5,6,7,2 };

		int b[] = { 7,6,5,4,3,2,1,3 };

		int kc = sizeof(a) / sizeof(a[0]);

		printArray(kc, a);

		printArray(kc, b);

		int* c;

		c = max_vect(kc, a, b);

		fmt::print("Результат: ");

		for (int i = 0; i < kc; i++) {

			fmt::print("{} ", c[i]);

		}

		string filename = "sortArray.txt";

		ofstream out(filename);

		for (int i = 0; i < kc; i++) {

			out << a[i] << " ";

		}

		out << "\n";  

		for (int i = 0; i < kc; i++) {

			out << b[i] << " ";

		}

		out << "\n"; 

		for (int i = 0; i < kc; i++) {

			out << c[i] << " ";

		}

		out << "\n"; 

		out.close();

		fmt::print("\n");

		delete[]c;

		fmt::print("Данные успешно записаны в {}.", filename);

		break;

	}

	}

	return 0;

}


