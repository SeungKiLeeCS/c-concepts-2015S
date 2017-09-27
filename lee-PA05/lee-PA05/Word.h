#ifndef WORD_H
#define WORD_H
#include <cstring>
#include <iostream>
using namespace std;

class Word
{
private:
    //null terminated cstring list, maxed at 25 chars.//
    char word[26];

public:
    //setter//
    void setWord(char* readIn);
    //getter//
    char* getWord();
    //function to sort through the words in alphabetical order//
    void sort();
    //default constructor//
    Word();
    //constructor with char* as parameter//
    Word(char* readIn);
};

#endif // WORD_H

