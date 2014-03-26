

#include "classes.h"



//************************************************
//*                                              *
//*           BEGIN MOVEMENT CLASS               *
//*                                              *
//************************************************


//"CONSTRUCTOR" METHODS HERE
movement::movement()
{
    type = STRAIGHT;
    doubleValue = 0.0;
    intValue = 0;
    isSet = false;
}

//"SETTER" METHODS HERE
void movement::setMovement(int dType, double dValue)
{
    type = dType;
    doubleValue = dValue;
    isSet = true;

    myDataType = IM_A_DOUBLE;
}

//IMPORTANT: this is an overloaded method
void movement::setMovement(int dType, int dValue)
{
    type = dType;
    intValue = dValue;
    isSet = true;

    myDataType = IM_A_INTEGER;
}

void movement::setState(bool state)
{
    if (state == true)
    {
        isSet = true;
    }
    else
    {
        isSet = false;
    }
}

//NEW METHODS

void movement::setCompletion(bool complete)
{
    if (complete == true)
    {
        completion = true;
    }
    else
    {
        completion = false;
    }
}

void movement::setDataType(bool data)
{
    if (data == IM_A_DOUBLE)
    {
        myDataType = IM_A_DOUBLE;
    }
    else
    {
        myDataType = IM_A_INTEGER;
    }
}

//"GETTER" METHODS HERE
int movement::getOperationType()
{
    return type;
}

double movement::getDoubleValue()
{
    return doubleValue;
}

int movement::getIntValue()
{
    return intValue;
}

bool movement::getIsSet()
{
    return isSet;
}

//NEW METHODS

bool movement::getCompletion()
{
    return completion;
}

bool movement::getDataType()
{
    return myDataType;
}



//************************************************
//*                                              *
//*           BEGIN OPTION CLASS                 *
//*                                              *
//************************************************


//"CONSTRUCTOR" METHODS HERE
option::option()
{
    optionType = 0;
    line = 0;
    name = "";
    optionMovement;

    optionIsSet = false;
}

//"SETTER" METHODS HERE
void option::setOption(int dLine, char *dName)
{
    optionType = OPTIONSTRING;
    line = dLine;
    name = dName;
}

void option::setOption(int dLine, movement dOptionMove)
{
    if (dOptionMove.getDataType() == IM_A_INTEGER)
    {
        optionType = OPTION_INT;
    }
    else
    {
        optionType = OPTIONMOVE;
    }
    line = dLine;
    optionMovement = dOptionMove;
    //optionMovement.setMovement(dOptionMove.getType(), dOptionMove.getDoubleValue());
}

void option::setState(bool state)
{
    if (state == true)
    {
        optionIsSet = true;
    }
    else
    {
        optionIsSet = false;
    }
}



//"GETTER" METHODS HERE
int option::getOptionType()
{
    return optionType;
}

int option::getLine()
{
    return line;
}

bool option::getState()
{
    return optionIsSet;
}

char* option::getName()
{
    return name;
}

movement option::getOptionMovement()
{
    return optionMovement;
}

void option::display()
{
    if (optionType == OPTIONSTRING)
    {
        LCD.WriteLine(name);
    }
    else if (optionType == OPTIONMOVE)
    {
        LCD.Write("  Type: ");
        LCD.Write(optionMovement.getOperationType());
        LCD.Write("  Time: ");
        LCD.WriteLine(optionMovement.getDoubleValue());
    }
    else if (optionType == OPTION_INT)
    {
        LCD.Write("  Type: ");
        LCD.Write(optionMovement.getOperationType());
        LCD.Write("  Int:  ");
        LCD.WriteLine(optionMovement.getIntValue());
    }
}


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











