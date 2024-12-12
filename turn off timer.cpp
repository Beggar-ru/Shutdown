#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int minuts = 0, seccond = 0;
    
    string choice;

    int stat;
    cout << "Выберите действие:" << endl << "1.Выключение ПК." << endl << "2.Отмена выключения ПК." << endl << "3.Закрыть." << endl << ">> ";
    cin >> stat;

    while (true) {
        if (stat == 1) {
            cout << "Введите время до выключения: ";
            cin >> minuts;
            seccond = minuts * 60;
            string command = "shutdown /s /t " + to_string(seccond);
            system(command.c_str());
            break;
        }
        if (stat == 2) {
            cout << "Отмена выключения...";
            string command1 = "shutdown /a";
            system(command1.c_str());
            break;
        }
        if (stat == 3) {
            return 0;
        }
        else {
            cout << "Выбрано неверное действие.";
            break;
        }
    }
    return 0;
}
