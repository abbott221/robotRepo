


//#include "main.h"

#include "driveHeaders.h"




//************************************************
//*                                              *
//*                RPS-APALOOZA                  *
//*                                              *
//************************************************

//METHOD 30
void SetCustomAction(int action)
{
    RPScustomAction = action;
}
/*
void DoCustomAction(int action)
{
    RPScustomAction = action;
}
*/

//METHOD 31
void ChangeTolerance(double value)
{
    RPStolerance = value;
}








//METHOD 40
void TurnLeftToZero()
{
    SetPowerLeft();

    //rMotor.SetPercent(rightPower);
    //lMotor.SetPercent(leftPower);


    //float targetAngle = (float) angle;

    float currentAngle = TheRPS.Heading();



    //turn until current is less than 5.0
    while( 5.0 < currentAngle )
    {
        logDataStuffs();

        currentAngle = TheRPS.Heading();
    }


    //rMotor.Stop();
    //lMotor.Stop();

    SetPowerStop();
}


//METHOD 41
void TurnRightToZero()
{
    SetPowerRight();

    //rMotor.SetPercent(-1 * rightPower);
    //lMotor.SetPercent(-1 * leftPower);


    //float targetAngle = (float) angle;

    float currentAngle = TheRPS.Heading();



    //turn until current is less than 5.0
    while( 5.0 < currentAngle )
    {
        logDataStuffs();

        currentAngle = TheRPS.Heading();
    }


    //rMotor.Stop();
    //lMotor.Stop();

    SetPowerStop();
}

//METHOD 42
void TurnLeftFromZero(double angle)
{
    SetPowerLeft();

    //rMotor.SetPercent(rightPower);
    //lMotor.SetPercent(leftPower);


    float targetAngle = (float) angle;

    float currentAngle = TheRPS.Heading();



    //turn until current is greater than target
    while( targetAngle > currentAngle )
    {
        logDataStuffs();

        currentAngle = TheRPS.Heading();
    }


    //rMotor.Stop();
    //lMotor.Stop();

    SetPowerStop();
}
//METHOD 43
void TurnRightFromZero(double angle)
{
    SetPowerRight();

    //rMotor.SetPercent(-1 * rightPower);
    //lMotor.SetPercent(-1 * leftPower);


    float targetAngle = (float) angle;

    float currentAngle = TheRPS.Heading();



    //turn until current is greater than target
    while( targetAngle > currentAngle )
    {
        logDataStuffs();

        currentAngle = TheRPS.Heading();
    }


    //rMotor.Stop();
    //lMotor.Stop();

    SetPowerStop();
}



//METHOD 50
void MoveToRealX(double givenX)
{
    //SetPowerStraight();

    //rMotor.SetPercent(rightPower);
    //lMotor.SetPercent(-1 * leftPower);


    float targetX = (float) givenX;

    float currentX = TheRPS.X();

    double travel = 0.0;

    if ( targetX < currentX )
    {
        travel = currentX - targetX;
        /*
        while( targetX < currentX )
        {
            logDataStuffs();

            currentX = TheRPS.X();
        }
        /**/
    }
    else
    {
        travel = targetX - currentX;
        /*
        while( targetX > currentX )
        {
            logDataStuffs();

            currentX = TheRPS.X();
        }
        /**/
    }

    EncForward(travel);

    //rMotor.Stop();
    //lMotor.Stop();

    //SetPowerStop();
}

//METHOD 51
void MoveToRealY(double givenY)
{
    //NOT YET
    //SetPowerStraight();

    //rMotor.SetPercent(rightPower);
    //lMotor.SetPercent(-1 * leftPower);


    float targetY = (float) givenY;

    //IT WAS PREVIOUSLY RPS.X
    float currentY = TheRPS.Y();

    double travel = 0.0;

    if ( targetY < currentY )
    {
        travel = currentY - targetY;
        /*
        while( targetY < currentY )
        {
            logDataStuffs();

            currentY = TheRPS.Y();
        }
        /**/
    }
    else
    {
        travel = targetY - currentY;
        /*
        while( targetY > currentY )
        {
            logDataStuffs();

            currentY = TheRPS.Y();
        }
        /**/
    }

    EncForward(travel);

    //rMotor.Stop();
    //lMotor.Stop();

    //SetPowerStop();
}




//METHOD 52
void CheckRealX(double givenX)
{

    float targetX = (float) givenX;

    float currentX = TheRPS.X();

    if ( myAbsolute(targetX - currentX) > RPStolerance )
    {
        //corrective behaviour
        beginCorrection();
    }


}

//METHOD 53
void CheckRealY(double givenY)
{

    float targetY = (float) givenY;

    float currentY = TheRPS.Y();

    if ( myAbsolute(targetY - currentY) > RPStolerance )
    {
        //corrective behaviour
        beginCorrection();
    }


}







//METHOD 60
void TurnLeftPast180()
{
    float currentAngle = TheRPS.Heading();

    float dAngle = 180.0 - currentAngle;

    double travel = 0.0;
    travel = (dAngle / 180.0) * 10.0;

    EncLeft(travel);

}

//METHOD 61
void TurnRightPast0()
{
    float currentAngle = TheRPS.Heading();

    float dAngle = currentAngle;

    double travel = 0.0;
    travel = (dAngle / 180.0) * 10.0;

    EncRight(travel);

}


//METHOD 62
void TurnLeftToAngle(double angle)
{
    RelativeTurnLeft(angle);
}

//METHOD 63
void TurnRightToAngle(double angle)
{
    RelativeTurnRight(angle);
}








//METHOD 80
void RelativeTurnLeft(double angle)
{
    double travel = 0.0;

    travel = (angle / 180.0) * 10.0;

    EncLeft(travel);
}

//METHOD 81
void RelativeTurnRight(double angle)
{
    double travel = 0.0;

    travel = (angle / 180.0) * 10.0;

    EncRight(travel);
}















