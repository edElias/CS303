#include <array>
#include <fstream>
#include <sstream>
#include <iostream>
#include "ReadFile.h"
//
//OPEN THE INPUT FILE
void readFile(int*& arr, int& numPlace, int& currentSize) {
    ifstream inputFile;
    inputFile.open("input.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    int number;
    while (inputFile >> number) {
        if (currentSize == numPlace) {
            // Double the size of the array
            numPlace *= 2;
            int* temp = new int[numPlace];

            // Copy the contents of the old array to the new array
            for (int i = 0; i < currentSize; ++i) {
                temp[i] = arr[i];
            }

            delete[] arr; // Free the old array
            arr = temp;   // Point to the new array
        }

        // Add the number to the array
        arr[currentSize++] = number;
    }

    inputFile.close(); // Close the file
}