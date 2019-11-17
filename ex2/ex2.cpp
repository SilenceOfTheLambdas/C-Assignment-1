/**
 * This includes the main function that is responsible for running the program
**/
#include "ReadWords.h"
#include "graph.h"
#include <iostream>
#include <map>

using namespace std;


auto main() -> int {
    graph g; // Create a new graph object
    cout << "Please enter filename of wordslist: ";
    string userInput;
    cin >> userInput;
    // Read the words, and then store the words into a vector
    ReadWords file = ReadWords(userInput.c_str());
    g.storeWordList();
    
    cout << "Now please enter text filename: ";
    cin >> userInput;
    // Read the words, then store it into a vector
    ReadWords txtFile = ReadWords(userInput.c_str());
    g.storeTxtFile();

    cout << "Please enter the name for the ouput file: ";
    string outputFile;
    cin >> outputFile;
    g.drawGraph(outputFile.c_str(), file, txtFile);
    system("pause");
}