#include <iostream>
#include <regex>  // ����������� ���������� ��� ���������� ���������
#include "Telephone_directory.hpp"
using namespace std;

// ������� ��� ������� ���������� �������� �� ����� ������
string trim(const string& str) {
    size_t first = str.find_first_not_of(" ");
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(" ");
    return str.substr(first, last - first + 1);
}

// �������� �� ������������ �����, ������� � ��������
bool is_valid_name(const string& name) {
    // ��������� �����, �����, ����� � ������, �� ��� ������ ���������� � ����� � �� ����� ���������� ��� ������������� �������
    return regex_match(name, regex("^[a-zA-Z�-��-���][a-zA-Z�-��-���0-9 -]*[a-zA-Z�-��-���0-9]$"));
}

// �������� �� ������������ ��������
bool is_valid_phone(const string& phone) {
    // ����������� ������� ��������� �/��� +7, �/��� ������, �/��� �������
    return regex_match(phone, regex("^(\\+7|8)?(\\(\\d{3}\\)|\\d{3})\\d{3}[-]?\\d{2}[-]?\\d{2}$"));
}

// �������� �� ������������ ����������� �����
bool is_valid_email(const string& email) {
    // �������� ������ �������� � �������� ������� email
    string trimmed_email = trim(email);
    return regex_match(trimmed_email, regex("^[a-zA-Z0-9]+@[a-zA-Z0-9]+\\.[a-zA-Z0-9]+$"));
}

int main() {
    setlocale(LC_ALL, "Russian");
    Telephone_directory tel_book;
    cout << "Telephone directory" << endl;
    int a = 0;
    Window();
    cin >> a;
    string filename = "phonedirectory.txt";
    while (a != 9) {
        switch (a) {
        case 1: { // ���������� �������� 
            cout << "Enter contact name:" << endl;
            string first_name;
            cin >> first_name;
            first_name = trim(first_name);
            if (!is_valid_name(first_name)) {
                cout << "Incorrect name." << endl;
                break;
            }

            cout << "Enter contact's last name:" << endl;
            string second_name;
            cin >> second_name;
            second_name = trim(second_name);
            if (!is_valid_name(second_name)) {
                cout << "Incorrect surname." << endl;
                break;
            }

            cout << "Enter contact's third name:" << endl;
            string third_name;
            cin >> third_name;
            third_name = trim(third_name);
            if (!is_valid_name(third_name)) {
                cout << "Incorrect surname." << endl;
                break;
            }


            cout << "Enter the contact's phone number:" << endl;
            string number;
            cin >> number;
            number = trim(number);
            if (!is_valid_phone(number)) {
                cout << "Incorrect phone number." << endl;
                break;
            }

            cout << "Enter the adress:" << endl;
            string adress;
            cin >> adress;
            adress = trim(adress);

            // ����� ���� ��� ��� ��������
            cout << "Enter the contact's birthday (DD-MM-YYYY):" << endl;
            string birthday;
            cin >> birthday;
            birthday = trim(birthday);


            // ����� ���� ��� email
            cout << "Enter the contact's email:" << endl;
            string email;
            cin >> email;
            email = trim(email);
            if (!is_valid_email(email)) {
                cout << "Incorrect email format." << endl;
                break;
            }

            tel_book.Add(first_name, second_name, "", number, adress, birthday, email); // ������� ������ �������� 
            break;
        }
        case 2: { // �������� ��������
            cout << "Enter the phone number of the contact you want to remove from your phone book.:" << endl;
            string number;
            cin >> number;
            number = trim(number);
            if (!is_valid_phone(number)) {
                cout << "Incorrect phone number." << endl;
                break;
            }
            tel_book.Delete(number);
            cout << "Contact deleted" << endl;
            break;
        }
        case 3: { // ������ ���� ���������
            tel_book.Print_all();
            break;
        }
        case 4: { // ����� �������� �� �������
            cout << "Enter contact's last name: " << endl;
            string second_name;
            cin >> second_name;
            second_name = trim(second_name);
            if (!is_valid_name(second_name)) {
                cout << "Incorrect surname." << endl;
                break;
            }
            tel_book.Find(second_name);
            break;
        }
        
        case 5: { // ���������� �������� 
            cout << "Enter the last name of the contact you want to change:" << endl;
            string second_name;
            cin >> second_name;
            second_name = trim(second_name);
            if (!is_valid_name(second_name)) {
                cout << "Incorrect surname." << endl;
                break;
            }

            cout << "Enter a new contact name:" << endl;
            string first_name;
            cin >> first_name;
            first_name = trim(first_name);
            if (!is_valid_name(first_name)) {
                cout << "Incorrect name." << endl;
                break;
            }

            cout << "Enter a new contact third name:" << endl;
            string third_name;
            cin >> third_name;
            third_name = trim(third_name);
            if (!is_valid_name(third_name)) {
                cout << "Incorrect name." << endl;
                break;
            }

            cout << "Enter the new contact phone number:" << endl;
            string number;
            cin >> number;
            number = trim(number);
            if (!is_valid_phone(number)) {
                cout << "Incorrect phone number." << endl;
                break;
            }

            cout << "Enter the new adress:" << endl;
            string address;
            cin >> address;
            address = trim(address);

            cout << "Enter the contact's new birthday (DD-MM-YYYY):" << endl;
            string birthday;
            cin >> birthday;
            birthday = trim(birthday);

            cout << "Enter the contact's new email:" << endl;
            string email;
            cin >> email;
            email = trim(email);
            if (!is_valid_email(email)) {
                cout << "Incorrect email format." << endl;
                break;
            }

            tel_book.Edit_contact(first_name, second_name, "", number, address, birthday, email);
            break;
        }
        case 6: { // ������� ���������� 
            tel_book.Clear();
            cout << "Telephone directory is clear." << endl;
            break;
        }
        case 7: { 
            // ���������� � ����
            tel_book.SaveToFile(filename);
            break; }
        case 8: { 
            // �������� �� �����
            tel_book.LoadFromFile(filename); 
            break; }
        default:
            cout << "Incorrect selection. Please try again.." << endl;
        }
        Window();
        cin >> a;
    }
    return 0;
}