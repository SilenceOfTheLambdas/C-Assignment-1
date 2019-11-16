#include "graph.h"
#include "ReadWords.h"
#include <map>
#include <iostream>

using namespace std;


void graph::calcOccurrence(ReadWords& wordList, ReadWords& txtFile) {
    map<string, int> occurrence;
    cout << "OI CUNT";
    bool isOccurrence;
    while (wordList.isNextWord()) {
        int occ = wordList.getNextWord().compare(txtFile.getNextWord()) ? occ+=1 : isOccurrence = false;
        if (isOccurrence) occurrence[wordList.getNextWord()] = occ;
    }

    for(auto elem : occurrence)
    {
        cout << elem.first << " " << elem.second << "\n";
    }
}
