## Exercise 1 ( 55 %)

The Date.h file in the ex1 folder of the zip file is a header file for a Date class similar to the Time
class from parts 3 and 4 of the lecture slides. You are required to implement this class in a Date.cpp
file.

The two constructors should initialise Date objects to ensure that they hold valid dates.

The isLeapYear function should return a Boolean value indicating whether the year held in the
object to which it is applied is a leap year. (A year is normally a leap year if it is a multiple of 4, but
years that are multiples of 100 are leap years only if they are divisible by 400, so 2000 was a leap
year but 2100 will not be.)

The ++ and – operators should adjust the date held in the object by one day (forwards or backwards
as appropriate). As with the Time class the value returned by the prefix versions should be the new
date, whereas the value returned by the postfix versions should be the old value of the date.

You are not required to provide +, -, += or -= operators.

Six comparison operators are required; these should return boolean results. Two of these are to be
written as members of the class; the rest must be written outside the class and use the two member
functions to obtain the result (using properties such as d1<d2 if d2>d1).

The << operator should output the date using the format 02/11/2019, always using 2, 2 and 4 digits,
with leading zeroes where necessary.


The operator string function should return a string object (not a C-string or character array)
holding a string representation of the date using the format 2 nd November 2019. The comments in
the header file indicate how string objects can be built by converting numbers to strings and using
concatenation. (The to_string function is declared in the <string> header file; it is not a member
of any class.)

This operator is invoked whenever a declaration of the form string s(d); is used when d is a Date
object, and also if string(d) is used anywhere in an expression, so to test it you could use a
statement such as cout << string(xmasday);.

The three-argument constructor should output a warning message if any arguments are invalid, and
the << operator will of course produce output; none of the other functions must not perform any
output.

Your submitted class will be tested using a main function that I will write, so you should not submit
a main function to test your code but it is strongly recommended that you write one to test your code.

In order to allow my test program to load successfully, if you fail to complete any of the required
functions you must instead provide dummy versions that return default values (e.g. false for the
comparison operators and an empty string for operator string). Failure to do this will result in
deductions from the marks for the functions that you do complete.

Note that the six comparison operators have lower precedence than << so when testing them you will
need to use code such as cout << (d<=d2), not cout << d<=d 2.

You must not modify the code in the supplied header file, but may if you wish add extra instance
variables to the class, such as arrays holding the number of days in each month or the names of the
months. You are not allowed to add extra functions or friends to the class, but you may write in the
.cpp file extra auxiliary functions that are not part of the class (such as a leap-year checking function
that takes the year as an argument).

## Exercise 2

This exercise involves write a program to analyse the text of a large file. The program will read the
file, generate some information about it, and provide output both to the screen and to a file (whose
name should be provided by the user).

The information to be provided by the program is a bar chart displaying the number of occurrences
in the file of each word from a list of words that will be provided in a second text file.

The program should ask the user for the names of the text file to be analysed, the file containing the
search words and the output file. The program should terminate cleanly with an appropriate error
message if any of the files cannot be opened.

For the purpose of this assignment a “word” should be regarded as being a sequence of non-white-
space characters containing at least one letter. Any punctuation at the beginning or end of a word


should be removed (note that there may be more than once such punctuation symbol); punctuation
symbols in the middle of a word and any digits are to be regarded as part of the word. You must use
the function ispunct, defined in the header file cctype, to check if a character is punctuation. All
input should be converted to lower case, so ”IT”, ”It”, and ”it.” should all be converted to ”it”.

If your program uses the exit function to terminate the program if a file cannot be opened you should
include the header file cstdlib; some compilers recognise exit without the inclusion of this file,
but some do not.

Bar Charts

Bar charts show visually the frequencies of certain items, the widths or heights of the bars being
proportional to the frequencies. Here is a bar chart of the count (hopefully correct!) of some words
from the next paragraph, converted to lower case.
the ********* 9
if ** 2
file 0
for ***** 5

If there are many occurrences of one or more word, the chart will need scaling, using one asterisk for
every n occurrences. If you do this, your output must indicate the scaling and the actual numbers
should be shown alongside the bars, as seen above. To gain maximum marks the scaling factor should
be chosen so that 20 asterisks are used for the word with most occurrences (so for example if the most
frequent word occurs 98 times you would use 1 asterisk for 1 to 5 occurrences, 2 for 6 to 10
occurrences , and 20 asterisks for 96 to 100 occurrences). The word file will contain at least one word
that does not occur in the text; such words should be distinguishable from words that do occur, so a
word that appears in the text must have at least one asterisk in the chart, but words that do not occur
should have no asterisks. The leftmost column of asterisks should be aligned as shown above.

Program Structure

Your program must contain a class called ReadWords and a class for generation of the bar graph
(which should send its output to both cout and the output file), each with a .cpp and a .h file, and a
main function in a separate file called ex2.cpp.

You may, if you wish, use more classes.

The header file for the ReadWords class and a partial implementation are provided in the ex 2 folder
in the zip file; you must use these and must not make any changes to the header file other than the
required changes to the comments. Changes to the provided code in the the cpp file are permitted.

A sample text file and word list will be provided to allow you to test your program; these will be
uploaded to Moodle early in week 6. A separate (unseen) word list will be used to test your submitted
work; this list will not contain more than 1 2 words and it will have a newline character at the end like
the word list file provided. All words in the list will be in lower case so case conversion is not required


It is recommended that you input the list of words into an array of strings before processing the text
file; a simple input loop like that used in lab 3 (but inputting strings instead of numbers) will be
sufficient for this. (If s is a string variable, a statement such as file >> s; inputs the next word
from the file into s, skipping any white space.)

The occurrence counts may be stored in a map if you know how to use one, but an array is perfectly
acceptable for this assignment. You should then enter a loop, calling isNextWord and getNextWord
until the former returns false.
