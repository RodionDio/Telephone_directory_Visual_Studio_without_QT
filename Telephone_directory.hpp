// Telephone_directory.h
#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Human {
    string first_name;
    string second_name;
    string third_name;
    string number;
    string address;
    string birthday;
    string email;

    Human(string first_name = "", string second_name = "", string third_name = "", string number = "", string adres = "", string birthday = "", string email = "")
        : first_name(first_name), second_name(second_name), third_name(third_name), number(number), address(adres), birthday(birthday), email(email) {}
};

class Telephone_directory {
public:
    void Add(string first_name, string second_name, string third_name = "", string number = "", string adres = "", string birthday = "", string email = "");
    void Delete(string number);
    void Print_all();
    void Find(string second_name);
    void Edit_contact(string first_name, string second_name, string third_name = "", string number = "", string adres = "", string birthday = "", string email = "");
    void Clear();
    void SaveToFile(const string& filename);
    void LoadFromFile(const string& filename);

private:
    map<string, Human> td;
};

ostream& operator<<(ostream& os, const Human& human);
void Window();

