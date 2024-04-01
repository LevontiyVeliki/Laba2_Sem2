#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Monitor {
    string firmName;
    int size;
    double cost;
};

int main() {
    setlocale(LC_ALL, "RUS");
    int numMonitors;
    Monitor monitor;
    cout << "Введите количество мониторов: ";
    cin >> numMonitors;
    ofstream outFile("monitors.bin", ios::binary);
    for (int i = 0; i < numMonitors; i++) {
        cout << "Монитор #" << (i + 1) << ":\n";
        cout << "Введите название фирмы: ";
        cin >> monitor.firmName;
        cout << "Введите размер по диагонали: ";
        cin >> monitor.size;
        cout << "Введите стоимость: ";
        cin >> monitor.cost;
        outFile.write(reinterpret_cast<const char*>(&monitor), sizeof(monitor));
    }
    outFile.close();
    ifstream inFile("monitors.bin", ios::binary);
    int numLargerMonitors = 0;
    double totalCost = 0;
    if (inFile.is_open()) {
        cout << "\nМониторы размером не менее 19 дюймов:\n";
        cout << "===================================\n";
        while (inFile.read(reinterpret_cast<char*>(&monitor), sizeof(monitor))) {
            if (monitor.size >= 19) {
                cout << "Название фирмы: " << monitor.firmName << "\n";
                cout << "Размер по диагонали: " << monitor.size << " дюймов\n";
                cout << "Стоимость: " << monitor.cost << "\n\n";

                numLargerMonitors++;
                totalCost += monitor.cost;
            }
        }
        double averageCost = numLargerMonitors > 0 ? totalCost / numLargerMonitors : 0;
        cout << "Средняя цена мониторов размером не менее 19 дюймов: " << averageCost << "\n";
        inFile.close();
    }
    else {
        cout << "Не удалось открыть файл.";
    }

    return 0;
}