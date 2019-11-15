/**
 * This includes the main function that is responsible for running the program
**/

#include "barChart.h"
#include "ReadWords.h"
#include <iostream>

using namespace std;


int main() {
    cout << "Please enter filename of wordslist: ";
    string userInput;
    cin >> userInput;
    ReadWords file = ReadWords(userInput.c_str());
    
    cout << "Now please enter text filename: ";
    cin >> userInput;
    ReadWords txtFile = ReadWords(userInput.c_str());

    barChart chart;
    chart.calcOccurrences(file, txtFile);

    system("pause");
}