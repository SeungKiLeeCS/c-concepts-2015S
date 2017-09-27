#ifndef GROUND_H
#define GROUND_H
#include "Package.h"

class Ground: public Package //child class of package, responsible for actions regarding Ground shipments.
{
public:
    Ground();
    void calcWeightFee();
    //Call function to calculate fees, and assign it to array gndList
    int updateGndCount(); //getter for ground shipment counts.
    void sortGround(); //bubble sort the Ground shipment array.
    void setGndFlat(); //calculate net flat fee for ground shipments.
    double getGndFlat(); //return the value for ground shipments net flat fee.
    void groundSubTotWeight(); //calculate the net weight charge for ground shipment.
    double getGndSubTotWeight(); //return the net weight charge for ground shipment.
    void printGround(); //print the array of ground shipments.

private:

    static int gndCount; // used number of packages of gound shipment type and flatFee subtotal calculation.
    // Also used for index location of array of gndList.
    // static variable.
    static double gndList[ARRAY_SIZE][2]; // array for ground shipments. Initialize to all 0.
    // [][0] contains weight and [][1] weightFee
    // static variable.
    double gndFlatFee; //used for storing the net flat fee for ground shipment.
    double gndSubTotWei =0.0;// weight subtotal for ground shipment, initialized at 0.0 for summation.
};

#endif // GROUND_H
