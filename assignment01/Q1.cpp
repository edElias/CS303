#include "Q1.h"
#include <iostream>
using namespace std;

// Default Constructor
NumberSearcher::NumberSearcher()
    : arr(nullptr), numPlace(0), currentSize(0) {}

// Parameterized Constructor
NumberSearcher::NumberSearcher(int* array, int& size, int& filledSize)
    : arr(array), numPlace(size), currentSize(filledSize) {}

// Function to search for a number
int NumberSearcher::findNumber(int userIn) {
    for (int i = 0; i < currentSize; ++i) {
        if (arr[i] == userIn) {
            cout << "\n"  << "Number " << userIn << " found at index " << i << "." << endl;
            return i; // Return the index if found
        }
    }

    cout << "\n"  << "Number " << userIn << " does not exist in the array." << endl;
    return -1; // Return -1 to indicate that the number was not found
}

// Function to modify the value at a given index
void NumberSearcher::modifyIndex(int index, int newValue, int& oldValue) {
    if (index >= 0 && index < currentSize) {
        oldValue = arr[index];
        arr[index] = newValue;
        cout << "\n"  << "Index " << index << " modified from " << oldValue << " to " << newValue << "." << endl;
    }
    else {
        cout << "\n"  << "Invalid index!" << endl;
    }
}

// Function to add a new integer to the end of the array
void NumberSearcher::addToEnd(int newValue) {
    if (currentSize == numPlace) {
        numPlace *= 2;
        int* temp = new int[numPlace];

        for (int i = 0; i < currentSize; ++i) {
            temp[i] = arr[i];
        }

        delete[] arr;
        arr = temp;
    }

    arr[currentSize++] = newValue;
    cout << "\n"  << "Added " << newValue << " to the end of the array." << endl;
}

// Function to remove a value at a given index or replace it with 0
void NumberSearcher::removeIndex(int index)
{
    if (index >= 0 && index < currentSize) 
    {
        for (int i = index; i < currentSize - 1; ++i) 
        {
            arr[i] = arr[i + 1];
        }
        currentSize--;
        cout << "\n"  << "Removed value at index " << index << " from the array." << endl;
    }
    else {
        cout << "\n"  << "Invalid index!" << endl;
    }
}
