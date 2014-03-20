
#include "corrective.h"


//int testingInteger = 0;




void beginCorrection()
{
    //testingInteger = 2;


    //if going for the pin
    //back up a few inches and re-line up with wall


}

void wontGoStraight()
{
    //
}

//================================================================




//METHOD 200
void ChangeTolerance(double value)
{
    RPStolerance = value;
}



//Method 201
void SetUpComparison(double distance)
{
    tempDefaultStorage = distance;
}


/*
 *
 * @clears tempDefaultStorage
 *
 */
//THIS IS NOT A MOVEMENT; returns the value of the distance which should be moved
double PerformComparison(double RPSdistance)
{
    double returnMe = RPSdistance;



    if (tempDefaultStorage > 0.0)
    {

        double inaccuracy = myAbsolute(RPSdistance - tempDefaultStorage);

        //if the rps is full of crap
        if (inaccuracy > RPStolerance)
        {
            returnMe = tempDefaultStorage;
        }
        else
        {
            returnMe = RPSdistance;
        }


    }
    tempDefaultStorage = 0.0;



    return returnMe;
}









