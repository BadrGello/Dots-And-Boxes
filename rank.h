#ifndef RANK_H
#define RANK_H

#include <stdio.h>
#include <sys/stat.h>
#define FILENAME "user_rank.bin"
#define MAX_USERS 10

typedef struct
{

    char playerName[256];
    int score;
    int moves;
    int gameSize;

} rankStruct;

//rankStruct Rank[10];

void bubbleSortDes (rankStruct arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].score < arr[j + 1].score)
            {
                // Swap the elements if they are in the wrong order
                rankStruct temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void rankWrite(char playerName[256], int score, int moves, int gameSize)
{
    FILE *file = fopen(FILENAME, "a+"); //opening the file for both reading and appending

    if (file==NULL)
    {
        //fprintf(stderr, "Error opening file.\n");
        printf("Error opening file.\n");
        return 1;
    }

    int numUsers=0;
    rankStruct Rank[MAX_USERS];


    rankStruct Player;

    strcpy(Player.playerName, playerName);
    Player.score=score;
    Player.moves=moves;
    Player.gameSize=gameSize;

    //Read existing users from file
    while (fscanf(file, "%s %d %d %d\n", Rank[numUsers].playerName, &Rank[numUsers].score, &Rank[numUsers].moves, &Rank[numUsers].gameSize) == 4)
    {
        numUsers++;
    }

    int playerExistsAt=-1;
    int playerAdded=-1;

    //Check if the player already exists
    for (int i=0; i<numUsers; i++) //++i
    {
        //strcasecmp
        if (strcmp(Rank[i].playerName, playerName)==0)
        {
            playerExistsAt=i;
            break;
        }
    }

    if (playerExistsAt==-1)
    {
        //Player not found, add to the list
        if (numUsers < MAX_USERS)
        {
            //Array has space, add the player
            Rank[numUsers]=Player;

            /*.playerName , playerName
            Rank[numUsers].score=score;
            Rank[numUsers].moves=moves;
            Rank[numUsers].gameSize=gameSize;*/

            numUsers++;
            playerAdded=1;

            printf("New Player Added To LeaderBoard\n");

        }
        else if (score > Rank[9].score)
        {
            Rank[9]=Player;
            /*Rank[9].score=score;
            Rank[9].moves=moves;
            Rank[9].gameSize=gameSize;*/

            playerAdded=1;
            printf("New Player Added To LeaderBoard\n");

        }
        //else player isn't added
        else
        {
            printf("Player Not Added, Player Lower Than Top 10\n");
        }
    }
    else //player already exists in the list
    {
        if (score > Rank[playerExistsAt].score)
        {
            Rank[playerExistsAt].score=score;
            Rank[playerExistsAt].moves=moves;
            Rank[playerExistsAt].gameSize=gameSize;
            printf("Player Score Updated\n");
        }


    }

    //sorting stage
    bubbleSortDes (Rank, numUsers);

    fclose(file);
    file = fopen(FILENAME, "w");
    for (int i=0;i<numUsers;i++)  //write array back to file
    {
        fprintf(file, "%s %d %d %d\n", Rank[i].playerName, Rank[i].score, Rank[i].moves, Rank[i].gameSize);
    }
    fclose(file);

    int rank_i=-1;
    for (int i=0;i<10;i++)
    {
        if (strcmp(playerName, Rank[i].playerName)==0) rank_i=i+1;
    }
    printf("Player's Rank: %d\n", rank_i);




}

void rankPrint()
{
    FILE *file = fopen(FILENAME, "r");

    int numUsers = 0;
    rankStruct Rank[MAX_USERS];
    while (fscanf(file, "%s %d %d %d\n", Rank[numUsers].playerName, &Rank[numUsers].score, &Rank[numUsers].moves, &Rank[numUsers].gameSize) == 4)
    {
        numUsers++;
        //printf("numUsers %d\n", numUsers);
    }
    fclose(file);
    if (numUsers>0)
    {
        printf("Return \n\n");
        printf("\033[36;1mTop 10 Players\033[0m\n\n");

        /*printf("Rank   Player   Score   Moves   GameSize\n");
        for (int i=0;i<numUsers;i++)
        {
            printf("%d     %s     %d     %d     %d\n",i+1 ,Rank[i].playerName, Rank[i].score, Rank[i].moves, Rank[i].gameSize);
        }*/

        printf("Rank   %-10s   %-6s   %-6s   %-8s\n\n", "Player", "Score", "Moves", "GameSize");
        for (int i = 0; i <numUsers; i++)
        {
            printf("%-4d   %-10s   %-6d   %-6d   %-8d\n", i + 1, Rank[i].playerName, Rank[i].score, Rank[i].moves, Rank[i].gameSize);
        }

        char x[10];
        while (1)
        {
            readLine(x,10);
            if (strcmp("return",x)==0 || strcmp("r",x)==0)
            {
                system("cls");
                return;
            }
        }
        system("cls");

    }
    else printf("Leaderboard Is Empty\n");




}

#endif
