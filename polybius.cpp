/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Hua Xu, Yihan Guo
 * erinhua, yihanguo
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * Polybius Square is a device invented by the Ancient
 *  Greek historian and scholar Polybius.
 */


#include "polybius.h"
#include <string>
using namespace std;



string mixKey(string key) {
    string result = "";
    result += key;
    for (int i = 0; i < ALNUM.length(); ++i) {
            if(key.find(ALNUM[i]) == -1) {
                result += ALNUM[i];
            }
        }
    return result;
    }
   

void fillGrid(char grid[SIZE][SIZE], string content) {
    int k = 0;
    for (int i = 0; i < SIZE ; ++i) {
        for (int j = 0;j < SIZE ; ++j) {
            grid[i][j] = content[k];
            ++k;
        }
    }
}

string findInGrid(char c, char grid[SIZE][SIZE]) {
    string positionInGrid1;
    string positionInGrid2;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == c) {
                positionInGrid1 = to_string(i);
                positionInGrid2 = to_string(j);
            }
        }
    }
    return positionInGrid1 + positionInGrid2;
}


string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt) {
    string resultOfKey = mixKey(key);
    fillGrid(grid,resultOfKey);
    string result = "";
    string originalUpper = toUpperCase(original);
    if (encrypt){
        for (int i = 0; i < originalUpper.size(); ++i) {
            if (originalUpper[i] == ' ') {
                result += " ";
            }
            else {
                string position = findInGrid(originalUpper[i],grid);
                result += position;
            }
        }
    }
    else {
        for (int i = 0; i < originalUpper.size(); i += 2) {
            if (isspace(originalUpper[i])) {
                result += " ";
                i = i - 1;
            }
            else {
                int row = charToInt(originalUpper[i]);
                int column = charToInt(originalUpper[i + 1]);
                result += grid[row][column];
            }
        }
    }
    return result;
}
