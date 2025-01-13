// Telephone_directory.cpp
#include "Telephone_directory.hpp"
#include <fstream>

void Telephone_directory::Add(string first_name, string second_name, string third_name, string number, string adres, string birthday, string email) {
    Human human(first_name, second_name, third_name, number, adres, birthday, email);
    td.emplace(second_name, human);
}

void Telephone_directory::Delete(string number) {
    for (auto it = td.begin(); it != td.end(); ++it) {
        if (it->second.number == number) {
            td.erase(it);
            return;
        }
    }
}

void Telephone_directory::Print_all() {
    for (const auto& element : td) {
        cout << element.second;
    }
}

void Telephone_directory::Find(string second_name) {
    if (td.find(second_name) != td.end()) {
        cout << td[second_name];
    }
    else {
        cout << "This user is not in the phone book" << endl;
    }
}

void Telephone_directory::Edit_contact(string first_name, string second_name, string third_name, string number, string adres, string birthday, string email) {
    if (td.find(second_name) != td.end()) {
        td[second_name].first_name = first_name;
        td[second_name].third_name = third_name;
        td[second_name].number = number;
        td[second_name].address = adres;
        td[second_name].birthday = birthday;
        td[second_name].email = email;
    }
    else {
        Add(first_name, second_name, third_name, number, adres, birthday, email);
    }
}

void Telephone_directory::Clear() {
    td.clear();
}

ostream& operator<<(ostream& os, const Human& human) {
    return os << human.first_name << "\t" << human.second_name << "\t" << human.third_name << "\t" << human.number << "\t"
        << human.address << "\t" << human.birthday << "\t" << human.email << endl;
}


void Telephone_directory::SaveToFile(const string& filename) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "Error opening file for writing: " << filename << endl;
        return;
    }
    for (const auto& element : td) {
        const Human& human = element.second;  // Получаем значение Human из map
        outFile << human.first_name << "\t"
            << human.second_name << "\t"
            << human.third_name << "\t"
            << human.number << "\t"
            << human.address << "\t"
            << human.birthday << "\t"
            << human.email << endl;
    }
    outFile.close();
    cout << "Phone book saved to file " << filename << endl;
}

void Telephone_directory::LoadFromFile(const string& filename) {
    ifstream inFile(filename);
    if (!inFile) {
        cerr << "Error opening file for reading: " << filename << endl;
        return;
    }
    td.clear();  // Очистка текущей книги перед загрузкой из файла 
    string line;

    // Чтение файла построчно
    while (getline(inFile, line)) {
        string first_name, second_name, third_name, number, adres, birthday, email;

        // Разделяем строку по пробелам
        size_t pos = 0;
        pos = line.find('\t'); // Ищем первый разделитель (табуляция или пробел)
        first_name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find('\t');
        second_name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find('\t');
        third_name = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find('\t');
        number = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find('\t');
        adres = line.substr(0, pos);
        line.erase(0, pos + 1);

        pos = line.find('\t');
        birthday = line.substr(0, pos);
        line.erase(0, pos + 1);

        email = line; // Последнее поле - email (оставшийся текст в строке)

        // Добавляем в телефонную книгу
        Add(first_name, second_name, third_name, number, adres, birthday, email);
    }

    inFile.close();
    cout << "Phone book loaded from file " << filename << endl;

    // После загрузки данных, выводим все контакты
    Print_all();
}

void Window() {
    cout << "Select an action:" << endl;
    cout << "1 - Add contact to phone book." << endl;
    cout << "2 - Delete contact from phone book." << endl;
    cout << "3 - Display the contents of the phone book." << endl;
    cout << "4 - Find a contact in the phone book." << endl;
    cout << "5 - Change contact information in phone book." << endl;
    cout << "6 - Clear phone book." << endl;
    cout << "7 - Save in file." << endl;
    cout << "8 - load from file." << endl;
    cout << "9 - Close the phone book." << endl;

}