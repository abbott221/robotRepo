#ifndef CLASSES_H
#define CLASSES_H


#include "../main.h"




class Operation
{
public:
    Operation();

    void set_iOperation(void ( *intPtr ) (int iValue));
    void set_fOperation(void ( *floatPtr ) (float fValue));
    void set_dOperation(void ( *doublePtr ) (double dValue));
    void set_vOperation(void ( *voidPtr ) ());

    TypeEnum getDataType();

    void perform_iOperation(int iValue);
    void perform_fOperation(float fValue);
    void perform_dOperation(double dValue);
    void perform_vOperation();


private:
    void ( *iPtr ) (int iValue);
    void ( *fPtr ) (float fValue);
    void ( *dPtr ) (double dValue);
    void ( *vPtr ) ();

    TypeEnum dataType;
};



class OperationTracker
{
public:
    OperationTracker(int size);
    void add_iOperation(int callID, void ( *intPtr ) (int iValue));
    void add_fOperation(int callID, void ( *floatPtr ) (float fValue));
    void add_dOperation(int callID, void ( *doublePtr ) (double dValue));
    void add_vOperation(int callID, void ( *voidPtr ) ());
    //void addOperation(int arraySpot, void ( *floatPtr ) (float value));
    //void addOperation(Operation dOperation);
    //void performOperation(float fValue);

    int getTrackerSize();

    Operation * tracker;

private:
    //int filled;
    int trackerSize;
};




class Movement
{
public:
    Movement();

    int getOperation();

    int getIntValue();
    float getFloatValue();
    double getDoubleValue();

    TypeEnum getDataType();

    bool getState();

    void set_iMovement( int callID, int value);
    void set_fMovement( int callID, float value);
    void set_dMovement( int callID, double value);
    void set_vMovement( int callID);

    void setMovement( Movement dMovement );

    void setState(bool dState);

    void perform_iMovement();
    void perform_fMovement();
    void perform_dMovement();
    void perform_vMovement();

private:
    int operationCallID;

    int iValue;
    float fValue;
    double dValue;

    TypeEnum dataType;

    bool movementState;

    moveInfoSmall expectedStart;
    moveInfoSmall expectedEnd;
};



class MovementTracker
{
public:
    //size is 144
    MovementTracker();

    //presets as operation, value
    int add_iMovement(int dOp, int value);
    int add_fMovement(int dOp, float value);
    int add_dMovement(int dOp, double value);
    int add_vMovement(int dOp); //void

    //driveProcess as operation, value
//    void perform_iMovement(int dOp);
//    void perform_fMovement(int dOp);
//    void perform_dMovement(int dOp);
//    void perform_vMovement(int dOp);

    Movement * tracker;

private:
    int filled;
    int trackerSize;
};









class option
{
    public:
        option();

        //setters
        //dataType is set automatically by the following 2 methods
        void setOption(int dLine, const char *dName);

        //void setOption(const char *dName, int jeff);

        void setJeffID(int jeff);

        void setOption(int dLine, Movement dOptionMovement);
        void setOption(option dOption);
        void setState(bool state);

        //getters
        int getJeffID();

        TypeEnum getDataType();
        int getLine();
        const char * getName();
        Movement getMovement();
        bool getState();

        void display();

    private:
        TypeEnum dataType;
        int line;
        const char * name;
        Movement optionMovement;
        bool optionState;

        int optionJeffID;
};

class Menu
{
    public:
        Menu();
        void addOption(const char * dLine);
        void addOption(const char * dLine, int jeff);
        void addOption(Movement dMovement);

        void setSubOpMenu(bool isSubOpMenu);
        bool getSubOpMenu();

        void setSelectionSize(int dSize);

        int UserInterface();
        void drawCursor(int pixHeight);

        option * selection;

    private:
        int selectionSize;

        bool subOpMenu;
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

extern PMode currentPowerMode;


extern MovementTracker mTracker;
extern OperationTracker opTracker;









extern int mainChoice;
extern Menu mainMenu;

extern int pageChoice;
extern Menu pageMenu;

extern int configureChoice;
extern Menu configureMenu;

extern int operationChoice;
extern Menu operationMenu;


extern int opSubChoice;
extern Menu opSubTimeMenu;
extern Menu opSubEncMenu;
extern Menu opSubLineMenu;

extern Menu opSubGeneralMenu;
extern Menu opSubRPSRealMenu;
extern Menu opSubRPSRealTurnMenu;



extern int moveChoice;
extern Menu moveMenu;







#endif // CLASSES_H
