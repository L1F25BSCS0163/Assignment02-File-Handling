
/*
  * Name       : Muhammad Anss
  * Reg No     : L1F25BSCS0163
  * Assignment : 02 - File Handling
  * Question   : Q5 - Expense Tracker
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    int choice;

    do {
        cout << "===== Expense Tracker =====" << endl;
        cout << "1. Add an expense" << endl;
        cout << "2. Show all expenses" << endl;
        cout << "3. Show total of a category" << endl;
        cout << "4. Clear all expenses" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            char category[20];
            int amount;

            cout << "Enter category: ";
            cin >> category;

            cout << "Enter amount: ";
            cin >> amount;

            if (amount <= 0) {
                cout << "Invalid amount!" << endl;
            }
            else {
                ofstream outFile("expenses.txt", ios::app);

                outFile << category << " " << amount << endl;
                outFile.close();

                cout << "Expense saved." << endl;
            }
        }
        else if (choice == 2) {
            ifstream inFile("expenses.txt");

            char categories[100][20];
            int amounts[100];
            int count = 0;
            int total = 0;

            while (count < 100 &&
                inFile >> categories[count] >> amounts[count]) {
                total = total + amounts[count];
                count++;
            }

            inFile.close();

            if (count == 0) {
                cout << "No expenses yet." << endl;
            }
            else {
                int largestIndex = 0;

                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". " << categories[i]
                        << " " << amounts[i] << endl;

                    if (amounts[i] > amounts[largestIndex]) {
                        largestIndex = i;
                    }
                }

                cout << "Total spent: " << total << endl;

                cout << "Largest expense: "
                    << categories[largestIndex] << " ("
                    << amounts[largestIndex] << ")" << endl;
            }
        }
        else if (choice == 3) {
            char wanted[20];
            char category[20];
            int amount;
            int count = 0;
            int total = 0;

            cout << "Enter category: ";
            cin >> wanted;

            ifstream inFile("expenses.txt");

            while (inFile >> category >> amount) {
                if (strcmp(category, wanted) == 0) {
                    count++;
                    total = total + amount;
                }
            }

            inFile.close();

            if (count == 0) {
                cout << "No expenses found for "
                    << wanted << endl;
            }
            else {
                cout << "Expenses in " << wanted
                    << ": " << count << endl;

                cout << "Total for " << wanted
                    << ": " << total << endl;
            }
        }
        else if (choice == 4) {
            ofstream outFile("expenses.txt");
            outFile.close();

            cout << "All expenses cleared." << endl;
        }
        else if (choice == 5) {
            cout << "Goodbye!" << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
