//
//  WordHuntSolver.h
//  WordHuntAssistant
//
//  Created by Kyle Whitecross on 5/24/20.
//  Copyright © 2020 Kyle Whitecross. All rights reserved.
//

#ifndef WordHuntSolver_h
#define WordHuntSolver_h

#include <queue>
#include <string>
#include <vector>
#include "dictionary.h"

using std::string;
using std::vector;
using std::queue;

const char LOOKED_AT = '#';
const int ROWS = 4;
const int COLS = 4;

class WordHuntSolver {
public:
    WordHuntSolver(char arr[ROWS][COLS], dictionary& dictp);
    ~WordHuntSolver();
    
    // finds all the words in the grid
    int findWords(vector<string>& wordsVec);
    
private:
    //struct for representing a current iteration of the grid
    struct CharGrid {
        CharGrid(char arr[ROWS][COLS], string start, int r, int c);
        ~CharGrid();
        
        //creates a new chargrid from this current one
        CharGrid spawn(int r, int c);
        
        //member variables
        char grid[ROWS][COLS];
        string word;
        int currentR;
        int currentC;
    };
    
    //processes a single grid and adds the new grids to the queue
    void processCharGrid(CharGrid& cg, vector<string>& wordsVec);
    
    //spawns new grids
    void addLeftRight(CharGrid& cg, int r, int c);
    //member data
    char grid[ROWS][COLS];
    queue<CharGrid> grids;
    dictionary& dict;
};

#endif /* WordHuntSolver_h */
