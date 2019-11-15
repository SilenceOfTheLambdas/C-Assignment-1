/**
 * This includes the main function that is responsible for running the program
**/

#include "ReadWords.h"
#include <iostream>

using namespace std;


int main() {
    cout << "Please enter filename of wordslist: ";
    string userInput;
    cin >> userInput;
    ReadWords file = ReadWords(userInput.c_str());


    cout << file.getNextWord() << endl 
    << file.getNextWord() << endl;
    file.close();
    system("pause");
}