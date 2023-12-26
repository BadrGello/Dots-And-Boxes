#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void loadTheGame() {
    FILE *fb;
    char saveSlot = '1';
    do {
        system("cls");
        if (saveSlot - '0' > 3 || saveSlot - '0' <= 0) {
            printf("invalid value");
        }
        printf("choose saveslot from 1 to 3\n");
        scanf("%c", &saveSlot);
        getchar(); // consume the newline character
    } while (saveSlot - '0' > 3 || saveSlot - '0' <= 0);

    if (saveSlot == '1') {
        fb = fopen("saveSlot1.bin", "rb");
    } else if (saveSlot == '2') {
        fb = fopen("saveSlot2.bin", "rb");
    } else if (saveSlot == '3') {
        fb = fopen("saveSlot3.bin", "rb");
    }
    char *pb,numericalGameData[100];
    fread(numericalGameData,sizeof(char),100,fb);
    pb=strtok(numericalGameData,",");
    int gameSize=pb[0]-'0';
    pb=strtok(NULL,",");
    int playerTurn=pb[0]-'0';
    pb=strtok(NULL,",");
    int dfsFlag=pb[0]-'0';
    pb=strtok(NULL,",");
    int botFlag=pb[0]-'0';
    pb=strtok(NULL,",");
    int savedTime=atoi(pb);
    pb=strtok(NULL,",");
    int p1Score=atoi(pb);
    pb=strtok(NULL,",");
    int p2Score=atoi(pb);
    pb=strtok(NULL,",");
    int player1moves=atoi(pb);
    pb=strtok(NULL,",");
    int player2moves=atoi(pb);
    pb=strtok(NULL,".");
    int z=atoi(pb);
    char arr[2 * gameSize + 1][2 * gameSize + 1];
    int i,j;
    for (i = 0; i <= 2 * gameSize; i++) {
        fread(arr[i], sizeof(char), 2 * gameSize + 1, fb);
    }
    char player1[256], player2[256];
    fread(player1, sizeof(char), 256, fb);
    fread(player2, sizeof(char), 256, fb);
    fclose(fb);
     system("cls");

    activeplayGround(gameSize,arr,player1,player2,dfsFlag,botFlag,playerTurn,p1Score,p2Score,player1moves,player2moves,z,savedTime);

}
