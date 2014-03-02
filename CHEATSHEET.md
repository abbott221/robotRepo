
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
