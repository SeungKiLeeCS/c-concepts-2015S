#ifndef TWODAY_H
#define TWODAY_H
#include "Package.h"


class Twoday: public Package //child class of package. Keeps track of everything related to Twoday shipping.
{
public:
    Twoday();//constructor for initializing weight charge rate.
    void checkTrackService();
    //function that will ask whether trackingNumber request is placed
    //Call function to calculate fees, and assign it to array tdyList
    //Call function that will create Tracking Number and assign it to tdyTN
    int updateTdyCount(); //getter function for count of Twoday shipments.
    void sortTwoday(); //bubble sort Twoday shipment array
    void setTdyFlat(); //calculate subtotal of flat fee for twoday shipment
    double getTdyFlat(); //return the subtotal of flat fee for twoday shipment
    void twodaySubTotWeight(); //calculate the subtotal of weight charge for twoday shipment
    double getTdySubTotWeight(); //return the subtotal of weight charge for twoday shipment
    void twodaySubtotTrack(); //calculate subtotal of tracking number fee
    double getTwodaySubtotTrack(); //return subtotal of tracking number fee
    void printTwoday(); //print Twoday shipment array

private:
    string track; //used to determine whether tracking service is added or not.
    static int tdyCount; // used number of packages of twoday shipment type and flatFee subtotal calculation.
    //static variable
    static double tdyList[ARRAY_SIZE][3]; // array for two day shipments. Initialize to all 0.
    //[][0] contains weight, [][1] weightFee, [][2] serviceFee
    //static variable
    static int tdyTN[ARRAY_SIZE]; // parellel array of tdyList for tracking number. Initialize to all 0.
    //static variable
    double tdyFlatFee; // stores net flat fee of twoday shipment
    double tdySubTotWei = 0.0; // stores net weight charge for twoday shipment, initialized at 0.0 for summation.
    double tdySubTotTrack = 0.0; // stores net tracking number fee, initialized at 0.0 for summation.
};

#endif // TWODAY_H
