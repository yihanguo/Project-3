/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Hua Xu, Yihan Guo
 * erinhua, yihanguo
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 *  create a program that asks the user for a cipher
 *  (Caesar, Vigenere, or Polybius),
 *   whether the user would like to encrypt or decrypt a message
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;


void ciphers() {
    //Get cipher type
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): ";
    string cipherType;
    getline(cin, cipherType);
    
    string typeUpperCase = toUpperCase(cipherType);
    
    if (typeUpperCase[0] != 'C' && typeUpperCase[0] != 'V'
        && typeUpperCase[0] != 'P') {
        cout << "Invalid cipher!";
        return;
    }
    
    //Get Cipher Mode
    cout << "Encrypt or decrypt: ";
    string cipherMode;
    getline(cin, cipherMode);
    
    string modeUpperCase = toUpperCase(cipherMode);
    
    if (modeUpperCase[0] != 'E' && modeUpperCase[0] != 'D') {
        cout << "Invalid mode!" ;
        return;
    }
    
    //Get Message
    cout << "Enter a message: ";
    string messageEnter;
    getline(cin, messageEnter);
    
    if (typeUpperCase[0] == 'P') {
        for (int i = 0; i < messageEnter.size(); i++) {
            if (!isalpha(messageEnter[i]) && !isspace(messageEnter[i])
                && !isdigit(messageEnter[i])) {
                cout << "Invalid message!";
                return;
            }
        }
    }
    
    //Get Keyword
    cout << "What is your key: ";
    
    if (typeUpperCase[0] == 'V') {
        //ensure the keyword contains at least one alphabetical character
        string keyOfV;
        getline(cin, keyOfV);
        
        int countOfAlpha = 0;
        
        for (int i = 0; i < keyOfV.size(); i++) {
            if (isalpha(keyOfV[i])) {
                countOfAlpha++;
            }
        }
        if (countOfAlpha == 0) {
            cout << "Invalid key!";
            return;
        }
        else {
            //print out the encrypted or decrypted message
            if (modeUpperCase[0] == 'E') {
                cout << "The encrypted message is: " 
                     << vigenereCipher(messageEnter, keyOfV, 1) << endl;
            }
            else if (modeUpperCase[0] == 'D') {
                cout << "The decrypted message is: " 
                     << vigenereCipher(messageEnter , keyOfV , 0) << endl;
            }
        }
    }
    
    else if (typeUpperCase[0] == 'C') {
        int intKeyOfC;
        cin >> intKeyOfC;
        //print out the encrypted or decrypted message
        if (modeUpperCase[0] == 'E') {
            cout << "The encrypted message is: " 
                 << caesarCipher(messageEnter, intKeyOfC, 1) << endl;
        }
        else if (modeUpperCase[0] == 'D') {
            cout << "The decrypted message is: " 
                 << caesarCipher(messageEnter , intKeyOfC , 0) << endl;
        }
    }
    
    else if (typeUpperCase[0] == 'P'){
        char grid[SIZE][SIZE];
        string keyOfP;
        getline(cin, keyOfP);
        keyOfP = toUpperCase(keyOfP);
        keyOfP = removeDuplicate(keyOfP);
        messageEnter = toUpperCase(messageEnter);
        //print out the encrypted or decrypted message
        if (modeUpperCase[0] == 'E') {
            cout << "The encrypted message is: " 
                 << polybiusSquare(grid, keyOfP , messageEnter , 1) << endl;
        }
        else if (modeUpperCase[0] == 'D') {
            cout << "The decrypted message is: " 
                 << polybiusSquare(grid, keyOfP , messageEnter , 0) << endl;
        }
    }
    return;
}


