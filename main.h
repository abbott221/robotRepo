#ifndef MAIN_H
#define MAIN_H


#define IM_A_DOUBLE 0
#define IM_A_INTEGER 1

#define STRAIGHT 0
#define LEFT 1
#define RIGHT 2
#define BACKWARDS 3
#define STOP 3

#define OPTIONSTRING 0
#define OPTIONMOVE 1
#define OPTION_INT 2



//#include <stdlib.h>


#include <FEHLCD.h>
#include <FEHIO.h>

#include <FEHUtility.h>
#include <FEHMotor.h>

#include <FEHServo.h>

#include <FEHWONKA.h>

#include <FEHBattery.h>


//remove when double and int works
#include "driveHeaders.h"

#include "classes.h"

#include "setStuff.h"


#include "random.h"
#include "corrective.h"

//#include "userInterface.h"


extern int leftPower;
extern int rightPower;

extern int tempLeftPower;
extern int tempRightPower;


extern int servoMin;
extern int servoMax;

extern float lowThresh;
extern float highThresh;

extern float optoThresh;

extern float bLineDifThresh;
extern float yLineDifThresh;
extern float leftOptoThresh;
extern float rightOptoThresh;
extern float midOptoThresh;


extern bool configLightStart;
extern bool configCourseTimer;
extern bool configDelay;
extern bool configRPS;






extern double displayRate;


//extern double initialAngle;

extern double courseStartTime;

extern int numOfDisplays;







extern int currentPowerMode;
extern int leftPowerMode;
extern int rightPowerMode;


extern float decisionLight;





extern int currentMove;



//extern moreMoves;


/**/



extern FEHMotor rMotor;

//-power is forward
extern FEHMotor lMotor;

extern ButtonBoard buttons;




extern FEHEncoder  leftEncoder;
extern FEHEncoder  rightEncoder;

extern AnalogInputPin CDS;

extern AnalogInputPin optoLeft;
extern AnalogInputPin optoMid;
extern AnalogInputPin optoRight;




extern FEHWONKA TheRPS;

extern FEHServo lolServo;

extern FEHBattery lolBattery;








void MainMenuCall();






#endif // MAIN_H
