/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Hua Xu, Yihan Guo
 * erinhua, yihanguo
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * a substitution cipher
 */

#include "caesar.h"
#include <iostream>
#include <cctype>

int const NUM_Of_ALPHABET = 26;
int const REVERSE_COEFFIECIENT = -1;

char shiftAlphaCharacter(char c, int n) {
    //split into cases of n>=0 and n<0
    if (n >= 0) {
        if (isupper(c)) {
            if (c + n % NUM_Of_ALPHABET > 'Z') {
                c = c + n %  NUM_Of_ALPHABET - NUM_Of_ALPHABET;
            }
            else {
                c += n % NUM_Of_ALPHABET;
            }
        }
        else {
            if(c + n % NUM_Of_ALPHABET > 'z') {
                c = c + n % NUM_Of_ALPHABET - NUM_Of_ALPHABET;
            }
            else {
                c += n % NUM_Of_ALPHABET;
            }
        }
    }
    else {
        if (isupper(c)) {
            if(c + n % NUM_Of_ALPHABET < 'A') {
                c = c + n % NUM_Of_ALPHABET + NUM_Of_ALPHABET;
            }
            else {
                c += n % NUM_Of_ALPHABET;
            }
        }
        else {
            if (c + n % NUM_Of_ALPHABET < 'a') {
                c = c + n % NUM_Of_ALPHABET + NUM_Of_ALPHABET;
            }
            else {
                c += n % NUM_Of_ALPHABET;
            }
        }
    }
    return c;
}


string caesarCipher(string original, int key, bool encrypt) {
    string modified = original;
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original[i]) && encrypt) {
            modified[i] = shiftAlphaCharacter(original[i], key);
        }
        else if (isalpha(original[i]) && !encrypt) {
            modified[i] = shiftAlphaCharacter(original[i], key * REVERSE_COEFFIECIENT);
        }
    }
    return modified;
}
