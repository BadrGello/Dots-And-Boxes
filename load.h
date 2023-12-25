#include<stdio.h>
#include<stdio.h>
#include"playGround.h"
void loadTheGame(){
   FILE *fb;
     char saveSlot='1';
    do
    {
    system("cls");
    if(saveSlot-'0'>3 ||saveSlot-'0'<=0) {
    printf("invalid value");
    }
     printf("choose saveslot from 1 to 3\n");
    scanf("%c",&saveSlot);
    } while ( saveSlot-'0'>3 ||saveSlot-'0'<=0);
    if(saveSlot=='1'){
        fb=fopen("saveSlot1.bin","rb");
    }
    else if(saveSlot=='2'){
         fb=fopen("saveSlot2.bin","rb");
    }
    else if(saveSlot=='3'){
         fb=fopen("saveSlot3.bin","rb");
    } 
      int gameSize;
     fread(&gameSize,sizeof(int),1,fb);
     char arr[2*gameSize+1][2*gameSize+1];
     int i;
    for(i=0;i<=2*gameSize;i++){
        fread((*arr)+i,sizeof(char),2*gameSize+1,fb);
    }
    int playerTurn,p1Score,p2Score,player1Moves,player2Moves,z;
    char player1[256],player2[256];
    fread(&playerTurn,sizeof(int),1,fb);
    fread(player1,sizeof(char),256,fb);
    fread(player2,sizeof(char),256,fb);
    fread(&p1Score,sizeof(int),1,fb);
    fread(&p2Score,sizeof(int),1,fb);
    fread(&player1Moves,sizeof(int),1,fb);
    fread(&player2Moves,sizeof(int),1,fb);
    fread(&z,sizeof(int),1,fb);
    fclose(fb);
    activeplayGround( arr[gameSize*2 + 1][gameSize*2 + 1], gameSize, 0, 0);
}