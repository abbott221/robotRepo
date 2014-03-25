#ifndef CORRECTIVE_H
#define CORRECTIVE_H


#include "main.h"





//extern int testingInteger;





extern int RPScustomAction;
extern double RPStolerance;




extern double initialMoveAngle;


void beginCorrection();

void wontGoStraight();

//==================================================




//METHOD 200 (changes RPS tolerance)
void ChangeTolerance(double value);

//Method 201
void SetUpComparison(double distance);

//THIS IS NOT A MOVEMENT
double PerformComparison(double RPSdistance);





#endif // CORRECTIVE_H
