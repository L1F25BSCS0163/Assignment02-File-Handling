
/*
  * Name       : Muhammad Anss
  * Reg No     : L1F25BSCS0163
  * Assignment : 02 - File Handling
  * Question   : Q3 - Scholarship List
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    char path[100];

    cout << "Enter the file name: ";
    cin.getline(path, 100);

    ifstream inFile(path);

    if (!inFile.is_open()) {
        cout << "Could not open " << path << "!" << endl;
        return 1;
    }

    ofstream outFile("scholarship.txt");

    int n;

    if (!(inFile >> n)) {
        cout << "No students found!" << endl;
        inFile.close();
        outFile.close();
        return 0;
    }

    if (n > 30) {
        cout << "Too many students!" << endl;
        inFile.close();
        outFile.close();
        return 0;
    }

    inFile.ignore(100, '\n');

    char name[30];
    char topName[30] = "";
    double cgpa;
    double total = 0;
    double highest = 0;
    int students = 0;
    int eligible = 0;

    for (int i = 0; i < n; i++) {
        if (!inFile.getline(name, 30, ',')) {
            break;
        }

        if (!(inFile >> cgpa)) {
            break;
        }

        inFile.ignore(100, '\n');

        cout << "[" << name << "] CGPA: " << cgpa << endl;

        students++;
        total = total + cgpa;

        if (cgpa >= 3.50) {
            outFile << name << "," << cgpa << endl;
            eligible++;
        }

        if (students == 1 || cgpa > highest) {
            highest = cgpa;
            strcpy(topName, name);
        }
    }

    if (students < n) {
        cout << "Warning: only " << students << " of "
            << n << " records found." << endl;
    }

    if (students == 0) {
        cout << "No students found!" << endl;
        inFile.close();
        outFile.close();
        return 0;
    }

    cout << "Students: " << students << endl;
    cout << "Average CGPA: " << total / students << endl;
    cout << "Eligible for scholarship: " << eligible << endl;
    cout << "Top student: " << topName
        << " (" << highest << ")" << endl;

    inFile.close();
    outFile.close();

    return 0;
}
