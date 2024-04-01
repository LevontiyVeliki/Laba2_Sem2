#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Функция для вывода матрицы
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для вывода вектора
void printVector(const vector<double>& vector) {
    for (const auto& elem : vector) {
        cout << elem << " ";
    }
    cout << endl << endl;
}

int main() {
    // Чтение из первого файла
    ifstream inputFile1("file1.txt");
    int k, n;
    inputFile1 >> k >> n;

    vector<vector<double>> matrix;

    for (int i = 0; i < k; i++) {
        vector<double> row(n + 1);
        for (int j = 0; j < n + 1; j++) {
            inputFile1 >> row[j];
        }
        matrix.push_back(row);
    }

    inputFile1.close();

    // Чтение из второго файла
    ifstream inputFile2("file2.txt");
    vector<vector<double>> solutions;

    for (int i = 0; i < k; i++) {
        vector<double> solution(n);
        for (int j = 0; j < n; j++) {
            inputFile2 >> solution[j];
        }
        solutions.push_back(solution);
    }

    inputFile2.close();

    // Вывод исходной системы уравнений и результатов
    for (int i = 0; i < k; i++) {
        cout << "Система уравнений " << i + 1 << ":" << endl;
        printMatrix(matrix);
        cout << "Решение: ";
        printVector(solutions[i]);
    }

    // Добавление новых данных
    ofstream outputFile1("file1.txt", ios::app);
    ofstream outputFile2("file2.txt", ios::app);

    int newK, newN;

    cout << "Введите количество новых матриц: ";
    cin >> newK;

    for (int i = 0; i < newK; i++) {
        cout << "Введите размерность матрицы: ";
        cin >> newN;

        outputFile1 << endl << newN << " " << newN + 1 << endl;

        for (int j = 0; j < newN; j++) {
            for (int k = 0; k < newN + 1; k++) {
                double elem;
                cout << "Введите элемент матрицы: ";
                cin >> elem;
                outputFile1 << elem << " ";
            }
            outputFile1 << endl;
        }

        for (int j = 0; j < newN; j++) {
            double elem;
            cout << "Введите элемент вектора: ";
            cin >> elem;
            outputFile2 << elem << " ";
        }
        outputFile2 << endl;
    }

    outputFile1.close();
    outputFile2.close();

    // Удаление ненужной информации
    ofstream tempFile1("temp1.txt");
    ofstream tempFile2("temp2.txt");

    for (int i = 0; i < k; i++) {
        tempFile1 << n << " " << n + 1 << endl;

        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n + 1; k++) {
                tempFile1 << matrix[i][j][k] << " ";
            }
            tempFile1 << endl;
        }

        for (int j = 0; j < n; j++) {
            tempFile2 << solutions[i][j] << " ";
        }
        tempFile2 << endl;
    }

    tempFile1.close();
    tempFile2.close();

    remove("file1.txt");
    remove("file2.txt");
    rename("temp1.txt", "file1.txt");
    rename("temp2.txt", "file2.txt");

    return 0;
}