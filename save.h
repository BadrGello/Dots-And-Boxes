#ifndef SAVE_H
#define SAVE_H

#include<stdio.h>
#include<stdlib.h>

void saveTheGame(int gameSize, char arr[2 * gameSize + 1][2 * gameSize + 1], int playerTurn, char player1[256], char player2[256], int p1Score, int p2Score, int player1Moves, int player2Moves, int z, int dfsFlag, int botFlag, int savedTime,char p1Color[20],char p2Color[20]) {
    FILE *fb, *fb2; //fb2 pointer to know if the file opned before or no
    char saveSlot = '1', x;
    int k = 0;

    do {
        k++;
        do {
            system("cls");
            if (k > 1) {//if k>1 thats mean the loop looped one time at least
                printf("There is a saved game in this slot. Do you want to overwrite it?\n");
                x=' '; //return x to its deafult
                while(x!='y'&&x!='Y'&&x!='n'&&x!='N'){ //y means over write it no means not

                printf("Please Enter (y/n):");
                getchar();
                scanf("%c", &x);

            }
             if (x == 'y'||x=='Y'||saveSlot=='r'||saveSlot=='R') {
                    break;
                }
            }
             system("cls");
            if ((saveSlot - '0' > 3 || saveSlot - '0' <= 0)&&saveSlot!='r'&&saveSlot!='R') {
                printf("Invalid Value\n");
            }

            printf("Choose save slot from 1 to 3 (press r to return to the game)\n");
            scanf(" %c", &saveSlot);
        } while ((saveSlot - '0' > 3 || saveSlot - '0' <= 0)&&saveSlot!='r'&&saveSlot!='R');

        if (saveSlot == '1') {
            fb2 = fopen("saveSlot1.bin", "rb"); //rb if there is no file return null but w+ create a one
            fb = fopen("saveSlot1.bin", "w+");
        } else if (saveSlot == '2') {
            fb2 = fopen("saveSlot2.bin", "rb");
            fb = fopen("saveSlot2.bin", "w+");
        } else if (saveSlot == '3') {
            fb2 = fopen("saveSlot3.bin", "rb");
            fb = fopen("saveSlot3.bin", "w+");
        }
          if (x == 'y'||x=='Y'||saveSlot=='r'||saveSlot=='R') {
                    break;
                }
    } while (fb2 != NULL&&saveSlot!='r'&&saveSlot!='R');
    if(saveSlot!='r'&&saveSlot!='R'){
    char numericalGameData[100];
    sprintf(numericalGameData, "%d,%d,%d,%d,%d,%d,%d,%d,%d,%d.",
            gameSize, playerTurn, dfsFlag, botFlag, savedTime, p1Score, p2Score, player1Moves, player2Moves, z); //get all numerical data in one string
    fwrite(numericalGameData, sizeof(char), 100, fb); //write it in the file
 //write the all grid in the file
    for (int i = 0; i <= 2 * gameSize; i++) {
        fwrite(arr[i], sizeof(char), 2 * gameSize + 1, fb);
    }

    fwrite(player1, sizeof(char), 256, fb);//write player1 name in the file
    fwrite(player2, sizeof(char), 256, fb);//write player2 name in the file
    fwrite(p1Color, sizeof(char), 20, fb);//write player1 color in the file
    fwrite(p2Color, sizeof(char), 20, fb);//write player2 color in the file

    fclose(fb);
    fclose(fb2);
}
}


#endif
