#include <iostream>
#include <cstring>

int main() {
	setlocale(LC_ALL, "rus");
	char str[100];
	std::cout << "Ââåäèòå ñòðîêó:";
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
			if ((sec == *ptr) or (int(sec) - int(*ptr) == 32) or (int(sec) - int(*ptr) == -32)) {
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
	std::cout << "Ñëîâ, îêàí÷èâàþùèõñÿ íà áóêâó b:" << count_b << std::endl;
	std::cout << "Äëèííà ñàìîãî äëèííîãî ñëîâà:" << max_len << std::endl;
	std::cout << "Áóêâ d â ïîñëåäíåì ñëîâå:" << count_d << std::endl;
	char *ptr1 = str;
	while (*ptr1 != '\0') {
		if (('a' <= *ptr1) and (*ptr1 <= 'z')) {
			*ptr1 = char(*ptr1 + 'A' - 'a');
		}
		ptr1++;
	}
	std::cout << "Ñòðîêà êàïñîì:" << str;
	std::cout << "Ñëîâ ñ ñîâïàäàþùèìè âòîðûì è ïðåäïîñëåäíèì ñèìâîëîì:" << count_q << std::endl;
	return 0;

}
