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
        wordListWords.push_back(removePunct(tmpVector[i]));
    }
}

void graph::storeTxtFile() {
    // Make a copy vector of the words from the 2nd file input by the user
    for (size_t i = 0; i < tmpVector.size(); i++) {
        txtFileWords.push_back(removePunct(tmpVector[i]));
    }
}

void graph::calcOccurrence(ReadWords& wordList, ReadWords& txtFile) {

    map<string, int> occurrence;
    int occ = 0;
    for (size_t i = 0; i != wordListWords.size(); i++) {
        for (size_t x = 0; x != txtFileWords.size(); x++) {
            if (wordListWords[i] == txtFileWords[x]) {
                occurrence[wordListWords[i]] = occ++;
            }
        }
        occ = 0;
    }
    
    for(auto elem : occurrence)
    {
        cout << elem.first << " " << elem.second << "\n";
    }
}