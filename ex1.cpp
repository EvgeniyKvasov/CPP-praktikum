#include <iostream>
#include <cmath>
#include <fmt/core.h>

using namespace std;

int main()
{
	system("chcp 1251");

	fmt::print("Зачада 1: расчет площади многоугольника.\n");

	fmt::print("\nВведите координаты вершин выпуклого пятиугольника попарно в формате x1 = , y2 = , и т.д.\n");

	int x1, x2, x3, x4, x5, y1, y2, y3, y4, y5;

	cin >> x1 >> y1;

	cin >> x2 >> y2;

	cin >> x3 >> y3;

	cin >> x4 >> y4;

	cin >> x5 >> y5;

	double s = abs((x1 * y2 + x2 * y3 + x3 * y4 + x4 * y5 + x5 * y1 - x2 * y1 - x3 * y2 - x4 * y3 - x5 * y4 - x1 * y5)) / 2;

	fmt::print("\nПлощадь фигуры равна: {}", s);

	return 0;  
}


