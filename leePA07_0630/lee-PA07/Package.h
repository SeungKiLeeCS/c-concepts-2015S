#ifndef PACKAGE_H
#define PACKAGE_H
#include <iostream>
using namespace std;

// global constant of Maximum Array Size for each kind of shipment
const int ARRAY_SIZE = 500;

// global declaration of flatFees, as it is cleaner to calculate the sum of flat fee with counter and constant
// rather than storing each flatFee in the array and adding them up.
const double OVN_FLAT = 12.00;
const double TDY_FLAT = 10.00;
const double GND_FLAT = 3.25;

class Package // Parent class of Overnight, Twoday, and Ground. Composed of getters, setters, and fees, rates,
        // tracking numbers, and other variables used in two or more child classes.
{
public:
// WEIGHT FEE SETTING
    void setWeightFee(); // calculate the instance weight fee according to user input and initialized value
// TRACKING NUMBER SETTING
    void setTrackNum();

protected:
    //DECLARATION OF VARIABLES USED IN MULTIPLE CHILD CLASSES
    double weight; // weight
    int trackNum; // 9 digit random tracking number
    double weightRate; // Charge per ounce for respective shipping method
    double weightFee; // Total charge due to weight for respective shipment; weightRate * weight;
    double serviceFee; // Charge for extra service such as confirmation for overnight, and tracknumber for twoday
};

#endif // PACKAGE_H
