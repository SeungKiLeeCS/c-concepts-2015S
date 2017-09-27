#include "Anagramfinder.h"
//default constructor//
Anagramfinder::Anagramfinder()
{

}

//function for finding anagram and writing out to a file
void Anagramfinder:: findAndWrite(char*& fileName, char*& outputFile)
{
    //
    input.readFile(fileName);
    //set the length of words
    int length = input.getLen();
    //sort letters for each word
    for(int i=0; i<length; i++)
    {
        input.getWord(i) -> sort();
    }
    //declaration of variables used for creating unique list//
    //have the uniqueNum declared to use to store the character sets to new array.
    int cmpHold;
    int uniqueNum = 0;
    bool addCheck;
    //only when the value equals that of add after the loop, add the word to the array.
    for(int i=0;i<length;i++)
    {
        for(int j=0;j<uniqueNum;j++)
        {
            cmpHold=strcmp(input.getWord(i)->getWord(), input.getWord(j)->getWord());
            if(cmpHold == 0)
            {
                addCheck = false;
            }
        }
        if(addCheck)
        {
            output.addWord(input.getWord(i)->getWord());
            uniqueNum++;
        }
        //write out to the file from commandline//
        output.makeFile(outputFile);
    }
}
