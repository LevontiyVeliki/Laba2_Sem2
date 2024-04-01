#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    ifstream inputFile("in.txt");
    ofstream outputFile("out.txt");
    string line;
    int task;
    cin >> task;
    switch (task) {
    case 1:
        if (inputFile.is_open() and outputFile.is_open()) {
            while (getline(inputFile, line)) {
                for (char& c : line) {
                    if (isupper(c)) {
                        c = tolower(c);
                    }
                }
                outputFile << line << '\n';
            }
            inputFile.close();
            outputFile.close();
            cout << "Файл успешно обработан и сохранен в out.txt." << endl;
        }
        else {
            cout << "Не удалось открыть файлы." << endl;
        }
        break;
    }
    return 0;
}
