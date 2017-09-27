#ifndef ANOFIND_H
#define ANOFIND_H
#include "wordlist.h"
#include <fstream>

class AnoFind
{
    int listSize = 0;

    WordList anoList;

    WordList originalList;

    int argc;
    char* argv;


public:
    AnoFind();

    AnoFind(int argc, char* argv[]);

    void outputAno(char* argv[]);

    void makeAnoList();

    void addOrigList(char* argv[]);
};

#endif // ANOFIND_H
