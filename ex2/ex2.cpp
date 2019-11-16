/**
 * This includes the main function that is responsible for running the program
**/
#include "ReadWords.h"
#include <iostream>
#include <map>

using namespace std;


int main() {
    cout << "Please enter filename of wordslist: ";
    string userInput;
    cin >> userInput;
    ReadWords file = ReadWords(userInput.c_str());
    
    cout << "Now please enter text filename: ";
    cin >> userInput;
    ReadWords txtFile = ReadWords(userInput.c_str());

    map<string, int> occurrence;
    bool isOccurrence;
    while (file.isNextWord()) {
        int occ = file.getNextWord().compare(txtFile.getNextWord()) ? occ+=1 : isOccurrence = false;
        if (isOccurrence) occurrence[file.getNextWord()] = occ;
    }

    for(auto elem : occurrence)
    {
        std::cout << elem.first << " " << elem.second << "\n";
    }

    system("pause");
}