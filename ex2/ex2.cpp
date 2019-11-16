/**
 * This includes the main function that is responsible for running the program
**/
#include "ReadWords.h"
#include "graph.h"
#include <iostream>
#include <map>

using namespace std;


auto main() -> int {
    cout << "Please enter filename of wordslist: ";
    string userInput;
    cin >> userInput;
    ReadWords file = ReadWords(userInput.c_str());
    
    cout << "Now please enter text filename: ";
    cin >> userInput;
    ReadWords txtFile = ReadWords(userInput.c_str());

    graph g;
    g.calcOccurrence(file, txtFile);
    system("pause");
}