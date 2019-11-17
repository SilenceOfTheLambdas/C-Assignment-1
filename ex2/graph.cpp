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
    for (int i = 0; i < tmpVector.size(); i++) {
        wordListWords.push_back(removePunct(tmpVector[i]));
    }
}

void graph::storeTxtFile() {
    // Make a copy vector of the first words in the 1st file
    for (int i = 0; i < tmpVector.size(); i++) {
        txtFileWords.push_back(removePunct(tmpVector[i]));
    }
}

void graph::calcOccurrence(ReadWords& wordList, ReadWords& txtFile) {

    for (string word: wordListWords) {
        cout << word << endl;
    }
    for (string word: txtFileWords) {
        cout << word << endl;
    }
    // map<string, int> occurrence;
    // int occ = 0;
    // for (int i  = 1; i <= 10; i++) {
    //     string word = wordList.getNextWord();
    //     string compWord = txtFile.getNextWord();
    //     bool isOccurrence = true;
    //     if (word == compWord) {
    //         occurrence[word] = occ+=1;
    //     } else occ = 0;
    // }
    
    // for(auto elem : occurrence)
    // {
    //     cout << elem.first << " " << elem.second << "\n";
    // }
}