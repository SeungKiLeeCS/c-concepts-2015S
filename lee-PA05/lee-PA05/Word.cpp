#include "Word.h"

//getter function for word//
char* Word:: getWord()
{
    return word;
}

//setter function for word//
void Word:: setWord(char* readIn)
{
    strcpy(word, readIn);
}

//default constructor.//
Word::Word()
{

}
//constructor with parameter char*//
Word::Word(char* readIn)
{
    strcpy(word, readIn);
}

//Function for sorting through the words to alphabetically organize letters//
void Word::sort()
{
    char temp;
    int i;
    bool sorted = false;

    while(!sorted)
    {
        sorted = true;
        for(i=0; i<(strlen(word))-1; i++) // have j look through the letter
        {
            if(word[i] > word[i+1])
            {
                temp = word[i];
                word[i] = word[i+1];
                word[i+1] = temp;
                sorted = false;
            }
        }
    }
}
