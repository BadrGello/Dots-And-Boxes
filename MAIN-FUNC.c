#include <stdio.h>

void playGround()
{
    //initial testing
    //3*3 therefor 4*4 dots: n=4 (2*n-1=7)
    int n=4; 
    char Arr[7][7]={{'.',' ','.',' ','.',' ','.'},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {'.',' ','.',' ','.',' ','.'},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {'.',' ','.',' ','.',' ','.'},
                    {' ',' ',' ',' ',' ',' ',' '},
                    {'.',' ','.',' ','.',' ','.'},};
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            printf("%c ",Arr[i][j]);

        }
    printf("\n");
    }
    






}


int main()
{
    playGround();

}