#ifndef CLASSES_H
#define CLASSES_H


#include "main.h"







class movement
{
    public:
        movement();
        void setMovement(int dType, double dValue);
        void setMovement(int dType, int dValue);

        void setState(bool state);

        int getOperationType();

        double getDoubleValue();
        int getIntValue();

        bool getIsSet();


        void setCompletion(bool complete);
        bool getCompletion();

        void setDataType(bool data);
        bool getDataType();


    private:
        int type;

        bool myDataType;

        double doubleValue;
        int intValue;

        bool isSet;

        bool completion;
};


class option
{
    public:
        option();
        void setOption(int dLine, char *dName);
        void setOption(int dLine, movement dOptionMovement);
        void setState(bool state);

        int getOptionType();
        int getLine();
        char* getName();
        movement getOptionMovement();

        bool getState();

        void display();


    private:
        int optionType;
        int line;
        char *name;
        movement optionMovement;

        bool optionIsSet;
};



class RPScleaner
{
    public:
        RPScleaner();

        //set initial move values
        void initiateMoveData();
        //set current values
        //stalls out after x time?
        //continues to scan until values aren't 0,0,0
        //SETTER method
        void update();

        //DO INTERNAL CALLS NEED [THIS.]METHOD();???

        //called internally, avoid externally
        //checks for 0,0,0
        bool currentValuesAreLegit();

        //sets X displacement
        void compareX(float supposedValue);
        //sets Y displacement
        void compareY(float supposedValue);
        //sets Angle displacement
        void compareAngle(float supposedValue);



        float getInitX();
        float getInitY();
        float getInitAngle();

        float getCurrentX();
        float getCurrentY();
        float getCurrentAngle();

        float getDisplacementX();
        float getDisplacementY();
        float getDisplacementAngle();


    private:
        float initX;
        float initY;
        float initAngle;

        float currentX;
        float currentY;
        float currentAngle;

        float displacementX;
        float displacementY;
        float displacementAngle;
};




extern RPScleaner cleaner;




#endif // CLASSES_H






