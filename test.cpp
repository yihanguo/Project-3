//
//  test.cpp
//  Project3

/* Hua Xu, Yihan Guo
* erinhua, yihanguo
*
* EECS 183: Project 3
* Fall 2023
*
* Test all code
*/

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>


void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testShiftAlphaCharacter();
void testCaesarCipher();
void testMixKey();
void testFillGrid();
void testFindInGrid();
void testPolybiusSquare();
void testVigenereCipher();


void startTests(){
    
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testShiftAlphaCharacter();
    testCaesarCipher();
    testMixKey();
    testFillGrid();
    testFindInGrid();
    testPolybiusSquare();
    testVigenereCipher();
    
    return;
    
}



//Test "utility.h"
void testToUpperCase(){
    cout << "Expected: ABCDE, Actual: " << toUpperCase("abcde") << endl;
    cout << "Expected: ROOEF, Actual: " << toUpperCase("rooef") << endl;
    cout << "Expected: AFTER A STORM COMES A CALM , Actual: " << toUpperCase
            ("After a storm comes a calm") << endl;
    cout << "Expected: &, Actual: " << toUpperCase("&") << endl;
}

void testRemoveNonAlphas(){
    cout << "Expected: EECS, Actual: " << removeNonAlphas("EECS 183!") << endl;
    cout << "Expected: hioneaa, Actual: " << removeNonAlphas("4hione0-  1aa!!") << endl;
}

void testRemoveDuplicate(){
    cout << "Expected: ABC, Actual: " << removeDuplicate("AABCABC") << endl;
    cout << "Expected: USB, Actual: " << removeDuplicate("UUUSBUSUB") << endl;
}

void testCharToInt(){
    cout << "Expected: 1, Actual: " << charToInt('1') << endl;
    cout << "Expected: 9, Actual: " << charToInt('9') << endl;
}

//Test "caesar.h"
void testShiftAlphaCharacter(){
    cout << "Expected: a, Actual: " << shiftAlphaCharacter('a', 0) << endl;
    cout << "Expected: d, Actual: " << shiftAlphaCharacter('b', 2) << endl;
    cout << "Expected: C, Actual: " << shiftAlphaCharacter('X', 5) << endl;
    cout << "Expected: V, Actual: " << shiftAlphaCharacter('X', 50) << endl;
    cout << "Expected: c, Actual: " << shiftAlphaCharacter('a', -50) << endl;
    cout << "Expected: S, Actual: " << shiftAlphaCharacter('X', -5) << endl;
}

void testCaesarCipher(){
    cout << "Expected: Cuuj cu qj jxu Tyqw qj 11 f.c., Actual: " 
         << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true)
         << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m., Actual: "
         << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.", 42, false)
         << endl;
    cout << "Expected: P zvsltusf zdlhy aoha P ht bw av uv nvvk., Actual: "
         << caesarCipher("I solemnly swear that I am up to no good.", 7, true)
         << endl;
    cout << "Expected: I solemnly swear that I am up to no good., Actual: "
         << caesarCipher("P zvsltusf zdlhy aoha P ht bw av uv nvvk.", 7, false)
         << endl;
}

//Test "polybius.h"
void testMixKey(){
    cout << "Expected: USEFLABCDGHIJKLMNOPQRTUVWXYZ123456789, Actual: "
         << mixKey("USEFL") << endl;
}

void testFillGrid(){
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    printGrid(grid);
    fillGrid(grid, mixKey("POLYBIUS"));
    printGrid(grid);
}

void testFindInGrid(){
    char grid[SIZE][SIZE];
    fillGrid(grid, ALNUM);
    cout << "Expected: 00, Actual: " << findInGrid('A', grid)  << endl;
    
}

void testPolybiusSquare(){
    char grid[SIZE][SIZE];
    cout << "Expected: 11110533 000102 1533 341411 04113334, Actual: "
         << polybiusSquare(grid, "183", "EECS 183 IS THE BEST", true) << endl;
    cout << "Expected:EECS 183 IS THE BEST, Actual: "
         << polybiusSquare(grid, "183", "11110533 000102 1533 341411 04113334", false)
         << endl;
}

//Test "vigenere.h"
void testVigenereCipher(){
    cout << "Expected: Euyb dv ee lxy Lzrk ll 11 f.g., Actual: " 
         << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true)
         << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m., Actual: "
         << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false)
         << endl;
    
}


