//The option "Type" is its index in the array

//0
typeSelect[0].setOption(2, "  Time: Straight");
//1
typeSelect[1].setOption(3, "  Time: Left");
//2
typeSelect[2].setOption(4, "  Time: Right");
typeSelect[3].setOption(5, "  Time: Backwards");

typeSelect[4].setOption(6, "  Encoder: Straight");
typeSelect[5].setOption(7, "  Encoder: Left");
typeSelect[6].setOption(8, "  Encoder: Right");
typeSelect[7].setOption(9, "  Encoder: Backwards");

typeSelect[8].setOption(10, "  Set Servo Position");








//PINS FOR THE WIRES

FEHMotor rMotor(FEHMotor::Motor1);

//-power is forward
FEHMotor lMotor(FEHMotor::Motor0);

ButtonBoard buttons( FEHIO::Bank3 );



FEHEncoder  leftEncoder( FEHIO::P0_0);
FEHEncoder  rightEncoder( FEHIO::P0_1);

AnalogInputPin CDS(FEHIO::P0_7);

AnalogInputPin optoLeft(FEHIO::P2_0);
AnalogInputPin optoMid(FEHIO::P2_2);
AnalogInputPin optoRight(FEHIO::P2_4);



FEHWONKA TheRPS;

FEHServo lolServo(FEHServo::Servo0);

FEHBattery lolBattery (FEHIO::BATTERY_VOLTAGE);





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
================================================================================
//METHOD 4
//goes "straight" for specified time
void EncForward(double distance);

//METHOD 5
void EncLeft(double distance);

//METHOD 6
void EncRight(double distance);

//METHOD 7
void EncBackward(double distance);
================================================================================
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
================================================================================
//METHOD 8
void SetServoDegree(int degrees);


Pause

//METHOD 13
void DisplayLightValue();

//METHOD 14
void FlyOverLightValue();
================================================================================
//METHOD 15
void ChangePhase();

//METHOD 30
void ChangeTolerance(double value);
================================================================================
//METHOD 31
void MoveToRealX(double givenX);

//METHOD 32
void MoveToRealY(double givenY);

//METHOD 33
void CheckRealX(double givenX);

//METHOD 34
void CheckRealY(double givenY);





