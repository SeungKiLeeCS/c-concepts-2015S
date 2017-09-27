#ifndef WORDLIST_H
#define WORDLIST_H
#include "word.h"

/*max num of words in a doc*/
const int LIST_MAX = 1000;

class WordList
{
    bool sizeDefined = false;
    int wordCount = 0;
    int listSize = 0;

    Word list[LIST_MAX];

public:
    WordList();
    WordList(int size);

    void addWord(Word w);

    Word getListWord(int i);

//    void setSize(int i);
    int getSize();
};

#endif // WORDLIST_H
