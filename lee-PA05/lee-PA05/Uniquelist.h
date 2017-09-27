#ifndef UNIQUELIST_H
#define UNIQUELIST_H
#include "Word.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

class Uniquelist
{
private:
    //array of Word object for unique words//
    Word uniquelist[1000];
    //int for counting how many words to put in the new array//
    int uniqueCount = 0;

public:
    //default constructor
    Uniquelist();
    //
    void addWord(char* uniqueWord);
    // Word class object for returning unique word//
    Word getWord(int i);
    //int value to get the uniqueCount value//
    int getCount();
    //file output function//
    void makeFile(char* fileName);
};

#endif // UNIQUELIST_H
