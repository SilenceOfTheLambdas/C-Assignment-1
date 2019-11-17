#ifndef GRAPH_H
#define GRAPH_H

#include "ReadWords.h"
#include <map>
#include <vector>

using namespace std;

class graph {

    public:
        static char to_lowercase(char c); // Converts each character to lowercase in a word
        static string removePunct(string word); // Removes all punctuation from the front and back of a word
        static vector<string> tmpVector; // Holds a temporary word list
        void drawGraph(const char* filename, ReadWords& wordList, ReadWords& txtFile); // Calculates the occurrence of a word
        void storeWordList(); // Store the elements in one file into a vector
        void storeTxtFile(); // Store the elemets in another file to a vector
        static map<string, int> occurrence; // A map that stores the word that occurred, and it's number of occurrences
};

#endif