#include "graph.h"
#include "ReadWords.h"
#include <map>
#include <iostream>
#include <vector>
#include<string.h>
#include <iomanip>

using namespace std;

vector<string> txtFileWords; // A temp vector that will be user to store the txt file
vector<string> wordListWords; // Stores the word list
vector<string> graph::tmpVector; // this currently holds the value of the word file, obtained from ReadWords.cpp

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

void graph::drawGraph(const char* filename, ReadWords& wordList, ReadWords& txtFile) {
    ofstream outputFile(filename, ios::out);
    map<string, int> occurrence;
    // Calculates the occurrence of words in one vector, to another vector
    int occ = 0;
    for (size_t i = 0; i != wordListWords.size(); i++) {
        for (size_t x = 0; x != txtFileWords.size(); x++) {
            if (wordListWords[i] == txtFileWords[x]) {
                occurrence[wordListWords[i]] = occ++;
            }
        }
        occ = 0;
    }
    int biggestWord = 0; // The size of the biggest word
    int biggestOcc = 0; // The larges number of occurrences
    int starsNo = 0; // The number of stars to show
    // Display the graph
    for (auto elem: occurrence) {
        if (elem.first.size() > biggestWord) biggestWord = elem.first.size();
        if (elem.second > biggestOcc) biggestOcc = elem.second;
    }
    cout << string(((biggestOcc+biggestWord+2)/2), '=') << "Results" << string(((biggestOcc+biggestWord+2)/2), '=') << endl;
    outputFile << string(((biggestOcc+biggestWord+2)/2), '=') << "Results" << string(((biggestOcc+biggestWord+2)/2), '=') << endl;
    cout << "Key: * = " << 1 << " occurrence" << endl;
    for (auto elem: occurrence) {
        starsNo = elem.second;
        cout << setw(biggestWord+2) << left << elem.first << '|' << setw(starsNo+2) << string(starsNo, '*') << setw(5) << left << elem.second << endl;
        cout << string((biggestWord+2), '-') << endl;
        outputFile << setw(biggestWord+2) << left << elem.first << '|' << setw(starsNo+2) << string(starsNo, '*') << setw(5) << left << elem.second << endl;
        outputFile << string((biggestWord+2), '-') << endl;
    }
}