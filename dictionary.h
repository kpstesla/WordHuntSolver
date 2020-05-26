//
//  dictionary.hpp
//  WordHuntAssistant
//
//  Created by Kyle Whitecross on 5/24/20.
//  Copyright © 2020 Kyle Whitecross. All rights reserved.
//

#ifndef dictionary_h
#define dictionary_h

#include <string>
using std::string;

class dictionary {
public:
    dictionary();
    ~dictionary();
    void loadWords(string filepath); // loads words from dictionary
    bool isWord(string word); // returns true if the word is in the dict
    bool isStub(string word); // returns true if the string is part of a longer word
    size_t size() {return numWords;}
private:
    struct Node {
        Node();
        ~Node();
        bool isWord;
        bool isStub;
        Node* letters[26];
    };
    void addWord(string word); //adds a word into the trie
    Node* head;
    size_t numWords;
    string setLower(string word); // sets all the chars in a string to lowercase
};






#endif /* dictionary_h */
