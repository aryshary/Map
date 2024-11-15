#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>
#include <map>
#include <fstream>

using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string sentence;
    cout << "Введіть речення: ";
    getline(cin, sentence);

    for (char& el : sentence) {
        el = tolower(el);
    }

    map<string, int> words;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        words[word]++;
    }

    string maxWord;
    int maxNum = 0;
    for (const auto& pair : words) {
        if (pair.second > maxNum) {
            maxWord = pair.first;
            maxNum = pair.second;
        }
    }

    ofstream file("result.txt");
    if (file.is_open()) {
        file << "Частотний словник слів:\n";
        for (const auto& pair : words) {
            file << pair.first << ": " << pair.second << "\n";
        }
        file << "Слово " << maxWord << " - найвживаніше, зустрічається " << maxNum << " разів\n";
        file.close();
    }
    
    return 0;
}
