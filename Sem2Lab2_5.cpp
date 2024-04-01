#include <iostream>
#include <fstream>
#pragma warning(disable : 4996)
using namespace std;

struct Purchase {
    char fullName[50];
    char date[11];
    double totalCost;
    double discountPercentage;
};

int main() {
    ofstream outFile("purchase.bin", ios::binary);
    if (!outFile) {
        cerr << "Failed to create binary file." << endl;
        return 1;
    }
    Purchase purchase1;
    strcpy(purchase1.fullName, "John Smith");
    strcpy(purchase1.date, "2020-05-20");
    purchase1.totalCost = 10000;
    purchase1.discountPercentage = 10;
    Purchase purchase2;
    strcpy(purchase2.fullName, "Jane Doe");
    strcpy(purchase2.date, "2020-05-21");
    purchase2.totalCost = 5000;
    purchase2.discountPercentage = 5;
    outFile.write(reinterpret_cast<char*>(&purchase1), sizeof(Purchase));
    outFile.write(reinterpret_cast<char*>(&purchase2), sizeof(Purchase));
    outFile.close();
    ifstream inFile("purchase.bin", ios::binary);
    if (!inFile) {
        cerr << "Failed to open binary file." << endl;
        return 1;
    }
    Purchase purchases[2];
    inFile.read(reinterpret_cast<char*>(&purchases[0]), sizeof(Purchase));
    inFile.read(reinterpret_cast<char*>(&purchases[1]), sizeof(Purchase));
    inFile.close();
    if (purchases[0].totalCost == 5000) {
        purchases[1].discountPercentage += 5;
    }

    ofstream updatedFile("purchase.bin", ios::binary | ios::trunc);
    if (!updatedFile) {
        cerr << "Failed to update binary file." << endl;
        return 1;
    }

    updatedFile.write(reinterpret_cast<char*>(&purchases[0]), sizeof(Purchase));
    updatedFile.write(reinterpret_cast<char*>(&purchases[1]), sizeof(Purchase));
    updatedFile.close();
    return 0;
}
