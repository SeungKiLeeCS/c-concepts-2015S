#ifndef OVERNIGHT_H
#define OVERNIGHT_H
#include "Package.h"

class Overnight: public Package // child class of package, class responsible for overnight shipment
{
public:
    Overnight();
    void checkConfirm();
    //function that will ask whether confirmation request is placed
    //Call function to calculate fees, and assign it to array ovnList
    //Call function that will create Tracking Number and assign it to ovnTN
    int updateOvnCount(); // getter for overnight shipment counts.
    void sortOvernight(); // sort function for overnight array
    void setOvnFlat(); // calculate subtotal of flat fee for overnight shipments
    double getOvnFlat(); // return the subtotal of flat fee for overnight shipments
    void overnightSubTotWeight(); // calculate subtotal of weight charge for overnight shipments
    double getOvnSubTotWeight(); // return subtotal of weight charge for overnight shipments.
    void overnightSubTotConfirm(); // calculate subtotal of confirmation fee
    double getOvernightSubTotConfirm(); // return the subtotal of confirmation fee
    void printOvernight(); // print the overnight array

private:
    string confirm; // used for checking whether to add confirmation service or not.
    static int ovnCount; // used number of packages of overnight shipment type and flatFee subtotal calculation.
    //static variable
    static double ovnList[ARRAY_SIZE][3]; // array for two day shipments. Initialize to all 0.
    //[][0] contains weight, [][1] weightFee, [][2] serviceFee
    //static variable
    static int ovnTN[ARRAY_SIZE]; // parellel array of ovnList for tracking number. Initialize to all 0.
    //static variable.
    double ovnFlatFee; //stores subtotal of flat fee for overnight
    double ovnSubTotWei = 0.0; //stores subtotal of weight for overnight, initialized at 0.0 for summation
    double ovnSubTotConfirm = 0.0; // subtotal of Confirmation fee for overnight. initialized at 0.0 for summation
};

#endif // OVERNIGHT_H
