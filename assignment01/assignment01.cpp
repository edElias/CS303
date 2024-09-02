// assignment01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "Function.h"
#include <array>
using namespace std;

int main() {
    int numPlace = 10;           // Initial size of the array
    int* arr = new int[numPlace]; // Create and declare the array dynamically with an initial size
    int currentSize = 0;         // Keeps track of the number of elements in the array

    readFile(arr, numPlace, currentSize); // Call readFile to fill the array

    // Output the array to verify
    for (int i = 0; i < currentSize; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr; // Free the final array

    return 0;
}