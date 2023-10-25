/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Hua Xu, Yihan Guo
 * erinhua, yihanguo
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * Vigenère cipher improves upon Caesar cipher
 * by shifting letters using different keys. 
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>
#include <cmath>

int const REVERSE_COEFFIECIENT = -1;

string vigenereCipher(string original, string keyword,
                      bool encrypt) {
    string Final = original;
    string refinedKeyword = removeNonAlphas(keyword);
    string refinedKeyword2 = toUpperCase(refinedKeyword);

    int k = 0;
    for (int i = 0; i < original.size(); i++) {
        int charsToInt = refinedKeyword2[k] - 'A';
        if (isalpha(original[i]) && encrypt){
            Final[i] = shiftAlphaCharacter(original[i], charsToInt);
            ++k;
            if (k >= refinedKeyword2.size()) {
                 k = 0;
                }
        }
        else if (isalpha(original[i]) && ! encrypt){
            Final[i] = shiftAlphaCharacter(original[i],
                       charsToInt * REVERSE_COEFFIECIENT);
            ++k;
            if (k >= refinedKeyword2.size()) {
                 k = 0;
                }
        }
    }
    return Final;
}



