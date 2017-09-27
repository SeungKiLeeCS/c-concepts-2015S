#include "Twoday.h"

//constructor that will initialize the per-ounce rate
Twoday::Twoday()
{
    weightRate = 0.30;
}

// Initialization of static variables
int Twoday:: tdyCount = 0;
double Twoday:: tdyList[ARRAY_SIZE][3] = {{0}};
int Twoday:: tdyTN[ARRAY_SIZE] = {0};

//
void Twoday:: checkTrackService()
{
    cout<<"You have chosen two day shipping. Has the customer chosen tracking number service?"<<endl;
    cout<<"[y/n]"<<endl;
    cin>> track;

    while (track != "y" && track != "n") //input error check
    {
        cout<<"The input must be either lowercase y or n. Please choose again."<<endl;
        cin.clear();
        cin>>track;
    }

    if (track == "y")
    {
        serviceFee = 2.23;
        cout<<"The addtional fee of $2.23 has been added to the final bill."<<endl;

        setTrackNum(); // tracking number generator

        cout<<"A tracking number has been created."<<endl;
        cout<<"The Tracking Number is: "<< trackNum <<endl;

        // trackNum sign to array!
        tdyTN[tdyCount] = trackNum;
    }
    else
    {
        serviceFee = 0.0;
        cout<<"No Tracking number has been created."<<endl;
        cout<<"No additional service fee is applied for this customer."<<endl;
        cout<<"The Tracking Number will appear as 0 in final display for this custormer."<<endl;
        tdyTN[tdyCount] = 0;
    }
//    cout<<"serviceFee = "<<serviceFee<<endl;

    setWeightFee();

//    cout<<"The weight fee is $ "<<weightFee<<endl;

    //assgin the weight, weightFee, serviceFee to respective position in array, and trackNum in parellel array.
    tdyList[tdyCount][0] = weight;
    tdyList[tdyCount][1] = weightFee;
    tdyList[tdyCount][2] = serviceFee;

    //print the instance results.
    cout<<"Weight in ounces : "<< tdyList[tdyCount][0]<<" ounces"<<endl;
    cout<<"Weight Charge : $ "<< tdyList[tdyCount][1]<<endl;
    cout<<"Service Charge : $ "<< tdyList[tdyCount][2]<<endl;
    if(tdyTN[tdyCount] == 0)
    {
        cout<<"Tracking Number : 000000000."<<endl;
    }
    else
    {
         cout<<"Tracking Number : "<<tdyTN[tdyCount]<<endl;
    }
    cout<<endl; // empty line for readability
    tdyCount++; // increment the counter of Twoday Shipment.
    cout<<"Number of Twoday Packages thus far : "<<tdyCount<<endl; //check function.

}

int Twoday:: updateTdyCount() //int function, a getter function for the count of twoday shipments
{
    return tdyCount;
}

void Twoday:: printTwoday() //void function printing the twoday shipment list.
{
    for(int i=0; i<tdyCount; i++)
    {
        if(tdyTN[i] != 0) // if tracking number is assigned, print out the array with tracking number
        {
            cout<<"Tracking Number: "<<tdyTN[i]<<" | ";
            cout<<"Weight: "<<tdyList[i][0]<<" Ounces"<<" | ";
            cout<<"Weight Fee: $ "<<tdyList[i][1]<<" | ";
            cout<<"Tracking Service Fee: $ "<<tdyList[i][2]<<" |"<<endl;
        }
        else// if no tracking number is assigned, print out 9 digits of zeros.
        {
            cout<<"Tracking Number: 000000000"<<" | ";
            cout<<"Weight: "<<tdyList[i][0]<<" Ounces"<<" | ";
            cout<<"Weight Charge: $ "<<tdyList[i][1]<<" | ";
            cout<<"Tracking Service Fee: $ "<<tdyList[i][2]<<" |"<<endl;
        }
    }
}

void Twoday:: sortTwoday() // array that bubble sorts the array of Twoday shipment
{
    bool sorted = true;

    while(sorted)
    {
        sorted = false;
        for(int i = 0; i < tdyCount -1; i++)
        {
            if(tdyList[i][0] < tdyList[i+1][0])
            {
                //compare weight column of tdyList to the one after it, if the latter is greater, swap the order.
                int tempTdyWeight = tdyList[i][0];
                tdyList[i][0] = tdyList[i+1][0];
                tdyList[i+1][0] = tempTdyWeight;
                //change the order of weight fee according to the changes in the tdyList.
                int tempTdyWeightFee = tdyList[i][1];
                tdyList[i][1] = tdyList[i+1][1];
                tdyList[i+1][1] = tempTdyWeightFee;
                //change the order of service fee according to the changes in the tdyList.
                int tempTdyServiceFee = tdyList[i][2];
                tdyList[i][2] = tdyList[i+1][2];
                tdyList[i+1][2] = tempTdyServiceFee;
                //change the order of Track Number according to the changes in the tdyList.
                int tempTdyTN = tdyTN[i];
                tdyTN[i] = tdyTN[i+1];
                tdyTN[i+1] = tempTdyTN;

                sorted = true;
            }
        }
    }
    printTwoday();
}

void Twoday:: setTdyFlat() //void function calculating the net flat fee by multiplying global constant and twoday counter
{
    tdyFlatFee = TDY_FLAT * tdyCount;
}

double Twoday:: getTdyFlat()//double function returning the value of total flat fee
{
    return tdyFlatFee;
}

//void function which will calculate the subtotal of weight charges for twoday shipment
void Twoday:: twodaySubTotWeight()
{
    for(int i; i<tdyCount; i++) //sum up the column where weight charges are stored in.
    {
        tdySubTotWei += tdyList[i][1];
    }
    cout<<"The Subtotal for Twoday shipment per-ounce charge is $ "<<tdySubTotWei<<endl;
}

double Twoday:: getTdySubTotWeight() //double function returning the subtotal of weight
{
        return tdySubTotWei;
}

void Twoday:: twodaySubtotTrack() //void function calculating the service fee of tracking numbers
{
    for(int i; i<tdyCount; i++)
    {
        tdySubTotTrack = tdySubTotTrack + tdyList[i][2]; // add up the column containing pertinent data
    }
    cout<<"The Subtotal for Twoday Tracking number service charge is $ "<<tdySubTotTrack<<endl;
    cout<<endl;
}

double Twoday:: getTwodaySubtotTrack() //void function returning subtotal of tracking number fee
{
    return tdySubTotTrack;
}
