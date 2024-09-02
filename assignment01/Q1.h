#pragma once
#include <iostream>
using namespace std;

class NumberSearcher {
private:
    int* arr;        // Pointer to the array
    int numPlace;    // Size of the array (capacity)
    int currentSize; // Current number of elements in the array

public:
    // Constructor
    NumberSearcher();
    NumberSearcher(int* array, int& size, int& filledSize);

    // Function to search for a number
    int findNumber(int userIn);

    // Function to modify the value at a given index
    void modifyIndex(int index, int newValue, int& oldValue);

    // Function to add a new integer to the end of the array
    void addToEnd(int newValue);

    // Function to remove a value at a given index or replace it with 0
    void removeIndex(int index);
};