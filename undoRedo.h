#include<stdio.h>
#include<stdlib.h>
//need to store the - | and its place, store playerTurn,p1score,p2score,player1moves,player2moves,remMoves
typedef struct
{

    int playerTurn;
    int p1Score;
    int p2Score;
    int player1Moves;
    int player2Moves;
    int remMoves;
    int r1,c1,r2,c2;
    int moveChecker;
    int winChecker;

}stepInfoStruct;


void undoRedo(int undoRedoCheck, int gameSize, char Grid[gameSize*2 + 1][gameSize*2 + 1], int *playerTurn, int *p1Score, int *p2Score, int *player1Moves, int *player2Moves, int *remMoves, int r1, int c1, int r2, int c2, int moveChecker, int winChecker)
{
    int currentMove;
    int lastMove;
    if (*player1Moves==0 && *player2Moves==0){ currentMove=0; lastMove=0; printf("currentMove=0 Success");}
    stepInfoStruct steps[2*gameSize*(gameSize+1)];
    int state=0;

    //If played (player(1 or 2)Moves is increased by 1) lastMove=currentMove, currentMove++
    if(undoRedoCheck==0 && moveChecker!=0)
    {
        ((steps[currentMove])).playerTurn=*playerTurn;
        ((steps[currentMove])).p1Score=*p1Score;
        ((steps[currentMove])).p2Score=*p2Score;
        ((steps[currentMove])).player1Moves=*player1Moves; //
        ((steps[currentMove])).player2Moves=*player2Moves; //
        ((steps[currentMove])).remMoves=*remMoves;
        ((steps[currentMove])).r1=r1;
        ((steps[currentMove])).c1=c1;
        ((steps[currentMove])).r2=r2;
        ((steps[currentMove])).c2=c2;
        ((steps[currentMove])).moveChecker=moveChecker;
        ((steps[currentMove])).winChecker=winChecker;

        currentMove++;
        lastMove=currentMove;
    }

    if(undoRedoCheck==1 && currentMove>0) //undo query
    {
        currentMove--;
        *playerTurn=((steps[currentMove])).playerTurn;
        *p1Score=((steps[currentMove])).p1Score;
        *p2Score=((steps[currentMove])).p2Score;
        *player1Moves=((steps[currentMove])).player1Moves;
        *player2Moves=((steps[currentMove])).player2Moves;
        *remMoves=((steps[currentMove])).remMoves;

        if(moveChecker==2 || moveChecker==3 || moveChecker==4 || moveChecker==5) Grid[((steps[currentMove])).r1 + ((steps[currentMove])).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]=' ';
        else printf("ERROR ON UNDO REDO FUNCTION");

        switch((steps[currentMove]).winChecker)
        {
            case 60: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-3]=' '; break;
            case 61: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-1]=' '; break;
            case 62: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-1][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]=' '; break;
            case 63: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-3][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]=' '; break;
            case 70: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-3]=' '; break;
            case 71: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-1]=' '; break;
            case 72: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-1][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]=' '; break;
            case 73: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-3][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]=' '; break;
            default: break;
        }


    }

    else if (undoRedoCheck==1) printf("Can't Undo Any Further");

    if(undoRedoCheck==2 && currentMove<lastMove) //redo query
    {
        currentMove++;
        *playerTurn=(steps[currentMove]).playerTurn;
        *p1Score=(steps[currentMove]).p1Score;
        *p2Score=(steps[currentMove]).p2Score;
        *player1Moves=(steps[currentMove]).player1Moves; // player1
        *player2Moves=(steps[currentMove]).player2Moves; // player 2
        *remMoves=(steps[currentMove]).remMoves;

        switch((steps[currentMove]).moveChecker)
        {
            case 2: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]='2'; break;
            case 3: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]='3'; break;
            case 4: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]='4'; break;
            case 5: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]='5'; break;
        }

        switch((steps[currentMove]).winChecker)
        {
            case 60: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-3]='6'; break;
            case 61: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-1]='6'; break;
            case 62: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-1][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]='6'; break;
            case 63: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-3][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]='6'; break;
            case 70: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-3]='7'; break;
            case 71: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-2][(steps[currentMove]).c1 + (steps[currentMove]).c2-1]='7'; break;
            case 72: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-1][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]='7'; break;
            case 73: Grid[(steps[currentMove]).r1 + (steps[currentMove]).r2-3][(steps[currentMove]).c1 + (steps[currentMove]).c2-2]='7'; break;
            default: break;
        }


    }
    else if(undoRedoCheck==2) printf("Can't Redo Any Further");

    //if (C1<0 || C2<0) state=-1; //can't do further undo



}
