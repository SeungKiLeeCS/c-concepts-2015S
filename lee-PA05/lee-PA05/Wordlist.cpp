#include "Wordlist.h"

//default constructor//
Wordlist::Wordlist()
{

}

//read in from a file//
void Wordlist:: readFile(char* fileName)
{
    int fileLength = 0;
    char readHold[26];

    ifstream fin(fileName);

    if(!fin)
    {
        cout<<"File does not exist."<<endl;
        cout<<"Program will terminate."<<endl;
        return;
    }

    else
    {
        fin>>fileLength;

        for(int i=0; i<fileLength; i++)
        {
            fin >> readHold; //readin values and store it.
            list[i].setWord(readHold);
        }
    }
    //close file//
    fin.close();
    //set the length of the file//
    setLen(fileLength);
}
//returning address of the word at given index location
Word* Wordlist::getWord(int i)
{
    return &list[i];
}
//return the length of the array for later use//
int Wordlist:: getLen()
{
    return length;
}
//set the length of the array for later use//
void Wordlist:: setLen(int fileLength)
{
    length = fileLength;
}
