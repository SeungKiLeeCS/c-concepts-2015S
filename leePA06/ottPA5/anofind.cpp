#include "anofind.h"
#include <cstring>
#include <iostream>

using namespace std;

/*default constructor. the manilla of folder possibilities*/
AnoFind::AnoFind(){
/*nothing*/
}


/*this will take in a the comand line character arrays and then
output the values of the anogram list into the output document*/
void AnoFind::outputAno(char* argv[]){
    /*displays each element of the unique anogram list*/
    bool notOpen = true;

    ofstream fout;

    /*if the document does not open then this will loop*/
    while(notOpen){

        /*this will open the output document*/
        fout.open(argv[2]);

        if(fout.is_open()){
            notOpen = false;
        } else
            cout<<"document not opening"<<endl;

    }

    /*writing into the document*/
    fout<<"There were "<<anoList.getSize()<<" Unique Character Sets"<<endl;

    for(int i = 0; i < anoList.getSize(); i++){
        fout<<i+1<<": "<<anoList.getListWord(i).getWord()<<endl;
    }

    /*this will close the output document*/
    fout.close();
}


/*this will take in the command line character arrays and create an original list from the input
document.  this function will return nothing*/
void AnoFind::addOrigList(char* argv[]){

    bool notReading = true;
    ifstream fin(argv[1]);

    while(notReading){

        /*checking if the document is open or not*/
        if(fin.is_open())
            notReading = false;
        else
            cout<<"Document not opening"<<endl;

        /*the input integer which will be taken from the first digit in a document*/
        int x = 0;
        fin>>x;

        //LEE: taking out the setSize function on request. Trying to find a solution on how to efficiently replace
        // the range. For time being, have the range = LIST_MAX for safe bet.

//        if(x > 0)
//            originalList.setSize(x);
//        else
//            notReading = true;
    }
    /*this adds the individual parts of the text document into the originalList WordList*/
    for(int i = 0; i < LIST_MAX; i++){

        char arrIn[WORD_MAX];
        fin>>arrIn;

        Word w;
        w.setWord(arrIn);
        originalList.addWord(w);
    }

    /*this closes the document :) */
    fin.close();
}

/*this wil not take in arguments. it will scan through the original word list and identify
words which are not currently contained in the anogram list (which begins blank), adding words
each time it doesn't find a duplicate*/
void AnoFind::makeAnoList(){
    /*takes in a wordlist called list and then modifies the existing anogram wordlist
    to contain the unique word objects*/

    for(int i = 0; i < originalList.getSize(); i++){
        bool addToList = true;

        /*determining if originalList position i is contained within the anogram list*/
        for(int j = 0; j < anoList.getSize(); j++){
            if(strcmp((originalList.getListWord(i)).getAno(), (anoList.getListWord(j)).getAno()))
                addToList = false;
        }
        /*adds the words not in anoList into anoList*/
        if(addToList)
            anoList.addWord(originalList.getListWord(i));
    }
}

/*this does the same thing as the method above, but it's mainly for the case that
the user does not input a file name when making an AnoFind*/
AnoFind::AnoFind(int argc, char* argv[]){
    /*takes in a wordlist called list and then modifies the existing anogram wordlist
    to contain the unique word objects*/

    addOrigList(argv);

    for(int i = 0; i < originalList.getSize(); i++){
        bool addToList = true;

        /*determining if originalList position i is contained within anoList*/
        for(int j = 0; j < anoList.getSize(); j++){
            if(i != j && strcmp(originalList.getListWord(i).getAno(), anoList.getListWord(j).getAno()) == 0){
                addToList = false;
            }
        }
        if(addToList){
            anoList.addWord(originalList.getListWord(i));
        }
    }

    listSize = anoList.getSize();

    //cout<<anoList.getSize()<<endl;
    outputAno(argv);

    //for(int i = 0; i < anoList.getSize(); i++){

    //}

}
