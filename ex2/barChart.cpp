#include "barChart.h"
#include "ReadWords.h"
#include <map>
#include <iostream>

using namespace std;

void barChart::calcOccurrences(ReadWords &wordListfile, ReadWords &txtFile) {

  map<string, int> occurrence;
  bool isOccurrence;
  while (wordListfile.isNextWord()) {
    int occ = wordListfile.getNextWord().compare(txtFile.getNextWord()) ? occ+=1 : isOccurrence = false;
    if (isOccurrence) occurrence[wordListfile.getNextWord()] = occ;
  }

  for(auto elem : occurrence)
  {
    std::cout << elem.first << " " << elem.second << "\n";
  }
}