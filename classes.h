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


#endif // CLASSES_H
