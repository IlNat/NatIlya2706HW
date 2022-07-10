/*
    Задание.
Создать класс СПРАВОЧНИК со следующими полями :
1. Название фирмы;
2. Владелец;
3. Телефон;
4. Адрес;
5. Род деятельности.

    Реализовать следующие возможности :
1. Поиск по названию;
2. Поиск по владельцу;
3. Поиск по номеру телефона;
4. Поиск по роду деятельности;
5. Показ всех записей и добавление.

Вся информация, должна сохранятся в файле, должна
быть реализована возможность добавления новых данных.
*/

#include <iostream>
#include <fstream>
#include "Windows.h"
using namespace std;

// Класс "Справочник".
class Guide
{
private:
    string nameOfOrganisation; // Имя организации.
    string nameOfOwner; // Имя владельца.
    string phoneNumber; // Номер телефона.
    string address; // Адрес.
    string typeOfActivity; // Род деятельности. 
public:
    
    // Конструктор по-умолчанию для класса "Справочник".
    Guide() {};
    
    // Установка имени организации.
    void setNameOfOrganisation(string settingNameOfOrganisation) { nameOfOrganisation = settingNameOfOrganisation; }
    
    // Установка имени владельца.
    void setNameOfOwner(string settingNameOfOwner) { nameOfOwner = settingNameOfOwner; }
    
    // Установка номера телефона.
    void setPhoneNumber(string settingPhoneNumber) { phoneNumber = settingPhoneNumber; }
    
    // Установка адреса.
    void setAddress(string settingAddress) { address = settingAddress; }
    
    // Установка рода деятельности.
    void setTypeOfActivity(string settingTypeOfActivity) { typeOfActivity = settingTypeOfActivity; }

    // Печать информации о пользователе.
    void print()
    {
        cout << "Печать информации пользователя.\n";
        cout << "Название организации: " << nameOfOrganisation << "\n";
        cout << "Имя владельца: " << nameOfOwner << "\n";
        cout << "Номер телефона: " << phoneNumber << "\n";
        cout << "Адрес: " << address << "\n";
        cout << "Род деятельности: " << typeOfActivity << "\n";
    }

    // Возвращение имени организации.
    string returnNameOfOrganisation() { return nameOfOrganisation; }

    // Возвращение имени владельца.
    string returnNameOfOwner() { return nameOfOwner; }

    // Возвращение номера телефона.
    string returnPhoneNumber() { return phoneNumber; }

    // Возвращение адреса.
    string returnAddress() { return address ; }

    // Возвращение рода деятельности.
    string returnTypeOfActivity() { return typeOfActivity; }
};



