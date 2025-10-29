#include <iostream>
#include <vector>
#include <string>

int main() {
	std::vector<int> temp, press;
	char word[6];
	char *ch = word;
	std::vector<std::string> commands = {
		"START",
		"SET TEMP 80",
		"SET PRESS 120",
		"STOP",
		"SET TEMP 85"
	};
	
	for (const auto& line : commands) {
		const char* p = line.c_str();
		memset(word, '\0', 6);
		char* ch = word;
		while (*p != '\0') {
			while ((*p != '\0') and (*p != ' ')) {
				*ch = *p;
				ch++;
				p++;
			}
			if (strcmp(word, "START") == 0) {
				std::string status = "Started";
			} else if (strcmp(word, "STOP") == 0) {
				std::string status = "Stoped";
			} else if (strcmp(word, "SET") == 0) {
				p++;
				memset(word, '\0', 6);
				char* ch = word;
				while (*p != ' ') {
					*ch = *p;
					ch++;
					p++;
				}
				if (strcmp(word, "TEMP") == 0) {
					p++;
					int num = 0;
					while (*p != '\0') {
						num = num * 10 + int(*p - '0');
						p++;
					}
					temp.push_back(num);
				}
				else if (strcmp(word, "PRESS") == 0) {
					p++;
					int num = 0;
					while (*p != '\0') {
						num = num * 10 + int(*p - '0');
						p++;
					}
					press.push_back(num);
					while (*p != '\0') {
						p++;
					}
				}
			}
		}
	}
	double avtemp = 0;
	for (int i = 0; i < temp.size(); i++) {
		avtemp += temp[i];
	}
	avtemp /= temp.size();
	int maxpress = 0;
	for (int i = 0; i < press.size(); i++) {
		if (press[i] > maxpress) {
			maxpress = press[i];
		}
	}
	for (int i = 0; i < commands.size(); i++) {
		std::cout << '[' << i + 1 << ']' << commands[i] << std::endl;
	}
	std::cout << "Average TEMP: " << avtemp << std::endl;
	std::cout << "Max PRESS: " << maxpress << std::endl;
	return 0;
}