

#include "main.h"


//METHOD 0
//goes "straight" for specified time
void DriveForTime(double time)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(-1 * leftPower);
    Sleep(time);
    rMotor.Stop();
    lMotor.Stop();
}


//METHOD 1
//definitely turns left for specified time
void TurnLeftForTime(double time)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(leftPower);
    Sleep(time);
    rMotor.Stop();
    lMotor.Stop();
}

//METHOD 2
//definitely turns right for specified time
void TurnRightForTime(double time)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(-1 * leftPower);
    Sleep(time);
    rMotor.Stop();
    lMotor.Stop();
}



//METHOD 3
//goes "straight" for specified time
void BackwardsForTime(double time)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(leftPower);
    Sleep(time);
    rMotor.Stop();
    lMotor.Stop();
}




//METHOD 4
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


//METHOD 5
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


//METHOD 6
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



//METHOD 7
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



//METHOD 8
void SetServoDegree(int degrees)
{
    Sleep(500);
    lolServo.SetDegree(degrees);
}



//METHOD 9
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

//METHOD 10
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



//METHOD 11
//this method sets the number for methods beyond 10



//METHOD 12
void ChangeOptoThreshold(double thresh)
{
    optoThresh = thresh;
}


//METHOD 13
void DisplayLightValue()
{
    double average = 0.0;
    for (int i = 0; i<100;i++)
    {
        average += CDS.Value();

        Sleep(1);
    }
    average = average / 100.0;

    LCD.Write("Value of Light = ");
    LCD.WriteLine(average);
}





