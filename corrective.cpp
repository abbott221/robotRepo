
#include "corrective.h"


//int testingInteger = 0;




double RPStolerance = 2.0;
int RPScustomAction = 0;
double tempDefaultStorage= 0.0;

//initial
float initialMoveAngle = 0.0;

//current
//put variables here

bool RPSisWorking = false;
bool initMoveDataValid = false;
bool correctionOn = false;



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

//========================================================

void CBinitiateMoveData()
{
    initialMoveAngle = TheRPS.Heading();

    //likely to change this statement or add conditions
    updateRPSisWorking();
    //RPSisWorking = true;

    if (RPSisWorking)
    {
        initMoveDataValid = true;
    }
    else
    {
        initMoveDataValid = false;
    }

}



void CBmidmovePassiveCheck()
{
    updateRPSisWorking();

    if (!initMoveDataValid && RPSisWorking)
    {

    }


    if (RPSisWorking)
    {
        float dAngle = initialMoveAngle - TheRPS.Heading();
        dAngle = myAbsolute( dAngle );
        //dAngle is the change in the angle since start of move




    }


}



void fillerForActionTaken()
{
    //
}



void updateRPSisWorking()
{
    float updateX = TheRPS.X();
    float updateY = TheRPS.Y();
    float updateHeading = TheRPS.Heading();

    if (updateX > 0.0 || updateX < 0.0)
    {
        RPSisWorking = true;
    }
    else if (updateY > 0.0 || updateY < 0.0)
    {
        RPSisWorking = true;
    }
    else if (updateHeading > 0.0)
    {
        RPSisWorking = true;
    }
    else
    {
        RPSisWorking = false;
    }
}




bool checkFlags()
{
    bool flagsAreGood = false;

    if (correctionOn)
    {
        if (initMoveDataValid)
        {
            if (RPSisWorking)
            {
                flagsAreGood = true;
            }
            else
            {
                flagsAreGood = false;
            }
        }
        else
        {
            flagsAreGood = false;
        }
    }
    else
    {
        flagsAreGood = false;
    }

    return flagsAreGood;
}
















