#include <iostream>

int main() {
	setlocale(LC_ALL, "rus");
	int nums[10];
	for (int i = 0; i < 10; i++) {
		if (i == 2) {
			std::cout << "Введите 3ее число:" << std::endl;
			std::cin >> nums[i];
			continue;
		}
		std::cout << "Введите " << i + 1 << "ое число:" << std::endl;
		std::cin >> nums[i];
	}
	std::cout << "Массив:";
	for (int n = 0; n < 9; n++) {
		std::cout << nums[n] << ',';
	}
	std::cout << nums[9] << std::endl;
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum += nums[i];
	}
	std::cout << "Сумма:" << sum << std::endl;
	int min = nums[0];
	for (int i = 1; i < 10; i++) {
		if (nums[i] < min) {
			min = nums[i];
		}
	}
	std::cout << "Минимальный элемент:" << min << std::endl;

	for (int i = 1; i < 10; i++) {
		if (nums[i] < nums[i - 1]) {
			for (int n = 0; n < i; n++) {
				if (nums[n] > nums[i]) {
					int num = nums[i];
					for (int a = i; a > n; a--) {
						nums[a] = nums[a - 1];
					}
					nums[n] = num;
					break;
				}
			}
		}
	}
	std::cout << "Сортированный массив:";
	for (int i = 0; i < 9; i++) {
		std::cout << nums[i] << ',';
	}
	std::cout << nums[9];
	return 0;
}