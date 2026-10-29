/*
 * Name       : Muhammad Anss
 * Reg No     : L1F25BSCS0163
 * Assignment : 02 - File Handling
 * Question   : Q1 - Stock Report (Debugging)
 */

#include <iostream>

// Fix 1: The fstream header is needed for file input and output.
#include <fstream>

using namespace std;

int main() {
    ifstream inFile("stock.txt");

    // FIX 2: Check whether the input file failed to open.
    if (!inFile) {
        cout << "stock.txt not found!" << endl;
        return 1;
    }

    // FIX 3: Skip the header line before reading stock items.
    inFile.ignore(100, '\n');

    // FIX 4: Append new records without deleting existing records.
    ofstream reorder("reorder.txt", ios::app);

    char code[10];
    int qty, count = 0, low = 0;
    double price;
    
    // FIX 5: Use double to preserve decimal values in the total.
    double total = 0;

    while (count < 50 && inFile >> code >> qty >> price) {
        count++;
        total = total + qty * price;
        if (qty < 10) {

            // FIX 6: Write each reorder item on a separate line.
            reorder << code << " " << qty << endl;
            low++;
        }
    }
    inFile.close();
    reorder.close();

    cout << "Items: " << count << endl;
    cout << "Total stock value: " << total << endl;
    cout << "Low stock items: " << low << endl;
    return 0;
}
