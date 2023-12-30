#ifndef DFS_H
#define DFS_H

#include "undoRedo.h"
//#include "stepInfoStruct.h"
//  currentMove, lastMove, steps[], botFlag, dfsActive, playerTurn

void openChain(int gameSize,char Grid[gameSize*2+1][gameSize*2+1],int r1,int c1,int r2,int c2,int* z,int* moves,int* score,     int *currentMove, int *lastMove, stepInfoStruct steps[], int botFlag, int dfsActive,    int *playerTurn){
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
             undoRedo(/*undoRedoCheck=*/0, gameSize, Grid, playerTurn, score, /* *p2Score=*/score, moves, /*player2Moves*/moves, z, r1+ r2-3,  c1+ c2-3, r1+ r2-1, c1+ c2-2, /*moveChecker=*/Grid[r1+ r2-3][ c1+ c2-3]-'0', /*winChecker1=*/Grid[r1+ r2-3][ c1+ c2-2]-'0', /*winChecker2=*/0, currentMove, lastMove, steps, botFlag, dfsActive=1);
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
int dfs(int gameSize,char Grid[2*gameSize+1][2*gameSize+1],int r1,int c1,int r2,int c2){
int x=1,y=1,z=1,w=1;
    if(r1==r2&&Grid[r1+r2-3][c1+c2-2]==' '&& r1!=1){
       Grid[r1+r2-3][c1+c2-2]='9';
       if(Grid[r1+r2-4][c1+c2-2]!=' ') x=1;
       else x=dfs(gameSize,Grid,r1-1,c1,r2-1,c2);
       if(Grid[r1+r2-3][c2+c2-2]!=' ') y=1;
       else y=dfs(gameSize,Grid,r1,c2,r2-1,c2);
       if(Grid[r1+r2-3][c1+c1-2]!=' ') z=1;
       else z=dfs(gameSize,Grid,r1,c1,r2-1,c1);
}
else if(r1==r2&&r1==1) x=0;
else if(r1==r2&&Grid[r1+r2-1][c1+c2-2]==' '&&r1!=gameSize+1){
       Grid[r1+r2-1][c1+c2-2]='9';
       if(Grid[r1+r2][c1+c2-2]!=' ') w=1;
       else w=dfs(gameSize,Grid,r1+1,c1,r2+1,c2);
       if(Grid[r1+r2-1][c2+c2-2]!=' ') y=1;
       else y=dfs(gameSize,Grid,r1,c2,r2+1,c2);
       if(Grid[r1+r2-1][c1+c1-2]!=' ') z=1;
       else z=dfs(gameSize,Grid,r1,c1,r2+1,c1);
}
else if(r1==r2&&r1==gameSize+1) w=0;
else if(c1==c2&&Grid[r1+r2-2][c1+c2-3]==' '&&c1!=1){
       Grid[r1+r2-2][c1+c2-3]='9';
       if(Grid[r1+r2-2][c1+c2-4]!=' ') z=1;
       else z=dfs(gameSize,Grid,r1,c1-1,r2,c2-1);
       if(Grid[r2+r2-2][c2+c1-3]!=' ') {x=1; }
       else x=dfs(gameSize,Grid,r2,c1-1,r2,c2);
       if(Grid[r1+r1-2][c1+c2-3]!=' ') w=1;
       else w=dfs(gameSize,Grid,r1,c2-1,r1,c1);
}
else if(c1==c2&&c1==1) z=0;
else if(c1==c2&&Grid[r1+r2-2][c1+c2-1]==' '&&c1!=gameSize+1){
       Grid[r1+r2-2][c1+c2-1]='9';
       if(Grid[r1+r2-2][c1+c2]!=' ') y=1;
       else y=dfs(gameSize,Grid,r1,c1+1,r2,c2+1);
       if(Grid[r2+r2-2][c2+c1-1]!=' ') x=1;
       else x=dfs(gameSize,Grid,r2,c1+1,r2,c2);
       if(Grid[r1+r1-2][c1+c2-1]!=' ') w=1;
       else w=dfs(gameSize,Grid,r1,c2+1,r1,c1);
}
else if(c1==c2&&c1==gameSize+1) y=0;
int r=(x*y*z*w);
return r;
}


void chainOfBoxes(int gameSize,char Grid[2*gameSize+1][2*gameSize+1],int r1,int c1,int r2,int c2,int* z,int* moves,int* score,     int *currentMove, int *lastMove, stepInfoStruct steps[], int botFlag, int dfsActive,    int *playerTurn){
    int i,j;
if(dfs(gameSize,Grid,r1,c1,r2,c2)){
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
else{
        for(i=0;i<=2*gameSize;i++){
        for(j=0;j<=2*gameSize;j++){
            if(Grid[i][j]=='9'){
              Grid[i][j]=' ';
            }
        }
    }

openChain(gameSize,Grid,r1,c1,r2,c2,z,moves,score,  currentMove, lastMove, steps, botFlag, dfsActive, playerTurn);
}
}

//undoRedo(0, gameSize, Grid, 1, &p1Score, &p2Score, &player1Moves, &player2Moves, &remMoves, r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, &currentMove, &lastMove, steps[], botFlag, 1);
//undoRedo(undoRedoCheck=0, gameSize, Grid, *playerTurn=2, /* *p1Score*/, *p2Score, /* *player1Moves*/, *player2Moves, *remMoves, r1, c1, r2, c2, moveChecker, winChecker1, winChecker2, *currentMove, *lastMove, steps[], botFlag, dfsActive=1);

#endif
