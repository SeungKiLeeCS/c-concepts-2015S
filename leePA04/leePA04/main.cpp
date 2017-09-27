#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//void function to sort through each character string and have it alphabetically organized//
//Check through all letters from the array and check them against one another.//
void sort(char **data, int length)
{
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i = 0; i <length; i++) // iterate through the word
        {
            for(int j =0; j < strlen(data[i])-1; j++) // have j look through the letter
            {
                if(data[i][j] > data[i][j+1])
                {
                    swap(data[i][j],data[i][j+1]); // use swap function to change letters' places if needed
                    sorted = false;
                }
            }
        }
    }
}
//void function//
//swaps characters in alphabetical order//
void swap(char &a, char &b)
{
    char temp = b;
    b = a;
    a = temp;
}


//void function//
//go through nested forloop to see if the alphabetically organized charcter set is equal to the other//
//increase the finalLen in order to count how many unique character sets are there//
//in the end, prints how many unique character sets one has, and list the unique characters sets//
//in alphatical order//

void compare(char** data, int length)
{
    char** word = new char*[length];//declare
    int cmpHold, i, j, finalLen=0;//have hold values to hold strcmp integer value,
    // and have the finalLen declared to use to store the charcter sets to new array.
        for(i=0;i<length;i++)
        {
            bool add = true;
            for(j=0; j<finalLen;j++)
            {
                cmpHold=strcmp(data[i],data[j]);
                if(cmpHold == 0 && i != j)
                {
                    add = false;
                }
            }
            if(add) // only when the value equals that of add after the loop, add the word to the array.
            {
                word[finalLen] = data[i];
                finalLen++;
            }
        }

    cout<<"Number of Unique character sets from this file is: "<<finalLen<<"."<<endl;
    // print number of unique character sets

        for(int i=0;i<finalLen;i++) // list the unique character sets.
        {
            cout<<word[i]<<endl;
        }
}

void printUnique()
{
    //cout<<uniqueCount<<endl;
    //for(int i=0; i< uniqueCount;i++)
    //{
    //  cout<<print[i]<<endl;
    //}
}

int main()
{
    char** data = nullptr;
    int length = 0;
    char tempHold[26];
    char fileName[26];
    char word[26];
    cout<<"Please choose a file to read in from."<<endl;
    cout<<"Make sure this is the correct and full name of the file."<<endl;

    cin>>fileName;

    ifstream fin(fileName);

    if(!fin.is_open())
    {
        cout<<"File does not exist.";
    }

    else
    {
        fin>>length; // take the first value for length of the array of array of characters.

        char** data = new char*[length]; // dynamically allocate space to place the values read in.
        for(int i=0; i<length; i++)
        {
            data[i] = new char[26];
            fin>>data[i]; //readin values and store it.
        }
        sort(data, length);
        compare(data,length);
    }
    return 0;
}
