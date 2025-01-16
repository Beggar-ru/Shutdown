#include <iostream>
#include <string>
#include <cstdio>
#include <windows.h>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <fstream>

using namespace std;

unordered_map<string, string> loadTranslations(const string& lang) {
    unordered_map<string, string> translations;
    ifstream file(lang);
    string line;

    while (getline(file, line)) {
        size_t pos = line.find('=');
        if (pos != string::npos) {
            string key = line.substr(0, pos);
            string value = line.substr(pos + 1);
            translations[key] = value;
        }
    }
    return translations;
}

string translate(const unordered_map<string, string>& translations, const string& msg){
    auto it = translations.find(msg);
    if (it != translations.end()) {
        return it->second;
    }
    return msg;
}

void shutdownPC(int seconds) {
    cout << "Выключение через: " << seconds << endl;
    string commandOFF = "shutdown /s /t " + to_string(seconds);
    system(commandOFF.c_str());
}

int main() {
    setlocale(LC_ALL, "ru");

    string language = determineLanguage();
    unordered_map<string, string> translations;

    if (langauge == "ru") ||
    (language == "uk") || 
    (language == "bk") ||
    (language == "kk") {
        translations = loadTranslations("ru_RU.txt");
    }
    else {
        tranlations = loadTranslations("en_US.txt");
    }

    cout << translate(translations, "TURN_OFF") << endl;
    

    int minuts = 0, seconds = 0;

    int stat;

    bool shutdown = false;

    while (true) {

        cout << "Выберите действие: \n1.Выключение ПК. \n2.Отмена выключения ПК. \n3.Закрыть. \n>> ";
        cin >> stat;

        switch (stat) {
        case 1:
            if (!shutdown) {
                cout << "Введите время до выключения: \n>> ";
                cin >> minuts;
                seconds = minuts * 60;
                shutdown = true;
                thread(shutdownPC, seconds).detach();
            }
            else {
                cout << "Таймер уже установлен.\n";
            }
            break;
        case 2:
            if (shutdown) {
                shutdown = false;
                string cancel_shutdown = "shutdown /a";
                system(cancel_shutdown.c_str());
                cout << "Выключение отменено.\n";
            }
            else {
                cout << "Нет запланированого выключения.\n";
            }
            break;
        case 3: {
            return 0;
        }
        default:
            cout << "Неверный выбор.\n";
            break;
        }
    }
}
