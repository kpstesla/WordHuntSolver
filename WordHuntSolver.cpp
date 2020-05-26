//
//  WordHuntSolver.cpp
//  WordHuntAssistant
//
//  Created by Kyle Whitecross on 5/24/20.
//  Copyright © 2020 Kyle Whitecross. All rights reserved.
//

#include "WordHuntSolver.h"
#include "dictionary.h"
#include <string>
#include <vector>
#include <queue>

using namespace std;

WordHuntSolver::WordHuntSolver(char arr[ROWS][COLS], dictionary& dictp)
:dict(dictp) {
    memcpy(grid, arr, ROWS * COLS * sizeof(char));
}

WordHuntSolver::~WordHuntSolver() {
    
}

int WordHuntSolver::findWords(vector<string>& wordsVec) {
    CharGrid origin(grid, "", 0, 0);
    //create all of the starting grids
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            CharGrid temp = origin.spawn(i, j);
            grids.push(temp);
        }
    }
    
    //process all the grids
    while (grids.size() > 0) {
        CharGrid curr = grids.front();
        grids.pop();
        processCharGrid(curr, wordsVec);
    }
    
    // remove uniques from array
    vector<string>::iterator ep = unique(wordsVec.begin(), wordsVec.end());
    wordsVec.resize(distance(wordsVec.begin(), ep));
    
    //sort the array
    auto lambda = [] (string s1, string s2) {
        return s1.size() > s2.size();
    };
    
    sort(wordsVec.begin(), wordsVec.end(), lambda);
    
    
    return wordsVec.size();
}

void WordHuntSolver::addLeftRight(CharGrid& cg, int r, int c) {
    if (c > 0) {
        if (cg.grid[r][c - 1] != LOOKED_AT) {
            CharGrid temp = cg.spawn(r, c - 1);
            grids.push(temp);
        }
    }
    if (c < COLS - 1) {
        if (cg.grid[r][c + 1] != LOOKED_AT) {
            CharGrid temp = cg.spawn(r, c + 1);
            grids.push(temp);
        }
    }
    if (cg.grid[r][c] != LOOKED_AT) {
        CharGrid temp = cg.spawn(r, c);
        grids.push(temp);
    }
}

void WordHuntSolver::processCharGrid(CharGrid& cg, vector<string>& wordsVec) {
    if (dict.isWord(cg.word)) {
        wordsVec.push_back(cg.word);
    }
    
    if (dict.isStub(cg.word)) {
        CharGrid temp = cg;
        int r = cg.currentR;
        int c = cg.currentC;
        
        //process same row
        addLeftRight(cg, r, c);
        
        //process upper row
        if (r > 0) {
            addLeftRight(cg, r - 1, c);
        }
        
        //process lower row
        if (r < ROWS - 1) {
            addLeftRight(cg, r + 1, c);
        }
    }
}

WordHuntSolver::CharGrid::CharGrid(char arr[ROWS][COLS], string start, int r, int c) {
    memcpy(grid, arr, ROWS * COLS * sizeof(char));
    word = start;
    currentC = c;
    currentR = r;
}

WordHuntSolver::CharGrid::~CharGrid() {
    
}

WordHuntSolver::CharGrid WordHuntSolver::CharGrid::spawn(int r, int c) {
    CharGrid temp = *this;
    temp.word += grid[r][c];
    temp.grid[r][c] = LOOKED_AT;
    temp.currentR = r;
    temp.currentC = c;
    return temp;
}
