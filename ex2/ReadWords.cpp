/**
 * Will display a graph showing the number of words that occur in file A based on a list in   * File B.
 * @author Callum-James Smith
**/
using namespace std;

#include "ReadWords.h"
#include "graph.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <iterator>


char graph::to_lowercase(char c)
{
  if (c >= 'A' && c <= 'Z')
     return c + 32;

  return c;
}

string graph::removePunct(string word) { 
  /**
   * Returns a string of the word with punctuation removed from front and back of word
   * @return - string - word
   * @param word - a string to be manipulated
   */
  string w;
  for (char &c: word) { c = graph::to_lowercase(c); }
  // Loop through the word, if there is punctuation; remove it. Do this until we reach a non-punct char
  for (int i = 0, len = word.size(); i < len; i++) {
    while (ispunct(word[i])) {
      word.erase(i--, 1);
      len = word.size();
      i++;
      if (!ispunct(word[i])) break;
    }
    break;
  }
  for (int i = word.size(), len = word.size(); i --> 0; ) {
    while (ispunct(word[i])) {
      word.erase(i--, 1);
      len = word.size();
      if (!ispunct(word[i])) break;
    }
    break;
  }

  return word;
}

ReadWords::ReadWords(const char *fname)
{   
  wordfile.open(fname);//open file
  if (!wordfile)
  {   cout << "Failed to open " << fname << endl;
  }
  wordfile >> nextword;
  eoffound = false;

  // Insert words into a vector stored in graph.h
  copy(istream_iterator<string>(wordfile),
         istream_iterator<string>(),
         back_inserter(graph::tmpVector));

}

string ReadWords::getNextWord()
{ // should return next word in file, converted to lower case
  // empty string should be returned if next word contains no letters
  
  // uses a one-word lookahead to avoid any problems relating to when if end-of-file
  // is detected due to absence/presence of newline at end of file

  string word = nextword;
  wordfile >> nextword;

  if (wordfile.eof())
     eoffound = true;

  if (word.empty())
     return "";
  
  for (char &c: word) {
    c = graph::to_lowercase(c);
  }
  word = graph::removePunct(word);

  return word;
}

bool ReadWords::isNextWord()
{ return !eoffound;
}

void ReadWords::close()
{
    if (eoffound) wordfile.close();
}
