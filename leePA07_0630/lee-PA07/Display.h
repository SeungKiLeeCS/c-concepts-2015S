#ifndef DISPLAY_H
#define DISPLAY_H
#include "Package.h"
#include "Overnight.h"
#include "Twoday.h"
#include "Ground.h"
#include <iostream>
using namespace std;

class Display // Class responsible for any major display and user interface
{
public:
    Display();
    void startScreen(); // initial screen.
    void chooseShipment(); // Function that wil ask the user to choose type of shipment.
    void repeat(); // repeats the chooseShipment function without recursion.
    void finalScreen(); // displays the final screen
    void printOvnList(); // print the list of overnight shipment in order of ascending Tracking number
    void printTdyList(); // print the list of twoday shipment in order of ascending weight
    void printGndList(); // print the list of ground shipment in order of ascending weight
    double subtotalConfirm(); // print the subtotal of revenue from delivery confirmation
    double subtotalTrackNum(); // print the subtotal of revenue from track number
    double subtotalWeightFee(); // print the subtotal by weight charge
    double subtotalFlatFee(); // print subtotal for flat fee
    void countOfPackage(); // print shipment count for each kind of shipment, and total
    void totalRevenue(); // print Total revenue
private:
    double netFlatFee; // storing the calculated value of subtotal of flatfee.
    double serviceFeeOvn; // storing the calculated value of subtotal of confirmation fee.
    double serviceFeeTwo; // storing the calculated value of subtotal of tracking number fee.
    double netWeightFee; // storing the calculated value of subtotal of weight charge.
};

#endif // DISPLAY_H
