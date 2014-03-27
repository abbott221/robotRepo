#include <string.h>
#include <stdio.h>



#include "main.h"



FEHMotor rMotor(FEHMotor::Motor1);

//-power is forward
FEHMotor lMotor(FEHMotor::Motor0);

ButtonBoard buttons( FEHIO::Bank3 );



FEHEncoder  leftEncoder( FEHIO::P0_0);
FEHEncoder  rightEncoder( FEHIO::P0_1);

AnalogInputPin CDS(FEHIO::P0_7);

DigitalInputPin Micro1(FEHIO::P1_0);
DigitalInputPin Micro2(FEHIO::P1_1);

AnalogInputPin optoLeft(FEHIO::P2_0);
AnalogInputPin optoMid(FEHIO::P2_2);
AnalogInputPin optoRight(FEHIO::P2_4);


FEHWONKA TheRPS;
FEHServo lolServo(FEHServo::Servo0);
FEHBattery lolBattery (FEHIO::BATTERY_VOLTAGE);


RPScleaner cleaner;





int leftPower = 77;
int rightPower = 80;

int tempLeftPower = 77;
int tempRightPower = 80;

int servoMin = 556;
int servoMax = 2500;

//for the encoders
float lowThresh = 0.388;
float highThresh = 1.547;

//for line following
float optoThresh = 1.5;
//float bLineDifThresh = 1.0;
//float yLineDifThresh = .4;
float bleftOptoThresh = 2.0;
float brightOptoThresh = 2.6;
float bmidOptoThresh = 2.6;
float yleftOptoThresh = 0.2;
float yrightOptoThresh = .6;
float ymidOptoThresh = 1.3;

bool light = true;

bool configLightStart = true;
bool configCourseTimer = true;
bool configDelay = true;
bool configRPS = true;





//int dataSpew = 20;
double displayRate = 0.2;

double courseStartTime = 0.0;
int numOfDisplays = 0;




//movement moves[12];


int currentPowerMode = STOP;
int leftPowerMode = leftPower;
int rightPowerMode = rightPower;

float decisionLight = 0.0;

int currentMove = 0;


movement moreMoves[144];




int UserInterface(option selection[], int size);

void tempBefore();

void tempAfter();

void driveProcess(movement moves[]);


int pageAndMoveInterface(movement moreMoves[]);

int pageInterface();

int moveTypeInterface();

int moveInterface(movement moves[]);






int pageChoice = -1;
option pageSelect[12];



int main(void)
{
    /*
    // reset the encoder counts to zero
    rightEncoder.ResetCounts();
    //returns the number of counts from the encoder
    rightEncoder.Counts();
    /**/


    //put the movement presets here???


        moreMoves[0].setMovement(8, 120);
        moreMoves[1].setMovement(50, 1.50);
        moreMoves[2].setMovement(6, 4.697);
        //moreMoves[3].setMovement(202, 0.0);
        moreMoves[4].setMovement(4, 21.2);
        //moreMoves[5].setMovement(203, 0.0);
        moreMoves[6].setMovement(5, 4.00);
        //moreMoves[5].setMovement(12, 2.00);
        moreMoves[7].setMovement(21, 5.0);
        moreMoves[8].setMovement(8, 45);
        moreMoves[9].setMovement(8, 120);


        moreMoves[12].setMovement(6, 4.0);
        moreMoves[13].setMovement(50, -2.549);
        moreMoves[14].setMovement(6, 4.00);
        moreMoves[15].setMovement(51, 20.559);
        moreMoves[16].setMovement(64, 88.80);
        moreMoves[17].setMovement(64, 88.80);
        moreMoves[18].setMovement(51, 46.0);
        moreMoves[19].setMovement(64, 84.00);
        moreMoves[20].setMovement(64, 84.00);
        moreMoves[21].setMovement(4, 8.00);
        moreMoves[22].setMovement(5, 5.00);


        moreMoves[24].setMovement(6, 6.0);
        moreMoves[25].setMovement(64, 133.0);
        moreMoves[26].setMovement(64, 133.0);


        moreMoves[36].setMovement(8, 45);
        moreMoves[37].setMovement(8, 120);
        moreMoves[38].setMovement(7, 3.50);
        moreMoves[39].setMovement(5, 4.0);
        moreMoves[40].setMovement(50, -1.299);
        moreMoves[41].setMovement(5, 11.0);
        moreMoves[42].setMovement(64, 103.0);
        moreMoves[43].setMovement(64, 103.00);
        moreMoves[44].setMovement(4, 21.50);
        moreMoves[45].setMovement(6, 4.00);

    /**/

    /*
    moreMoves[0].setMovement(0, 1.0);
    moreMoves[1].setMovement(1, 1.0);
    moreMoves[2].setMovement(2, 1.0);
    moreMoves[3].setMovement(3, 3.0);
    /**/




    pageSelect[0].setOption(2, "  Page 1");
    pageSelect[1].setOption(3, "  Page 2");
    pageSelect[2].setOption(4, "  Page 3");
    pageSelect[3].setOption(5, "  Page 4");
    pageSelect[4].setOption(6, "  Page 5");
    pageSelect[5].setOption(7, "  Page 6");
    pageSelect[6].setOption(8, "  Page 7");
    pageSelect[7].setOption(9, "  Page 8");
    pageSelect[8].setOption(10, "  Page 9");
    pageSelect[9].setOption(11, "  Page 10");
    pageSelect[10].setOption(12, "  Page 11");
    pageSelect[11].setOption(13, "  Page 12");

    for (int i = 0; i < 12; i++)
    {
        pageSelect[i].setState(true);
    }



    while (true)
    {
        MainMenuCall();
    }
    //THAT WAS A WHILE TRUE, MAIN CODE ENDS HERE

    return 0;
}



