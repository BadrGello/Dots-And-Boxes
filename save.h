#include<stdio.h>
#include<stdlib.h>
void saveTheGame(int gameSize,char arr[2*gameSize+1][2*gameSize+1],int playerTurn,char player1[256],char player2[256],int p1Score,int p2Score,int player1Moves,int player2Moves,int z){
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
        fb=fopen("saveSlot1.bin","rb+");
    }
    else if(saveSlot=='2'){
         fb=fopen("saveSlot2.bin","rb+");
    }
    else if(saveSlot=='3'){
         fb=fopen("saveSlot3.bin","rb+");
    }
    fwrite(&gameSize,sizeof(int),1,fb);
    int i;
    for(i=0;i<=2*gameSize;i++){
        fwrite(arr[i],sizeof(char),2*gameSize+1,fb);
    }
    fwrite(&playerTurn,sizeof(int),1,fb);
    fwrite(player1,sizeof(char),256,fb);
    fwrite(player2,sizeof(char),256,fb);
    fwrite(&p1Score,sizeof(int),1,fb);
    fwrite(&p2Score,sizeof(int),1,fb);
    fwrite(&player1Moves,sizeof(int),1,fb);
    fwrite(&player2Moves,sizeof(int),1,fb);
    fwrite(&z,sizeof(int),1,fb);
    fclose(fb);
}