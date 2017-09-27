#ifndef WORD
#define WORD
#include <string>

using namespace std;

const int WORD_MAX = 26;

class Word {

    char word[WORD_MAX];
    char ano[WORD_MAX];

    int length;
    //LEE:change the swap function to private function, as it is not used in any other class.//
    void swap(char* arr, int i);

public:
    int getLength();

    void setWord(char w[WORD_MAX]);

    char* getWord();

    char* getAno();

    Word();

    Word(char w[WORD_MAX]);

};

#endif // WORD

