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

FEHServo lolServo(FEHServo::Servo0);












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
