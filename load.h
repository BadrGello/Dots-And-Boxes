#ifndef LOAD_H
#define LOAD_H

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void loadTheGame() {
    FILE *fb; //make file pointer
    char saveSlot = '1';
    int k=0;
    do{
            k++;
    do {
         system("cls");
         if(k>1){ //if k>1 that means that the function looped one time at least
                printf("There is no saved game in this saving slot please try again\n");
            }
                if (saveSlot=='r'||saveSlot=='R') { //thats mean the user wnt to return to main menu
                    break;
                }
        if ((saveSlot - '0' > 3 || saveSlot - '0' <= 0)&&saveSlot!='r'&&saveSlot!='R') {
            printf("Invalid Value\n");
        }
        printf("Choose save slot from 1 to 3 (press r to return to main menu)\n");
        scanf("%c", &saveSlot);
        getchar(); // consume the newline character
    } while ((saveSlot - '0' > 3 || saveSlot - '0' <= 0)&&saveSlot!='r'&&saveSlot!='R');

    if (saveSlot == '1') {
        fb = fopen("saveSlot1.bin", "rb");  //open the file named saveSlot1.bin
    } else if (saveSlot == '2') {
        fb = fopen("saveSlot2.bin", "rb"); //open the file named saveSlot2.bin
    } else if (saveSlot == '3') {
        fb = fopen("saveSlot3.bin", "rb"); //open the file named saveSlot3.bin
    }
    if (saveSlot=='r'||saveSlot=='R'){
            break;
    }
    }
    while(fb==NULL); //if fb = NULL thats mean there is no file in the choosen save slot
    if(saveSlot!='r'&&saveSlot!='R'){
    char *pb,numericalGameData[100];
    fread(numericalGameData,sizeof(char),100,fb); //returning all numerical data in string then seprate them all in its place
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
    //get all the grid from the file
    for (i = 0; i <= 2 * gameSize; i++) {
        fread(arr[i], sizeof(char), 2 * gameSize + 1, fb);
    }
    char player1[256], player2[256],p1Color[20],p2Color[20];
    fread(player1, sizeof(char), 256, fb);
    fread(player2, sizeof(char), 256, fb);
    fread(p1Color, sizeof(char), 20, fb);
    fread(p2Color, sizeof(char), 20, fb);
    fclose(fb);
    system("cls");
    activeplayGround(gameSize,arr,player1,player2,dfsFlag,botFlag,playerTurn,p1Score,p2Score,player1moves,player2moves,z,savedTime,p1Color,p2Color);

}
system("cls");
}


#endif
