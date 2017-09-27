#ifndef WORDLIST_H
#define WORDLIST_H
#include "Word.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

class Wordlist
{
private:
    //array of Word object//
    Word list[1000];
    //length for read in from the file//
    int length = 0;

public:
    //file input function//
    void readFile(char* fileName);
    //returning the address of the word//
    Word* getWord(int i);
    //return the list's length//
    int getLen();
    //setter for the list's length//
    void setLen(int fileLength);
    //default constructor//
    Wordlist();
};

#endif // WORDLIST_H
