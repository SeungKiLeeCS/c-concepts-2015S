#include "Overnight.h"

//constructor that wil initialze the per-ounce charge
Overnight::Overnight()
{
    weightRate = 0.45;
}

// Initialization of static variables
int Overnight:: ovnCount = 0;
double Overnight:: ovnList[ARRAY_SIZE][3] = {{0}};
int Overnight:: ovnTN[ARRAY_SIZE] = {0};

void Overnight:: checkConfirm()
{
    setTrackNum(); //automatically assign a tracking number to the instance

    cout<<"You have chosen overnight shipping. Has the customer chosen confirmation service?"<<endl;
    cout<<"[y/n]"<<endl;
    cin>> confirm;

    while (confirm != "y" && confirm != "n") // input error check.
    {
        cout<<"The input must be either lowercase y or n. Please choose again."<<endl;
        cin.clear();
        cin>>confirm;
    }

    if (confirm == "y")
    {
        serviceFee = 3.18;
        cout<<"The addtional fee of $3.18 has been added to the final bill."<<endl;
    }
    else
    {
        serviceFee = 0.0;
        cout<<"No additional service fee is applied for this customer."<<endl;
    }

    //assgin the weight, weightFee, serviceFee to respective position in array, and trackNum in parellel array.
    setWeightFee();

    //assgin the weight, weightFee, serviceFee to respective position in array, and trackNum in parellel array.
    ovnList[ovnCount][0] = weight;
    ovnList[ovnCount][1] = weightFee;
    ovnList[ovnCount][2] = serviceFee;
    ovnTN[ovnCount] = trackNum;

    cout<<"Weight in ounces : "<< ovnList[ovnCount][0]<<" ounces"<<endl;
    cout<<"Weight Charge : $ "<< ovnList[ovnCount][1]<<endl;
    cout<<"Service Charge : $ "<< ovnList[ovnCount][2]<<endl;
    cout<<"Tracking Number : "<< ovnTN[ovnCount]<<endl;
    cout<<endl; // empty line for readability
    ovnCount++; // increment the counter of Twoday Shipment.

    cout<<"Number of Overnight Packages thus far : "<<ovnCount<<endl; //check function.

}

int Overnight:: updateOvnCount() //getter function for count of shipments for overnight shipments
{
    return ovnCount;
}

void Overnight:: printOvernight() // void function printing the list of overnight shipments
{
    for(int i=0; i<ovnCount; i++)
    {
            cout<<"Tracking Number: "<<ovnTN[i]<<" | ";
            cout<<"Weight: "<<ovnList[i][0]<<" Ounces"<<" | ";
            cout<<"Weight Charge: $ "<<ovnList[i][1]<<" | ";
            cout<<"Confirmation Fee: $ "<<ovnList[i][2]<<" |"<<endl;
    }
}

void Overnight:: sortOvernight() //bubble sort function for array of overnight shipments
{
    bool sorted = true;

    while(sorted)
    {
        sorted = false;
        for(int i = 0; i < ovnCount -1; i++)
        {
            if(ovnTN[i] < ovnTN[i+1]) //sort in order of tracking number
            {
                //if tracking number is less than the one after it, switch the palce
                int tempOvnTN = ovnTN[i];
                ovnTN[i] = ovnTN[i+1];
                ovnTN[i+1] = tempOvnTN;
                //change the Weight column of ovnList according to the change in its parellel array.
                int tempOvnWeight = ovnList[i][0];
                ovnList[i][0] = ovnList[i+1][0];
                ovnList[i+1][0] = tempOvnWeight;
                //change the WeightFee column of ovnList according to the change in its parellel array.
                int tempOvnWeightFee = ovnList[i][1];
                ovnList[i][1] = ovnList[i+1][1];
                ovnList[i+1][1] = tempOvnWeightFee;
                //change the ServiceFee column of ovnList according to the change in its parellel array.
                int tempOvnServiceFee = ovnList[i][2];
                ovnList[i][2] = ovnList[i+1][2];
                ovnList[i+1][2] = tempOvnServiceFee;

                sorted = true;
            }
        }
    }
    printOvernight(); // call print function
}

//void function calculating the flat fee for overnight shipments by multiplying global constant and count for shipment.
void Overnight:: setOvnFlat()
{
    ovnFlatFee = OVN_FLAT * ovnCount;
}

//double function returning the flat fee value.
double Overnight:: getOvnFlat()
{
    return ovnFlatFee;
}

//void function calculating the subtotal of the weight charge of overnight shipments
void Overnight:: overnightSubTotWeight()
{
    for(int i; i<ovnCount; i++)
    {
        ovnSubTotWei += ovnList[i][1]; //add up the column with pertinent data
    }
    cout<<"The Subtotal for Overnight shipment per-ounce charge is $ "<<ovnSubTotWei<<endl;
}

//void function returning the value of subtotal for weight charge
double Overnight:: getOvnSubTotWeight()
{
     return ovnSubTotWei;
}

//void function calculating the confirmation fee
void Overnight:: overnightSubTotConfirm()
{
    for(int i=0; i<ovnCount; i++)
    {
        ovnSubTotConfirm += ovnList[i][2]; // add up the column with pertinent data
    }
    cout<<"The total Service fee of Confirmation is $ "<<ovnSubTotConfirm<<endl;
    cout<<endl; // extra blank for readability
}

//void function as getter for net confirmation fee
double Overnight:: getOvernightSubTotConfirm()
{
    return ovnSubTotConfirm;
}
