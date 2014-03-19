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

//METHOD 18
void Pause(double time);




//METHOD 4
//goes "straight" for specified time
void EncForward(double distance);

//METHOD 5
void EncLeft(double distance);

//METHOD 6
void EncRight(double distance);

//METHOD 7
void EncBackward(double distance);




//METHOD 12
void ChangeOptoThreshold(double optoThresh);

//METHOD 9
void FollowBlackLine(double goThisLong);

//METHOD 10
void FollowLightLine(double goThisLong);

//METHOD 16
void unFollowBlackLine(double goThisLong);

//METHOD 17
void unFollowLightLine(double goThisLong);





//METHOD 8
void SetServoDegree(int degrees);

//METHOD 13
void DisplayLightValue();

//METHOD 14
void FlyOverLightValue(double time);





//METHOD 15
void SetCustomAction(int action);

//METHOD 30
void ChangeTolerance(double value);

//METHOD 31
void MoveToRealX(double givenX);

//METHOD 32
void MoveToRealY(double givenY);


//METHOD 33
void CheckRealX(double givenX);

//METHOD 34
void CheckRealY(double givenY);




#endif // DRIVEHEADERS_H
