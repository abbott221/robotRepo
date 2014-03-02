#ifndef DRIVEHEADERS_H
#define DRIVEHEADERS_H


#include "main.h"


//goes "straight" for specified time
void DriveForTime(double time);

//goes "straight" for specified time
void BackwardsForTime(double time);

//definitely turns left for specified time
void TurnLeftForTime(double time);

//definitely turns right for specified time
void TurnRightForTime(double time);




//goes "straight" for specified time
void EncForward(double distance);

//goes "straight" for specified time
void EncLeft(double distance);

//definitely turns left for specified time
void EncRight(double distance);

//definitely turns right for specified time
void EncBackward(double distance);



void LineFromRight(double goThisLong);

void LineFromLeft(double goThisLong);



void SetServoDegree(int degrees);

void ChangeOptoThreshold(double optoThresh);




#endif // DRIVEHEADERS_H