void MainMenuCall()
{
    int mainChoice = -1;
    option mainSelect[5];
    //option mainSelect[ THIS DOESN'T NEED SET; WHY??????? ];


    int moveChoice = -1;
    //option moveSelect[12];

    int typeChoice = -1;

    int configureChoice = -1;
    option configureSelect[4];
    //option configureSelect[ THIS DOESN'T NEED SET; WHY??????? ];










    //BEGIN USER INTERFACE: MAIN MENU

    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    LCD.WriteLine("Robot UI 4.02 has loaded");

    //The array position of each option is the option's value returned from userInterface
    mainSelect[0].setOption(2, "  PLACE HOLDER :)");
    mainSelect[1].setOption(3, "  Run");
    mainSelect[2].setOption(4, "  Adjust Movement");
    mainSelect[3].setOption(5, "  Display Movements");
    mainSelect[4].setOption(6, "  Insert Movement");
    mainSelect[5].setOption(7, "  Turn On Movement");
    mainSelect[6].setOption(8, "  Turn Off Movement");
    mainSelect[7].setOption(9, "  Turn On Page");
    mainSelect[8].setOption(10, "  Turn Off Page");
    mainSelect[9].setOption(11, "  Calibrate/Configure");
    mainSelect[9].setState(false);

    mainChoice = UserInterface(mainSelect, 10);

    //END USER INTERFACE: MAIN MENU




    //movement tempMove;


    if (mainChoice == 0)
    {
        //in case your finger slips, 2 or 3 fewer button presses
    }

    else if (mainChoice == 1)
    {
        //Option 1: Run

        driveProcess(moreMoves);

    }

    else if (mainChoice == 2)
    {
        //Option 2: Adjust (Set) Movement



        //USER INTERFACE: MOVEMENT SELECTION
        moveChoice = pageAndMoveInterface(moreMoves);



        //USER INTERFACE: MOVEMENT TYPE SELECTION
        typeChoice = moveTypeInterface();



        //Set the time of the adjusted move
        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        //integer valued move
        if (typeChoice == 8)
        {
            int tempIntValue = moreMoves[moveChoice].getIntValue();

            int incrs[] = {5, 3, 1};

            tempIntValue = SetInteger(tempIntValue, incrs, 3);

            moreMoves[moveChoice].setMovement(typeChoice, tempIntValue);
        }
        else if (typeChoice == 11)
        {
            int moveIncrs[] = {100, 25, 5, 1};

            int intIncrs[] = {5, 3, 1};
            double doubleIncrs[] = {1.0, 0.1, 0.01};

            int tempIntValue = 0;
            double tempDoubleValue = 0.0;

            int expansion = SetInteger(tempIntValue, moveIncrs, 4);

            //EXPANSION IS THE VALUE OF THE TYPE OF MOVE TO SET; NOW IT'S LIKE SETTING ANOTHER MOVE

            //change threshold method
            if (expansion == 12)
            {
                tempDoubleValue = SetDouble(tempDoubleValue, doubleIncrs, 3);

                moreMoves[moveChoice].setMovement(expansion, tempDoubleValue);
            }
            else if (expansion == 13)
            {
                moreMoves[moveChoice].setMovement(expansion, 0.0);
            }
            else
            {
                int theDataType = setTheDataType();

                if (theDataType == 0)
                {
                    tempDoubleValue = SetDouble(tempDoubleValue, doubleIncrs, 3);
                    moreMoves[moveChoice].setMovement(expansion, tempDoubleValue);
                    moreMoves[moveChoice].setDataType(IM_A_DOUBLE);
                }

                else
                {
                    tempIntValue = SetInteger(tempIntValue, intIncrs, 3);
                    moreMoves[moveChoice].setMovement(expansion, tempIntValue);
                    moreMoves[moveChoice].setDataType(IM_A_INTEGER);
                }

            }



            //tempIntValue stores that out of range move
            //tempIntValue = SetInteger(tempIntValue, incrs, 3);

            //moreMoves[moveChoice].setMovement(typeChoice, tempIntValue);
        }
        //double valued move
        else
        {
            double tempDoubleValue = moreMoves[moveChoice].getDoubleValue();

            double incrs[] = {1.0, 0.1, 0.01};

            tempDoubleValue = SetDouble(tempDoubleValue, incrs, 3);

            moreMoves[moveChoice].setMovement(typeChoice, tempDoubleValue);
        }

    }

    else if (mainChoice == 3)
    {
        //Option 3: Display movements

        //moveChoice = pageAndMoveInterface();
        pageAndMoveInterface(moreMoves);

    }
    //INSERT MOVEMENT
    else if (mainChoice == 4)
    {
        //Option 4: Insert movement

        LCD.WriteLine("Enter num of move (0-142)");

        int incrs[] = {25, 10, 1};
        int tempNum = SetInteger(0, incrs, 3);

        bool tempState;
        for (int i = 142; i >= tempNum; i--)
        {
            tempState = moreMoves[i].getIsSet();
            if (moreMoves[i].getDataType() == IM_A_DOUBLE)
            {
                moreMoves[i+1].setMovement(moreMoves[i].getOperationType(), moreMoves[i].getDoubleValue());
            }
            else
            {
                moreMoves[i+1].setMovement(moreMoves[i].getOperationType(), moreMoves[i].getIntValue());
            }
            moreMoves[i+1].setState(tempState);
        }
        moreMoves[tempNum].setMovement(0, 0.0);
        moreMoves[tempNum].setState(false);
    }
    else if (mainChoice == 5)
    {
        //Option 4: Turn on (Old Add) movement

        moveChoice = pageAndMoveInterface(moreMoves);

        moreMoves[moveChoice].setState(true);

    }
    else if (mainChoice == 6)
    {
        //Option 5: Turn off (Old Delete) Movement

        moveChoice = pageAndMoveInterface(moreMoves);

        moreMoves[moveChoice].setState(false);

        //moreMoves[moveChoice].setMovement(STRAIGHT, 0.0);

    }
    else if (mainChoice == 7)
    {
        //Option 6: Add page
        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        LCD.WriteLine("Select Page");

        //pageChoice = pageInterface();
        pageChoice = UserInterface(pageSelect, 12);


        for (int i = 0; i < 12; i++)
        {
            moreMoves[i + (12 * pageChoice)].setState(true);
        }

        pageSelect[pageChoice].setState(true);

    }
    else if (mainChoice == 8)
    {
        //Option 7: Delete Page
        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        LCD.WriteLine("Select Page");

        //pageChoice = pageInterface();
        pageChoice = UserInterface(pageSelect, 12);

        for (int i = 0; i < 12; i++)
        {
            moreMoves[i + (12 * pageChoice)].setState(false);
        }

        pageSelect[pageChoice].setState(false);

    }

    else if (mainChoice == 9)
    {
        //Option 8: Calibrate/Configure

        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        //LCD.WriteLine("Cunfiguer Yor Stuf Heer");

        LCD.Write("Voltage: ");
        LCD.WriteLine(lolBattery.Voltage());

        configureSelect[0].setOption(2, "  Calibrate Power");

        configureSelect[1].setOption(3, "  Calibrate Servo");

        configureSelect[2].setOption(4, "  Start with Light");
        configureSelect[2].setState(configLightStart);

        configureSelect[3].setOption(5, "  Course Timer");
        configureSelect[3].setState(configCourseTimer);

        configureSelect[4].setOption(6, "  2 sec delay");
        configureSelect[4].setState(configDelay);

        configureSelect[5].setOption(7, "  Use RPS");
        configureSelect[5].setState(configRPS);

        configureSelect[6].setOption(8, "  Read mid-opto value");

        configureSelect[7].setOption(9, "  Read CDS values");

        configureSelect[8].setOption(10, "  Read RPS values");

        //configureSelect[9].setOption(11, "  Data Spew Modulus");
        configureSelect[9].setOption(11, "  Time between displays");





        configureChoice = UserInterface(configureSelect, 10);



        LCD.Clear( FEHLCD::Black );
        LCD.SetFontColor( FEHLCD::White );

        //calibrate motor
        if (configureChoice == 0)
        {
            LCD.Clear( FEHLCD::Black );
            LCD.SetFontColor( FEHLCD::White );

            LCD.WriteLine("Setting Left Motor");

            int tempPower = leftPower;
            int incrs[] = {5, 3, 1};
            tempPower = SetInteger(tempPower, incrs, 3);

            leftPower = tempPower;

            LCD.Clear( FEHLCD::Black );
            LCD.SetFontColor( FEHLCD::White );
            LCD.WriteLine("Setting Right Motor");


            tempPower = rightPower;
            //int incrs[] = {5, 3, 1};
            tempPower = SetInteger(tempPower, incrs, 3);

            rightPower = tempPower;
        }
        //calibrate servo
        else if (configureChoice == 1)
        {
            LCD.Clear( FEHLCD::Black );
            LCD.SetFontColor( FEHLCD::White );

            LCD.WriteLine("Commence the calibration?");

            lolServo.Calibrate();

            //INPUT THE NUMBERS


            LCD.WriteLine("Setting Min");

            int tempTicks = 0;
            int incrs[] = {500, 100, 10, 1};
            tempTicks = SetInteger(tempTicks, incrs, 4);

            servoMin = tempTicks;

            LCD.Clear( FEHLCD::Black );
            LCD.SetFontColor( FEHLCD::White );
            LCD.WriteLine("Setting Max");


            tempTicks = 0;
            //int incrs[] = {5, 3, 1};
            tempTicks = SetInteger(tempTicks, incrs, 4);

            servoMax = tempTicks;



        }

        else if (configureChoice == 2)
        {
            if (configLightStart == true)
            {
                configLightStart = false;
            }
            else
            {
                configLightStart = true;
            }
        }
        else if (configureChoice == 3)
        {
            if (configCourseTimer == true)
            {
                configCourseTimer = false;
            }
            else
            {
                configCourseTimer = true;
            }
        }
        else if (configureChoice == 4)
        {
            if (configDelay == true)
            {
                configDelay = false;
            }
            else
            {
                configDelay = true;
            }
        }
        else if (configureChoice == 5)
        {
            if (configRPS == true)
            {
                configRPS = false;
            }
            else
            {
                configRPS = true;
            }
        }

        //mid-opto values
        else if (configureChoice == 6)
        {
            while( buttons.MiddlePressed() )
            {
                //this menu is entered by pressing the middle button
            }
            while( !buttons.MiddlePressed() )
            {
                LCD.Write(optoLeft.Value());
                LCD.Write(" ");
                LCD.Write(optoMid.Value());
                LCD.Write(" ");
                LCD.WriteLine(optoRight.Value());

                Sleep(0.10);
            }
            while( buttons.MiddlePressed() )
            {
                //nothing
            }
        }

        //CDS values
        else if (configureChoice == 7)
        {
            while( buttons.MiddlePressed() )
            {
                //this menu is entered by pressing the middle button
            }
            while( !buttons.MiddlePressed() )
            {
                LCD.WriteLine(CDS.Value());
                Sleep(.10);
            }
            while( buttons.MiddlePressed() )
            {
                //nothing
            }
        }

        //RPS values
        else if (configureChoice == 8)
        {
            while( buttons.MiddlePressed() )
            {
                //this menu is entered by pressing the middle button
            }
            TheRPS.InitializeMenu();
            TheRPS.Enable();
            while( !buttons.MiddlePressed() )
            {
                LCD.Write(TheRPS.Heading());
                LCD.Write(" ");
                LCD.Write(TheRPS.X());
                LCD.Write(" ");
                LCD.WriteLine(TheRPS.Y());
                Sleep(.10);
            }
            TheRPS.Disable();
            while( buttons.MiddlePressed() )
            {
                //nothing
            }
        }
        else if (configureChoice == 9)
        {
            LCD.WriteLine("Setting display rate");

            double tempRate = displayRate;
            double incrs[] = {1.0, 0.1, 0.01};
            tempRate = SetDouble(tempRate, incrs, 3);

            //dataSpew = tempSpew;
            displayRate = tempRate;
        }


    }

}








