//  Name: Seung Ki Lee
//  Program: PA02
//  Function: Bill calculator for hospital use. For each patient requires the user to input the duration of stay, room type of choice,
//  whether the patient had any tests, if so what kind of test and how many, and total cost of medicine. Immediately after the input is
//  complete, program will print out the total bill for the according patient. Then it will ask the user whether to repeat itself for
//  more patients. When the user chooses no, it will add up the total subcharges for each part entered up to the point, and then in the
//  end display it will print out the grand total for the entire patients.

#include <iostream>
using namespace std;

//prototype of functions//
void startScreen(int patientNumber);
float roomCharge(int patientNumber, float &roomSubCharge, float &tempRoomTotal);
float tempRoom(float &tempRoomTotal, float &roomSubCharge);
float labTest(int patientNumber, float &testSubCharge,float &tempTestTotal);
float tempTest(float &tempTestTotal, float &testSubCharge);
float medicine(int patientNumber, float &roomSubCharge, float &medSubCharge, float &tempMedTotal);
float tempMed(float &tempMedTotal, float &roomSubCharge);
void displayPersonSubtotal(int patientNumber, float personSubtotal, float roomSubCharge, float medSubCharge, float testSubCharge);
void displayGrandTotal(float &tempRoomTotal, float &tempTestTotal, float &tempMedTotal, float grandTotal);

int main()
{
    //declaring variables for personal subcharges, grand subtotals, grand total, and anything required for calculation//
    float roomSubCharge =0.0, medSubCharge=0.0, personSubtotal=0.0, testSubCharge=0.0, grandTotal=0.0;
    float tempRoomTotal = 0.0, tempMedTotal = 0.0, tempTestTotal = 0.0;
    int patientNumber=1;
    char addMore;

    //Loop of start screen and main function.

    do
    {
    //call function for starting screen//
    startScreen(patientNumber);
    //call function for room charge//
    roomCharge(patientNumber, roomSubCharge, tempRoomTotal);

    //call function for lab test//
    labTest(patientNumber, testSubCharge, tempTestTotal);

    //call function for medicine//
    medicine(patientNumber, roomSubCharge, medSubCharge, tempMedTotal);
    cout<<endl;
    //print personal sub total//
    displayPersonSubtotal(patientNumber, personSubtotal, roomSubCharge, medSubCharge, testSubCharge);

    //ask whether to continue if yes, increment patient number for display.//
    cout<<"Would you like to add another invoice? Press y for Yes."<<endl;
    cout<<"If you wish to end the program, press any other button";
    cin>>addMore;
    patientNumber++;
    }while(addMore=='y');
    //if user does not want to continue, call function to display grand subtotal//
    displayGrandTotal(tempRoomTotal, tempTestTotal, tempMedTotal, grandTotal);
    return 0;
}

//starting screen. Uses the patientNumber for user-friendliness.//
void startScreen(int patientNumber)
{
    cout<<"Welcome. Thank you for Choosing Lee's Hospital Bill Calculator."<<endl;
    cout<<"Please enter information of patient below."<<endl;
    cout<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"Patient "<<patientNumber<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<endl;
}

//Room Charge. Uses roomType, stayDay, and discountDay for selection of room and calculation of subtotal.//

float roomCharge(int patientNumber, float &roomSubCharge, float &tempRoomTotal)
{
    int roomType=0, stayDay, discountDay;
    float typeCharge;
    cout<<"What is the room type for patient "<<patientNumber<<"? Please enter the type number."<<endl;
    cout<<endl;
    cout<<"1- Private Room: $525.00/day"<<endl;
    cout<<"2- Semi-Private Room: $412.00?day"<<endl;
    cout<<"3- ICU: $877.00/day"<<endl;
    cout<<endl;

    while(roomType < 1||roomType > 3)
    {
        cin>>roomType;

        // if roomType is one of 3, change the value of typeCharge for calculation.
        if(roomType == 1||roomType == 2||roomType == 3)
        {
            if(roomType == 1)
            {
                typeCharge=525.00;
            }
            else if(roomType == 2)
            {
                typeCharge=412.00;
            }
            else
            {
                typeCharge=877.00;
            }
            while(stayDay<0)
            {
                cout<<"How many days did Patient "<<patientNumber<<" stay?"<<endl;

                cin>>stayDay;

                //get the days of stay for multiplication. Divide the day by 7 to figure out how many discount days patient has
                if(stayDay>0)
                {
                    discountDay = stayDay/7;
                    roomSubCharge = ((stayDay-discountDay)*typeCharge)+((discountDay*typeCharge)*0.88);

                    tempRoom(tempRoomTotal, roomSubCharge);
                }
                // if the input is out of range, loops back to the choice.
                else
                {
                    cout<<"The patient must stay at least one day. Please enter the number again."<<endl;
                }
            }
        }
        // if the input is out of range, loops back to the choice.
        else
        {
            cout<<"Wrong input. Please enter the room type number from 1 to 3."<<endl;
        }
    }
    return roomSubCharge;
}

