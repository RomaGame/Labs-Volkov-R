#include <iostream>

int main() {
	setlocale(LC_ALL, "rus");
	double v;
	std::cout << "������� ��������" << std::endl;
	std::cin >> v;
	if (v < 60) {
		std::cout << "�������� � �������� �����" << std::endl;
	}
	else if (60 <= v <= 80) {
		std::cout << "�� ������������� � ���������� ��������" << std::endl;
	}
	else {
		std::cout << "���������� ��������!" << std::endl;
	}


	return 0;
}