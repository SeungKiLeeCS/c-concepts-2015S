#ifndef ANAGRAMFINDER_H
#define ANAGRAMFINDER_H
#include "Wordlist.h"
#include "Uniquelist.h"
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Anagramfinder
{
private:
    //object of Wordlist class//
    Wordlist input;
    //object of Uniquelist class//
    Uniquelist output;

public:
    //default constructor//
    Anagramfinder();
    //find anagram from the file input and write out to a output file//
    void findAndWrite(char*& fileName, char*& outputFile);
};

#endif // ANAGRAMFINDER_H
