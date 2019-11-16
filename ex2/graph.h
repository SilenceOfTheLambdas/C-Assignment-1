#ifndef GRAPH_H
#define GRAPH_H

#include "ReadWords.h"
#include <map>

using namespace std;

class graph {

    public:
        void calcOccurrence(ReadWords& wordList, ReadWords& txtFile);
    private:
        static map<string, int> occurrence;
};

#endif