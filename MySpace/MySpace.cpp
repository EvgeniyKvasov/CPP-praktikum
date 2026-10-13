#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int nod(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int difoant(int a, int b, int c) {
	if (c % nod(a, b)) {
		cout << "No decisions!\n";
	}
	return c;
}

int main() {
	cout << "Euclidus algorithm and Difoantus equation.\n";
	int a, b, c;
	cout << "Enter three digits:\n";
	cin >> a >> b >> c;
	cout << nod(a, b) << endl;
	cout << difoant(a, b, c);
	return 0;
}

