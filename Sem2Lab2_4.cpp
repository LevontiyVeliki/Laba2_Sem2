#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void writeRussianAlphabetToFile(string filename) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Ошибка открытия файла." << endl;
        return;
    }

    string russianAlphabet = "абвгдеёжзийклмнопрстуфхцчшщъыьэю";
    file.write(russianAlphabet.c_str(), russianAlphabet.size());

    file.close();
}

void rewriteFileToUppercase(string inputFilename, string outputFilename) {
    ifstream inputFile(inputFilename, ios::binary);
    if (!inputFile.is_open()) {
        cout << "Ошибка открытия файла." << endl;
        return;
    }

    ofstream outputFile(outputFilename, ios::binary);
    if (!outputFile.is_open()) {
        cout << "Ошибка создания файла." << endl;
        return;
    }

    char c;
    while (inputFile.read(&c, sizeof(c))) {
        c = toupper(c);
        outputFile.write(&c, sizeof(c));
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    setlocale(LC_ALL, "RUS");
    string filename = "russian_alphabet.bin";
    string uppercaseFilename = "russian_alphabet_uppercase.bin";
    writeRussianAlphabetToFile(filename);
    cout << "Символы до изменения файла:" << endl;
    ifstream inputFile(filename, ios::binary);
    if (inputFile.is_open()) {
        char c;
        while (inputFile.read(&c, sizeof(c))) {
            cout << c;
        }
        cout << endl;
        inputFile.close();
    }
    rewriteFileToUppercase(filename, uppercaseFilename);
    cout << "Символы после изменения файла:" << endl;
    ifstream uppercaseFile(uppercaseFilename, ios::binary);
    if (uppercaseFile.is_open()) {
        char c;
        while (uppercaseFile.read(&c, sizeof(c))) {
            cout << c;
        }
        cout << endl;
        uppercaseFile.close();
    }
    return 0;
}
