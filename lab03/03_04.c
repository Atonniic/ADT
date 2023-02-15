#include <stdio.h>
#include <stdlib.h>

char maze[101][101];
int n;

void traverseMaze(int i,int j) {
    int k, di[4]={1,-1,0,0}, dj[4]={0,0,1,-1};
    if (i<0 || i>=n) {
        return;
    }
    else if (j<0 || j>=n) {
        return;
    }
    else if (maze[i][j]=='#' || maze[i][j]=='.') {
        return;
    }
    if (maze[i][j] == 'G') {
        for (i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                printf("%c" ,maze[i][j]);
            }
            printf("\n");
        }
        exit(0);
    }
    if (maze[i][j] != 'S') {
        maze[i][j] = '.';
    }
    for (k=0; k<4; k++){
        if(maze[i+di[k]][j+dj[k]] != 'S') {
            traverseMaze(i+di[k],j+dj[k]);
        }
    }
    if (maze[i][j]!='S') {
        maze[i][j] = ' ';
    }
    return;
}

int main(){
    int i, j, start_i, start_j;;
    scanf("%d", &n);
    for (i=0; i<n; i++) {
        scanf(" %[^\n]s", maze[i]);
        for (j=0; j<n; j++) {
            if (maze[i][j] == 'S') {
                start_i = i; 
                start_j = j;
            }
        }
    }
    traverseMaze(start_i, start_j);
    return 0;
}
