
#include "secMenu.h"
void playGround(int gameSize, int dfsFlag, int botFlag) //dfs and bot markers, if = 1, it's enabled
{
    int i,j,player1Moves=0,player2Moves=0;
    char Arr[2*gameSize+1][2*gameSize+1],a[256],b[4]; //
    //The following is initializing the gird with the given gameSize
    for (i=0;i<=2*gameSize;i++){
        for (j=0;j<=2*gameSize;j++){
        if(i%2==0&&j%2==0) Arr[i][j]='.';
        else Arr[i][j]=' ';
        }
    }

    void activeplayGround(char Arr[gameSize*2 + 1][gameSize*2 + 1], int gameSize, int dfsFlag, int botFlag)
    {
        char player1[256],player2[256];   //holds the players names
        int r1,c1,r2,c2,p1Score=0,p2Score=0,z=2*gameSize*(gameSize+1); //z is the remaining moves
        int playerTurn=1; //1 or 2 or 0(BOT)[Acts as player 2]

        printf("\033[0;34mplayer1 enter your name:\033[0m "); //player 1 is blue
        scanf("%s",player1);
        system("cls");
        printf("\033[0;31mplayer2 enter your name:\033[0m "); //player 2 is red
        scanf("%s",player2);
        system("cls");

        clock_t begin = clock();
        int time_spent=0,t=0;

        while(r1!=-1&& z>0) //r1 currently is the EXIT option, if inputted -1 the game will end
        {
            //printing the time
            printf("time spent %d:%d\n",t,time_spent);
            //printing the score
            printf(" \033[0;34m%s's score :%d\033[0m           ",player1,p1Score);
            printf(" \033[0;31m%s's score :%d\033[0m \n",player2,p2Score);
            printf(" \033[0;34m%s played :%d moves\033[0m      ",player1,player1Moves);
            printf(" \033[0;31m%s played :%d moves\033[0m \n",player2,player2Moves);
            printf("remaining moves:%d\n",z);
            int l=p1Score,t=p2Score;
            //Printing The Grid
            printf("\n  ");
            for(int i=1;i<=gameSize+1;i++) printf("%d   ",i); //printing the 1st row of numbers to help players choose the dots
            printf("\n");

            int k=1; //to print the indecies
            for(int i=0;i<gameSize*2 + 1;i++)
            {
                if (i%2==0)
                {
                    printf("%d ",k);     //printing the 1st col of numbers to help players choose the dots
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

            //***************************************************************************************************//
            //Taking the coordinates of the dots, determining the score and the player turns. [scanning the grid]//
            //***************************************************************************************************//

            if(playerTurn==1)
            {
                printf(" \033[0;34m%s's turn : \033[0m",player1);
                int i=0;
                for(i=0;i<4;i++){
                scanf(" %c",&b[i]); //scaning the 4 coordinates into an array to minimize the errors when the user inputs
            }

                r1=b[0]-'0';  c1=b[1]-'0';  r2=b[2]-'0';  c2=b[3]-'0';
                if (r1==-1) break;
                if ((c2==c1)&&(abs(r1-r2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' '&& r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)){
                  player1Moves++;
                    Arr[r1+r2-2][c1+c2-2]='2'; // |
                    if(c1!=1){
                    if(Arr[r1+r2-2][c1+c2-4]!=' ' && Arr[r1+r2-3][c1+c2-3]!=' ' && Arr[r1+r2-1][c1+c2-3]!=' ') {
                    Arr[r1+r2-2][c1+c2-3]='6'; // #
                    p1Score++;
                    if (dfsFlag==1) dfs(gameSize,Arr,&r1,&c1,&r2,&c2,&z,&player1Moves,&p1Score);
                    }
                    }
                    if(c1!=gameSize+1){
                    if (Arr[r1+r2-2][c1+c2]!=' '&& Arr[r1+r2-3][c1+c2-1]!=' ' && Arr[r1+r2-1][c1+c2-1]!=' ') {
                       Arr[r1+r2-2][c1+c2-1]='6'; // #
                       p1Score++;
                       if (dfsFlag==1) dfs(gameSize,Arr,&r1,&c1,&r2,&c2,&z,&player1Moves,&p1Score);
                    }
                }
                }
                else if ((r2==r1)&&(abs(c1-c2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' '&&r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)){
                     player1Moves++;
                     Arr[r1+r2-2][c1+c2-2]='3'; // -
                     if(r1!=gameSize+1){
                     if(Arr[r1+r2][c1+c2-2]!=' '  && Arr[r1+r2-1][c1+c2-1]!=' ' &&Arr[r1+r2-1][c1+c2-3]!=' '  ){
                     Arr[r1+r2-1][c1+c2-2]='6';
                     p1Score++;
                     if (dfsFlag==1) dfs(gameSize,Arr,&r1,&c1,&r2,&c2,&z,&player1Moves,&p1Score);
                     }
                     }
                     if(r1!=1){
                     if(Arr[r1+r2-4][c1+c2-2]!=' ' && Arr[r1+r2-3][c1+c2-1]!=' ' &&Arr[r1+r2-3][c1+c2-3]!=' '  ){
                     Arr[r1+r2-3][c1+c2-2]='6';
                     p1Score++;
                     if (dfsFlag==1) dfs(gameSize,Arr,&r1,&c1,&r2,&c2,&z,&player1Moves,&p1Score);
                     }
                }
                }
                else
                {
                    system( "cls" );
                    printf("Invalid Value, Please Enter Again\n");
                    continue;
                }
                if(p1Score>l) {
                        system( "cls" );
                        z--;

                        clock_t end = clock();
                        time_spent = (int)(end - begin) / CLOCKS_PER_SEC;
                        t=time_spent/60;
                        if (t!=0) time_spent-=t*60;

                        continue;

                }

                playerTurn=2;
                z--;
                clock_t end = clock();
                time_spent = (int)(end - begin) / CLOCKS_PER_SEC;
                t=time_spent/60;
                if (t!=0) time_spent-=t*60;
                system( "cls" );
            }

            else if(playerTurn==2)
            {
                printf(" \033[0;31m%s's turn : \033[0m \n",player2);
                 int i=0;
           for(i=0;i<4;i++){
            scanf(" %c",&b[i]);
           }

                r1=b[0]-'0';  c1=b[1]-'0';  r2=b[2]-'0';  c2=b[3]-'0';
                if (r1==-1) break;
                if ((c2==c1)&&(abs(r1-r2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' '&&r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)) {
                   player2Moves++;
                    Arr[r1+r2-2][c1+c2-2]='4';
                    if( c1!=1 ){
                    if(Arr[r1+r2-2][c1+c2-4]!=' '&& Arr[r1+r2-3][c1+c2-3]!=' ' && Arr[r1+r2-1][c1+c2-3]!=' ') {
                    Arr[r1+r2-2][c1+c2-3]='7'; // #
                    p2Score++;
                    if (dfsFlag==1) dfs(gameSize,Arr,&r1,&c1,&r2,&c2,&z,&player2Moves,&p2Score);
                    }
                    }
                    if(c1!=gameSize+1 ){
                    if (Arr[r1+r2-2][c1+c2]!=' '&&  Arr[r1+r2-3][c1+c2-1]!=' ' && Arr[r1+r2-1][c1+c2-1]!=' ') {
                       Arr[r1+r2-2][c1+c2-1]='7'; // #
                       p2Score++;
                       if (dfsFlag==1) dfs(gameSize,Arr,&r1,&c1,&r2,&c2,&z,&player2Moves,&p2Score);
                    }
                    }
                }
                else if ((r2==r1)&&(abs(c1-c2)==1)&&(Arr[r1+r2-2][c1+c2-2]==' '&&r1<=gameSize+1&&r2<=gameSize+1&&c1<=gameSize+1&&c2<=gameSize+1)){
                   player2Moves++;
                    Arr[r1+r2-2][c1+c2-2]='5';
                    if( r1!=gameSize+1 ){
                    if(Arr[r1+r2][c1+c2-2]!=' '&&Arr[r1+r2-1][c1+c2-1]!=' ' &&Arr[r1+r2-1][c1+c2-3]!=' '  ){
                     Arr[r1+r2-1][c1+c2-2]='7';
                     p2Score++;
                     if (dfsFlag==1) dfs(gameSize,Arr,&r1,&c1,&r2,&c2,&z,&player2Moves,&p2Score);
                     }
                    }
                    if(r1!=1 ){
                     if(Arr[r1+r2-4][c1+c2-2]!=' ' &&  Arr[r1+r2-3][c1+c2-1]!=' ' &&Arr[r1+r2-3][c1+c2-3]!=' '  ){
                     Arr[r1+r2-3][c1+c2-2]='7';
                     p2Score++;
                     if (dfsFlag==1) dfs(gameSize,Arr,&r1,&c1,&r2,&c2,&z,&player2Moves,&p2Score);
                     }
                    }
                }
                else
                {
                    system( "cls" );
                    printf("Invalid Value, Please Enter Again\n");
                    continue;
                }
                if(p2Score>t) {
                        z--;

                        clock_t end = clock();
                        time_spent = (int)(end - begin) / CLOCKS_PER_SEC;
                        t=time_spent/60;
                        if (t!=0) time_spent-=t*60;

                        system( "cls" );
                        continue;

                }
                playerTurn=1;
                z--;

                clock_t end = clock();
                time_spent = (int)(end - begin) / CLOCKS_PER_SEC;
                t=time_spent/60;
                if (t!=0) time_spent-=t*60;

                system( "cls" );
            }

            else if(playerTurn==0)
            {

            }




        }

            //the game (the while) loop has ended: the final results printing screen
            printf("\n  ");
            for(int i=1;i<=gameSize+1;i++) printf("%d   ",i); //printing the 1st row of numbers to help players choose the dots
            printf("\n");
            int k=1;
            for(int i=0;i<gameSize*2 + 1;i++)
            {
                if (i%2==0)
                {
                    printf("%d ",k);
                    k++;                                 //printing the 1st col of numbers to help players choose the dots
                }
                else printf("  ");
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
        if(p1Score>p2Score) printf("\033[0;34m%s wins\033[0m ",player1);
        else if(p2Score>p1Score) printf("\033[0;31m%s wins\033[0m ",player2);
        else   printf("Draw");
    }

    activeplayGround(Arr, gameSize, dfsFlag, botFlag);

}


