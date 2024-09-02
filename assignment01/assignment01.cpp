// assignment01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "ReadFile.h"
using namespace std;

int main() {
    int numPlace = 10;           // Initial size of the array
    int* arr = new int[numPlace]; // Create and declare the array dynamically with an initial size
    int currentSize = 0;         // Keeps track of the number of elements in the array
    int userIn1, userIn2;
    readFile(arr, numPlace, currentSize); // Call readFile to fill the array

    //// Output the array to verify
    //for (int i = 0; i < currentSize; ++i) {
    //    cout << arr[i] << " ";
    //}
    //

    //delete[] arr; // Free the final array

    NumberSearcher searcher(arr, numPlace, currentSize);
    //Q1 FUNCTIONS
    
    //1) A function to check if a certain integer exists in the array if the number is present return the index where the number is present.
    cout << "Enter a number to find: " << endl;
    cin >> userIn1;
    
    searcher.findNumber(userIn1);

    //2) A function that can modify the value of an integer when called with the index of the integer in the array and return the new value and old value back to the user.
    cout << "\nEnter an index and a number you would like to replace it with: " << endl;
    cin >> userIn1 >> userIn2;
    
    int oldValue;
    searcher.modifyIndex(userIn1, userIn2, oldValue);

    //3) A function that adds a new integer to the end of the array
    cout << "\nEnter a number to add to the array: " << endl;
    cin >> userIn1;
    
    searcher.addToEnd(userIn1);

    //4) A function which intakes an index of an array and removes the integer altogether
    cout << "\nEnter an index to remove that value: " << endl;
    cin >> userIn1;
    
    searcher.removeIndex(userIn1);

    return 0;
}