

#include "main.h"



//goes "straight" for specified time
void DriveForTime(double time)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(-1 * leftPower);
    Sleep(time);
    rMotor.Stop();
    lMotor.Stop();
}

//goes "straight" for specified time
void BackwardsForTime(double time)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(leftPower);
    Sleep(time);
    rMotor.Stop();
    lMotor.Stop();
}

//definitely turns left for specified time
void TurnLeftForTime(double time)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(leftPower);
    Sleep(time);
    rMotor.Stop();
    lMotor.Stop();
}

//definitely turns right for specified time
void TurnRightForTime(double time)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(-1 * leftPower);
    Sleep(time);
    rMotor.Stop();
    lMotor.Stop();
}








//goes "straight" for specified time
void EncForward(double distance)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(-1 * leftPower);

    while (leftEncoder.Counts() <= ((distance * 200) / (3 * 3.1415)))
    {
        //do nothing
    }

    rMotor.Stop();
    lMotor.Stop();
}

//goes "straight" for specified time
void EncLeft(double distance)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(leftPower);

    while (leftEncoder.Counts() <= ((distance * 200) / (3 * 3.1415)))
    {
        //do nothing
    }

    rMotor.Stop();
    lMotor.Stop();
}

//definitely turns left for specified time
void EncRight(double distance)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(leftPower);

    while (leftEncoder.Counts() <= ((distance * 200) / (3 * 3.1415)))
    {
        //do nothing
    }

    rMotor.Stop();
    lMotor.Stop();
}

//definitely turns right for specified time
void EncBackward(double distance)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(-1 * leftPower);

    while (leftEncoder.Counts() <= ((distance * 200) / (3 * 3.1415)))
    {
        //do nothing
    }

    rMotor.Stop();
    lMotor.Stop();
}



void LineFromRight(double goThisLong)
{
    lMotor.SetPercent(-1 * leftPower);
    rMotor.SetPercent(rightPower);

    double startTime = TimeNow();
    double dTime = 0.0;

    while( dTime < goThisLong)
    {
        if (optoMid.Value() > 0.5)
        {
            lMotor.SetPercent(-1 * leftPower);
            rMotor.SetPercent(rightPower);
        }
        else if (optoRight.Value() > 0.5)
        {
            lMotor.SetPercent(-1 * 85);
            rMotor.SetPercent(15);
        }
        else if (optoLeft.Value() > 0.5)
        {
            lMotor.SetPercent(-1 * 15);
            rMotor.SetPercent(85);
        }

        dTime = TimeNow() - startTime;
    }

    rMotor.Stop();
    lMotor.Stop();
}

void LineFromLeft(double goThisLong)
{
    lMotor.SetPercent(-1 * leftPower);
    rMotor.SetPercent(rightPower);

    double startTime = TimeNow();
    double dTime = 0.0;

    while( dTime < goThisLong)
    {
        if (optoMid.Value() > 0.5)
        {
            lMotor.SetPercent(-1 * leftPower);
            rMotor.SetPercent(rightPower);
        }
        else if (optoRight.Value() > 0.5)
        {
            lMotor.SetPercent(-1 * 15);
            rMotor.SetPercent(85);
        }
        else if (optoLeft.Value() > 0.5)
        {
            lMotor.SetPercent(-1 * 85);
            rMotor.SetPercent(15);
        }

        dTime = TimeNow() - startTime;
    }

    rMotor.Stop();
    lMotor.Stop();
}





void SetServoDegree(int degrees)
{
    Sleep(500);
    lolServo.SetDegree(degrees);
}


//METHOD 12
void ChangeOptoThreshold(double thresh)
{
    //
}





