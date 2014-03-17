

#include "main.h"


void drawCursor(int height);

int pageInterface();

int moveInterface(movement moves[]);



int UserInterface (option selection[], int size)
{
    //int size;
    //size = sizeof(selection) / sizeof(option);

    int choice = 0;

    int height[size];

    LCD.SetFontColor( FEHLCD::White );

    for (int i = 0; i < size; i++)
    {
        selection[i].display();

        height[i] = 6 + ( (selection[i].getLine() - 1) * 17);


        if (selection[i].getState() == true)
        {
            //DISPLAY THE LITTLE DOT
            LCD.SetFontColor(FEHLCD::Green);
            //x,y,width,height
            LCD.FillRectangle(12, (height[i]+2),5,5);
            LCD.SetFontColor( FEHLCD::White );
        }
    }



    int minHeight = 0;
    int maxHeight = size - 1;

    int current = 0;
    int previous = 0;


    LCD.SetFontColor( FEHLCD::Red );
    drawCursor(height[current]);
    //LCD.DrawRectangle(6,height[current],5,5);


    bool noSelection = true;

    while( noSelection )
    {
        previous = current;

        if( buttons.LeftPressed() )
        {
            while( buttons.LeftPressed() )
            {
                //nothing
            }
            //Do Stuff here

            if (current == minHeight)
            {
                current = maxHeight;
            }
            else
            {
                current--;
            }
        }
        else if( buttons.RightPressed() )
        {
            while( buttons.RightPressed() )
            {
                //nothing
            }
            //Do Stuff here

            if (current == maxHeight)
            {
                current = minHeight;
            }
            else
            {
                current++;
            }
        }
        else if( buttons.MiddlePressed() )
        {
            while( buttons.MiddlePressed() )
            {
                //nothing
            }

            //Exit the loop
            noSelection = false;
        }

        if (current != previous)
        {
            //cover up previous cursor
            LCD.SetFontColor( FEHLCD::Black );
            drawCursor(height[previous]);
            //LCD.DrawRectangle(6,height[previous],5,5);

            //draw new cursor
            LCD.SetFontColor( FEHLCD::Red );
            drawCursor(height[current]);
            //LCD.DrawRectangle(6,height[current],5,5);
        }

        Sleep(.10);
    }

    //IMPORTANT LINE RIGHT HERE
    return current;
}



void drawCursor(int pixHeight)
{
    //LCD.DrawRectangle(6,pixHeight,5,5);
    //x,y,width,height
    LCD.DrawRectangle(6,(pixHeight - 5), 305, 17);
}



/*
 * MOVE TYPE INTERFACE
 *
LCD.Clear( FEHLCD::Black );
LCD.SetFontColor( FEHLCD::White );

LCD.WriteLine("0=straight;1=left;2=right");

typeSelect[0].setOption(2, "  Straight");
typeSelect[1].setOption(3, "  Left");
typeSelect[2].setOption(4, "  Right");
typeSelect[3].setOption(5, "  Backwards");

typeChoice = UserInterface(typeSelect, 4);
*/




