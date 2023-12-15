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
        while(r1!=-1)
        {
            for(int i=0;i<gameSize*2 + 1;i++)
            {
                for(int j=0;j<gameSize*2 + 1;j++)
                    {
                        printf("%c ",Arr[i][j]);
                    }
                printf("\n");
            }

            scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
            if (r1==-1) break;
            if ((c2==c1)&&(abs(r1-r2)==1)) Arr[r1+r2-2][c1+c2-2]='|';
            else if ((r2==r1)&&(abs(c1-c2)==1)) Arr[r1+r2-2][c1+c2-2]='-';
            else{
                printf("Invalid Value, Please Enter Again\n");
                continue;
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
