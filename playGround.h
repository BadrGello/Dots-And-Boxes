#ifndef PLAYGROUND_H
#define PLAYGROUND_H

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "botRandom.h"
#include "save.h"
#include "undoRedo.h"
#include "readLine.h"
#include "mainMenu.h"
#include "rank.h"

//#define size 256
void activeplayGround( int gameSize,char Grid[gameSize*2 + 1][gameSize*2 + 1] ,char player1[256],char player2[256], int dfsFlag, int botFlag,int playerTurn,int p1Score,int p2Score,int player1Moves,int player2Moves,int z,int savedTime );
void playGround(int gameSize, int dfsFlag, int botFlag) //dfs and bot markers, if = 1, it's enabled
{
    int i,j;
    char Grid[2*gameSize+1][2*gameSize+1];
    //The following is initializing the gird with the given gameSize
    for (i=0;i<=2*gameSize;i++){
        for (j=0;j<=2*gameSize;j++){
        if(i%2==0&&j%2==0) Grid[i][j]='.';
        else Grid[i][j]=' ';
        }
    }

    int p1Score=0,p2Score=0,z=2*gameSize*(gameSize+1),player1Moves=0,player2Moves=0; //z is the remaining moves
    int playerTurn=1;
    char player1[256],player2[256]; //holds the players names
    char p1Color[20],p2Color[20]; //holds player's colors
    while (1)
    {
        printf("Player 1, Choose Your Color: 1 2 3 4\n");
        readLine(p1Color,20);
        if (strcmp(p1Color, "red")==0 || strcmp(p1Color, "")==0 || strcmp(p1Color, "")==0 || strcmp(p1Color, "")==0) break;
        else {system("cls"); printf("Invaled Value\n");}

    }
    system("cls");
    while (1)
    {
        printf("Player 2, Choose Your Color: 5 6 7 8\n");
        readLine(p2Color,20);
        if (strcmp(p2Color, "blue")==0 || strcmp(p2Color, "")==0 || strcmp(p2Color, "")==0 || strcmp(p2Color, "")==0) break;
        else {system("cls"); printf("Invaled Value\n");}
    }
    system("cls");

    printf("\033[0;34mPlayer1, Enter your name:\033[0m "); //player 1 is blue
    readLine(player1,256);
    system("cls");
    if(botFlag==1){strcpy(player2, "Computer");} //if not bot, it'll scanf for player 2 name instead
    else{
    printf("\033[0;31mPlayer2, Enter your name:\033[0m "); //player 2 is red
    readLine(player2,256);
    system("cls");}
    int savedTime=0;

    char options[100];
    activeplayGround( gameSize,Grid,player1,player2, dfsFlag,  botFlag,playerTurn,p1Score,p2Score,player1Moves,player2Moves,z,savedTime);

}

