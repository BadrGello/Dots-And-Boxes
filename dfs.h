void openChain(int gameSize,char Grid[gameSize*2+1][gameSize*2+1],int r1,int c1,int r2,int c2,int* z,int* moves,int* score, int* dfsActive){
    if(r1== r2){
        if(r1!=gameSize+1 && Grid[r1+ r2-3][ c1+ c2-2]!=' '){
            if(Grid[r1+ r2][ c1+ c2-2]==' '&&Grid[r1+ r2-1][ c1+ c2-1]!=' '&&Grid[r1+ r2-1][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2][ c1+ c2-2]=Grid[r1+ r2-2][ c1+ c2-2];
             Grid[r1+ r2-1][ c1+ c2-2]=Grid[r1+ r2-3][ c1+ c2-2];
             *dfsActive=1;
             openChain(gameSize,Grid,r1+1,c1,r2+1,c2,z,moves,score,dfsActive);
            }
            else if(Grid[r1+ r2][ c1+ c2-2]!=' '&&Grid[r1+ r2-1][ c1+ c2-1]==' '&&Grid[r1+ r2-1][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-1][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-2]-1;
             Grid[r1+ r2-1][ c1+ c2-2]=Grid[r1+ r2-3][ c1+ c2-2];
             *dfsActive=1;
             if( c1> c2)   openChain(gameSize,Grid,r1,c1,r2+1,c1,z,moves,score,dfsActive);
             else  openChain(gameSize,Grid,r1,c2,r2+1,c2,z,moves,score,dfsActive);
            }
            else if(Grid[r1+ r2][ c1+ c2-2]!=' '&&Grid[r1+ r2-1][ c1+ c2-1]!=' '&&Grid[r1+ r2-1][ c1+ c2-3]==' ') {
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-1][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-2]-1;
             Grid[r1+ r2-1][ c1+ c2-2]=Grid[r1+ r2-3][ c1+ c2-2];
             ( r2)++;
             *dfsActive=1;
             if( c1> c2)  openChain(gameSize,Grid,r1,c2,r2+1,c2,z,moves,score,dfsActive);
             else   openChain(gameSize,Grid,r1,c1,r2+1,c1,z,moves,score,dfsActive);
            }
        }
        else if(r1!=1 &&Grid[r1+ r2-1][ c1+ c2-2]!=' '){
            if(Grid[r1+ r2-4][ c1+ c2-2]==' '&&Grid[r1+ r2-3][ c1+ c2-1]!=' '&&Grid[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-4][ c1+ c2-2]=Grid[r1+ r2-2][ c1+ c2-2];
             Grid[r1+ r2-3][ c1+ c2-2]=Grid[r1+ r2-3][ c1+ c2-2];
             (r1)--;
             ( r2)--;
             *dfsActive=1;
             openChain(gameSize,Grid,r1-1,c1,r2-1,c2,z,moves,score,dfsActive);
            }
            else if(Grid[r1+ r2-4][ c1+ c2-2]!=' '&&Grid[r1+ r2-3][ c1+ c2-1]==' '&&Grid[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-3][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-2]-1;
             Grid[r1+ r2-3][ c1+ c2-2]=Grid[r1+ r2-3][ c1+ c2-2];
             *dfsActive=1;
             if( c1> c2)   openChain(gameSize,Grid,r1,c1,r2-1,c1,z,moves,score,dfsActive);
             else  openChain(gameSize,Grid,r1,c2,r2-1,c2,z,moves,score,dfsActive);
            }
            else if(Grid[r1+ r2-4][ c1+ c2-2]!=' '&&Grid[r1+ r2-3][ c1+ c2-1]!=' '&&Grid[r1+ r2-3][ c1+ c2-3]==' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-3][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-2]-1;
             Grid[r1+ r2-3][ c1+ c2-2]=Grid[r1+ r2-3][ c1+ c2-2];
             *dfsActive=1;
             if( c1> c2)   openChain(gameSize,Grid,r1,c2,r2-1,c2,z,moves,score,dfsActive);
             else   openChain(gameSize,Grid,r1,c1,r2-1,c1,z,moves,score,dfsActive);
            }
        }
    }
    else if( c1== c2){
      if( c1!=1&& Grid[r1+ r2-2][ c1+ c2-1!=' ']){
            if(Grid[r1+ r2-2][ c1+ c2-4]==' '&&Grid[r1+ r2-1][ c1+ c2-3]!=' '&&Grid[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-2][ c1+ c2-4]=Grid[r1+ r2-2][ c1+ c2-2];
             Grid[r1+ r2-2][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-1];
             *dfsActive=1;
             openChain(gameSize,Grid,r1,c1-1,r2,c2-1,z,moves,score,dfsActive);
            }
            else if(Grid[r1+ r2-2][ c1+ c2-4]!=' '&&Grid[r1+ r2-1][ c1+ c2-3]!=' '&&Grid[r1+ r2-3][ c1+ c2-3]==' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-3][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-2]+1;
             Grid[r1+ r2-2][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-1];
             *dfsActive=1;
             if(r1> r2) openChain(gameSize,Grid,r2,c1-1,r2,c2,z,moves,score,dfsActive);
             else  openChain(gameSize,Grid,r1,c1-1,r1,c2,z,moves,score,dfsActive);

            }
            else if(Grid[r1+ r2-2][ c1+ c2-4]!=' '&&Grid[r1+ r2-1][ c1+ c2-3]==' '&&Grid[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-1][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-2]+1;
             Grid[r1+ r2-2][ c1+ c2-3]=Grid[r1+ r2-2][ c1+ c2-1];
             *dfsActive=1;
             if(r1> r2) openChain(gameSize,Grid,r1,c1-1,r1,c2,z,moves,score,dfsActive);
             else openChain(gameSize,Grid,r2,c1-1,r2,c2,z,moves,score,dfsActive);
            }
      }
      else if( c1!=gameSize+1&& Grid[r1+ r2-2][ c1+ c2-3!=' ']){
             if(Grid[r1+ r2-2][ c1+ c2]==' '&&Grid[r1+ r2-1][ c1+ c2-1]!=' '&&Grid[r1+ r2-3][ c1+ c2-1]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-2][ c1+ c2]=Grid[r1+ r2-2][ c1+ c2-2];
             Grid[r1+ r2-2][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-3];
             *dfsActive=1;
            openChain(gameSize,Grid,r1,c1+1,r2,c2+1,z,moves,score,dfsActive);
             }
            else if(Grid[r1+ r2-2][ c1+ c2]!=' '&&Grid[r1+ r2-1][ c1+ c2-1]==' '&&Grid[r1+ r2-3][ c1+ c2-1]!=' '){
             ( *z)--;
             ( *moves)++;
             (*score)++;
             Grid[r1+ r2-3][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-2]+1;
             Grid[r1+ r2-2][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-3];
             *dfsActive=1;
             if(r1> r2)      openChain(gameSize,Grid,r1,c1+1,r1,c2,z,moves,score,dfsActive);
             else        openChain(gameSize,Grid,r2,c1+1,r2,c2,z,moves,score,dfsActive);
            }
            else if(Grid[r1+ r2-2][ c1+ c2]!=' '&&Grid[r1+ r2-1][ c1+ c2-1]!=' '&&Grid[r1+ r2-3][ c1+ c2-1]==' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             Grid[r1+ r2-3][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-2]+1;
             Grid[r1+ r2-2][ c1+ c2-1]=Grid[r1+ r2-2][ c1+ c2-3];
             *dfsActive=1;
             if(r1> r2)  openChain(gameSize,Grid,r2,c1+1,r2,c2,z,moves,score,dfsActive);
             else   openChain(gameSize,Grid,r1,c1+1,r1,c2,z,moves,score,dfsActive);
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
       else x=dfs(gameSize,Grid,r1,c1-1,r2,c2-1);
       if(Grid[r2+r2-2][c2+c2-3]!=' ') x=1;
       else y=dfs(gameSize,Grid,r2,c1-1,r2,c2);
       if(Grid[r1+r1-2][c1+c1-3]!=' ') w=1;
       else z=dfs(gameSize,Grid,r1,c2-1,r1,c1);
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


void chainOfBoxes(int gameSize,char Grid[2*gameSize+1][2*gameSize+1],int r1,int c1,int r2,int c2,int* z,int* moves,int* score, int* dfsActive){
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
            }
            if(Grid[i][j-1]==' ') {
                    Grid[i][j-1]='2';
                    (*z)--;
                    (*moves)++;
            }
            if(Grid[i+1][j]==' ') {
                    Grid[i+1][j]='3';
                    (*z)--;
                    (*moves)++;
            }
            if(Grid[i][j+1]==' ') {
                    Grid[i-1][j]='3';
                    (*z)--;
                    (*moves)++;
            }
            Grid[i][j]='6';
            }
            else {
            if(Grid[i][j+1]==' ') {
                    Grid[i][j+1]='4';
                    (*z)--;
                    (*moves)++;
            }
            if(Grid[i][j-1]==' ') {
                    Grid[i][j-1]='4';
                    (*z)--;
                    (*moves)++;
            }
            if(Grid[i+1][j]==' ') {
                    Grid[i+1][j]='5';
                    (*z)--;
                    (*moves)++;
            }
            if(Grid[i][j+1]==' ') {
                    Grid[i-1][j]='5';
                    (*z)--;
                    (*moves)++;
            }
            Grid[i][j]='7';
            }
            }
        }
    }

*dfsActive=1;
}
else{
        for(i=0;i<=2*gameSize;i++){
        for(j=0;j<=2*gameSize;j++){
            if(Grid[i][j]=='9'){
              Grid[i][j]=' ';
            }
        }
    }
openChain(gameSize,Grid,r1,c1,r2,c2,z,moves,score,dfsActive);
}
}