/*
 * MOVE INTERFACE
 *
LCD.Clear( FEHLCD::Black );
LCD.SetFontColor( FEHLCD::White );

LCD.WriteLine("Select movement");

for (int i = 0; i < 12; i++)
{

    tempMove.setMovement(moves[i].getType(), moves[i].getTime());
    moveSelect[i].setOption( (i+2), tempMove);

}

moveChoice = UserInterface(moveSelect, 12);
*/
int pageAndMoveInterface(movement moreMoves[])
{
    int pageChoice = -1;
    int moveChoice = -1;

    //movement *thisMove;


    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    pageChoice = pageInterface();

    /*********************************/

    movement tempMoves[12];


    for (int i = 0; i < 12; i++)
    {
        tempMoves[i] = moreMoves[i + (12 * pageChoice)];
    }







    /***********************************/

    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    //LCD.WriteLine("Display goes here");

    moveChoice = moveInterface(tempMoves);
    moveChoice = moveChoice + (12 * pageChoice);

    /*
    if (pageChoice == 0)
    {
        moveChoice = moveInterface(page1);
        //thisMove = &page1[moveChoice];
    }
    else if (pageChoice == 1)
    {
        moveChoice = moveInterface(page2);
        //thisMove = &page2[moveChoice];
    }
    else if (pageChoice == 2)
    {
        moveChoice = moveInterface(page3);
        //thisMove = &page3[moveChoice];
    }
    else if (pageChoice == 3)
    {
        moveChoice = moveInterface(page4);
    }
    else if (pageChoice == 4)
    {
        moveChoice = moveInterface(page5);
    }
    else if (pageChoice == 5)
    {
        moveChoice = moveInterface(page6);
    }
    else if (pageChoice == 6)
    {
        moveChoice = moveInterface(page7);
    }
    */

    return moveChoice;
}

int pageInterface ()
{
    int pageChoice = -1;
    option displayPageSelect[12];

    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    LCD.WriteLine("Select Page");

    displayPageSelect[0].setOption(2, "  Page 1");
    displayPageSelect[1].setOption(3, "  Page 2");
    displayPageSelect[2].setOption(4, "  Page 3");
    displayPageSelect[3].setOption(5, "  Page 4");
    displayPageSelect[4].setOption(6, "  Page 5");
    displayPageSelect[5].setOption(7, "  Page 6");
    displayPageSelect[6].setOption(8, "  Page 7");
    displayPageSelect[7].setOption(9, "  Page 8");
    displayPageSelect[8].setOption(10, "  Page 9");
    displayPageSelect[9].setOption(11, "  Page 10");
    displayPageSelect[10].setOption(12, "  Page 11");
    displayPageSelect[11].setOption(13, "  Page 12");


    pageChoice = UserInterface(displayPageSelect, 12);

    return pageChoice;
}


int moveTypeInterface ()
{
    int typeChoice = -1;
    option typeSelect[4];

    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    LCD.WriteLine("0=straight;1=left;2=right");

    typeSelect[0].setOption(2, "  Time: Straight");
    typeSelect[1].setOption(3, "  Time: Left");
    typeSelect[2].setOption(4, "  Time: Right");
    typeSelect[3].setOption(5, "  Time: Backwards");

    typeSelect[4].setOption(6, "  Encoder: Straight");
    typeSelect[5].setOption(7, "  Encoder: Left");
    typeSelect[6].setOption(8, "  Encoder: Right");
    typeSelect[7].setOption(9, "  Encoder: Backwards");

    typeSelect[8].setOption(10, "  Set Servo Position");

    typeSelect[9].setOption(11, "  Line From Right");
    typeSelect[10].setOption(12, "  Line From Left");

    typeSelect[11].setOption(13, "  Num Codes - Sheet");

    typeChoice = UserInterface(typeSelect, 12);


    return typeChoice;
}


int moveInterface (movement moves[])
{
    int moveChoice = -1;
    option moveSelect[12];
    movement tempMove;

    LCD.Clear( FEHLCD::Black );
    LCD.SetFontColor( FEHLCD::White );

    LCD.WriteLine("Select movement");

    for (int i = 0; i < 12; i++)
    {
        if (moves[i].getDataType() == IM_A_INTEGER)
        {
            tempMove.setMovement(moves[i].getOperationType(), moves[i].getIntValue());
            moveSelect[i].setOption( (i+2), tempMove);
            moveSelect[i].setState( moves[i].getIsSet() );
        }
        else
        {
            tempMove.setMovement(moves[i].getOperationType(), moves[i].getDoubleValue());
            moveSelect[i].setOption( (i+2), tempMove);
            moveSelect[i].setState( moves[i].getIsSet() );
        }
    }

    moveChoice = UserInterface(moveSelect, 12);





    return moveChoice;
}

