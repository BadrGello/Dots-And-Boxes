#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// r1 c1 r2 c2 (c2==c1)&&(abs(r1-r2)==1) ,, (r2==r1)&&(abs(c1-c2)==1)
//Function to generate a random number within a specific range [min, max]
void  generateRandomNumber(int min, int max, int *r1, int *c1, int *r2, int *c2) // 1 10 // (10-1+1) + 1;
    {
        //Seeding the random number generator with the current time
        time_t t;
        time(&t);
        srand(t);

        int h; //if h=1, r1=r2, if h=0, c1=c2
        h=rand()%(2);

        if(h==1){
        *r1=rand() % (max - min + 1) + min;
        *r2=*r1;
        *c1=rand() % (max - min + 1) + min;
        if (*c1==max)*c2=*c1-1;
        else *c2=*c1+1;
        }
        else if(h==0){
        *c1=rand() % (max - min + 1) + min;
        *c2=*c1;
        *r1=rand() % (max - min + 1) + min;
        if (*r1==max)*r2=*r1-1;
        else *r2=*r1+1;


        }
    }


