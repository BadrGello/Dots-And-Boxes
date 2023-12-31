#ifndef MAINMENU_H
#define MAINMENU_H

#include "readLine.h"
#include "playGround.h"
#include "load.h"
#include "rank.h"

void mainMenu(){
    int gameSize;
    char menu[100];
    while (1) //strcmp compares 2 strings and returns 0 if the 2 strings are equal
    {
        int option=0; int botFlag=0; int dfsFlag=0;

        printf("Start Game\nLoad Game\nLeaderboard\nExit\n");
        readLine(menu,100); //readLine function do as follows: 1)Skips all leading whitespaces 2)replaces extra whitespaces between words with just 1 space 3)turns any uppercase character to lowercase
        if (strcmp("start game",menu)==0 || strcmp("start",menu)==0 || strcmp("s",menu)==0 || strcmp("sg",menu)==0 || strcmp("1",menu)==0) //setting different variations of the expected input
        {
            option=1;
            system("cls");
        }
        else if (strcmp("load game",menu)==0 || strcmp("load",menu)==0 || strcmp("lg",menu)==0 || strcmp("2",menu)==0)
        {
            option=2;
            system("cls");
        }
        else if (strcmp("leaderboard",menu)==0 || strcmp("leader",menu)==0 || strcmp("board",menu)==0 || strcmp("lb",menu)==0 || strcmp("3",menu)==0)
        {
            option=3;
            system("cls");
        }
        else if ( strcmp("exit",menu)==0 || strcmp("e",menu)==0 || strcmp("4",menu)==0 )
        {
            exit(0);
        }
        else
        {
            system("cls");
            printf("Invalid option. Please try again.\n");
        }

        //**********//
        //Start Game//
        //**********//

        if (option==1)
        {
            while(1){
            printf("1 vs 1\n1 vs BOT\nReturn\n");
            readLine(menu,100);
            int start=0;
            if (strcmp("1 vs 1",menu)==0 || strcmp("1vs1",menu)==0 || strcmp("1",menu)==0 || strcmp("one vs one",menu)==0 || strcmp("onevsone",menu)==0) {botFlag=0;start=1;};
            if (strcmp("1 vs bot",menu)==0 || strcmp("1vsbot",menu)==0 || strcmp("bot",menu)==0 || strcmp("2",menu)==0 || strcmp("one vs bot",menu)==0 || strcmp("onevsbot",menu)==0) {botFlag=1;start=1;};
            if (start==1)
            {
                system("cls");
                while(1){
                printf("Enter The Game Size (1 Digit) From 2 up to 8 [3*3 Dots up to 9*9 Dots]\nReturn\n");
                readLine(menu,100);
                for(int i=2;i<=8;i++)
                {
                    if(menu[0]-'0'==i)
                    {
                        system("cls");
                        while (1){
                        printf("Do you want DFS enabled?\nYes or No\n"); //asks the player if they want DFS
                        readLine(menu,100);
                        if (strcmp(menu,"yes")==0 || strcmp(menu,"y")==0) {dfsFlag=1; system("cls"); break;} //if Yes dfs=1
                        else if (strcmp(menu,"no")==0 || strcmp(menu,"n")==0) {dfsFlag=0; system("cls"); break;} //if no dfs=0
                        else
                        {
                            system("cls");
                            printf("Invalid option. Please try again.\n");
                        }
                        }
                        gameSize=i;
                        playGround(gameSize,dfsFlag,botFlag);
                        exit(0);
                    }
                }
                if (strcmp("return",menu)==0 || strcmp("r",menu)==0)
                {
                    system("cls");
                    break;
                }
                else
                {
                    system("cls");
                    printf("Invalid option. Please try again.\n");
                }
                }
            }
           /* else if (strcmp("1 vs bot",menu)==0 || strcmp("1vsbot",menu)==0 || strcmp("bot",menu)==0 || strcmp("2",menu)==0 || strcmp("one vs bot",menu)==0 || strcmp("onevsbot",menu)==0)
            {
             /////////////////BOT AI
            }*/
            else if (strcmp("return",menu)==0 || strcmp("r",menu)==0 || strcmp("3",menu)==0)
            {
                system("cls");
                break;
            }
            else
            {
                system("cls");
                printf("Invalid option. Please try again.\n");
            }
            }
        }

        //*********//
        //Load Game//
        //*********//
        if (option==2)
        {
            loadTheGame();
        }

        //***********//
        //LeaderBoard//
        //***********//

        if (option==3)
        {
            rankPrint();
        }
    }
}


#endif
