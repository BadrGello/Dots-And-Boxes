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
    char *pgameSize,*pplayerTurn,*pp1Score,*pp2Score,*pplayer1moves,*pplayer2moves,*pz,*pbotflag,*pdfsflag,numericalGameData[100];
    fread(numericalGameData,sizeof(char),100,fb);
    pgameSize=strtok(numericalGameData,",");
    pplayerTurn=strtok(NULL,",");
    pdfsflag=strtok(NULL,",");
    pbotflag=strtok(NULL,",");
    pp1Score=strtok(NULL,",");
    pp2Score=strtok(NULL,",");
    pplayer1moves=strtok(NULL,",");
    pplayer2moves=strtok(NULL,",");
    pz=strtok(NULL,".");
    int gameSize=pgameSize[0]-'0';
    int playerTurn=pplayerTurn[0]-'0';
    int dfsFlag=pdfsflag[0]-'0';
    int botFlag=pbotflag[0]-'0';
    int p1Score=atoi(pp1Score);
    int p2Score=atoi(pp2Score);
    int player1moves=atoi(pplayer1moves);
    int player2moves=atoi(pplayer2moves);
    int z=atoi(pz);
    char arr[2 * gameSize + 1][2 * gameSize + 1];
    int i,j;
    for (i = 0; i <= 2 * gameSize; i++) {
        fread(arr[i], sizeof(char), 2 * gameSize + 1, fb);
    }
    char player1[256], player2[256];
    fread(player1, sizeof(char), 256, fb);
    fread(player2, sizeof(char), 256, fb);
    fclose(fb);


    activeplayGround(gameSize,arr,player1,player2,dfsFlag,botFlag,playerTurn,p1Score,p2Score,player1moves,player2moves,z);

}
