#include <string>
#include "word.h"
#include <cstring>


/*getLength will take in no parameters and return the length of the word (not including the null terminator*/
int Word::getLength(){
    return strlen(word);
}

/*the set word method will take in a character array (inputW) and modify the exusting
character array (word) to become equal to the input array*/
void Word::setWord(char inputW[WORD_MAX]){
    strcpy(word, inputW);
}

/*this function is a noble function, it takes no parameters which might muttle its
true purpose of existence. the valiant getWord will simply serve its master, word
instance, and return the letters occupying its character array, then awaiting to its
post quietly waiting to be summoned again, only to serve*/
char* Word::getWord(){
    return word;
}

/*swap will swap the locations of two characters in a char array.  this function takes in
an array and the position of the swap, it then swaps the location of the character at
location i with the character at location i+1*/
void Word::swap(char* arr, int i){

    char temp = arr[i];
    arr[i] = arr[i+1];
    arr[i+1] = temp;
}


/*the getAno function will not take in any parameters but it will return an alphabetized
character array of the word instance it is called for*/
char* Word::getAno(){

    /*this will set the anagram to the original word*/
    strcpy(ano, word);

    bool sorted = true;

    /*this will modify the anagram array by sorting the letters by value until it is alphabetical*/
    while(sorted){
        /*this will be looped through until the word is organized alphabetically and the
        boolean == false*/
        sorted = false;
        for(int i = 0; i < strlen(ano) -1; i++){
            if(ano[i] > ano[i+1]){
                swap(ano, i);
                sorted = true;
            }
        }
    }
    return ano;
}

/*this takes in a character array and copies that character array. it returns nothing*/
Word::Word(char w[]){
    strcpy(word, w);
}

/*this is the default homie*/
Word::Word(){
    /*default homes*/
}

