#include <iostream>
#include <cstring>

int main() {
	setlocale(LC_ALL, "rus");
	char str[100];
	std::cout << "������� ������:";
	std::cin.getline(str,100);
	
	char *ptr = str;
	int count_b = 0;
	int max_len = 0;
	int cur_len = 1;
	int count_q = 0;
	char sec;
	while (*ptr != '\0') {
		ptr++;
		while ((*ptr != ' ') and (*ptr != '\0')) {
			cur_len++;
			if (cur_len == 2) {
				sec = *ptr;
			}
			ptr++;		
		}
		ptr--;
		if ((*ptr == 'b') or (*ptr == 'B')) {
			count_b++;
		}
		if (cur_len > 1) {
			ptr--;
			if (sec == *ptr) {
				count_q++;
			}
			ptr++;
		}
		if (cur_len > max_len) {
			max_len = cur_len;
		}
		cur_len = 0;
		ptr++;
	}
	int count_d = 0;
	ptr--;
	while (*ptr != ' ') {
		if ((*ptr == 'd') or (*ptr == 'D')) {
			count_b++;
		}
		ptr--;
	}
	std::cout << "����, �������������� �� ����� b:" << count_b << std::endl;
	std::cout << "������ ������ �������� �����:" << max_len << std::endl;
	std::cout << "���� d � ��������� �����:" << count_d << std::endl;
	char *ptr1 = str;
	while (*ptr1 != '\0') {
		if (('a' <= *ptr1) and (*ptr1 <= 'z')) {
			*ptr1 = char(*ptr1 + 'A' - 'a');
		}
		ptr1++;
	}
	std::cout << "������ ������:" << str;
	std::cout << "���� � ������������ ������ � ������������� ��������:" << count_q << std::endl;
	return 0;
}