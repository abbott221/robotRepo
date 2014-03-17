#include "main.h"


#include "main.h"


void theLoop(movement loopMoves[], int numMoves);


void tempBefore ()
{
    int tempSize = 20;
    movement useThese[tempSize];


    theLoop(useThese, tempSize);


}


void tempAfter ()
{
    int tempSize = 14;
    movement useThese[tempSize];




    theLoop(useThese, tempSize);

}



void driveProcess(movement moves[])
{
    //Option 4: Run

    double time;
    int pressOven;

    lMotor.Stop();
    rMotor.Stop();

    leftEncoder.SetThresholds(lowThresh, highThresh);

    lolServo.SetMin(servoMin);
    lolServo.SetMax(servoMax);

    //LCD.WriteLine(lolBattery.Voltage());

    if (configRPS)
    {
        TheRPS.InitializeMenu();
        TheRPS.Enable();
        pressOven = TheRPS.Oven();
    }

    if (configLightStart)
    {
        float value = 0.60;
        while (value > 0.30 )
        {
            value = CDS.Value();
            Sleep(.10);

            LCD.WriteLine(value);
        }
    }

    if (configCourseTimer)
    {
        time = TimeNow();
    }
    courseStartTime = TimeNow();
    numOfDisplays = 0;


    tempBefore();

    theLoop(moves, 144);

    tempAfter();

    if (configRPS)
    {
        TheRPS.Disable();

        LCD.Write("Oven Presses: ");
        LCD.WriteLine(pressOven);
    }

    if (configCourseTimer)
    {
        time = TimeNow() - time;
        LCD.Write("Time for run: ");
        LCD.WriteLine(time);
    }

    LCD.Write("Voltage: ");
    LCD.WriteLine(lolBattery.Voltage());

    LCD.WriteLine("Press Middle Button");
    while( !buttons.MiddlePressed() )
    {
        //nothing
    }

    lMotor.Stop();
    rMotor.Stop();
}



void theLoop(movement loopMoves[], int numMoves)
{
    double goForTime = 0.0;
    int useIntValue = 0;

    /*
     * THE METHOD "logDataStuffs()" HAS REMOVED THE NEED FOR THE COMPLETION VARIABLE
     *
     *
    for (int i = 0; i < numMoves; i++)
    {
        loopMoves[i].setCompletion(false);
    }
    */

    for (int i = 0; i < numMoves; i++)
    {

        goForTime = loopMoves[i].getDoubleValue();
        useIntValue = loopMoves[i].getIntValue();

        /*
         * USE "logDataStuffs()" INSTEAD
         *
         *
        if (configRPS)
        {
            LCD.Write(TheRPS.Heading());
            LCD.Write(" ");
            LCD.Write(TheRPS.X());
            LCD.Write(" ");
            LCD.WriteLine(TheRPS.Y());
        }
        */

        if (loopMoves[i].getIsSet() == true)
        {
            //milliCounter = 0;
            initialAngle = TheRPS.Heading();
            leftEncoder.ResetCounts();
            rightEncoder.ResetCounts();

            //this sleep timer was for diagnosis of the first move not being a proper distance?
            //Sleep(.25);

            if (loopMoves[i].getOperationType() == STRAIGHT)
            {
                DriveForTime(goForTime);
            }
            else if (loopMoves[i].getOperationType() == LEFT)
            {
                TurnLeftForTime(goForTime);
            }
            else if (loopMoves[i].getOperationType() == RIGHT)
            {
                TurnRightForTime(goForTime);
            }
            else if (loopMoves[i].getOperationType() == BACKWARDS)
            {
                BackwardsForTime(goForTime);
            }

            else if (loopMoves[i].getOperationType() == 4)
            {
                EncForward(goForTime);
            }
            else if (loopMoves[i].getOperationType() == 5)
            {
                EncLeft(goForTime);
            }
            else if (loopMoves[i].getOperationType() == 6)
            {
                EncRight(goForTime);
            }
            else if (loopMoves[i].getOperationType() == 7)
            {
                EncBackward(goForTime);
            }

            else if (loopMoves[i].getOperationType() == 8)
            {
                SetServoDegree(useIntValue);
            }


            else if (loopMoves[i].getOperationType() == 9)
            {
                LineFromLeft(goForTime);
            }
            else if (loopMoves[i].getOperationType() == 10)
            {
                LineFromRight(goForTime);
            }



            //METHOD 12
            else if (loopMoves[i].getOperationType() == 12)
            {
                ChangeOptoThreshold(goForTime);
            }
            else if (loopMoves[i].getOperationType() == 13)
            {
                DisplayLightValue();
            }
        }



    } //end for loop
}














