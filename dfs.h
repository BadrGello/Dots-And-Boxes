#ifndef DFS_H
#define DFS_H

#include "undoRedo.h"
//#include "stepInfoStruct.h"
//  currentMove, lastMove, steps[], botFlag, dfsActive, playerTurn

void openChain(int gameSize,char Grid[gameSize*2+1][gameSize*2+1],int r1,int c1,int r2,int c2,int* z,int* moves,int* score,     int *currentMove, int *lastMove, stepInfoStruct steps[], int botFlag, int dfsActive,    int *playerTurn){
  //if the line close a box and make the other box have 3 side filled close the another box and try again
    if(r1== r2){
        if(r1!=gameSize+1 && Grid[r1+ r2-3][ c1+ c2-2]!=' '){
            if(Grid[r1+ r2][ c1+ c2-2]==' '&&Grid[r1+ r2-1][ c1+ c2-1]!=' '&&Grid[r1+ r2-1][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2][ c1+ c2-2]=Grid[r1+ r2-2][ c1+ c2-2];  //Grid[r1+ r2][ c1+ c2-2] is moveChecker
             Grid[r1+ r2-1][ c1+ c2-2]=Grid[r1+ r2-3][ c1+ c2-2]; //Grid[r1+ r2-1][ c1+ c2-2] is winChecker
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2,  c1+ c2-2, r1+ r2-1, c1+ c2-2, /*moveChecker=*/Grid[r1+ r2][ c1+ c2-2]-'0', /*winChecker1=*/Grid[r1+ r2-1][ c1+ c2-2]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             openChain(gameSize,Grid,r1+1,c1,r2+1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
            }
            else if(Grid[r1+ r2][ c1+ c2-2]!=' '&&Grid[r1+ r2-1][ c1+ c2-1]==' '&&Grid[r1+ r2-1][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-1][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-2]-1;
             Grid[r1+ r2-1][ c1+ c2-2]=Grid[r1+ r2-3][ c1+ c2-2];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-1,  c1+ c2-1, r1+ r2-1, c1+ c2-2, /*moveChecker=*/Grid[r1+ r2-1][ c1+ c2-1]-'0', /*winChecker1=*/Grid[r1+ r2-1][ c1+ c2-2]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             if( c1> c2)   openChain(gameSize,Grid,r1,c1,r2+1,c1,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             else  openChain(gameSize,Grid,r1,c2,r2+1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
            }
            else if(Grid[r1+ r2][ c1+ c2-2]!=' '&&Grid[r1+ r2-1][ c1+ c2-1]!=' '&&Grid[r1+ r2-1][ c1+ c2-3]==' ') {
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-1][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-2]-1;
             Grid[r1+ r2-1][ c1+ c2-2]=Grid[r1+ r2-3][ c1+ c2-2];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-1,  c1+ c2-3, r1+ r2-1, c1+ c2-2, /*moveChecker=*/Grid[r1+ r2-1][ c1+ c2-3]-'0', /*winChecker1=*/Grid[r1+ r2-1][ c1+ c2-2]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             if( c1> c2)  openChain(gameSize,Grid,r1,c2,r2+1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             else   openChain(gameSize,Grid,r1,c1,r2+1,c1,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
            }
        }
        else if(r1!=1 &&Grid[r1+ r2-1][ c1+ c2-2]!=' '){
            if(Grid[r1+ r2-4][ c1+ c2-2]==' '&&Grid[r1+ r2-3][ c1+ c2-1]!=' '&&Grid[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-4][ c1+ c2-2]=Grid[r1+ r2-2][ c1+ c2-2];
             Grid[r1+ r2-3][ c1+ c2-2]=Grid[r1+ r2-1][ c1+ c2-2];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-4,  c1+ c2-2, r1+ r2-3, c1+ c2-2, /*moveChecker=*/Grid[r1+ r2-4][ c1+ c2-2]-'0', /*winChecker1=*/Grid[r1+ r2-3][ c1+ c2-2]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             openChain(gameSize,Grid,r1-1,c1,r2-1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
            }
            else if(Grid[r1+ r2-4][ c1+ c2-2]!=' '&&Grid[r1+ r2-3][ c1+ c2-1]==' '&&Grid[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-3][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-2]-1;
             Grid[r1+ r2-3][ c1+ c2-2]=Grid[r1+ r2-1][ c1+ c2-2];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-3,  c1+ c2-1, r1+ r2-3, c1+ c2-2, /*moveChecker=*/Grid[r1+ r2-3][ c1+ c2-1]-'0', /*winChecker1=*/Grid[r1+ r2-3][ c1+ c2-2]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             if( c1> c2)   openChain(gameSize,Grid,r1,c1,r2-1,c1,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             else  openChain(gameSize,Grid,r1,c2,r2-1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
            }
            else if(Grid[r1+ r2-4][ c1+ c2-2]!=' '&&Grid[r1+ r2-3][ c1+ c2-1]!=' '&&Grid[r1+ r2-3][ c1+ c2-3]==' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-3][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-2]-1;
             Grid[r1+ r2-3][ c1+ c2-2]=Grid[r1+ r2-1][ c1+ c2-2];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-3,  c1+ c2-3, r1+ r2-3, c1+ c2-2, /*moveChecker=*/Grid[r1+ r2-3][ c1+ c2-3]-'0', /*winChecker1=*/Grid[r1+ r2-3][ c1+ c2-2]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             if( c1> c2)   openChain(gameSize,Grid,r1,c2,r2-1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             else   openChain(gameSize,Grid,r1,c1,r2-1,c1,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
            }
        }
    }
    else if( c1== c2){
      if( c1!=1&& Grid[r1+ r2-2][ c1+ c2-1]!=' '){
            if(Grid[r1+ r2-2][ c1+ c2-4]==' '&&Grid[r1+ r2-1][ c1+ c2-3]!=' '&&Grid[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-2][ c1+ c2-4]=Grid[r1+ r2-2][ c1+ c2-2];
             Grid[r1+ r2-2][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-1];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-2,  c1+ c2-4, r1+ r2-2, c1+ c2-3, /*moveChecker=*/Grid[r1+ r2-2][ c1+ c2-4]-'0', /*winChecker1=*/Grid[r1+ r2-2][ c1+ c2-3]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             openChain(gameSize,Grid,r1,c1-1,r2,c2-1,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
            }
            else if(Grid[r1+ r2-2][ c1+ c2-4]!=' '&&Grid[r1+ r2-1][ c1+ c2-3]!=' '&&Grid[r1+ r2-3][ c1+ c2-3]==' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-3][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-2]+1;
             Grid[r1+ r2-2][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-1];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-3,  c1+ c2-3, r1+ r2-2, c1+ c2-3, /*moveChecker=*/Grid[r1+ r2-3][ c1+ c2-3]-'0', /*winChecker1=*/Grid[r1+ r2-2][ c1+ c2-3]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             if(r1> r2) openChain(gameSize,Grid,r2,c1-1,r2,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             else  openChain(gameSize,Grid,r1,c1-1,r1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);

            }
            else if(Grid[r1+ r2-2][ c1+ c2-4]!=' '&&Grid[r1+ r2-1][ c1+ c2-3]==' '&&Grid[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-1][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-2]+1;
             Grid[r1+ r2-2][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-1];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-1,  c1+ c2-3, r1+ r2-2, c1+ c2-3, /*moveChecker=*/Grid[r1+ r2-1][ c1+ c2-3]-'0', /*winChecker1=*/Grid[r1+ r2-2][ c1+ c2-3]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             if(r1> r2) openChain(gameSize,Grid,r1,c1-1,r1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             else openChain(gameSize,Grid,r2,c1-1,r2,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
            }
      }
      else if( c1!=gameSize+1&& Grid[r1+ r2-2][ c1+ c2-3]!=' '){
             if(Grid[r1+ r2-2][ c1+ c2]==' '&&Grid[r1+ r2-1][ c1+ c2-1]!=' '&&Grid[r1+ r2-3][ c1+ c2-1]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-2][ c1+ c2]=Grid[r1+ r2-2][ c1+ c2-2];
             Grid[r1+ r2-2][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-3];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-2,  c1+ c2, r1+ r2-2, c1+ c2-1, /*moveChecker=*/Grid[r1+ r2-2][ c1+ c2]-'0', /*winChecker1=*/Grid[r1+ r2-2][ c1+ c2-1]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             openChain(gameSize,Grid,r1,c1+1,r2,c2+1,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             }
             else if(Grid[r1+ r2-2][ c1+ c2]!=' '&&Grid[r1+ r2-1][ c1+ c2-1]==' '&&Grid[r1+ r2-3][ c1+ c2-1]!=' '){
             ( *z)--;
             ( *moves)++;
             (*score)++;
             Grid[r1+ r2-1][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-2]+1;
             Grid[r1+ r2-2][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-3];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-1,  c1+ c2-1, r1+ r2-2, c1+ c2-1, /*moveChecker=*/Grid[r1+ r2-1][ c1+ c2-1]-'0', /*winChecker1=*/Grid[r1+ r2-2][ c1+ c2-1]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             if(r1> r2)      openChain(gameSize,Grid,r1,c1+1,r1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             else        openChain(gameSize,Grid,r2,c1+1,r2,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             }
             else if(Grid[r1+ r2-2][ c1+ c2]!=' '&&Grid[r1+ r2-1][ c1+ c2-1]!=' '&&Grid[r1+ r2-3][ c1+ c2-1]==' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-3][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-2]+1;
             Grid[r1+ r2-2][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-3];
             ////
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-3,  c1+ c2-1, r1+ r2-2, c1+ c2-1, /*moveChecker=*/Grid[r1+ r2-3][ c1+ c2-1]-'0', /*winChecker1=*/Grid[r1+ r2-2][ c1+ c2-1]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
             if(r1> r2)  openChain(gameSize,Grid,r2,c1+1,r2,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
             else   openChain(gameSize,Grid,r1,c1+1,r1,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
            }
      }
    }
}
int dfs(int gameSize,char Grid[2*gameSize+1][2*gameSize+1],int r1,int c1,int r2,int c2){ //dfs function
int x=1,y=1,z=1,w=1;
    if(r1==r2&&Grid[r1+r2-3][c1+c2-2]==' '&& r1!=1){//if the line drawn is horizontal and the box above it is empty and not equal to the first line
       Grid[r1+r2-3][c1+c2-2]='9';                   // make the box = visted
       if(Grid[r1+r2-4][c1+c2-2]!=' ') x=1;          //if the line above the box is not empty return x=1
       else x=dfs(gameSize,Grid,r1-1,c1,r2-1,c2);    // else x= the dfs of the line above the box
       if(Grid[r1+r2-3][c2+c2-2]!=' ') y=1;          //if the line next to the box is not empty return y=1
       else y=dfs(gameSize,Grid,r1,c2,r2-1,c2);      //else y= the dfs of the line next to the box
       if(Grid[r1+r2-3][c1+c1-2]!=' ') z=1;          //if the line next to the box in the other direction is not empty return z=1
       else z=dfs(gameSize,Grid,r1,c1,r2-1,c1);      //else z= the dfs of the line next to the box in the other direction
else if(r1==r2&&r1==1) x=0;                          //else if line horizontal and equal to the first line x=0
else if(r1==r2&&Grid[r1+r2-1][c1+c2-2]==' '&&r1!=gameSize+1){ //else if the line drawn is horizontal and the box under it is empty and not equal to the last line
       Grid[r1+r2-1][c1+c2-2]='9';                            // make the box = visted
       if(Grid[r1+r2][c1+c2-2]!=' ') w=1;                     //if the line under the box is not empty return w=1
       else w=dfs(gameSize,Grid,r1+1,c1,r2+1,c2);             // else w= the dfs of the line above the box
       if(Grid[r1+r2-1][c2+c2-2]!=' ') y=1;                   //if the line next to the box is not empty return y=1
       else y=dfs(gameSize,Grid,r1,c2,r2+1,c2);              //else y= the dfs of the line next to the box
       if(Grid[r1+r2-1][c1+c1-2]!=' ') z=1;                  //if the line next to the box in the other direction is not empty return z=1
       else z=dfs(gameSize,Grid,r1,c1,r2+1,c1);              //else z= the dfs of the line next to the box in the other direction
}
else if(r1==r2&&r1==gameSize+1) w=0;                         //else if line horizontal and equal to the last line w=0
else if(c1==c2&&Grid[r1+r2-2][c1+c2-3]==' '&&c1!=1){         //else if line is vertical and the box left to it is empty and the line not equal to the first line
       Grid[r1+r2-2][c1+c2-3]='9';                           //the box =visted
       if(Grid[r1+r2-2][c1+c2-4]!=' ') z=1;                  //if the line in the left of the box is not empty z=1
       else z=dfs(gameSize,Grid,r1,c1-1,r2,c2-1);            //else z=dfs of the line in the left of the box
       if(Grid[r2+r2-2][c2+c1-3]!=' ') {x=1; }               //if the line above the box is not empty return x=1
       else x=dfs(gameSize,Grid,r2,c1-1,r2,c2);              // else x= the dfs of the line above the box
       if(Grid[r1+r1-2][c1+c2-3]!=' ') w=1;                  //if the line under the box is not empty return w=1
       else w=dfs(gameSize,Grid,r1,c2-1,r1,c1);              // else w= the dfs of the line above the box
}
else if(c1==c2&&c1==1) z=0;                                         //else if line is vertical and the line = the first line z=0
else if(c1==c2&&Grid[r1+r2-2][c1+c2-1]==' '&&c1!=gameSize+1){       //else if line is vertical and the box right to it is empty and the line not equal to the first line
       Grid[r1+r2-2][c1+c2-1]='9';                                  //the box =visted
       if(Grid[r1+r2-2][c1+c2]!=' ') y=1;                           //if the line in the right of the box is not empty y=1
       else y=dfs(gameSize,Grid,r1,c1+1,r2,c2+1);                   //else y=dfs of the line in the right of the box
       if(Grid[r2+r2-2][c2+c1-1]!=' ') x=1;                          //if the line above the box is not empty return x=1
       else x=dfs(gameSize,Grid,r2,c1+1,r2,c2);                     // else x= the dfs of the line above the box
       if(Grid[r1+r1-2][c1+c2-1]!=' ') w=1;                         //if the line under the box is not empty return w=1
       else w=dfs(gameSize,Grid,r1,c2+1,r1,c1);                     // else w= the dfs of the line above the box
}
else if(c1==c2&&c1==gameSize+1) y=0;                                //else if line is vertical and the line = the last line y=0
else x=0;                                                           // else (the box infront of you is visted before) x=0(any variable to make return =0)
int r=(x*y*z*w);                                                    // r=multiplicaton of all variables(if any return =0 r=0 else r=1) and returning r
return r;
}


void chainOfBoxes(int gameSize,char Grid[2*gameSize+1][2*gameSize+1],int r1,int c1,int r2,int c2,int* z,int* moves,int* score,     int *currentMove, int *lastMove, stepInfoStruct steps[], int botFlag, int dfsActive,    int *playerTurn){
    int i,j;
if(dfs(gameSize,Grid,r1,c1,r2,c2)){ //if the dfs return =1 make all the boxes visted by the color of player who played this play and fill al line around it
    for(i=0;i<=2*gameSize;i++){
        for(j=0;j<=2*gameSize;j++){
            if(Grid[i][j]=='9'){
            (*score)++;
            if(Grid[r1+r2-2][c1+c2-2]=='2'||Grid[r1+r2-2][c1+c2-2]=='3'){
            if(Grid[i][j+1]==' ') {
                    Grid[i][j+1]='2';
                    (*z)--;
                    (*moves)++;
                    ////
                    undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z, i, j+1, i, j, /*moveChecker=*/2, /*winChecker1=*/6, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);

            }
            if(Grid[i][j-1]==' ') {
                    Grid[i][j-1]='2';
                    (*z)--;
                    (*moves)++;
                    ////
                    undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z, i, j-1, i, j, /*moveChecker=*/2, /*winChecker1=*/6, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);

            }
            if(Grid[i+1][j]==' ') {
                    Grid[i+1][j]='3';
                    (*z)--;
                    (*moves)++;
                    ////
                    undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z, i+1, j, i, j, /*moveChecker=*/3, /*winChecker1=*/6, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);

            }
            if(Grid[i-1][j]==' ') {
                    Grid[i-1][j]='3';
                    (*z)--;
                    (*moves)++;
                    ////
                    undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z, i-1, j, i, j, /*moveChecker=*/3, /*winChecker1=*/6, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);

            }
            undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z,-1, -1, i, j, /*moveChecker=*/-1, /*winChecker1=*/6, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
            Grid[i][j]='6';
            }
            else {
            if(Grid[i][j+1]==' ') {
                    Grid[i][j+1]='4';
                    (*z)--;
                    (*moves)++;
                    ////
                    undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z, i, j+1, i, j, /*moveChecker=*/4, /*winChecker1=*/7, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
            }
            if(Grid[i][j-1]==' ') {
                    Grid[i][j-1]='4';
                    (*z)--;
                    (*moves)++;
                    ////
                    undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z, i, j-1, i, j, /*moveChecker=*/4, /*winChecker1=*/7, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
            }
            if(Grid[i+1][j]==' ') {
                    Grid[i+1][j]='5';
                    (*z)--;
                    (*moves)++;
                    ////
                    undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z, i+1, j, i, j, /*moveChecker=*/5, /*winChecker1=*/7, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
            }
            if(Grid[i-1][j]==' ') {
                    Grid[i-1][j]='5';
                    (*z)--;
                    (*moves)++;
                    ////
                    undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z, i-1, j, i, j, /*moveChecker=*/5, /*winChecker1=*/7, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
            }

            undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=-1*/score, moves, /*player2Moves-1*/moves, z,-1, -1, i, j, /*moveChecker=*/-1, /*winChecker1=*/7, /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
            Grid[i][j]='7';
            }
            }
        }
    }

}
else{      // if dfs return =0 return all visted boxes to its deafult
        for(i=0;i<=2*gameSize;i++){
        for(j=0;j<=2*gameSize;j++){
            if(Grid[i][j]=='9'){
              Grid[i][j]=' ';
            }
        }
    }

openChain(gameSize,Grid,r1,c1,r2,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn); //try open chain
}
}

//undoRedo(0, gameSize, Grid, 1, &p1Score, &p2Score, &player1Moves, &player2Moves, &remMoves, r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps[], botFlag, 1);
//undoRedo(undoRedoCheck=0, gameSize, Grid, *playerTurn=2, /* *p1Score*/, *p2Score, /* *player1Moves*/, *player2Moves, *remMoves, r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, *currentMove, *lastMove, steps[], botFlag, dfsActive=1);

#endif
