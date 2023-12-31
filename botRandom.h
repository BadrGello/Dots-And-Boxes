#ifndef BOT_H
#define BOT_H



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// r1 c1 r2 c2 (c2==c1)&&(abs(r1-r2)==1) ,, (r2==r1)&&(abs(c1-c2)==1)
//Function to generate a random number within a specific range [min 1, max gameSize+1]
    void generateRandomNumber(int gameSize, char Grid[2 * gameSize + 1][2 * gameSize + 1], int *r1, int *c1, int *r2, int *c2) // 1 10 // (10-1+1) + 1;
    {
        time_t t;
        time(&t);
        srand(t); //Seeding the random number generator with the current time

        int choose[50][2];
        int k=0;
        //printf("Entered RandomBot Succ\n");

        for (int i=0;i<2*gameSize+1;i++)
        {
            //printf("i:%d\n",i);
            for (int j=0;j<2*gameSize+1;j++)
            {
                //printf("j:%d\n",j);
                if (!(i%2==1 && j%2==1) && Grid[i][j]==' ') //if the position isn't a # place and it's an empty place THEREFOR, a valid place to play in
                {
                    choose[k][0]=i;
                    choose[k][1]=j;
                    //printf("valid i:%d, valid j:%d, \n",choose[k][0],choose[k][1]);
                    k++;
                }
            }
        }
        //printf("Finished Loop\n");

        int randomIndex = rand() % k;

       // printf("K %d ,Random Index K %d\n",k, randomIndex);

        // Retrieve the randomly chosen i and j
        int chosenI = choose[randomIndex][0]; // i=r1+r2-2
        int chosenJ = choose[randomIndex][1]; // j=c1+c2-2

        //printf("chosenI %d ,chosenJ %d\n",chosenI,chosenJ);



        if (chosenI%2==0) //(r2==r1)&&(abs(c1-c2)==1) -> c1-c2=1 OR c2-c1=1 AND j=c1+c2-3+1 THEREFOR 1) j=c1+c2-3+c1-c2 = 2c1-3 [c1-c2=1] OR 2) j=c1+c2-3+c2-c1 = 2c2-3 [c2-c1=1]
        {
            *r1=(chosenI+2)/2; printf("r1 %d",*r1);
            *r2=*r1; printf("r2 %d", *r2);
            *c1=(chosenJ+3)/2 ; printf("c1 %d",*c1);
            *c2=*c1-1 ; printf("c2 %d\n",*c2);


        }
        if (chosenJ%2==0) //(c2==c1)&&(abs(r1-r2)==1)
        {
            *c1=(chosenJ+2)/2; printf("c1 %d",*c1);
            *c2=*c1; printf("c2 %d",*c2);
            *r1=(chosenI+3)/2 ; printf("r1 %d",*r1);
            *r2=*r1-1; printf("r2 %d\n", *r2);
        }

        //exit(0);
        /*do {


        int h; //if h=1, r1=r2, if h=0, c1=c2
        h=rand()%(2);

        if(h==1)
        {
            *r1=rand() % (gameSize+1) + 1;
            *r2=*r1;
            *c1=rand() % (gameSize+1) + 1;
            if (*c1==gameSize+1) *c2=*c1-1;
            else *c2=*c1+1;
        }

        else if(h==0)
        {
            *c1=rand() % (gameSize+1) + 1;
            *c2=*c1;
            *r1=rand() % (gameSize+1) + 1;
            if (*r1==gameSize+1) *r2=*r1-1;
            else *r2=*r1+1;
        }

        } while (Grid[*r1+*r2-2][*c1+*c2-2]!=' ');*/


    }



#endif
