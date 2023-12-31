#ifndef UNDOREDO_H
#define UNDOREDO_H

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
    int winChecker1;
    int winChecker2;
    int dfsActive;


} stepInfoStruct;


void undoRedo(int undoRedoCheck, int gameSize, char Grid[gameSize*2 + 1][gameSize*2 + 1], int *playerTurn, int *p1Score, int *p2Score, int *player1Moves, int *player2Moves, int *remMoves, int r1, int c1, int r2, int c2, int moveChecker, int winChecker1, int winChecker2, int *currentMove, int *lastMove, stepInfoStruct steps[], int botFlag, int dfsActive)
{
    //Debugging//
    //printf("Before Entering Any IF: undoRedoCheck %d, playerTurn %d, p1Score %d, p2Score %d, player1Moves %d, player2Moves %d, remMoves %d, r1 %d, c1 %d, r2 %d, c2 %d, moveChecker %d, winChecker1 %d, winChecker2 %d, *currentMove %d, *lastMove %d, \n", undoRedoCheck, *playerTurn, *p1Score, *p2Score, *player1Moves, *player2Moves, *remMoves, r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, *currentMove, *lastMove);
    //Debugging//

    if(undoRedoCheck==0 && moveChecker!=0)
    {
        if(dfsActive==1)
        {
        //printf("NOTICE: dfsActive==1\n");
        *currentMove=*currentMove+1;
        *lastMove=*currentMove;

        steps[*currentMove].playerTurn=*playerTurn;

        if(*playerTurn==1)
        {
            steps[*currentMove].p1Score=*p1Score;
            steps[*currentMove].player1Moves=*player1Moves;

            steps[*currentMove].p2Score=steps[*currentMove-1].p2Score;
            steps[*currentMove].player2Moves=steps[*currentMove-1].player2Moves;
        }
        else if (*playerTurn==2)
        {
            steps[*currentMove].p2Score=*p2Score;
            steps[*currentMove].player2Moves=*player2Moves;

            steps[*currentMove].p1Score=steps[*currentMove-1].p1Score;
            steps[*currentMove].player1Moves=steps[*currentMove-1].player1Moves;

        }
        else {printf("ERROR ON DFSACTIVE=1"); exit(0);}

        steps[*currentMove].remMoves=*remMoves;
        steps[*currentMove].r1=r1; //(position i for movechecker )
        steps[*currentMove].c1=c1; //(position j for movechecker )
        steps[*currentMove].r2=r2; //(position i for winchecker )
        steps[*currentMove].c2=c2; //(position j for winchecker )
        steps[*currentMove].moveChecker=moveChecker;
        steps[*currentMove].winChecker1=winChecker1;
        //steps[*currentMove].winChecker2=winChecker2;
        steps[*currentMove].dfsActive=dfsActive;


        }

        else
        {

        *currentMove=*currentMove+1;
        *lastMove=*currentMove;
        steps[*currentMove].playerTurn=*playerTurn;
        steps[*currentMove].p1Score=*p1Score;
        steps[*currentMove].p2Score=*p2Score;
        steps[*currentMove].player1Moves=*player1Moves;
        steps[*currentMove].player2Moves=*player2Moves;
        steps[*currentMove].remMoves=*remMoves;
        steps[*currentMove].r1=r1;
        steps[*currentMove].c1=c1;
        steps[*currentMove].r2=r2;
        steps[*currentMove].c2=c2;
        steps[*currentMove].moveChecker=moveChecker;
        steps[*currentMove].winChecker1=winChecker1;
        steps[*currentMove].winChecker2=winChecker2;

        }

        //printf("undoRedoCheck==0 Success\n");
        //printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, DFSACTIVE %d \n",steps[*currentMove].playerTurn,steps[*currentMove].p1Score,steps[*currentMove].p2Score,steps[*currentMove].player1Moves,steps[*currentMove].player2Moves,steps[*currentMove].remMoves,steps[*currentMove].r1,steps[*currentMove].c1,steps[*currentMove].r2,steps[*currentMove].c2 ,steps[*currentMove].dfsActive );
        //printf("*currentMove, *lastMove after adding to steps finished %d, %d\n",*currentMove, *lastMove);
    }

    if(undoRedoCheck==-1)
    {

        *currentMove=0;
        steps[*currentMove].playerTurn=*playerTurn;
        steps[*currentMove].p1Score=*p1Score;
        steps[*currentMove].p2Score=*p2Score;
        steps[*currentMove].player1Moves=*player1Moves;
        steps[*currentMove].player2Moves=*player2Moves;
        steps[*currentMove].remMoves=*remMoves;

        //printf("undoRedoCheck==-1 Success\n");
        //printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",steps[*currentMove].playerTurn,steps[*currentMove].p1Score,steps[*currentMove].p2Score,steps[*currentMove].player1Moves,steps[*currentMove].player2Moves,steps[*currentMove].remMoves,steps[*currentMove].r1,steps[*currentMove].r2,steps[*currentMove].c1,steps[*currentMove].c2  );
        //printf("*currentMove, *lastMove after adding to steps finished %d, %d\n",*currentMove, *lastMove);
        //Sleep(2000); //10 sec
    }

    if(undoRedoCheck==1 && *currentMove>0) //undo query
    {
        do
        {
            if(steps[*currentMove].dfsActive==1)
            {
                //printf("NOTICE: dfsActive==1 in Undo Query\n");
                *currentMove=*currentMove-1;
                *playerTurn=steps[*currentMove].playerTurn; //current moves+1
                *p1Score=steps[*currentMove].p1Score;
                *p2Score=steps[*currentMove].p2Score;
                *player1Moves=steps[*currentMove].player1Moves;
                *player2Moves=steps[*currentMove].player2Moves;
                *remMoves=steps[*currentMove].remMoves;

                //if (Grid[(steps[*currentMove+1]).r1][(steps[*currentMove+1]).c1]==2 || Grid[(steps[*currentMove+1]).r1][(steps[*currentMove+1]).c1]==3 || Grid[(steps[*currentMove+1]).r1][(steps[*currentMove+1]).c1]==4 || Grid[(steps[*currentMove+1]).r1][(steps[*currentMove+1]).c1]==5) Grid[(steps[*currentMove+1]).r1][(steps[*currentMove+1]).c1]=' '; //moveChecker
                //if (Grid[(steps[*currentMove+1]).r1][(steps[*currentMove+1]).c1]==7 || Grid[(steps[*currentMove+1]).r1][(steps[*currentMove+1]).c1]==6) Grid[(steps[*currentMove+1]).r2][(steps[*currentMove+1]).c2]=' '; //winChecker
                //if(steps[*currentMove].moveChecker!=-1)
                {
                    Grid[(steps[*currentMove+1]).r1][(steps[*currentMove+1]).c1]=' ';
                }
                //if(steps[*currentMove].winChecker1!=-1)
                {
                    Grid[(steps[*currentMove+1]).r2][(steps[*currentMove+1]).c2]=' ';
                }
                //printf("NOTICE: \n");
            }

            else
            {
            *currentMove=*currentMove-1;
            *playerTurn=steps[*currentMove].playerTurn; //current moves+1
            *p1Score=steps[*currentMove].p1Score;
            *p2Score=steps[*currentMove].p2Score;
            *player1Moves=steps[*currentMove].player1Moves;
            *player2Moves=steps[*currentMove].player2Moves;
            *remMoves=steps[*currentMove].remMoves;


        //Debugging//
        //printf("undoRedoCheck %d, playerTurn %d, p1Score %d, p2Score %d, player1Moves %d, player2Moves %d, remMoves %d, r1 %d, c1 %d, r2 %d, c2 %d, moveChecker %d, winChecker1 %d, winChecker2 %d, *currentMove %d, *lastMove %d, \n", undoRedoCheck, *playerTurn, *p1Score, *p2Score, *player1Moves, *player2Moves, *remMoves, r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, *currentMove, *lastMove);
        //Debugging//

        if(steps[*currentMove+1].moveChecker==2 || steps[*currentMove+1].moveChecker==3 || steps[*currentMove+1].moveChecker==4 || steps[*currentMove+1].moveChecker==5) Grid[steps[*currentMove+1].r1 + steps[*currentMove+1].r2-2][(steps[*currentMove+1]).c1 + (steps[*currentMove+1]).c2-2]=' ';

        else printf("ERROR ON UNDO REDO FUNCTION\n");

        switch (steps[*currentMove+1].winChecker1) //winchecker 1 is even number (60 62 ...)
        {
            case 60: Grid[(steps[*currentMove+1]).r1 + (steps[*currentMove+1]).r2-2][(steps[*currentMove+1]).c1 + (steps[*currentMove+1]).c2-3]=' '; break;
            case 62: Grid[(steps[*currentMove+1]).r1 + (steps[*currentMove+1]).r2-1][(steps[*currentMove+1]).c1 + (steps[*currentMove+1]).c2-2]=' '; break;
            case 70: Grid[(steps[*currentMove+1]).r1 + (steps[*currentMove+1]).r2-2][(steps[*currentMove+1]).c1 + (steps[*currentMove+1]).c2-3]=' '; break;
            case 72: Grid[(steps[*currentMove+1]).r1 + (steps[*currentMove+1]).r2-1][(steps[*currentMove+1]).c1 + (steps[*currentMove+1]).c2-2]=' '; break;
            default: break;
        }

        switch (steps[*currentMove+1].winChecker2) //winchecker 1 is even number (60 62 ...)
        {
            case 61: Grid[(steps[*currentMove+1]).r1 + (steps[*currentMove+1]).r2-2][(steps[*currentMove+1]).c1 + (steps[*currentMove+1]).c2-1]=' '; break;
            case 63: Grid[(steps[*currentMove+1]).r1 + (steps[*currentMove+1]).r2-3][(steps[*currentMove+1]).c1 + (steps[*currentMove+1]).c2-2]=' '; break;
            case 71: Grid[(steps[*currentMove+1]).r1 + (steps[*currentMove+1]).r2-2][(steps[*currentMove+1]).c1 + (steps[*currentMove+1]).c2-1]=' '; break;
            case 73: Grid[(steps[*currentMove+1]).r1 + (steps[*currentMove+1]).r2-3][(steps[*currentMove+1]).c1 + (steps[*currentMove+1]).c2-2]=' '; break;
            default: break;
        }
        system("cls");
        }
        } while(steps[*currentMove].playerTurn!=1 && *currentMove>0 && botFlag==1 || steps[*currentMove].dfsActive==1);
    }

    else if (undoRedoCheck==1 && *currentMove<=0) {system("cls"); printf("\033[0;35mCan't Undo Any Further\n\033[0m");}

    if(undoRedoCheck==2 && *currentMove<*lastMove) //redo query
    {
        do
        {

            if(steps[*currentMove+1].dfsActive==1)
            {
                //printf("NOTICE: dfsActive==1 in Redo Query\n");

                *currentMove=*currentMove+1;
                *playerTurn=steps[*currentMove].playerTurn; //current moves
                *p1Score=steps[*currentMove].p1Score;
                *p2Score=steps[*currentMove].p2Score;
                *player1Moves=steps[*currentMove].player1Moves;
                *player2Moves=steps[*currentMove].player2Moves;
                *remMoves=steps[*currentMove].remMoves;

                //Grid[(steps[*currentMove+1]).r1][(steps[*currentMove+1]).c1]= steps[*currentMove].moveChecker ; //moveChecker
                //Grid[(steps[*currentMove+1]).r2][(steps[*currentMove+1]).c2]= steps[*currentMove].winChecker1 ; //winChecker
                if(steps[*currentMove].moveChecker==2 || steps[*currentMove].moveChecker==3 || steps[*currentMove].moveChecker==4 || steps[*currentMove].moveChecker==5)
                {
                    Grid[(steps[*currentMove]).r1][(steps[*currentMove]).c1]=steps[*currentMove].moveChecker+'0';
                }
                if(steps[*currentMove].winChecker1==7 || steps[*currentMove].winChecker1==6)
                {
                    Grid[(steps[*currentMove]).r2][(steps[*currentMove]).c2]=steps[*currentMove].winChecker1+'0';
                }
                //printf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, DFSACTIVE %d, moveCh %d, winCh %d, '%c'   , '%c'    \n",steps[*currentMove].playerTurn,steps[*currentMove].p1Score,steps[*currentMove].p2Score,steps[*currentMove].player1Moves,steps[*currentMove].player2Moves,steps[*currentMove].remMoves,steps[*currentMove].r1,steps[*currentMove].c1,steps[*currentMove].r2,steps[*currentMove].c2 ,steps[*currentMove].dfsActive,steps[*currentMove].moveChecker,steps[*currentMove].winChecker1, Grid[(steps[*currentMove]).r1][(steps[*currentMove]).c1] , Grid[(steps[*currentMove]).r2][(steps[*currentMove]).c2] );

            }
            else
            {

        *currentMove=*currentMove+1;
        *playerTurn=(steps[*currentMove]).playerTurn;
        *p1Score=(steps[*currentMove]).p1Score;
        *p2Score=(steps[*currentMove]).p2Score;
        *player1Moves=(steps[*currentMove]).player1Moves; // player1
        *player2Moves=(steps[*currentMove]).player2Moves; // player2
        *remMoves=(steps[*currentMove]).remMoves;

        //Debugging//
        //printf("undoRedoCheck %d, playerTurn %d, p1Score %d, p2Score %d, player1Moves %d, player2Moves %d, remMoves %d, r1 %d, c1 %d, r2 %d, c2 %d, moveChecker %d, winChecker1 %d, winChecker2 %d, *currentMove %d, *lastMove %d, \n", undoRedoCheck, *playerTurn, *p1Score, *p2Score, *player1Moves, *player2Moves, *remMoves, r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, *currentMove, *lastMove);
        //Debugging//


        switch (steps[*currentMove].moveChecker)
        {
            case 2: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-2][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-2]='2'; break;
            case 3: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-2][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-2]='3'; break;
            case 4: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-2][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-2]='4'; break;
            case 5: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-2][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-2]='5'; break;
        }

        switch (steps[*currentMove].winChecker1)
        {
            case 60: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-2][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-3]='6'; break;
            case 62: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-1][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-2]='6'; break;
            case 70: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-2][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-3]='7'; break;
            case 72: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-1][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-2]='7'; break;
            default: break;
        }
        switch (steps[*currentMove].winChecker2)
        {
            case 61: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-2][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-1]='6'; break;
            case 63: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-3][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-2]='6'; break;
            case 71: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-2][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-1]='7'; break;
            case 73: Grid[(steps[*currentMove]).r1 + (steps[*currentMove]).r2-3][(steps[*currentMove]).c1 + (steps[*currentMove]).c2-2]='7'; break;
            default: break;
        }
        system("cls");

        }
        } while(steps[*currentMove].playerTurn!=1 && *currentMove>0 && botFlag==1 || steps[*currentMove].dfsActive==1);
    }
    else if(undoRedoCheck==2 && *currentMove>=*lastMove) {system("cls"); printf("\033[0;35mCan't Redo Any Further\n\033[0m");}

}


//undoRedo(undoRedoCheck=0, gameSize, Grid, *playerTurn=1, *p1Score, /* *p2Score*/, *player1Moves, /* *player2Moves*/, *remMoves, r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, *currentMove, *lastMove, steps[], botFlag, dfsActive=1):
//undoRedo(undoRedoCheck=0, gameSize, Grid, *playerTurn=2, /* *p1Score*/, *p2Score, /* *player1Moves*/, *player2Moves, *remMoves, r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, *currentMove, *lastMove, steps[], botFlag, dfsActive=1):


#endif
