#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <memory>
#include <algorithm>


class MusicalInstrument {
protected:
    std::string name;
    std::string material;
    float price;
    std::vector<std::string> owners;
public:
    MusicalInstrument(std::string Name, std::string Material, float Price, std::string Owners) {
        name = Name;
        material = Material;
        price = Price;
        std::stringstream owners_stream(Owners);
        std::string owner;
        while (std::getline(owners_stream, owner, '|')) {
            owners.push_back(owner);
        };
    };

    virtual void display() {
        std::cout << "Название: " << name << " ";
        std::cout << "Материал: " << material << " ";
        std::cout << "Цена: " << price << " ";
        std::cout << "Владельцы: ";
        for (const auto& suply : owners) {
            std::cout << suply << " ";
        }
        std::cout << std::endl;
    }

    void setName(std::string name) { name = name; }
    void setMaterial(std::string Material) { material = Material; }
    void setPrice(float Price) { price = Price; }
    void setOwners(std::vector<std::string> Owners) { owners = Owners; }

    std::string getName() { return name; }
    std::string getMaterial() { return material; }
    float getPrice() { return price; }
    std::vector<std::string> getOwners() { return owners; }
    virtual std::string getType() { return 0; };

    virtual std::string getStringType() { return " "; };
    virtual float getStringCount() { return 0; };

    virtual void setStringType(std::string Type) {}
    virtual void setStringCount(int StringCount) {}

    virtual float getTubeLenght() { return 0; };
    virtual std::string getBrassType() { return " "; };

    virtual void setTubeLenght(float TubeLenght) {}
    virtual void setBrassType(std::string Type) {}
    ~MusicalInstrument() {
        std::cout << "Инструмент удалён" << std::endl;
    }
};

class StringInstrument : public MusicalInstrument {
protected:
    int stringCount = 0;
    std::string type = "";
public:
    StringInstrument(std::string Name, std::string Material, float Price, std::string parametr, std::string Owners) : MusicalInstrument(Name, Material, Price, Owners) {
        std::string stringStringCount = "";
        for (char i : parametr) {
            if (std::isalpha(i)) {
                type += i;
            }
            else if (i != '-') {
                stringStringCount += i;
            }
        };
        stringCount = stof(stringStringCount);
    }
    void display() override {
        std::cout << "Название: " << name << " ";
        std::cout << "Материал: " << material << " ";
        std::cout << "Цена: " << price << " ";
        std::cout << "Количество струн: " << stringCount << " ";
        std::cout << "Тип строя: " << type << " ";
        std::cout << "Владельцы: ";
        for (const auto& suply : owners) {
            std::cout << suply << " ";
        }
        std::cout << std::endl;
    }
    std::string getStringType() override { return type; };
    float getStringCount() override { return stringCount; };
    std::string getType() override { return "String"; };

    void setStringType(std::string Type) override { type = Type; }
    void setStringCount(int StringCount) override { stringCount = StringCount; }
};

class BrassInstrument : public MusicalInstrument {
protected:
    float tubeLenght;
    std::string type = "";
public:
    BrassInstrument(std::string Name, std::string Material, float Price, std::string parametr, std::string Owners) : MusicalInstrument(Name, Material, Price, Owners) {
        std::string stringTubeLenght = "";
        for (char i : parametr) {
            if (std::isalpha(i)) {
                type += i;
            }
            else if (i != '-') {
                stringTubeLenght += i;
            }
        };
        tubeLenght = stof(stringTubeLenght);
    }
    void display() override {
        std::cout << "Название: " << name << " ";
        std::cout << "Материал: " << material << " ";
        std::cout << "Цена: " << price << " ";
        std::cout << "Длина трубы: " << tubeLenght << " ";
        std::cout << "Тип латуни: " << type << " ";
        std::cout << "Владельцы: ";
        for (const auto& suply : owners) {
            std::cout << suply << " ";
        }
        std::cout << std::endl;
    }
    float getTubeLenght() override { return tubeLenght; };
    std::string getBrassType() override { return type; };
    std::string getType() override { return "Brass"; };

    void setTubeLenght(float TubeLenght) override { tubeLenght = TubeLenght; }
    void setBrassType(std::string Type) override { type = Type; }
};

