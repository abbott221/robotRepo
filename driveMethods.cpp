#include "main.h"


void straightenUp()
{
    double tolerance = initialAngle - TheRPS.Heading();
    if (tolerance < 0.0)
    {
        tolerance = tolerance * -1;
    }

    if (tolerance > 0.2 && tolerance < 179.8)
    {
        LCD.WriteLine("Straighten Up");
    }
}

void logDataStuffs()
{
    double dTime = TimeNow() - courseStartTime;

    if (dTime > displayRate * numOfDisplays)
    {
        LCD.Write(TheRPS.Heading());
        LCD.Write(" ");
        LCD.Write(TheRPS.X());
        LCD.Write(" ");
        LCD.WriteLine(TheRPS.Y());

        LCD.Write(optoLeft.Value());
        LCD.Write(" ");
        LCD.Write(optoMid.Value());
        LCD.Write(" ");
        LCD.WriteLine(optoRight.Value());

        numOfDisplays++;
    }

    //milliCounter++;
}




//METHOD 0
//goes "straight" for specified time
void DriveForTime(double time)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(-1 * leftPower);

    //Sleep(time);

    double startTime = TimeNow();
    double dTime = 0.0;
    while( dTime < time )
    {
        logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    rMotor.Stop();
    lMotor.Stop();
}


//METHOD 1
//definitely turns left for specified time
void TurnLeftForTime(double time)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(leftPower);

    //Sleep(time);

    double startTime = TimeNow();
    double dTime = 0.0;
    while( dTime < time)
    {
        logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    rMotor.Stop();
    lMotor.Stop();
}

//METHOD 2
//definitely turns right for specified time
void TurnRightForTime(double time)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(-1 * leftPower);

    //Sleep(time);

    double startTime = TimeNow();
    double dTime = 0.0;
    while( dTime < time)
    {
        logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    rMotor.Stop();
    lMotor.Stop();
}



//METHOD 3
//goes "straight" for specified time
void BackwardsForTime(double time)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(leftPower);

    //Sleep(time);

    double startTime = TimeNow();
    double dTime = 0.0;
    while( dTime < time)
    {
        Sleep(1);

        logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    rMotor.Stop();
    lMotor.Stop();
}




//METHOD 4
void EncForward(double distance)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(-1 * leftPower);

    while (rightEncoder.Counts() <= ((distance * 36) / (2.75 * 3.1415)))
    {
        if(leftEncoder.Counts() - rightEncoder.Counts() > 2){

            rMotor.SetPercent(rightPower+6);

            lMotor.SetPercent(-1 * leftPower);
        }
        else if(leftEncoder.Counts() - rightEncoder.Counts() < -2){
            rMotor.SetPercent(rightPower);

            lMotor.SetPercent(-1 * (leftPower+4));
 
        }
        else if(leftEncoder.Counts() - rightEncoder.Counts() > -2 && leftEncoder.Counts() - rightEncoder.Counts() < 2 ){

            rMotor.SetPercent(rightPower);

            lMotor.SetPercent(-1 * leftPower);
        }
        logDataStuffs();
    }

    rMotor.Stop();
    lMotor.Stop();
}


//METHOD 5
void EncLeft(double distance)
{
    rMotor.SetPercent(rightPower);
    lMotor.SetPercent(leftPower);


    while (rightEncoder.Counts() <= ((distance * 36) / (2.75 * 3.1415)))
    {
        if(leftEncoder.Counts() - rightEncoder.Counts() > 2){

              rMotor.SetPercent(rightPower+6);

              lMotor.SetPercent(leftPower);
        }
        else if(leftEncoder.Counts() - rightEncoder.Counts() < -2){

              rMotor.SetPercent(rightPower);

              lMotor.SetPercent(leftPower+4);

        }
        else if(leftEncoder.Counts() - rightEncoder.Counts() > -2 && leftEncoder.Counts() - rightEncoder.Counts() < 2 ){

              rMotor.SetPercent(rightPower);

              lMotor.SetPercent(leftPower);
        }
        logDataStuffs();
    }

    rMotor.Stop();
    lMotor.Stop();
}


