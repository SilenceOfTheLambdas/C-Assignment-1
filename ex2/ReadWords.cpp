/**
 * Will display a graph showing the number of words that occur in file A based on a list in   * File B.
 * @author Callum-James Smith
**/
using namespace std;

#include "ReadWords.h"
#include <cctype>
#include <cstdlib>
#include <iostream>

char to_lowercase(char c)
{
  if (c >= 'A' && c <= 'Z')
     return c + 32;

  return c;
}

string removePunct(string word)
{ // should return a copy of the word with all leading and trailing punctuation      
  // removed
  // punctuation elsewhere in the word should not be removed
  // note that a word could have more than one leading/trailing punctuation symbols
  // you need to write this

  return word;
}

ReadWords::ReadWords(const char *fname)
{   wordfile.open(fname);//open file
    if (!wordfile)
    {   cout << "Failed to open " << fname << endl;
        exit(1);
    }
    wordfile >> nextword;
    eoffound = false;
}

string ReadWords::getNextWord()
{ // should return next word in file, converted to lower case
  // empty string should be returned if next word contains no letters
  
  // uses a one-word lookahead to avoid any problems relating to when if end-of-file
  // is detected due to absence/presence of newline at end of file

  // incomplete

  string str;
  string word = nextword;
  wordfile >> nextword;

  if (wordfile.eof())
     eoffound = true;

  if (word.empty())
     return "";
  
  for (char &c: str) {
    c = to_lowercase(c);
  }
  word = str;
  word = removePunct(str);

  return word;
}

bool ReadWords::isNextWord()
{ return !eoffound;
}

void ReadWords::close()
{ // you must write this
    if (eoffound) ReadWords::wordfile.close();
}
