#include "Package.h"

void Package:: setTrackNum() // Random Number generator of 9 digits integers.
{
    trackNum = rand() % 999999999 + 100000000;
}

void Package:: setWeightFee() // Function which receives input for weight then use the information from each child class
//constructor to calculate the weightFee for the particular shipment
{
    cout<<"Please enter in the weight."<<endl;
    cin>>weight;

    //error check for non-number input and negative or zero input
    while(cin.fail()||weight <= 0.0)
    {
          cin.clear(); //stop the program from inputing invalid value
          string nonNum;
          cin>>nonNum; //stop the infinite error message
          cout<<"Invalid input. The input must be a number larger than 0. Please try again."<<endl;
          cin>>weight;//let the user input the number again.
    }

    weightFee = weight * weightRate; // calculate weight fee
}
