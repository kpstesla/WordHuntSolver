//
//  main.cpp
//  WordHuntAssistant
//
//  Created by Kyle Whitecross on 5/8/20.
//  Copyright © 2020 Kyle Whitecross. All rights reserved.
//

#include <iostream>
#include <ctype.h>
#include <string>
#include <fstream>
#include "dictionary.h"
#include "WordHuntSolver.h"

using namespace std;

//globals

void printArr(char arr[][4], int r) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    //load dictionary
    cout << "Loading dictionary..." << endl;
    string filepath = "dictionary.txt";
    int minSize = 4;
    dictionary dict;
    dict.loadWords(filepath);
    cout << "Dictionary loaded!  Size: " << dict.size() << " words." << endl;
    cout << "Enter the 4x4 grid characters (top to bottom, left to right):" << endl;
    
    vector<string> words;
    
    assert(dict.isWord("mesoglea"));
    
    //read in input
    
    char chars[4][4];
    char temp;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            do {
                cin >> temp;
            } while (!isalpha(temp));
            chars[i][j] = temp;
        }
    }
    
    /*
    char chars[4][4] = {
        {'E', 'A', 'N' ,'E'},
        {'O', 'H', 'N', 'D'},
        {'L', 'R', 'R', 'O'},
        {'T', 'H', 'T', 'S'}
    };
    */
    
    //find all the words
    cout << "Entered array:" << endl;
    printArr(chars, 4);
    cout << "Finding best words..... ";
    WordHuntSolver whs(chars, dict);
    int numWords = whs.findWords(words);
    cout << "Found " << numWords << " words." << endl;
    cout << "Not printing words less than " << minSize << " chars long. " << endl;
    
    //print the words
    for (int i = 0; i < numWords; i++) {
        if (words[i].size() >= minSize)
            cout << words[i] << endl;
    }
}