//Lab Test Bill. Have subCharge to save for personal calculation and tempTotal for Grand Total. //

float labTest(int patientNumber, float &testSubCharge, float &tempTestTotal)
{

    int testNum=0, testCount;
    float tempChargeTest;
    char anyTest;

    //check if the patient had any test at all. if not, automatically change test bill to 0.00.

    cout<<"Did patient "<<patientNumber<<" have any lab tests? Enter 0 if the patient DIDN'T have any tests. Press any other button to continue."<<endl;
    cin>>anyTest;
    if(anyTest!='0')
    {
        cout<<"What test did the patient "<<patientNumber<<" have? Please choose the test number."<<endl;
        cout<<"Test 1: $125.00"<<endl;
        cout<<"Test 2: $250.00"<<endl;
        cout<<"Test 3: $550.00"<<endl;
        while(testNum < 1 || testNum >3)
        {
            cin>>testNum;

            //user chooses the number and it gives the according price to the testCharge. if the choice is out of range, loop back.
            if(testNum == 1 || testNum == 2 || testNum == 3)
            {
                if(testNum == 1)
                {
                    tempChargeTest = 125.00;
                }
                else if(testNum == 2)
                {
                    tempChargeTest = 250.00;
                }
                else
                {
                    tempChargeTest = 550.00;
                }

                cout<<"How many of medical test " <<testNum<< " did patient "<<patientNumber<<" have?"<<endl;
                cin>>testCount;
                testSubCharge = tempChargeTest*testCount;
            }

            else
            {
                cout<<"Wrong input. Please enter the room type number from 1 to 3."<<endl;
            }
        }
    }

    else
    {
        testSubCharge = 0.00;
    }
            tempTest(tempTestTotal, testSubCharge);


    return testSubCharge;
}

//Medicine Bill. Pass in roomSubCharge for the discount.//

float medicine(int patientNumber, float &roomSubCharge, float &medSubCharge, float &tempMedTotal)
{
    float tempMedSubCharge;
    cout<<"Enter the total medicine bill for patient "<< patientNumber<<"."<<endl;
    cin>>tempMedSubCharge;
    if(roomSubCharge>4000.00)
    {
        cout<<"Because the total room charge for patient "<<patientNumber<<" is over $4000, the patient will get 5% discount on medicine bill."<<endl;
        medSubCharge = tempMedSubCharge*0.95;
    }
    else
    {
        medSubCharge = tempMedSubCharge;
    }

    cout<<"medSubCharge"<<medSubCharge<<endl;

    tempMed(tempMedTotal, medSubCharge);
    return medSubCharge;
}

//Display subtotal for the patient. Pass in the SubCharge variables to calculate the total subcharge for patient.//

void displayPersonSubtotal(int patientNumber, float personSubtotal, float roomSubCharge, float medSubCharge, float testSubCharge)
{
    personSubtotal = roomSubCharge + medSubCharge + testSubCharge;

    cout<<"The room charge for patient "<<patientNumber<<" is: $ "<<roomSubCharge<<endl;
    cout<<"The test charge for patient "<<patientNumber<<" is: $ "<<testSubCharge<<endl;
    cout<<"The medicine bill for patient "<<patientNumber<<" is: $ "<<medSubCharge<<endl;
    cout<<endl;
    cout<<"The total bill for patient "<<patientNumber<<" is: $ "<<personSubtotal<<endl;
}

//Display grand subtotal of all patients entered. Have the tempTotal variable to hold the value throughout the loop.
//Once the tempTotals are all printed, print out the grand total of all patients. Then End the program.

void displayGrandTotal(float &tempRoomTotal, float &tempTestTotal, float &tempMedTotal, float grandTotal)
{
    cout<<"**************************************************************"<<endl;
    cout<<"The grand subtotal for room charges you've entered is: $ "<<tempRoomTotal<<endl;
    cout<<"The grand subtotal for test charges you've entered is: $ "<<tempTestTotal<<endl;
    cout<<"The grand subtotal for medicine bills you've entered is: $ "<<tempMedTotal<<endl;
    grandTotal = tempRoomTotal + tempMedTotal + tempTestTotal;
    cout<<"The grand total for everything is: $ "<<grandTotal<<endl;
    cout<<"**************************************************************"<<endl;
    cout<<"Thank you for using Lee's Hospital. The program will now be terminated.";
}

//tempTotal functions. Functions to get the tempTotal values and return them. Used in the subCharge functions to return multiple values.

float tempRoom(float &tempRoomTotal, float &roomSubCharge)
{
    tempRoomTotal =  roomSubCharge + tempRoomTotal;
    return tempRoomTotal;
}

//tempTest

float tempTest(float &tempTestTotal, float &testSubCharge)
{
    tempTestTotal = tempTestTotal + testSubCharge;
    return tempTestTotal;
}

//tempMed

float tempMed(float &tempMedTotal, float &medSubCharge)
{
    tempMedTotal = medSubCharge+tempMedTotal;
    return tempMedTotal;
}
