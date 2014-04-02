


#include "classes.h"







//************************************************
//*                                              *
//*          BEGIN RPScleaner CLASS              *
//*                                              *
//************************************************


//"CONSTRUCTOR" METHODS HERE
RPScleaner::RPScleaner()
{
    initX = 0.0;
    initY = 0.0;
    initAngle = 0.0;

    currentX = 0.0;
    currentY = 0.0;
    currentAngle = 0.0;

    displacementX = 0.0;
    displacementY = 0.0;
    displacementAngle = 0.0;
}




void RPScleaner::initiateMoveData()
{
    update();

    initX = currentX;
    initY = currentY;
    initAngle = currentAngle;
}


void RPScleaner::update()
{
    do {
        currentX = TheRPS.X();
        currentY = TheRPS.Y();
        currentAngle = TheRPS.Heading();
    } while ( !currentValuesAreLegit() );
    //continue until we don't have 0,0,0
}

bool RPScleaner::currentValuesAreLegit()
{
    bool returnThis = false;


    //check x =/= 0
    if (currentX > 0.0 || currentX < 0.0)
    {
        returnThis = true;
    }
    //check y =/= 0
    else if (currentY > 0.0 || currentY < 0.0)
    {
        returnThis = true;
    }
    //check angle =/= 0
    else if (currentAngle > 0.0)
    {
        returnThis = true;
    }
    else
    {
        returnThis = false;
    }



    return returnThis;
}



void RPScleaner::compareX(float supposedValue)
{
    //to-do
}
void RPScleaner::compareY(float supposedValue)
{
    //to-do
}
void RPScleaner::compareAngle(float supposedValue)
{
    //to-do
}


//LOTS OF "GETTER" METHODS

float RPScleaner::getInitX()
{
    return initX;
}
float RPScleaner::getInitY()
{
    return initY;
}
float RPScleaner::getInitAngle()
{
    return initAngle;
}


float RPScleaner::getCurrentX()
{
    return currentX;
}
float RPScleaner::getCurrentY()
{
    return currentY;
}
float RPScleaner::getCurrentAngle()
{
    return currentAngle;
}


float RPScleaner::getDisplacementX()
{
    return displacementX;
}
float RPScleaner::getDisplacementY()
{
    return displacementY;
}
float RPScleaner::getDisplacementAngle()
{
    return displacementAngle;
}









