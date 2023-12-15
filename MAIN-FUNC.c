//test
#include <stdio.h>
#include <stdlib.h>

void playGround(int gameSize)
{
    //char G2[5][5]
    char G3[7][7]= {{'.' , ' ' , '.' , ' ' , '.' , ' ' , '.'}, //3*3 therefor 4*4 dots: n=4 (3*2+1=7)
                    {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '},
                    {'.' , ' ' , '.' , ' ' , '.' , ' ' , '.'},
                    {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '},
                    {'.' , ' ' , '.' , ' ' , '.' , ' ' , '.'},
                    {' ' , ' ' , ' ' , ' ' , ' ' , ' ' , ' '},
                    {'.' , ' ' , '.' , ' ' , '.' , ' ' , '.'}};
    //char G4[9][9]
    //char G5[11][11]

    void activeplayGround(char Arr[gameSize*2 + 1][gameSize*2 + 1], int gameSize)
    {
        int r1,c1,r2,c2;
        int playerTurn=1; //1 or 2 or 0(BOT)[Acts as player 2]
        while(r1!=-1)
        {
            //Printing The Grid
            printf("\n");
            if (gameSize==2)printf("  1   2   3 \n");
            if (gameSize==3)printf("  1   2   3   4\n");
            if (gameSize==4)printf("  1   2   3   4   5\n");
            if (gameSize==5)printf("  1   2   3   4   5   6\n");

            int k=1; //to print the indecies
            for(int i=0;i<gameSize*2 + 1;i++)
            {
                if (i%2==0)
                {
                    printf("%d ",k);
                    k++;
                }
                for(int j=0;j<gameSize*2 + 1;j++)
                    {
                        if ((Arr[i][j]==' ')||(Arr[i][j]=='.')) printf("%c ",Arr[i][j]);
                        else if(Arr[i][j]=='2') printf("  \033[0;34m|\033[0m ");
                        else if(Arr[i][j]=='3') printf("\033[0;34m_\033[0m ");
                        else if(Arr[i][j]=='4') printf("  \033[0;31m|\033[0m ");
                        else if(Arr[i][j]=='5') printf("\033[0;31m_\033[0m ");
                    }
                printf("\n");
            }
            printf("\n");

            //Taking the coordinates of the dots

            if(playerTurn==1)
            {
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                if (r1==-1) break;
                if ((c2==c1)&&(abs(r1-r2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' ')) Arr[r1+r2-2][c1+c2-2]='2'; // |
                else if ((r2==r1)&&(abs(c1-c2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' ')) Arr[r1+r2-2][c1+c2-2]='3'; // -
                else
                {
                    printf("Invalid Value, Please Enter Again\n");
                    continue;
                }
                //Some else and if's to handle that if the current player completed a box the playerTurn is 1 again
                //if ()playerTurn=1;
                //else playerTurn=2;
                playerTurn=2;
            }

            else if(playerTurn==2)
            {
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                if (r1==-1) break;
                if ((c2==c1)&&(abs(r1-r2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' ')) Arr[r1+r2-2][c1+c2-2]='4';
                else if ((r2==r1)&&(abs(c1-c2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' ')) Arr[r1+r2-2][c1+c2-2]='5';
                else
                {
                    printf("Invalid Value, Please Enter Again\n");
                    continue;
                }
                playerTurn=1;
            }

            else if(playerTurn==0)
            {

            }




        }
    }
    //if (gameSize==2) activeplayGround(G2,gameSize);
    if (gameSize==3) activeplayGround(G3,gameSize);
    //if (gameSize==4) activeplayGround(G4,gameSize);
    //if (gameSize==5) activeplayGround(G5,gameSize);
}


int main()
{
    playGround(3);

}
