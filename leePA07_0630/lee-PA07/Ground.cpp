#include "Ground.h"
using namespace std;

//constructor which will initialze the per-ounce charge
Ground::Ground()
{
    weightRate = 0.20;
}

// Initialization of static variable for counter
int Ground:: gndCount = 0;

double Ground:: gndList[ARRAY_SIZE][2]= {{0}};

//void function that calls function to calculate weight fee according to user input
//and store the values into respective column in the array
void Ground:: calcWeightFee()
{
    cout<<"You have chosen Ground Shipping."<<endl;
    cout<<endl;

    setWeightFee();

    gndList[gndCount][0] = weight;
    gndList[gndCount][1] = weightFee;

    cout<<"weight in ounces : "<< gndList[gndCount][0]<<" Ounces."<<endl;
    cout<<"Weight Charge : $ "<< gndList[gndCount][1]<<endl;
    cout<<endl; // empty line for readability

    gndCount++;
    /* return the value using getter function so the value will be updated even after the function terminates */

    cout<<"Number of Ground Packages thus far : "<<gndCount<<endl; //check function.
}

//update and getter function for gndCount
int Ground:: updateGndCount()
{

    return gndCount;
}

// void function calculating subtotal of weight charge
void Ground:: groundSubTotWeight()
{
// iterate the loop until it goes through everything in the array
    for(int i; i<gndCount; i++)
    {
        gndSubTotWei += gndList[i][1]; // add each element in the column
    }
    cout<<"The Subtotal for Ground shipment per-ounce charge is $ "<<gndSubTotWei<<endl;

}
// getter function for subtotal of weight charge
double Ground:: getGndSubTotWeight()
{
    return gndSubTotWei;
}

//void function used to bubble sort through the array of ground shipments and rearrange them
//according to their weight
void Ground::sortGround()
{
    bool sorted = true;

    while(sorted)
    {
        sorted = false;
        for(int i = 0; i < gndCount -1; i++)
        {
            if(gndList[i][0] < gndList[i+1][0])
            {
                //compare weight column of tdyList to the one after it, if the latter is greater, swap the order.
                int tempGndWeight = gndList[i][0];
                gndList[i][0] = gndList[i+1][0];
                gndList[i+1][0] = tempGndWeight;
                //Alter the weight fee column parallel to the weight column.
                int tempGndWeightFee = gndList[i][1];
                gndList[i][1] = gndList[i+1][1];
                gndList[i+1][1] = tempGndWeightFee;

                sorted = true;
            }
        }
    }
    printGround();
}

//void function that will print ground list.
void Ground:: printGround()
{
    cout<<endl;// blank space for readability.
    for(int i=0;i<gndCount;i++)
    {
        cout<<"Weight:"<<gndList[i][0]<<" Ounces"<<"|"<<"Weight Fee: $ "<<gndList[i][1]<<"|"<<endl;
    }
}

//void function that will calcuate total flat fee for ground shipment.
void Ground:: setGndFlat()
{
    gndFlatFee = GND_FLAT * gndCount; //global constant multiplied by count of ground shipments
}

//double function returning net flat fee of ground shipment.
double Ground:: getGndFlat()
{
    return gndFlatFee;
}
