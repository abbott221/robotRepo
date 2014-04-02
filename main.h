#ifndef MAIN_H
#define MAIN_H



#include <FEHLCD.h>
#include <FEHIO.h>
#include <FEHUtility.h>
#include <FEHMotor.h>
#include <FEHServo.h>
#include <FEHWONKA.h>
#include <FEHBattery.h>



typedef enum
{
    tString = 0,
    tInt,
    tFloat,
    tDouble,
    tVoid

    //opInt,
    //opFloat,
    //opDouble,
    //opVoid
} TypeEnum;

typedef enum
{
    STRAIGHT = 0,
    LEFT,
    RIGHT,
    BACKWARDS,
    STOP
} PMode;



struct moveInfoSmall
{
    float infoX;
    float infoY;
    float infoHead;
};

struct moveInfo
{
    float theoryStartX;
    float theoryStartY;
    float theoryStartHead;

    float theoryEndX;
    float theoryEndY;
    float theoryEndHead;

    float expStartX;
    float expStartY;
    float expStartHead;

    float expEndX;
    float expEndY;
    float expEndHead;
};





#include "drive/drive.h"

#include "classes/classes.h"

#include "setup/menuSetup.h"

#include "other.h"







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

extern double courseStartTime;

extern int numOfDisplays;


extern int leftPowerMode;
extern int rightPowerMode;

extern float decisionLight;

extern int currentMove;









extern FEHMotor lMotor;
extern FEHMotor rMotor;

extern ButtonBoard buttons;
extern FEHEncoder  leftEncoder;
extern FEHEncoder  rightEncoder;

extern AnalogInputPin CDS;

extern DigitalInputPin Micro1;
extern DigitalInputPin Micro2;

extern AnalogInputPin optoLeft;
extern AnalogInputPin optoMid;
extern AnalogInputPin optoRight;

extern FEHWONKA TheRPS;
extern FEHServo lolServo;
extern FEHBattery lolBattery;



void MainMenuCall();
void ConfigureMenuCall();



#endif // MAIN_H
