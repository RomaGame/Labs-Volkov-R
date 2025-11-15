#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
    short ch;
    int num;
    std::string str, file_str, nums;
    std::fstream File;
    std::vector<std::string>list;
    std::vector<int>numList;
menu:
    std::cout << "1. Add tasks/create tasks.txt" << std::endl;
    std::cout << "2. Search or sort" << std::endl;
    std::cout << "3. Add new task" << std::endl;
    std::cout << "4. Get tasks by priority" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter choice (0-5): ";
    std::cin >> ch;
    switch (ch) {
    default:
        return 0;
        break;
    case 1:

        File.open("tasks.txt");
        if (!File.is_open()) {
            std::ofstream File("tasks.txt");
        }

        std::cout << "Enter task: Name;Priority;Term(DD:MM:YY)" << std::endl;
        std::cin.ignore();
        std::getline(std::cin, str);
        while (!str.empty()) {
            File << str << std::endl;
            std::getline(std::cin, str);
        }
        File.close();
        goto menu;

    case 2:
        std::cout << "1. Search" << std::endl;
        std::cout << "2. Sort" << std::endl;
        std::cout << "0. Cancel" << std::endl;
        std::cout << "Enter choice: ";
        std::cin >> ch;
        switch (ch) {
        default:
            std::cout << "Canceled" << std::endl;
            goto menu;
        case 1:
            File.open("tasks.txt");
            std::cout << "Task name: ";
            std::cin.ignore();
            std::getline(std::cin, str);
            num = 0;
            while (File >> file_str) {
                if (file_str.substr(0, str.size()) == str and file_str[str.size()] == ';') {
                    std::cout << file_str << std::endl;
                    num = 1;
                }
            }
            if (num == 0) {
                std::cout << "Task not found" << std::endl;
            }
            File.close();
            goto menu;
        case 2:
            File.open("tasks.txt");
            std::cout << "Sort by: " << std::endl;
            std::cout << "1. Priority" << std::endl;
            std::cout << "2. Date " << std::endl;
            std::cout << "0. Cancel" << std::endl;
            std::cout << "Enter choice: ";
            std::cin >> ch;

            switch (ch)
            {
            default:
                std::cout << "Canceled" << std::endl;
                goto menu;
            case 1:

                while (File >> file_str) {
                    nums = "";
                    for (char i : file_str) {
                        if (int(i) > 47 && int(i) < 58) {
                            nums += i;
                        }
                    }
                    nums = (nums.substr(0, nums.size() - 6));
                    list.push_back(file_str);
                    numList.push_back(stoi(nums));
                }
                File.close();
                break;
            case 2:

                while (File >> file_str) {
                    list.push_back(file_str);
                    numList.push_back(stoi(file_str.substr(file_str.size() - 3, 2) + file_str.substr(file_str.size() - 6, 2) + file_str.substr(file_str.size() - 9, 2)));
                }
                File.close();
                break;
            }
        sort:
            for (int i = 0;i < numList.size() - 1;i++) {
                if (numList[i] > numList[i + 1]) {
                    nums = list[i + 1];
                    list[i + 1] = list[i];
                    list[i] = nums;
                    num = numList[i + 1];
                    numList[i + 1] = numList[i];
                    numList[i] = num;
                    goto sort;
                }
            }

            std::ofstream File("tasks.txt");
            for (std::string i : list) {
                File << i << std::endl;
            }
            File.close();
            goto menu;
        }
    case 3:
        std::cout << "Enter task: Name;Priority;Term(DD:MM:YY)." << std::endl;
        std::cin.ignore();
        std::getline(std::cin, str);
        File << str << std::endl;
        std::getline(std::cin, str);
        File.close();
        goto menu;
    case 4:

        File.open("tasks.txt");
        std::cout << "Priority: ";
        std::cin >> num;
        while (File >> file_str) {
            nums = "";
            for (char i : file_str) {
                if (int(i) >= 48 and int(i) <= 57) {
                    nums += i;
                }
            }
            nums = nums.substr(0, nums.size() - 6);
            if (std::stoi(nums) < num) {
                std::cout << file_str << nums << std::endl;
            }
        }
        File.close();
        goto menu;
        
    }
}
