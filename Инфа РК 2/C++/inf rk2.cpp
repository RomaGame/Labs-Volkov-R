#include <iostream>
#include <vector>
#include <string>

class BankAccount {
public:
    int acc_id;
    std::string name;
    float balance;

    BankAccount(int Acc_id, std::string Name, float Balance) {
        acc_id = Acc_id;
        name = Name;
        balance = Balance;
    };
    BankAccount(int Acc_id, std::string Name) {
        acc_id = Acc_id;
        name = Name;
        balance = 0;
    };
    BankAccount(int Acc_id) {
        acc_id = Acc_id;
        name = "Undenified";
        balance = 0;
    };
    BankAccount() {
        acc_id = -1;
        name = "Undenified";
        balance = 0;
    };

    void Deposit(float cash) {
        if (cash >= 0)
        {
            balance = balance + cash;
        }
        else {
            std::cerr << "Error: Deposit cash < 0" << std::endl;
        }
    };

    void Withdraw(float cash) {
        if (cash >= 0)
        {
            balance = balance - cash;
        }
        else {
            std::cerr << "Error: Withdraw cash < 0" << std::endl;
        }
    };
};

class SavingAccount : public BankAccount {
public:
    float persentage = 0;

    using BankAccount::BankAccount;
    SavingAccount(int Acc_id, std::string Name, float Balance, float Persentage) : BankAccount(Acc_id, Name, Balance) {
        persentage = Persentage;
    }

    void AddCash() {
        balance += balance * (persentage / 100);
    }
};

int main() {
    SavingAccount First(1, "Иван", 0, 15);
    First.Deposit(1000);
    std::cout << First.balance << std::endl;
    First.AddCash();
    std::cout << First.balance << std::endl;
    return 0;
}