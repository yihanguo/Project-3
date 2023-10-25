/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Hua Xu, Yihan Guo
 * erinhua, yihanguo
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * Serve as helper functions in caesar.cpp, vigenere.cpp, and polybius.cpp
 */

#include "utility.h"
#include <iostream>
#include <cctype>


string toUpperCase(string original) {
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original[i])) {
            original[i] = toupper(original[i]);
        }
    }
    return original;
}



string removeNonAlphas(string original) {
    string modified;
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original[i])) {
            modified += original[i];
        }
    }
    return modified;
}

string removeDuplicate(string original) {
    string modified = "";
    modified += original[0];
    for (int i = 1; i < original.size(); i++) {
        if (modified.find(original[i]) == -1) {
            modified += original[i];
        }
    }
    return modified;
}

int charToInt(char original) {
    int modified;
        modified = original - '0';
        return modified;
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
