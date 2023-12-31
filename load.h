#ifndef LOAD_H
#define LOAD_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void loadTheGame() {
    FILE *fb;
    char saveSlot = '1',x;
    int k=0;
    do{
            k++;
    do {
         system("cls");
         if(k>1){
                printf("There is no saved game in this saving slot\nDo you want to return to main menu?\n");
                x=' ';
                while(x!='y'&&x!='Y'&&x!='n'&&x!='N'){
                printf("Please Enter(y/n):");
                scanf("%c", &x);
                //getchar();

            }
            }
                if (x == 'y'||x=='Y'||saveSlot=='r'||saveSlot=='R') {
                    break;
                }
         system("cls");
        if ((saveSlot - '0' > 3 || saveSlot - '0' <= 0)&&saveSlot!='r'&&saveSlot!='R') {
            printf("Invalid Value\n");
        }
        printf("Choose save slot from 1 to 3 (press r to return to main menu)\n");
        scanf("%c", &saveSlot);
        getchar(); // consume the newline character
    } while ((saveSlot - '0' > 3 || saveSlot - '0' <= 0)&&saveSlot!='r'&&saveSlot!='R');

    if (saveSlot == '1') {
        fb = fopen("saveSlot1.bin", "rb");
    } else if (saveSlot == '2') {
        fb = fopen("saveSlot2.bin", "rb");
    } else if (saveSlot == '3') {
        fb = fopen("saveSlot3.bin", "rb");
    }
    if (x == 'y'||x=='Y'||saveSlot=='r'||saveSlot=='R'){
            break;
    }
    }
    while(fb==NULL);
    if(x!='y'&&x!='Y'&&saveSlot!='r'&&saveSlot!='R'){
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
system("cls");
}


#endif
