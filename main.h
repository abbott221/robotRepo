#ifndef MAIN_H
#define MAIN_H


#define IM_A_DOUBLE 0
#define IM_A_INTEGER 1

#define STRAIGHT 0
#define LEFT 1
#define RIGHT 2
#define BACKWARDS 3

#define OPTIONSTRING 0
#define OPTIONMOVE 1
#define OPTION_INT 2



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

//#include "userInterface.h"


extern int leftPower;
extern int rightPower;

extern int servoMin;
extern int servoMax;

extern float lowThresh;
extern float highThresh;

extern float optoThresh;


extern bool configLightStart;
extern bool configCourseTimer;
extern bool configDelay;
extern bool configRPS;


extern int milliCounter;

extern int dataSpew;


extern double initialAngle;


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

/**/





/*

FEHMotor rMotor(FEHMotor::Motor0);

//-power is forward
FEHMotor lMotor(FEHMotor::Motor1);

ButtonBoard buttons( FEHIO::Bank3 );

FEHEncoder  rightEncoder( FEHIO::P0_0);
FEHEncoder  leftEncoder( FEHIO::P0_1);

AnalogInputPin CDS(FEHIO::P0_7);

/**/



#endif // MAIN_H
