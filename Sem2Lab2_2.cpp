#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;
int main() {
    setlocale(LC_ALL, "RUS");
    ofstream file("patients.txt");
    if (file.is_open()) {
        file << "Пациент 1: Иванов; Иван; Иванович; м; русский; 180; 75; 1990, 01, 01; 1234567890; 123456, Россия, Москва, район1, город1, улица1, 1, 1; 1; 18; 00001; Бронхит; 4+\n";
        file << "Пациент 2: Петров; Петр; Петрович; м; русский; 170; 65; 1995, 02, 02; 9876543210; 654321, Россия, Санкт-Петербург, район2, город2, улица2, 2, 2; 2; 18; 00002; Грипп; 3+\n";
        file.close();
        cout << "Файл успешно создан и заполнен данными.\n";
    }
    else {
        cout << "Ошибка при создании файла.\n";
    }
    ifstream readFile("patients.txt");
    if (readFile.is_open()) {
        string line;
        while (getline(readFile, line)) {
            cout << line << "\n";
        }
        readFile.close();
    }
    else {
        cout << "Ошибка при открытии файла для чтения.\n";
    }
    return 0;
}

struct Patient {
    string lastName;
    string firstName;
    string middleName;
    string gender;
    string nationality;
    int height;
    int weight;
    string dateOfBirth;
    string phoneNumber;
    string address;
    string hospitalNumber;
    int department;
    string medicalCardNumber;
    string diagnosis;
    string bloodGroup;
};

vector<Patient> getPatientsByDepartment(const vector<Patient>& patients, int department) {
    vector<Patient> patientsByDepartment;
    for (const auto& patient : patients) {
        if (patient.department == department) {
            patientsByDepartment.push_back(patient);
        }
    }
    return patientsByDepartment;
}

int main_1() {
    vector<Patient> patients;
    setlocale(LC_ALL, "RUS");
    ifstream file("patients.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            if (line.find("Пациент") != string::npos) {
                Patient patient;
                stringstream ss(line);
                string delimiter = "; ";
                string token;
                getline(ss, token, ':');
                getline(ss, token, ':');
                stringstream pss(token);

                getline(pss, patient.lastName, ';');
                getline(pss, patient.firstName, ';');
                getline(pss, patient.middleName, ';');
                getline(pss, patient.gender, ';');
                getline(pss, patient.nationality, ';');
                pss >> patient.height;
                pss.ignore();
                pss >> patient.weight;
                pss.ignore();
                getline(pss, patient.dateOfBirth, ';');
                getline(pss, patient.phoneNumber, ';');
                getline(pss, patient.address, ';');
                getline(pss, patient.hospitalNumber, ';');
                pss >> patient.department;
                pss.ignore();
                getline(pss, patient.medicalCardNumber, ';');
                getline(pss, patient.diagnosis, ';');
                getline(pss, patient.bloodGroup, ';');
                patients.push_back(patient);
            }
        }
        file.close();
    }
    else {
        cout << "Ошибка при открытии файла для чтения.\n";
        return 1;
    }
    vector<Patient> patientsByDepartment = getPatientsByDepartment(patients, 18);
    if (patientsByDepartment.empty()) {
        cout << "Нет пациентов в 18 отделении.\n";
    }
    else {
        ofstream outputFile("patients_by_department.txt");
        if (outputFile.is_open()) {
            for (const auto& patient : patientsByDepartment) {
                outputFile << "Пациент: " << patient.lastName << "; " << patient.firstName << "; " << patient.middleName << "\n";
            }
            outputFile.close();
            cout << "Результаты сохранены в файл patients_by_department.txt\n";
        }
        else {
            cout << "Ошибка при создании файла для записи результатов.\n";
        }
    }
    return 0;
}