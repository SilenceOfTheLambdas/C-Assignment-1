#ifndef GRAPH_H
#define GRAPH_H

#include "ReadWords.h"
#include <map>
#include <vector>

using namespace std;

class graph {

    public:
        static char to_lowercase(char c);
        static string removePunct(string word);
        static vector<string> tmpVector;
        void calcOccurrence(ReadWords& wordList, ReadWords& txtFile);
        void storeWordList();
        void storeTxtFile();
        static map<string, int> occurrence;
};

#endif