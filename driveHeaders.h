#ifndef DRIVEHEADERS_H
#define DRIVEHEADERS_H


#include "main.h"

//METHOD 0
//goes "straight" for specified time
void DriveForTime(double time);

//METHOD 1
//definitely turns left for specified time
void TurnLeftForTime(double time);

//METHOD 2
//definitely turns right for specified time
void TurnRightForTime(double time);

//METHOD 3
//goes "straight" for specified time
void BackwardsForTime(double time);



//METHOD 4
//goes "straight" for specified time
void EncForward(double distance);

//METHOD 5
//goes "straight" for specified time
void EncLeft(double distance);

//METHOD 6
//definitely turns left for specified time
void EncRight(double distance);

//METHOD 7
//definitely turns right for specified time
void EncBackward(double distance);

//METHOD 8
void SetServoDegree(int degrees);

//METHOD 9
void LineFromLeft(double goThisLong);

//METHOD 10
void LineFromRight(double goThisLong);


//METHOD 12
void ChangeOptoThreshold(double optoThresh);

//METHOD 13
void DisplayLightValue();




#endif // DRIVEHEADERS_H
