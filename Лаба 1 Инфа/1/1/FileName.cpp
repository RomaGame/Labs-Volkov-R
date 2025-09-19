#include <iostream>

int main() {
	setlocale(LC_ALL, "rus");
	double v;
	std::cout << "Введите скорость" << std::endl;
	std::cin >> v;
	if (v < 60) {
		std::cout << "Скорость в пределах нормы" << std::endl;
	}
	else if (60 <= v <= 80) {
		std::cout << "Вы приближаетесь к превышению скорости" << std::endl;
	}
	else {
		std::cout << "Превышение скорости!" << std::endl;
	}


	return 0;
}