//METHOD 6
void EncRight(double distance)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(-1* leftPower);

    while (rightEncoder.Counts() <= ((distance * 36) / (2.75 * 3.1415)))
    {
        if(leftEncoder.Counts() - rightEncoder.Counts() > 2){

             rMotor.SetPercent(-1 * (rightPower+6));

             lMotor.SetPercent(-1 *leftPower);
        }
        else if(leftEncoder.Counts() - rightEncoder.Counts() < -2){

             rMotor.SetPercent(-1 * rightPower);

             lMotor.SetPercent(-1 *(leftPower+4));

        }
        else if(leftEncoder.Counts() - rightEncoder.Counts() > -2 && leftEncoder.Counts() - rightEncoder.Counts() < 2 ){

             rMotor.SetPercent(-1 * rightPower);

             lMotor.SetPercent(-1 *leftPower);
        }
        logDataStuffs();
    }

    rMotor.Stop();
    lMotor.Stop();
}



//METHOD 7
void EncBackward(double distance)
{
    rMotor.SetPercent(-1 * rightPower);
    lMotor.SetPercent(leftPower);

    while (rightEncoder.Counts() <= ((distance * 36) / (2.75 * 3.1415)))
    {
        if(leftEncoder.Counts() - rightEncoder.Counts() > 2){

             rMotor.SetPercent(-1 * (rightPower+6));

             lMotor.SetPercent(leftPower);
        }
        else if(leftEncoder.Counts() - rightEncoder.Counts() < -2){

             rMotor.SetPercent(-1 * rightPower);

             lMotor.SetPercent(leftPower+4);

        }
        else if(leftEncoder.Counts() - rightEncoder.Counts() > -2 && leftEncoder.Counts() - rightEncoder.Counts() < 2 ){

             rMotor.SetPercent(-1 * rightPower);

             lMotor.SetPercent(leftPower);
        }
        logDataStuffs();
    }

    rMotor.Stop();
    lMotor.Stop();
}


//METHOD 8
void SetServoDegree(int degrees)
{

    //Sleep(500);

    double startTime = TimeNow();
    double dTime = 0.0;
    while( dTime < 0.5)
    {
        logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    lolServo.SetDegree(degrees);
}



//METHOD 9
void LineFromLeft(double goThisLong)
{
    lMotor.SetPercent(-1 * 60);
    rMotor.SetPercent(60);

    double startTime = TimeNow();
    double dTime = 0.0;

    while( dTime < goThisLong)
    {
        if (optoMid.Value() > optoThresh)
        {
            lMotor.SetPercent(-1 * 60);
            rMotor.SetPercent(60);
        }
        else if (optoRight.Value() > optoThresh)
        {
            lMotor.SetPercent(-1 * 5);
            rMotor.SetPercent(75);
        }
        else if (optoLeft.Value() > optoThresh)
        {
            lMotor.SetPercent(-1 * 75);
            rMotor.SetPercent(5);
        }

        logDataStuffs();
        dTime = TimeNow() - startTime;
    }

    rMotor.Stop();
    lMotor.Stop();
}

//METHOD 10
void LineFromRight(double goThisLong)
{
    lMotor.SetPercent(-1 * 60);
    rMotor.SetPercent(60);

    double startTime = TimeNow();
    double dTime = 0.0;

    while( dTime < goThisLong)
    {
        if (optoMid.Value() > optoThresh)
        {
            lMotor.SetPercent(-1 * 60);
            rMotor.SetPercent(60);
        }
        else if (optoRight.Value() > optoThresh)
        {
            lMotor.SetPercent(-1 * 75);
            rMotor.SetPercent(5);
        }
        else if (optoLeft.Value() > optoThresh)
        {
            lMotor.SetPercent(-1 * 5);
            rMotor.SetPercent(75);
        }

        logDataStuffs();
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

        logDataStuffs();
        Sleep(1);
    }
    average = average / 100.0;

    LCD.Write("Value of Light = ");

    //COMMENT OUT THIS LINE IF YOU DON'T WANT IT
    LCD.WriteLine(average);

    //Blue = 0.367
    //Red = 0.164
    //Threshold = 0.265

    if (average < 0.265)
    {
        LCD.WriteLine("Red");
    }
    else
    {
        LCD.WriteLine("Blue");
    }
}





