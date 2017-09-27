#include "wordlist.h"

/*getListWord will take in an integer representing the position
of the Word Object in a Word array and return that Word*/
Word WordList::getListWord(int i){
     return list[i].getWord();
}

/*addWord will take in a word object w and add it into the
WordList object's array of Words at the last position, nothing is
returned in this function*/
void WordList::addWord(Word w){

        list[wordCount].setWord(w.getWord());
        /*this incriments the amount of known words in the array of Words*/
        wordCount++;

        /*if the size of an array is not defined, then the size will
         * incriment every time there is a new word added*/
        if(!sizeDefined)
            listSize ++;
}

//LEE: removing setSize function on request. Due to the conditional on undefined size, the list will increment automatically//

// /*setSize will declare the size of a WordList when it is not declared during
//initialization*/
//void WordList::setSize(int i){
//    listSize = i;
//    sizeDefined = true;
//}

 /*WordList(int size) will take in an integer and set the size of the WordList
array to become equal to that size, nothing is returned*/
WordList::WordList(int size){

    /*the size of a WordList is declared here, preventing the size from
    incrimenting every time there is an additional Word added*/
    listSize = size;
    sizeDefined = true;
}

/*getSize will take in no parameters and return the size of the array of Words
within the WordList class*/
int WordList::getSize(){
    //return wordCount;
    return listSize;
}

/*this does nothing. it is the default*/
WordList::WordList(){
    /*nothing to see here, move along*/
}


