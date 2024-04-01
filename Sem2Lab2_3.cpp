#include <iostream>
#include <fstream>
#include <cctype>
#include <string>

using namespace std;

int main_1() {
    setlocale(LC_ALL, "RUS");
    ifstream inputFile("in.txt");
    ofstream outputFile("out.txt");
    string line;

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
        cout << "���� ������� ��������� � �������� � out.txt." << endl;
    }
    else {
        cout << "�� ������� ������� �����." << endl;
    }
    return 0;
}