void activeplayGround( int gameSize,char Grid[gameSize*2 + 1][gameSize*2 + 1],char player1[256],char player2[256], int dfsFlag, int botFlag,int playerTurn,int p1Score,int p2Score,int player1Moves,int player2Moves,int z ,int savedTime)
{

        int r1,c1,r2,c2;
        char b[5]; b[4]='\0';
        clock_t begin = clock();
        int time_spent=savedTime,t=savedTime/60;
        time_spent-=t*60;
        int carrier=savedTime;
        //int steps[z];

        //*************//
        //The Game Loop//
        //*************//

            stepInfoStruct steps[180];
            int moveChecker=0;
            int winChecker1=0;
            int winChecker2=0;
            int undoRedoCheck=-1;
            int currentMove=0;
            int lastMove=0;
            int dfsActive=0;


        int EXIT=0;
        while(z>0) //while there are still remaining moves to play, the game will continue looping
        {
            clock_t end = clock();
            time_spent = ((int)(end - begin) / CLOCKS_PER_SEC)+savedTime;
            t=time_spent/60;
            time_spent-=t*60;

            if (undoRedoCheck==-1)
                {undoRedo(-1, gameSize, Grid, &playerTurn, &p1Score, &p2Score, &player1Moves, &player2Moves, &z , r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps, botFlag, dfsActive);}
            undoRedoCheck=0;
            winChecker1=0;
            winChecker2=0;
            dfsActive=0;

            //printing the time
            printf("Time Spent %d:%d\n",t,time_spent);
            //printing the score and the moves
            printf(" \033[0;34m%s's Score :%d\033[0m           ",player1,p1Score);
            printf(" \033[0;31m%s's Score :%d\033[0m \n",player2,p2Score);
            printf(" \033[0;34m%s Played :%d Moves\033[0m      ",player1,player1Moves);
            printf(" \033[0;31m%s Played :%d Moves\033[0m \n",player2,player2Moves);
            printf("Remaining Moves:%d\n",z);
            int l=p1Score,t=p2Score;
            //Printing The Grid
            printf("\n  ");
            for(int i=1;i<=gameSize+1;i++) printf("%d   ",i); //printing the 1st row of numbers to help players choose the dots
            printf("\n");

            int k=1; //to print the indecies
            for(int i=0;i<gameSize*2 + 1;i++)
            {
                if (i%2==0)
                {
                    printf("%d ",k);     //printing the 1st col of numbers to help players choose the dots
                    k++;
                }
                else printf("  ");
                for(int j=0;j<gameSize*2 + 1;j++)
                    {
                        if ((Grid[i][j]==' ')||(Grid[i][j]=='.')) printf("%c ",Grid[i][j]);
                        else if(Grid[i][j]=='2') printf("\033[0;34m|\033[0m ");
                        else if(Grid[i][j]=='3') printf("\033[0;34m_\033[0m ");
                        else if(Grid[i][j]=='6') printf("\033[0;34m#\033[0m ");
                        else if(Grid[i][j]=='4') printf("\033[0;31m|\033[0m ");
                        else if(Grid[i][j]=='5') printf("\033[0;31m_\033[0m ");
                        else if(Grid[i][j]=='7') printf("\033[0;31m#\033[0m ");
                    }
                printf("\n");
            }
            printf("\n");

            //***************************************************************************************************//
            //Taking the coordinates of the dots, determining the score and the player turns. [scanning the grid]//
            //***************************************************************************************************//

            //********//
            //PLAYER 1//
            //********//

            if(playerTurn==1)
            {
                //Start: Scanning and handling in game options//
                printf("Undo  Redo  Save  Exit\n");
                printf(" \033[0;34m%s's Turn : \033[0m",player1);
                int i=0;
                for(i=0;i<4;i++)
                {
                    scanf(" %c",&b[i]); //scaning the 4 coordinates into an Griday to minimize the errors when the user inputs
                    b[i]=tolower(b[i]); //making any uppercase character lowercased
                }
                r1=b[0]-'0';  c1=b[1]-'0';  r2=b[2]-'0';  c2=b[3]-'0';
                //scanf("%d %d %d %d",&r1,&r2,&c1,&c2);

                if (strcmp("undo",b)==0) //UNDO//
                {
                    undoRedoCheck=1;
                    undoRedo(1, gameSize, Grid, &playerTurn, &p1Score, &p2Score, &player1Moves, &player2Moves, &z , r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps, botFlag, dfsActive);
                    continue;
                }
///////////////////printf("this should not be printed if pressed undo\n");
///////////////////Sleep(10000);
                else if (strcmp("redo",b)==0) //REDO//
                {
                    undoRedoCheck=2;
                    undoRedo(2, gameSize, Grid, &playerTurn, &p1Score, &p2Score, &player1Moves, &player2Moves, &z , r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps, botFlag, dfsActive);
                    continue;
                }
                else if (strcmp("save",b)==0) //SAVE//
                {
                 savedTime = time_spent;
                 saveTheGame(gameSize,Grid,playerTurn,player1,player2,p1Score,p2Score,player1Moves,player2Moves, z,dfsFlag,botFlag, savedTime);
                 savedTime=carrier;
                }
                else if (strcmp("exit",b)==0)
                {
                    //getchar();
                    system("cls");
                    mainMenu();
                    //exit(EXIT_SUCCESS);
                    //EXIT=1;
                    //break;
                }
                //End: Scanning and handling in game options//

                if (EXIT==1) break;
                if ((c2==c1)&&(abs(r1-r2)==1)&&(Grid[r1+r2-2][c1+c2-2]==' '&& r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)){
                    player1Moves++;
                    Grid[r1+r2-2][c1+c2-2]='2'; // |
                    moveChecker=2; //UndoRedo

                    if(c1!=1){
                    if(Grid[r1+r2-2][c1+c2-4]!=' ' && Grid[r1+r2-3][c1+c2-3]!=' ' && Grid[r1+r2-1][c1+c2-3]!=' ') {
                    Grid[r1+r2-2][c1+c2-3]='6'; // #
                    p1Score++;
                    winChecker1=60; //UndoRedo
                    /////////////////
                    }
                    }

                    if(c1!=gameSize+1){
                    if (Grid[r1+r2-2][c1+c2]!=' '&& Grid[r1+r2-3][c1+c2-1]!=' ' && Grid[r1+r2-1][c1+c2-1]!=' ') {
                    Grid[r1+r2-2][c1+c2-1]='6'; // #
                    p1Score++;
                    winChecker2=61; //UndoRedo
                    /////////////////
                    }
                    }
                }
                else if ((r2==r1)&&(abs(c1-c2)==1)&&(Grid[r1+r2-2][c1+c2-2]==' ' && r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)){
                     player1Moves++;
                     Grid[r1+r2-2][c1+c2-2]='3'; // -
                     moveChecker=3; //UndoRedo

                     if(r1!=gameSize+1){
                     if(Grid[r1+r2][c1+c2-2]!=' '  && Grid[r1+r2-1][c1+c2-1]!=' ' &&Grid[r1+r2-1][c1+c2-3]!=' '  ){
                     Grid[r1+r2-1][c1+c2-2]='6';
                     p1Score++;
                     winChecker1=62; //UndoRedo
                     }
                     }

                     if(r1!=1){
                     if(Grid[r1+r2-4][c1+c2-2]!=' ' && Grid[r1+r2-3][c1+c2-1]!=' ' &&Grid[r1+r2-3][c1+c2-3]!=' '  ){
                     Grid[r1+r2-3][c1+c2-2]='6';
                     p1Score++;
                     winChecker2=63; //UndoRedo
                     }
                     }

                }
                else
                {
                    system( "cls" );
                    printf("Invalid Value, Please Enter Again\n");
                    continue;
                }
                if(p1Score>l) {

                        z--;
                        if (dfsFlag==1) chainOfBoxes(gameSize,Grid,r1,c1,r2,c2,&z,&player1Moves,&p1Score, &currentMove, &lastMove, steps, botFlag, dfsActive, &playerTurn);
                        undoRedo(0, gameSize, Grid, &playerTurn, &p1Score, &p2Score, &player1Moves, &player2Moves, &z , r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps, botFlag, dfsActive);

                        system( "cls" );
                        continue;

                }

                playerTurn=2;
                z--;
                undoRedo(0, gameSize, Grid, &playerTurn, &p1Score, &p2Score, &player1Moves, &player2Moves, &z , r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps, botFlag, dfsActive);

                system( "cls" );
            }

            //********//
            //PLAYER 2//
            //********//

            else if(playerTurn==2)
            {
                if (botFlag==0){
                //Start: Scanning and handling in game options//
                printf("Undo  Redo  Save  Exit\n");
                printf(" \033[0;31m%s's Turn : \033[0m",player2);
                int i=0;
                for(i=0;i<4;i++)
                {
                    scanf(" %c",&b[i]); //scaning the 4 coordinates into an Griday to minimize the errors when the user inputs
                    b[i]=tolower(b[i]); //making any uppercase character lowercased
                }
                if (botFlag==0){r1=b[0]-'0';  c1=b[1]-'0';  r2=b[2]-'0';  c2=b[3]-'0';}

                if (strcmp("undo",b)==0) //UNDO//
                {
                    undoRedoCheck=1;
                    undoRedo(1, gameSize, Grid, &playerTurn, &p1Score, &p2Score, &player1Moves, &player2Moves, &z , r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps, botFlag, dfsActive);
                    continue;
                }
                else if (strcmp("redo",b)==0) //REDO//
                {
                    undoRedoCheck=2;
                    undoRedo(2, gameSize, Grid, &playerTurn, &p1Score, &p2Score, &player1Moves, &player2Moves, &z , r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps, botFlag, dfsActive);
                    continue;
                }
                else if (strcmp("save",b)==0) //SAVE//
                {
                 savedTime = time_spent;
                 saveTheGame(gameSize,Grid,playerTurn,player1,player2,p1Score,p2Score,player1Moves,player2Moves, z,dfsFlag,botFlag, savedTime);
                 savedTime=carrier;
                }
                else if (strcmp("exit",b)==0)
                {
                    //getchar();
                    system("cls");
                    mainMenu();
                    //exit(EXIT_SUCCESS);
                    //EXIT=1;
                    //break;
                }
                }
                //End: Scanning and handling in game options//

                else generateRandomNumber(1,gameSize+1,&r1,&c1,&r2,&c2);
                if (EXIT==1) break;
                if ((c2==c1)&&(abs(r1-r2)==1)&&(Grid[r1+r2-2][c1+c2-2]==' ' && r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)) {
                    player2Moves++;
                    Grid[r1+r2-2][c1+c2-2]='4';
                    moveChecker=4; //UndoRedo

                    if( c1!=1 ){
                    if(Grid[r1+r2-2][c1+c2-4]!=' '&& Grid[r1+r2-3][c1+c2-3]!=' ' && Grid[r1+r2-1][c1+c2-3]!=' ') {
                    Grid[r1+r2-2][c1+c2-3]='7'; // #
                    p2Score++;
                    winChecker1=70; //UndoRedo
                    }
                    }

                    if(c1!=gameSize+1 ){
                    if (Grid[r1+r2-2][c1+c2]!=' '&&  Grid[r1+r2-3][c1+c2-1]!=' ' && Grid[r1+r2-1][c1+c2-1]!=' ') {
                    Grid[r1+r2-2][c1+c2-1]='7'; // #
                    p2Score++;
                    winChecker2=71; //UndoRedo
                    }
                    }


                }
                else if ((r2==r1)&&(abs(c1-c2)==1)&&(Grid[r1+r2-2][c1+c2-2]==' ' && r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)){
                    player2Moves++;
                    Grid[r1+r2-2][c1+c2-2]='5';
                    moveChecker=5; //UndoRedo

                    if( r1!=gameSize+1 ){
                    if(Grid[r1+r2][c1+c2-2]!=' '&&Grid[r1+r2-1][c1+c2-1]!=' ' &&Grid[r1+r2-1][c1+c2-3]!=' '  ){
                    Grid[r1+r2-1][c1+c2-2]='7';
                    p2Score++;
                    winChecker1=72; //UndoRedo
                    }
                    }

                    if(r1!=1 ){
                    if(Grid[r1+r2-4][c1+c2-2]!=' ' &&  Grid[r1+r2-3][c1+c2-1]!=' ' &&Grid[r1+r2-3][c1+c2-3]!=' '  ){
                    Grid[r1+r2-3][c1+c2-2]='7';
                    p2Score++;
                    winChecker2=73; //UndoRedo
                    }
                    }

                }
                else
                {
                    system( "cls" );
                    printf("Invalid Value, Please Enter Again\n");
                    continue;
                }
                if(p2Score>t) {
                        z--;
                        if (dfsFlag==1) chainOfBoxes(gameSize,Grid,r1,c1,r2,c2,&z,&player2Moves,&p2Score, &currentMove, &lastMove, steps, botFlag, dfsActive, &playerTurn);
                        undoRedo(0, gameSize, Grid, &playerTurn, &p1Score, &p2Score, &player1Moves, &player2Moves, &z , r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps, botFlag, dfsActive);

                        system( "cls" );
                        continue;

                }
                playerTurn=1;
                z--;
                undoRedo(0, gameSize, Grid, &playerTurn, &p1Score, &p2Score, &player1Moves, &player2Moves, &z , r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps, botFlag, dfsActive);

                system( "cls" );
            }


        }

            //the game (while) loop has ended: the final result printing screen
            printf("\n  ");
            for(int i=1;i<=gameSize+1;i++) printf("%d   ",i); //printing the 1st row of numbers to help players choose the dots
            printf("\n");
            int k=1;
            for(int i=0;i<gameSize*2 + 1;i++)
            {
                if (i%2==0)
                {
                    printf("%d ",k);
                    k++;                                 //printing the 1st col of numbers to help players choose the dots
                }
                else printf("  ");
                for(int j=0;j<gameSize*2 + 1;j++)
                    {
                        if ((Grid[i][j]==' ')||(Grid[i][j]=='.')) printf("%c ",Grid[i][j]);
                        else if(Grid[i][j]=='2') printf("\033[0;34m|\033[0m ");
                        else if(Grid[i][j]=='3') printf("\033[0;34m_\033[0m ");
                        else if(Grid[i][j]=='6') printf("\033[0;34m#\033[0m ");
                        else if(Grid[i][j]=='4') printf("\033[0;31m|\033[0m ");
                        else if(Grid[i][j]=='5') printf("\033[0;31m_\033[0m ");
                        else if(Grid[i][j]=='7') printf("\033[0;31m#\033[0m ");
                    }
                printf("\n");
            }
            printf("\n");
        if(p1Score>p2Score)
        {
            printf("\033[0;34m%s wins\033[0m \n",player1);
            rankWrite (player1, p1Score, player1Moves, gameSize);   //send player1Name, p1score, player1moves, gamesize to be written into the file AND display his rank after adding him to the list

        }
        else if(p2Score>p1Score)
        {
            printf("\033[0;31m%s wins\033[0m \n",player2);
            rankWrite (player2, p2Score, player2Moves, gameSize);   //send player1Name, p1score, player1moves, gamesize to be written into the file AND display his rank after adding him to the list
        }
        else   printf("Draw\n");

        char answer[4];
        while(1)//strcmp(answer,"yes")!=0 && strcmp(answer,"Yes")!=0 && strcmp(answer,"no")!=0 && strcmp(answer,"No")!=0)
        {
            printf("Do you want to go to main menu (yes/no)?\n");
            scanf("%s",answer);
            if (strcmp(answer,"yes")==0 || strcmp(answer,"Yes")==0 || strcmp(answer,"Y")==0 || strcmp(answer,"y")==0) {getchar(); system("cls"); mainMenu();}
            else if (strcmp(answer,"no")==0||strcmp(answer,"No")==0  || strcmp(answer,"N")==0 || strcmp(answer,"n")==0) exit(0);
            system("cls");
            //printf("Please enter (y/n)\n");
        }
}



#endif
