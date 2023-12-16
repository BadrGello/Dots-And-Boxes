//test
#include <stdio.h>
#include <stdlib.h>
void playGround(int gameSize)
{
int i,j;
char Arr[2*gameSize+1][2*gameSize+1];
for (i=0;i<=2*gameSize;i++){
for (j=0;j<=2*gameSize;j++){
if(i%2==0&&j%2==0) Arr[i][j]='.';
else Arr[i][j]=' ';
}
}

    void activeplayGround(char Arr[gameSize*2 + 1][gameSize*2 + 1], int gameSize)
    {
        char player1[256],player2[256];
        int r1,c1,r2,c2,x=0,y=0,z=2*gameSize*(gameSize+1);
        int playerTurn=1; //1 or 2 or 0(BOT)[Acts as player 2]
        printf("\033[0;34mplayer1 enter your name:\033[0m ");
        scanf("%s",player1);
         system("cls");
         printf("\033[0;31mplayer2 enter your name:\033[0m ");
         scanf("%s",player2);
         system("cls");
        while(r1!=-1&&z>0)
        {
            //printing the score
            printf(" \033[0;34m%s's score :%d\033[0m \n",player1,x);
            printf(" \033[0;31m%s's score :%d\033[0m \n",player2,y);
            printf("remaining moves:%d\n",z);
            int l=x,t=y;
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
                else printf("  ");
                for(int j=0;j<gameSize*2 + 1;j++)
                    {
                        if ((Arr[i][j]==' ')||(Arr[i][j]=='.')) printf("%c ",Arr[i][j]);
                        else if(Arr[i][j]=='2') printf("\033[0;34m|\033[0m ");
                        else if(Arr[i][j]=='3') printf("\033[0;34m_\033[0m ");
                        else if(Arr[i][j]=='6') printf("\033[0;34m#\033[0m ");
                        else if(Arr[i][j]=='4') printf("\033[0;31m|\033[0m ");
                        else if(Arr[i][j]=='5') printf("\033[0;31m_\033[0m ");
                        else if(Arr[i][j]=='7') printf("\033[0;31m#\033[0m ");
                    }
                printf("\n");
            }
            printf("\n");

            //Taking the coordinates of the dots

            if(playerTurn==1)
            {
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                if (r1==-1) break;
                if ((c2==c1)&&(abs(r1-r2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' '&&r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)){
                    Arr[r1+r2-2][c1+c2-2]='2'; // |
                    if(c1!=1){
                    if(Arr[r1+r2-2][c1+c2-4]!=' ' && Arr[r1+r2-3][c1+c2-3]!=' ' && Arr[r1+r2-1][c1+c2-3]!=' ') {
                    Arr[r1+r2-2][c1+c2-3]='6'; // #
                    x++;
                    }
                    }
                    if(c1!=gameSize+1){
                    if (Arr[r1+r2-2][c1+c2]!=' '&& Arr[r1+r2-3][c1+c2-1]!=' ' && Arr[r1+r2-1][c1+c2-1]!=' ') {
                       Arr[r1+r2-2][c1+c2-1]='6'; // #
                       x++;
                    }
                }
                }
                else if ((r2==r1)&&(abs(c1-c2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' '&&r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)){
                     Arr[r1+r2-2][c1+c2-2]='3'; // -
                     if(r1!=gameSize+1){
                     if(Arr[r1+r2][c1+c2-2]!=' '  && Arr[r1+r2-1][c1+c2-1]!=' ' &&Arr[r1+r2-1][c1+c2-3]!=' '  ){
                     Arr[r1+r2-1][c1+c2-2]='6';
                     x++;
                     }
                     }
                     if(r1!=1){
                     if(Arr[r1+r2-4][c1+c2-2]!=' ' && Arr[r1+r2-3][c1+c2-1]!=' ' &&Arr[r1+r2-3][c1+c2-3]!=' '  ){
                     Arr[r1+r2-3][c1+c2-2]='6';
                     x++;
                     }
                }
                }
                else
                {
                    system( "cls" );
                    printf("Invalid Value, Please Enter Again\n");
                    continue;
                }
                if(x>l) {
                         system( "cls" );
                        z--;
                        continue;

                }

                //Some else and if's to handle that if the current player completed a box the playerTurn is 1 again
                //if ()playerTurn=1;
                //else playerTurn=2;
                playerTurn=2;
                z--;
                 system( "cls" );
            }

            else if(playerTurn==2)
            {
                scanf("%d %d %d %d",&r1,&c1,&r2,&c2);
                if (r1==-1) break;
                if ((c2==c1)&&(abs(r1-r2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' '&&r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)) {
                    Arr[r1+r2-2][c1+c2-2]='4';
                    if( c1!=1 ){
                    if(Arr[r1+r2-2][c1+c2-4]!=' '&& Arr[r1+r2-3][c1+c2-3]!=' ' && Arr[r1+r2-1][c1+c2-3]!=' ') {
                    Arr[r1+r2-2][c1+c2-3]='7'; // #
                    y++;
                    }
                    }
                    if(c1!=gameSize+1 ){
                    if (Arr[r1+r2-2][c1+c2]!=' '&&  Arr[r1+r2-3][c1+c2-1]!=' ' && Arr[r1+r2-1][c1+c2-1]!=' ') {
                       Arr[r1+r2-2][c1+c2-1]='7'; // #
                       y++;
                    }
                    }
                }
                else if ((r2==r1)&&(abs(c1-c2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' '&&r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)){
                    Arr[r1+r2-2][c1+c2-2]='5';
                    if( r1!=gameSize+1 ){
                    if(Arr[r1+r2][c1+c2-2]!=' '&&Arr[r1+r2-1][c1+c2-1]!=' ' &&Arr[r1+r2-1][c1+c2-3]!=' '  ){
                     Arr[r1+r2-1][c1+c2-2]='7';
                     y++;
                     }
                    }
                    if(r1!=1 ){
                     if(Arr[r1+r2-4][c1+c2-2]!=' ' &&  Arr[r1+r2-3][c1+c2-1]!=' ' &&Arr[r1+r2-3][c1+c2-3]!=' '  ){
                     Arr[r1+r2-3][c1+c2-2]='7';
                     y++;
                     }
                    }
                }
                else
                {
                    system( "cls" );
                    printf("Invalid Value, Please Enter Again\n");

                    continue;
                }
                if(y>t) {
                        z--;
                        system( "cls" );
                        continue;

                }
                playerTurn=1;
                z--;
                            system( "cls" );
            }

            else if(playerTurn==0)
            {

            }




        }
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
                else printf("  ");
                for(int j=0;j<gameSize*2 + 1;j++)
                    {
                        if ((Arr[i][j]==' ')||(Arr[i][j]=='.')) printf("%c ",Arr[i][j]);
                        else if(Arr[i][j]=='2') printf("\033[0;34m|\033[0m ");
                        else if(Arr[i][j]=='3') printf("\033[0;34m_\033[0m ");
                        else if(Arr[i][j]=='6') printf("\033[0;34m#\033[0m ");
                        else if(Arr[i][j]=='4') printf("\033[0;31m|\033[0m ");
                        else if(Arr[i][j]=='5') printf("\033[0;31m_\033[0m ");
                        else if(Arr[i][j]=='7') printf("\033[0;31m#\033[0m ");
                    }
                printf("\n");
            }
            printf("\n");
 if(x>y) printf("\033[0;34m%s wins\033[0m ",player1);
 else if(y>x) printf("\033[0;31m%s wins\033[0m ",player2);
 else   printf("Draw");
    }
    //if (gameSize==2) activeplayGround(G2,gameSize);
 activeplayGround(Arr,gameSize);
    //if (gameSize==4) activeplayGround(G4,gameSize);
    //if (gameSize==5) activeplayGround(G5,gameSize);
}


int main()
{
    playGround(3);

}
