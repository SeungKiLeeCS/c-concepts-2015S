#include "Uniquelist.h"

//default constructor//
Uniquelist::Uniquelist()
{

}

//function to add words to uniquelist//
void Uniquelist::addWord(char* uniqueWord)
{
    uniquelist[uniqueCount].setWord(uniqueWord);
    uniqueCount++;
}

// returning unique word at each index location
Word Uniquelist::getWord(int i)
{
    return uniquelist[i];
}

// returning the value of uniqueCount for file output
int Uniquelist::getCount()
{
    return uniqueCount;
}

// file write out function//
void Uniquelist::makeFile(char *fileName)
{
    ofstream output;
    output.open(fileName);
    output << "Total number of unique character sets are: " << uniqueCount << endl;

    for(int i=0; i<uniqueCount; i++)
    {
        output << uniquelist[i].getWord() <<endl;
    }
    output.close();
}
