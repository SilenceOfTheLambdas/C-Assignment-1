#include "graph.h"
#include "ReadWords.h"
#include <map>
#include <iostream>
#include <vector>
#include<string.h>

using namespace std;

vector<string> txtFileWords; // A temp vector that will be user to store the txt file
vector<string> wordListWords; // Stores the word list
vector<string> graph::tmpVector;

void graph::storeWordList() {
    // Make a copy vector of the first words in the 1st file
    for (size_t i = 0; i < tmpVector.size(); i++) {
        cout << tmpVector[i] << endl;
        wordListWords.push_back(removePunct(tmpVector[i]));
    }
}

void graph::storeTxtFile() {
    // Make a copy vector of the first words in the 1st file
    for (size_t i = 0; i < tmpVector.size(); i++) {
        cout << tmpVector[i] << endl;
        txtFileWords.push_back(removePunct(tmpVector[i]));
    }
}

void graph::calcOccurrence(ReadWords& wordList, ReadWords& txtFile) {
    // // Testing
    // for (string word: wordListWords) {
    //     cout << word << endl;
    // }
    // for (string word: txtFileWords) {
    //     cout << word << endl;
    // }

    cout << "Testing...............................................\n";

    map<string, int> occurrence;
    int occ = 0;
    for (size_t i = 0; i != wordListWords.size(); i++) {
        for (size_t x = 0; x != txtFileWords.size(); x++) {
            if (wordListWords[i] == txtFileWords[x]) {
                occurrence[wordListWords[i]] = occ+=1;
            }
        }
        occ = 0;
    }
    
    for(auto elem : occurrence)
    {
        cout << elem.first << " " << elem.second << "\n";
    }
}