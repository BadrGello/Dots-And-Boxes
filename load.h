#include <stdio.h>
#include <stdlib.h>

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

    int gameSize;
    fread(&gameSize, sizeof(int), 1, fb);
    char arr[2 * gameSize + 1][2 * gameSize + 1];
    int i;
    for (i = 0; i <= 2 * gameSize; i++) {
        fread(arr[i], sizeof(char), 2 * gameSize + 1, fb);
    }

    int playerTurn, p1Score, p2Score, player1Moves, player2Moves, z;
    char player1[256], player2[256],numericalGameData[100];
    fread(player1, sizeof(char), 256, fb);
    fread(player2, sizeof(char), 256, fb);
    fread(numericalGameData,sizeof(char),100,fb);
    fclose(fb);
    printf("%s", numericalGameData);
}
