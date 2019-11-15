
#ifndef BARCHART_H
#define BARCHART_H

using namespace std;

#include <string>
#include <fstream>
#include <map>
#include "ReadWords.h"

class barChart {
    public:
        void calcOccurrences(ReadWords &wordListFile, ReadWords &txtFile);

    private:
        map<string, int> occurrence;
};


#endif