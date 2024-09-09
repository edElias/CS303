#include <iostream>
#include <limits> // For numeric_limits
#include "ReadFile.h"
using namespace std;

int main() {
    int numPlace = 10;           // Initial size of the array
    int* arr = new int[numPlace]; // Create and declare the array dynamically with an initial size
    int currentSize = 0;         // Keeps track of the number of elements in the array
    int userIn1, userIn2;
    int choice;                  // User's menu choice
    bool running = true;         // Loop control variable
    readFile(arr, numPlace, currentSize); // Call readFile to fill the array

    NumberSearcher searcher(arr, numPlace, currentSize);

    while (running) {
        // Display menu
        cout << "\nMenu:\n";
        cout << "1. Find a number in the array\n";
        cout << "2. Modify a number in the array\n";
        cout << "3. Add a number to the array\n";
        cout << "4. Remove a number from the array\n";
        //cout << "5. Display array\n"; // UNCOMMENT for testing
        cout << "5. Exit\n"; // Change to 6 for testing
        cout << "Enter your choice: ";

        // Validate menu choice input
        while (!(cin >> choice)) {
            cin.clear(); // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number for your choice: ";
        }

        switch (choice) {
        case 1:
            // Find a number in the array
            cout << "Enter a number to find: ";
            while (!(cin >> userIn1)) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                cout << "Invalid input. Please enter a valid number to find: ";
            }
            searcher.findNumber(userIn1);
            break;

        case 2:
            // Modify a number in the array with exception handling
            try {
                cout << "\nEnter an index and a number you would like to replace it with: ";
                while (!(cin >> userIn1 >> userIn2)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter valid numbers for the index and replacement: ";
                }

                // Ensure the index is within a valid range
                if (userIn1 < 0 || userIn1 >= currentSize) {
                    throw out_of_range("Invalid index. Please enter an index within the array bounds.");
                }

                int oldValue;
                searcher.modifyIndex(userIn1, userIn2, oldValue);
                cout << "Old value: " << oldValue << " replaced with " << userIn2 << endl;
            }
            catch (const out_of_range& e) {
                cout << "Error: " << e.what() << endl;
            }
            catch (...) {
                cout << "An unexpected error occurred while modifying the array." << endl;
            }
            break;

        case 3:
            // Add a number to the array with exception handling
            try {
                cout << "\nEnter a number to add to the array: ";
                while (!(cin >> userIn1)) {
                    cin.clear(); // Clear the error flag
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
                    cout << "Invalid input. Please enter a valid number to add: ";
                }

                searcher.addToEnd(userIn1);
            }
            catch (...) {
                cout << "An unexpected error occurred while adding to the array." << endl;
            }
            break;

        case 4:
            // Remove a number from the array
            cout << "\nEnter an index to remove that value: ";
            while (!(cin >> userIn1)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid index to remove: ";
            }
            searcher.removeIndex(userIn1);
            break;

            // case 5: UNCOMMENT for testing
            //    // Display the array
            //    cout << "Current array: ";
            //    for (int i = 0; i < currentSize; ++i) {
            //        cout << arr[i] << " ";
            //    }
            //    cout << endl;
            //    break;

        case 5: // Change to 6 for testing
            // Exit the program
            running = false;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    delete[] arr; // Free the final array
    return 0;
}