int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream outputFile;
    outputFile.open("output.txt");

    Guide* guide;
    
    cout << "Добро пожаловать в справочник. Введите количество пользователей: \n";
    int amountOfUsers; // Количество пользователей.
    cin >> amountOfUsers;
    guide = new Guide[amountOfUsers]; 
    for (int i = 0; i < amountOfUsers; i++)
    {
        string nameOfOrganisation;
        string nameOfOwner;
        string phoneNumber;
        string address;
        string typeOfActivity;

        outputFile << "Пользователь " << i + 1 << ":\n";
        cout << "Введите имя организации " << i + 1 << "-го пользователя: ";
        cin >> nameOfOrganisation;
        outputFile << nameOfOrganisation << '\n';
        cout << "Введите имя " << i + 1 << "-го владельца : ";
        cin >> nameOfOwner;
        outputFile << nameOfOwner << '\n';
        cout << "Введите номер телефона " << i + 1 << "-го пользователя: ";
        cin >> phoneNumber;
        outputFile << phoneNumber << '\n';
        cout << "Введите адрес " << i + 1 << "-го пользователя: ";
        cin >> address;
        outputFile << address << '\n';
        cout << "Введите род деятельности " << i + 1 << "-го пользователя: ";
        cin >> typeOfActivity;
        outputFile << typeOfActivity << '\n';

        guide[i].setNameOfOrganisation(nameOfOrganisation);
        guide[i].setNameOfOwner(nameOfOwner);
        guide[i].setPhoneNumber(phoneNumber);
        guide[i].setAddress(address);
        guide[i].setTypeOfActivity(typeOfActivity);
        
    }

    int choice;
    do
    {
        cout << "Команды:\n1 - поиск по названию организации;\n2 - поиск по имени владельца;\n3 - поиск по номеру телефона;\n4 - поиск по роду деятельности\n5 - печать всех пользователей\n6 - изменение данных пользователя;\n7 - добавление пользователя;\n8 - вызод из программы.\nВведите команду: ";
        cin >> choice;
        switch (choice) 
        {
        case 1: 
        {
            cout << "Поиск по названию организации. Введите название организации для поиска: \n";
            string fragment;
            cin >> fragment;
            bool isFound = false; // Если фрагмент не найден, то выводится сообщение "Ничего не найдено!".
            int positionOfFragment;
            cout << "Результаты:\n";
            for (int i = 0; i < amountOfUsers; i++)
            {
                positionOfFragment = guide[i].returnNameOfOrganisation().find(fragment);
                if (positionOfFragment != -1) 
                {
                    isFound = true; 
                    cout << i << ". " << guide[i].returnNameOfOrganisation() << '\n';
                }                    
            }
            if (!isFound)
                cout << "Ничего не найдено!\n";
            break;
        }
        case 2:
        {
            cout << "Поиск по имени владельца. Введите имя владельца для поиска: \n";
            string fragment;
            cin >> fragment;
            bool isFound = false; // Если фрагмент не найден, то выводится сообщение "Ничего не найдено!".
            int positionOfFragment;
            cout << "Результаты:\n";
            for (int i = 0; i < amountOfUsers; i++)
            {
                positionOfFragment = guide[i].returnNameOfOwner().find(fragment);
                if (positionOfFragment != -1)
                {
                    isFound = true;
                    cout << i + 1 << ". " << guide[i].returnNameOfOwner() << '\n';
                }
            }
            if (!isFound)
                cout << "Ничего не найдено!\n";
            break;
        }
        case 3:
        {
            cout << "Поиск по номеру телефона. Введите номер телефона для поиска: \n";
            string fragment;
            cin >> fragment;
            bool isFound = false; // Если фрагмент не найден, то выводится сообщение "Ничего не найдено!".
            int positionOfFragment;
            cout << "Результаты:\n";
            for (int i = 0; i < amountOfUsers; i++)
            {
                positionOfFragment = guide[i].returnPhoneNumber().find(fragment);
                if (positionOfFragment != -1)
                {
                    isFound = true;
                    cout << i + 1<< ". " << guide[i].returnPhoneNumber() << '\n';
                }
            }
            if (!isFound)
                cout << "Ничего не найдено!\n";
            break;
        }
        case 4:
        {
            cout << "Поиск по роду деятельности. Введите название рода деятельности для поиска: \n";
            string fragment;
            cin >> fragment;
            bool isFound = false; // Если фрагмент не найден, то выводится сообщение "Ничего не найдено!".
            int positionOfFragment;
            cout << "Результаты:\n";
            for (int i = 0; i < amountOfUsers; i++)
            {
                positionOfFragment = guide[i].returnTypeOfActivity().find(fragment);
                if (positionOfFragment != -1)
                {
                    isFound = true;
                    cout << i + 1 << ". " << guide[i].returnTypeOfActivity() << '\n';
                }
            }
            if (!isFound)
                cout << "Ничего не найдено!\n";
            break;
        }
        case 5:
        {
            cout << "Печать информации о всех пользователях: ";
            for (int i = 0; i < amountOfUsers; i++)
            {
                guide[i].print();
            }
            break;
        }
        case 6:
        {
            cout << "Изменение информации о пользователе.\n";
            int ID;
            cout << "Введите номер пользователя: ";
            cin >> ID;
            ID--;
            int choiceToChange; // Выбор "изменения".
            string bufferWithChanges; // Буфер с изменениями.
            cout << "Команды:\n1 - изменение названия организации;\n2 - изменение имени владельца;\n3 - изменение номера телефона;\n4 - изменение адреса\n5 - изменение рода деятельности.\nВведите команду: ";
            cin >> choiceToChange;
            switch (choiceToChange)
            {
            case 1:
            {
                cout << "Изменение названия организации. Введите новое название организации: ";
                cin >> bufferWithChanges;
                guide[ID].setNameOfOrganisation(bufferWithChanges);
                break;
            }
            case 2:
            {
                cout << "Изменение имени владельца. Введите новое имя владельца: ";
                cin >> bufferWithChanges;
                guide[ID].setNameOfOwner(bufferWithChanges);
                break;
            }
            case 3:
            {
                cout << "Изменение номера телефона. Введите новый номер телефона: ";
                cin >> bufferWithChanges;
                guide[ID].setPhoneNumber(bufferWithChanges);
                break;
            }
            case 4:
            {
                cout << "Изменение адреса. Введите новый адрес: ";
                cin >> bufferWithChanges;
                guide[ID].setAddress(bufferWithChanges);
                break;
            }
            case 5:
            {
                cout << "Изменение рода деятельности. Введите новое название рода деятельности: ";
                cin >> bufferWithChanges;
                guide[ID].setTypeOfActivity(bufferWithChanges);
                break;
            }
            default:
            {
                cout << "Такой команды нет.\n";
                break;
            }
            }
            break;
        }
        case 7: 
        {
            cout << "Добавление пользователя.\n";
            amountOfUsers++;
            string nameOfOrganisation;
            string nameOfOwner;
            string phoneNumber;
            string address;
            string typeOfActivity;

            outputFile << "Пользователь " << amountOfUsers - 1 << ":\n";

            cout << "Введите имя организации: ";
            cin >> nameOfOrganisation;
            outputFile << nameOfOrganisation << '\n';
            cout << "Введите имя: ";
            cin >> nameOfOwner;
            outputFile << nameOfOwner << '\n';
            cout << "Введите номер телефона: ";
            cin >> phoneNumber;
            outputFile << phoneNumber << '\n';
            cout << "Введите адрес: ";
            cin >> address;
            outputFile << address << '\n';
            cout << "Введите род деятельности: ";
            cin >> typeOfActivity;
            outputFile << typeOfActivity << '\n';

            guide[amountOfUsers - 1].setNameOfOrganisation(nameOfOrganisation);
            guide[amountOfUsers - 1].setNameOfOwner(nameOfOwner);
            guide[amountOfUsers - 1].setPhoneNumber(phoneNumber);
            guide[amountOfUsers - 1].setAddress(address);
            guide[amountOfUsers - 1].setTypeOfActivity(typeOfActivity);
            break;
        }
        case 8:
        {
            cout << "Выход из программы.\n";
            break;
        }
        default:
        {
            cout << "Такой команды нет.\n";
            break;
        }
        }
    } while (choice != 8);
}
