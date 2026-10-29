/*
  * Name       : Muhammad Anss
  * Reg No     : L1F25BSCS0163
  * Assignment : 02 - File Handling
  * Question   : Q2 - Parking Report
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ifstream inFile("parking.txt");

    if (!inFile) {
        cout << "parking.txt not found!" << endl;
        return 1;
    }

    int day, month, year;
    char slash;

    inFile >> day >> slash >> month >> slash >> year;
    inFile.ignore(100, '\n');
    inFile.ignore(100, '\n');

    ofstream outFile("receipts.txt");

    cout << "Parking report for " << day << "/"
        << month << "/" << year << endl;

    outFile << "Receipts for " << day << "/"
        << month << "/" << year << endl;

    char plate[15];
    char type;
    char inTime[6], outTime[6];
    char longestPlate[15] = "";

    int count = 0, cars = 0, bikes = 0;
    int totalCollected = 0;
    int longestMinutes = -1;

    while (count < 30 &&
        inFile >> plate >> type >> inTime >> outTime) {

        int inHour = (inTime[0] - '0') * 10
            + (inTime[1] - '0');
        int inMin = (inTime[3] - '0') * 10
            + (inTime[4] - '0');

        int outHour = (outTime[0] - '0') * 10
            + (outTime[1] - '0');
        int outMin = (outTime[3] - '0') * 10
            + (outTime[4] - '0');

        int startMinutes = inHour * 60 + inMin;
        int endMinutes = outHour * 60 + outMin;
        int parkedMinutes = endMinutes - startMinutes;

        int chargedHours = (parkedMinutes + 59) / 60;

        if (chargedHours == 0) {
            chargedHours = 1;
        }

        int fee;

        if (type == 'C') {
            fee = chargedHours * 100;
            cars++;
        }
        else {
            fee = chargedHours * 40;
            bikes++;
        }

        count++;
        totalCollected = totalCollected + fee;

        if (parkedMinutes > longestMinutes) {
            longestMinutes = parkedMinutes;
            strcpy(longestPlate, plate);
        }

        if (type == 'C') {
            cout << plate << " Car ";
        }
        else {
            cout << plate << " Bike ";
        }

        cout << parkedMinutes / 60 << " h "
            << parkedMinutes % 60 << " min Fee: "
            << fee << endl;

        outFile << plate << " " << fee << endl;
    }

    inFile.close();
    outFile.close();

    if (count == 0) {
        cout << "No vehicles found!" << endl;
        return 0;
    }

    cout << "Vehicles: " << count << endl;
    cout << "Cars: " << cars << " Bikes: " << bikes << endl;
    cout << "Total collected: " << totalCollected << endl;

    cout << "Longest stay: " << longestPlate << " ("
        << longestMinutes / 60 << " h "
        << longestMinutes % 60 << " min)" << endl;

    return 0;
}