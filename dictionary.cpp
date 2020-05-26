//
//  dictionary.cpp
//  WordHuntAssistant
//
//  Created by Kyle Whitecross on 5/24/20.
//  Copyright © 2020 Kyle Whitecross. All rights reserved.
//

#include "dictionary.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

dictionary::dictionary() {
    numWords = 0;
    head = new Node;
}

dictionary::~dictionary() {
    delete head;
}

void dictionary::loadWords(string filepath) {
    string line;
    ifstream file;
    file.open(filepath);
    while (getline(file, line)) {
        addWord(line);
    }
    file.close();
}

void dictionary::addWord(string word) {
    word = setLower(word);
    Node* curr = head;
    int temp;
    for (int i = 0, n = word.size(); i < n; i++) {
        temp = word[i] - 'a';
        curr->isStub = true;
        //create a new node
        if (curr->letters[temp] == nullptr) {
            curr->letters[temp] = new Node;
        }
        curr = curr->letters[temp];
    }
    if (!(curr->isWord)) {
        numWords++;
    }
    curr->isWord = true;
}

bool dictionary::isWord(string word) {
    word = setLower(word);
    Node* curr = head;
    int temp;
    for (int i = 0, n = word.size(); i < n; i++) {
        temp = word[i] - 'a';
        curr = curr->letters[temp];
        if (curr == nullptr)
            return false;
    }
    return curr->isWord;
}

bool dictionary::isStub(string word) {
    word = setLower(word);
    Node* curr = head;
    int temp;
    for (int i = 0, n = word.size(); i < n; i++) {
        temp = word[i] - 'a';
        curr = curr->letters[temp];
        if (curr == nullptr)
            return false;
    }
    return curr->isStub;
}

string dictionary::setLower(string word) {
    for (int i = 0, n = word.size(); i < n; i++) {
        word[i] = tolower(word[i]);
    }
    return word;
}

dictionary::Node::Node() {
    isWord = false;
    isStub = false;
    for (int i = 0; i < 26; i++)
        letters[i] = nullptr;
}

dictionary::Node::~Node() {
    for (int i = 0; i < 26; i++) {
        delete letters[i];
    }
}
