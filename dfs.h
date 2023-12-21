void dfs(char arr[gameSIze+1][],int gameSIze,int *r1,int *c1,int *r2,int *c2,int *z,int *moves,int *score){
    if(*r1==*r2){
        if(*r1!=gameSIze+1 && arr[*r1+*r2-3][*c1+*c2-2]!=' '){
            if(arr[*r1+*r2][*c1+*c2-2]==' '&&arr[*r1+*r2-1][*c1+*c2-1]!=' '&&arr[*r1+*r2-1][*c1+*c2-3]!=' '){
             *z--;
             *moves++;
             *score++;
             arr[*r1+*r2][*c1+*c2-2]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-1][*c1+*c2-2]=arr[*r1+*r2-3][*c1+*c2-2];
             *r1++;
             *r2++;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
            else if(arr[*r1+*r2][*c1+*c2-2]!=' '&&arr[*r1+*r2-1][*c1+*c2-1]==' '&&arr[*r1+*r2-1][*c1+*c2-3]!=' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-1][*c1+*c2-1]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-1][*c1+*c2-2]=arr[*r1+*r2-3][*c1+*c2-2];
             *r2++;
             if(*c1>*c2) *c2=*c1;
             else *c1=*c2;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
            else if(arr[*r1+*r2][*c1+*c2-2]!=' '&&arr[*r1+*r2-1][*c1+*c2-1]!=' '&&arr[*r1+*r2-1][*c1+*c2-3]==' ') {
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-1][*c1+*c2-3]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-1][*c1+*c2-2]=arr[*r1+*r2-3][*c1+*c2-2];
             *r2++;
             if(*c1>*c2) *c1=*c2;
             else *c2=*c1;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
        }
        else if(*r1!=1 &&arr[*r1+*r2-1][*c1+*c2-2]!=' '){
            if(arr[*r1+*r2-4][*c1+*c2-2]==' '&&arr[*r1+*r2-3][*c1+*c2-1]!=' '&&arr[*r1+*r2-3][*c1+*c2-3]!=' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-4][*c1+*c2-2]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-3][*c1+*c2-2]=arr[*r1+*r2-3][*c1+*c2-2];
             *r1--;
             *r2--;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
            else if(arr[*r1+*r2-4][*c1+*c2-2]!=' '&&arr[*r1+*r2-3][*c1+*c2-1]==' '&&arr[*r1+*r2-3][*c1+*c2-3]!=' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-3][*c1+*c2-1]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-3][*c1+*c2-2]=arr[*r1+*r2-3][*c1+*c2-2];
             *r1--;
             if(*c1>*c2) *c2=*c1;
             else *c1=*c2;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
            else if(arr[*r1+*r2-4][*c1+*c2-2]!=' '&&arr[*r1+*r2-3][*c1+*c2-1]!=' '&&arr[*r1+*r2-3][*c1+*c2-3]==' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-3][*c1+*c2-3]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-3][*c1+*c2-2]=arr[*r1+*r2-3][*c1+*c2-2];
             *r1--;
             if(*c1>*c2) *c1=*c2;
             else *c2=*c1;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
        }
    }
    else if(*c1==*c2){
      if(*c1!=1&& arr[*r1+*r2-2][*c1+*c2-1!=' ']){
            if(arr[*r1+*r2-2][*c1+*c2-4]==' '&&arr[*r1+*r2-1][*c1+*c2-3]!=' '&&arr[*r1+*r2-3][*c1+*c2-3]!=' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-2][*c1+*c2-4]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-2][*c1+*c2-3]=arr[*r1+*r2-2][*c1+*c2-1];
             *c1--;
             *c2--;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
            else if(arr[*r1+*r2-2][*c1+*c2-4]!=' '&&arr[*r1+*r2-1][*c1+*c2-3]!=' '&&arr[*r1+*r2-3][*c1+*c2-3]==' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-3][*c1+*c2-3]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-2][*c1+*c2-3]=arr[*r1+*r2-2][*c1+*c2-1];
             *c1--;
             if(*r1>*r2) *r1=*r2;
             else *r2=*r1;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
            else if(arr[*r1+*r2-2][*c1+*c2-4]!=' '&&arr[*r1+*r2-1][*c1+*c2-3]==' '&&arr[*r1+*r2-3][*c1+*c2-3]!=' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-1][*c1+*c2-3]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-2][*c1+*c2-3]=arr[*r1+*r2-2][*c1+*c2-1];
             *c1--;
             if(*r1>*r2) *r2=*r1;
             else *r1=*r2;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
      }
      else if(*c1!=gameSIze+1&& arr[*r1+*r2-2][*c1+*c2-3!=' ']){
             if(arr[*r1+*r2-2][*c1+*c2]==' '&&arr[*r1+*r2-1][*c1+*c2-1]!=' '&&arr[*r1+*r2-3][*c1+*c2-1]!=' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-2][*c1+*c2]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-2][*c1+*c2-1]=arr[*r1+*r2-2][*c1+*c2-3];
             *c1++;
             *c2++;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
             }
            else if(arr[*r1+*r2-2][*c1+*c2]!=' '&&arr[*r1+*r2-1][*c1+*c2-1]==' '&&arr[*r1+*r2-3][*c1+*c2-1]!=' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-3][*c1+*c2-1]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-2][*c1+*c2-1]=arr[*r1+*r2-2][*c1+*c2-3];
             *c1--;
             if(*r1>*r2) *r2=*r1;
             else *r1=*r2;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
            else if(arr[*r1+*r2-2][*c1+*c2]!=' '&&arr[*r1+*r2-1][*c1+*c2-1]!=' '&&arr[*r1+*r2-3][*c1+*c2-1]==' '){
                 *z--;
             *moves++;
             *score++;
             arr[*r1+*r2-3][*c1+*c2-1]=arr[*r1+*r2-2][*c1+*c2-2];
             arr[*r1+*r2-2][*c1+*c2-1]=arr[*r1+*r2-2][*c1+*c2-3];
             *c1--;
             if(*r1>*r2) *r1=*r2;
             else *r2=*r1;
             dfs(arr,gameSize,r1,c1,r2,c2,z,moves,score);
            }
      }
    }
}
