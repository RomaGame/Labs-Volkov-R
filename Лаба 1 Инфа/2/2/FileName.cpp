#include <iostream>

int main() {
	setlocale(LC_ALL, "rus");
	int a = 0;
	std::cout << "¬ведите число:" << std::endl;
	std::cin >> a;
	int n = 1;
	while (a > 0) {
		n *= a;
		a -= 1;
	}
	std::cout << n << std::endl;
	return 0;
}