void openChain(int gameSize,char arr[gameSize*2+1][gameSize*2+1],int r1,int c1,int r2,int c2,int* z,int* moves,int* score){
    if(r1== r2){
        if(r1!=gameSize+1 && arr[r1+ r2-3][ c1+ c2-2]!=' '){
            if(arr[r1+ r2][ c1+ c2-2]==' '&&arr[r1+ r2-1][ c1+ c2-1]!=' '&&arr[r1+ r2-1][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2][ c1+ c2-2]=arr[r1+ r2-2][ c1+ c2-2];
             arr[r1+ r2-1][ c1+ c2-2]=arr[r1+ r2-3][ c1+ c2-2];
             openChain(gameSize,arr,r1+1,c1,r2+1,c2,z,moves,score);
            }
            else if(arr[r1+ r2][ c1+ c2-2]!=' '&&arr[r1+ r2-1][ c1+ c2-1]==' '&&arr[r1+ r2-1][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-1][ c1+ c2-1]=arr[r1+ r2-2][ c1+ c2-2]-1;
             arr[r1+ r2-1][ c1+ c2-2]=arr[r1+ r2-3][ c1+ c2-2];
             if( c1> c2)   openChain(gameSize,arr,r1,c1,r2+1,c1,z,moves,score);
             else  openChain(gameSize,arr,r1,c2,r2+1,c2,z,moves,score);
            }
            else if(arr[r1+ r2][ c1+ c2-2]!=' '&&arr[r1+ r2-1][ c1+ c2-1]!=' '&&arr[r1+ r2-1][ c1+ c2-3]==' ') {
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-1][ c1+ c2-3]=arr[r1+ r2-2][ c1+ c2-2]-1;
             arr[r1+ r2-1][ c1+ c2-2]=arr[r1+ r2-3][ c1+ c2-2];
             ( r2)++;
             if( c1> c2)  openChain(gameSize,arr,r1,c2,r2+1,c2,z,moves,score);
             else   openChain(gameSize,arr,r1,c1,r2+1,c1,z,moves,score);
            }
        }
        else if(r1!=1 &&arr[r1+ r2-1][ c1+ c2-2]!=' '){
            if(arr[r1+ r2-4][ c1+ c2-2]==' '&&arr[r1+ r2-3][ c1+ c2-1]!=' '&&arr[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-4][ c1+ c2-2]=arr[r1+ r2-2][ c1+ c2-2];
             arr[r1+ r2-3][ c1+ c2-2]=arr[r1+ r2-3][ c1+ c2-2];
             (r1)--;
             ( r2)--;
             openChain(gameSize,arr,r1-1,c1,r2-1,c2,z,moves,score);
            }
            else if(arr[r1+ r2-4][ c1+ c2-2]!=' '&&arr[r1+ r2-3][ c1+ c2-1]==' '&&arr[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-3][ c1+ c2-1]=arr[r1+ r2-2][ c1+ c2-2]-1;
             arr[r1+ r2-3][ c1+ c2-2]=arr[r1+ r2-3][ c1+ c2-2];
             if( c1> c2)   openChain(gameSize,arr,r1,c1,r2-1,c1,z,moves,score);
             else  openChain(gameSize,arr,r1,c2,r2-1,c2,z,moves,score);
            }
            else if(arr[r1+ r2-4][ c1+ c2-2]!=' '&&arr[r1+ r2-3][ c1+ c2-1]!=' '&&arr[r1+ r2-3][ c1+ c2-3]==' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-3][ c1+ c2-3]=arr[r1+ r2-2][ c1+ c2-2]-1;
             arr[r1+ r2-3][ c1+ c2-2]=arr[r1+ r2-3][ c1+ c2-2];
             if( c1> c2)   openChain(gameSize,arr,r1,c2,r2-1,c2,z,moves,score);
             else   openChain(gameSize,arr,r1,c1,r2-1,c1,z,moves,score);
            }
        }
    }
    else if( c1== c2){
      if( c1!=1&& arr[r1+ r2-2][ c1+ c2-1!=' ']){
            if(arr[r1+ r2-2][ c1+ c2-4]==' '&&arr[r1+ r2-1][ c1+ c2-3]!=' '&&arr[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-2][ c1+ c2-4]=arr[r1+ r2-2][ c1+ c2-2];
             arr[r1+ r2-2][ c1+ c2-3]=arr[r1+ r2-2][ c1+ c2-1];
             openChain(gameSize,arr,r1,c1-1,r2,c2-1,z,moves,score);
            }
            else if(arr[r1+ r2-2][ c1+ c2-4]!=' '&&arr[r1+ r2-1][ c1+ c2-3]!=' '&&arr[r1+ r2-3][ c1+ c2-3]==' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-3][ c1+ c2-3]=arr[r1+ r2-2][ c1+ c2-2]+1;
             arr[r1+ r2-2][ c1+ c2-3]=arr[r1+ r2-2][ c1+ c2-1];
             if(r1> r2) openChain(gameSize,arr,r2,c1-1,r2,c2,z,moves,score);
             else  openChain(gameSize,arr,r1,c1-1,r1,c2,z,moves,score);
             
            }
            else if(arr[r1+ r2-2][ c1+ c2-4]!=' '&&arr[r1+ r2-1][ c1+ c2-3]==' '&&arr[r1+ r2-3][ c1+ c2-3]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-1][ c1+ c2-3]=arr[r1+ r2-2][ c1+ c2-2]+1;
             arr[r1+ r2-2][ c1+ c2-3]=arr[r1+ r2-2][ c1+ c2-1];
             if(r1> r2) openChain(gameSize,arr,r1,c1-1,r1,c2,z,moves,score);
             else openChain(gameSize,arr,r2,c1-1,r2,c2,z,moves,score);
            }
      }
      else if( c1!=gameSize+1&& arr[r1+ r2-2][ c1+ c2-3!=' ']){
             if(arr[r1+ r2-2][ c1+ c2]==' '&&arr[r1+ r2-1][ c1+ c2-1]!=' '&&arr[r1+ r2-3][ c1+ c2-1]!=' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-2][ c1+ c2]=arr[r1+ r2-2][ c1+ c2-2];
             arr[r1+ r2-2][ c1+ c2-1]=arr[r1+ r2-2][ c1+ c2-3];
            openChain(gameSize,arr,r1,c1+1,r2,c2+1,z,moves,score);
             }
            else if(arr[r1+ r2-2][ c1+ c2]!=' '&&arr[r1+ r2-1][ c1+ c2-1]==' '&&arr[r1+ r2-3][ c1+ c2-1]!=' '){
             ( *z)--;
             ( *moves)++;
             (*score)++;
             arr[r1+ r2-3][ c1+ c2-1]=arr[r1+ r2-2][ c1+ c2-2]+1;
             arr[r1+ r2-2][ c1+ c2-1]=arr[r1+ r2-2][ c1+ c2-3];
             if(r1> r2)      openChain(gameSize,arr,r1,c1+1,r1,c2,z,moves,score);
             else        openChain(gameSize,arr,r2,c1+1,r2,c2,z,moves,score);
            }
            else if(arr[r1+ r2-2][ c1+ c2]!=' '&&arr[r1+ r2-1][ c1+ c2-1]!=' '&&arr[r1+ r2-3][ c1+ c2-1]==' '){
             (*z)--;
             (*moves)++;
             (*score)++;
             arr[r1+ r2-3][ c1+ c2-1]=arr[r1+ r2-2][ c1+ c2-2]+1;
             arr[r1+ r2-2][ c1+ c2-1]=arr[r1+ r2-2][ c1+ c2-3];
             if(r1> r2)  openChain(gameSize,arr,r2,c1+1,r2,c2,z,moves,score);
             else   openChain(gameSize,arr,r1,c1+1,r1,c2,z,moves,score);
            }
      }
    }
}
int dfs(int gameSize,char arr[2*gameSize+1][2*gameSize+1],int r1,int c1,int r2,int c2){
int x=1,y=1,z=1,w=1;
    if(r1==r2&&arr[r1+r2-3][c1+c2-2]==' '&& r1!=1){
       arr[r1+r2-3][c1+c2-2]='9';
       if(arr[r1+r2-4][c1+c2-2]!=' ') x=1;
       else x=dfs(gameSize,arr,r1-1,c1,r2-1,c2);
       if(arr[r1+r2-3][c2+c2-2]!=' ') y=1;
       else y=dfs(gameSize,arr,r1,c2,r2-1,c2);
       if(arr[r1+r2-3][c1+c1-2]!=' ') z=1;
       else z=dfs(gameSize,arr,r1,c1,r2-1,c1);
}
else if(r1==r2&&r1==1) x=0;
else if(r1==r2&&arr[r1+r2-1][c1+c2-2]==' '&&r1!=gameSize+1){
       arr[r1+r2-1][c1+c2-2]='9';
       if(arr[r1+r2][c1+c2-2]!=' ') w=1;
       else w=dfs(gameSize,arr,r1+1,c1,r2+1,c2);
       if(openChain[r1+r2-1][c2+c2-2]!=' ') y=1;
       else y=dfs(gameSize,arr,r1,c2,r2+1,c2);
       if(arr[r1+r2-1][c1+c1-2]!=' ') z=1;
       else z=dfs(gameSize,arr,r1,c1,r2+1,c1);
}
else if(r1==r2&&r1==gameSize+1) w=0;
     if(c1==c2&&arr[r1+r2-2][c1+c2-3]==' '&&r1!=1){
       arr[r1+r2-2][c1+c2-3]='9';
       if(arr[r1+r2-2][c1+c2-4]!=' ') z=1;
       else x=dfs(gameSize,arr,r1,c1-1,r2,c2-1);
       if(arr[r1+r2-2][c2+c2-3]!=' ') x=1;
       else y=dfs(gameSize,arr,r1,c1-1,r2,c2);
       if(arr[r1+r2-2][c1+c1-3]!=' ') w=1;
       else z=dfs(gameSize,arr,r1,c2-1,r2,c1);
}
else if(c1==c2&&c1==1) z=0;
else if(c1==c2&&arr[r1+r2-2][c1+c2-1]==' '&&c1!=gameSize+1){
       arr[r1+r2-2][c1+c2-1]='9';
       if(arr[r1+r2-2][c1+c2]!=' ') y=1;
       else y=dfs(gameSize,arr,r1,c1+1,r2,c2+1);
       if(arr[r2+r2-2][c2+c1-1]!=' ') x=1;
       else x=dfs(gameSize,arr,r2,c1+1,r2,c2);
       if(arr[r1+r1-2][c1+c2-1]!=' ') w=1;
       else w=dfs(gameSize,arr,r1,c2+1,r1,c1);
}
else if(c1==c2&&c1==gameSize+1) y=0;
int r=(x*y*z*w);
return r;
}
void chainOfBoxes(int gameSize,char arr[2*gameSize+1][2*gameSize+1],int r1,int c1,int r2,int c2,int* z,int* moves,int* Score){
    int i,j;
if(dfs(gameSize,arr,r1,c1,r2,c2)){
    for(i=0;i<=2*gameSize;i++){
        for(j=0;j<=2*gameSize;j++){
            if(arr[i][j]=='9'){
            (*z)--;
            (*moves)++;
            (*score)++;   
            if(arr[r1+r2-2][c1+c2-2]=='2'||arr[r1+r2-2][c1+c2-2]=='3'){
            if(arr[i][j+1]==' ') arr[i][j+1]='2';
            if(arr[i][j-1]==' ') arr[i][j-1]='2';
            if(arr[i+1][j]==' ') arr[i+1][j]='3';
            if(arr[i][j+1]==' ') arr[i-1][j]='3';
            arr[i][j]='6';
            }
            else {
            if(arr[i][j+1]==' ') arr[i][j+1]='4';
            if(arr[i][j-1]==' ') arr[i][j-1]='4';
            if(arr[i+1][j]==' ') arr[i+1][j]='5';
            if(arr[i][j+1]==' ') arr[i-1][j]='5';
            arr[i][j]='7';
            }
            }
        }
    }
}
else{
        for(i=0;i<=2*gameSize;i++){
        for(j=0;j<=2*gameSize;j++){
            if(arr[i][j]=='9'){
              arr[i][j]=' ';
            }
        }
    }

}
}
