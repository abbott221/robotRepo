

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
}

//IMPORTANT: this is an overloaded method
void movement::setMovement(int dType, int dValue)
{
    type = dType;
    intValue = dValue;
    isSet = true;
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
    if (dOptionMove.getOperationType() == 8)
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