int main() {
    setlocale(LC_ALL,"rus");
    short choose;
    std::fstream file;
    std::vector<std::unique_ptr<MusicalInstrument>> objects;

    std::string string1;
    std::string string2;
    std::vector<std::string> list;

start:
    std::cout << "Выберите действие" << std::endl;
    std::cout << "1. Загрузить из файла" << std::endl;
    std::cout << "2. Список инструментов" << std::endl;
    std::cout << "3. Изменить объект" << std::endl;
    std::cout << "4. Подсчёт струнных инструментов с более чем 6 струнами" << std::endl;
    std::cout << "5. Сортировка по цене" << std::endl;
    std::cout << "6. Поиск духового инструмента с самой длинной трубой" << std::endl;
    std::cout << "7. Все инструменты из дерева дороже 600" << std::endl;
    std::cout << "8. Инструмент с наибольшим числом струн" << std::endl;
    std::cout << "9. Сортировка по типу строя, потом по цене" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cin >> choose;

    switch (choose)
    {
    default:
        return 0;
        break;
    case 1:
        file.open("catalog.txt");
        while (std::getline(file, string1)) {
            std::stringstream ss(string1);
            while (std::getline(ss, string2, ';')) {
                list.push_back(string2);
            };
            if (string1.substr(0, 6) == "String") {
                objects.emplace_back(std::make_unique<StringInstrument>(list[1], list[2], stof(list[3]), list[4], list[5]));
            }
            else {
                objects.emplace_back(std::make_unique<BrassInstrument>(list[1], list[2], stof(list[3]), list[4], list[5]));
            };
            string1 = "";
            string2 = "";
            list = {};
        };
        file.close();
        goto start;
    case 2:
        for (auto& i : objects) {
            i->display();
        };
        goto start;
    case 3:
        for (auto& i : objects) {
            std::cout << "Выбранный инструмент: " << std::endl;
            i->display();
            std::cout << "Изменить: " << std::endl;
            std::cout << "1. Цену " << std::endl;
            std::cout << "2. Материал " << std::endl;
            std::cout << "3. Добавить владельца" << std::endl;
            std::cout << "4. Следующий инструмент " << std::endl;
            std::cout << "0. Выход" << std::endl;
            std::cin >> choose;
            switch (choose)
            {
            default:
                goto start;
            case 1:
                std::cout << "Изменить цену на: " << std::endl;
                std::cin >> string1;
                i->setPrice(stof(string1));
                goto start;
            case 2:
                std::cout << "Изменить материал на: " << std::endl;
                std::cin >> string1;
                i->setMaterial(string1);
                goto start;
            case 3:
                std::cout << "Название поставщика: " << std::endl;
                std::cin >> string1;
                list = i->getOwners();
                list.push_back(string1);
                i->setOwners(list);
                goto start;
            case 4:
                break;
            }
        }
        goto start;
    case 4: {
        auto count{ [&objects](int strings)
            {
            unsigned n {};
            for (auto& object : objects)
                if (object->getType() == "String")
                    if (object->getStringCount() > strings) ++n;
            return n;
            }
        };
        std::cout << "Найдено" << count(6) << "инструмента(-ов) с более чем 6 струнами" << std::endl;
        goto start;
    }
    case 5:
        std::sort(objects.begin(), objects.end(), [](const std::unique_ptr<MusicalInstrument>& a, const std::unique_ptr<MusicalInstrument>& b) {return a->getPrice() < b->getPrice();});
        std::cout << "Отсортированно по цене" << std::endl;
        goto start;
    case 6:
        std::cout << "Инструмент с наибольшей длинной трубы:" << std::endl;
        std::max_element(objects.begin(), objects.end(), [](const std::unique_ptr<MusicalInstrument>& a, const std::unique_ptr<MusicalInstrument>& b) {return a->getTubeLenght() < b->getTubeLenght();})->get()->display();
        goto start;
    case 7: {
        std::vector<std::unique_ptr<MusicalInstrument>> filtr;
        for (const auto& ptr : objects) {
            if (ptr->getMaterial() == "Wood" && ptr->getPrice() > 600) {
                filtr.push_back(std::make_unique<MusicalInstrument>(*ptr));
            }
        }
        std::cout << "Найденные деревянные инструменты дороже 600:" << std::endl;
        for (auto& i : filtr) {
            i->display();
        }
        goto start;
    }
    case 8:
        std::cout << "Инструмент с наибольшим количеством струн:" << std::endl;
        std::max_element(objects.begin(), objects.end(), [](const std::unique_ptr<MusicalInstrument>& a, const std::unique_ptr<MusicalInstrument>& b) {return a->getStringCount() < b->getStringCount();})->get()->display();
        goto start;
    case 9:
        std::sort(objects.begin(), objects.end(), [](const std::unique_ptr<MusicalInstrument>& a, const std::unique_ptr<MusicalInstrument>& b) {if (a->getStringType() == b->getStringType()) return a->getPrice() < b->getPrice(); else return a->getStringType() < b->getStringType();});
        std::cout << "Отсортированно по цене" << std::endl;
        goto start;
    }
}