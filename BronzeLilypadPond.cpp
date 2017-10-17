//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>
#include <queue>

using namespace std;
queue<int> pox;
queue<int> poy;
int m, n, m1, m2;
int mat[35][35], visited[35][35];

int check(int x, int y)
{
    if(x>=0 && x<m && y>=0 && y<n)
        return 1;
    return 0;
}

int bfs(int row, int col)
{
    pox.push(row), poy.push(col);
    visited[row][col]=1;
    while(!pox.empty()){
        int x=pox.front(), y=poy.front();
        pox.pop(), poy.pop();
        int step=visited[x][y];
        if(mat[x][y]!=1 && mat[x][y]!=4 && mat[x][y]!=3)
            continue;
        if(mat[x][y]==4){
            return step-1;
        }
        if(check(x+m1, y+m2) && !visited[x+m1][y+m2])
            pox.push(x+m1), poy.push(y+m2), visited[x+m1][y+m2]=step+1;
        if(check(x+m1, y-m2) && !visited[x+m1][y-m2])
            pox.push(x+m1), poy.push(y-m2), visited[x+m1][y-m2]=step+1;
        if(check(x-m1, y+m2) && !visited[x-m1][y+m2])
            pox.push(x-m1), poy.push(y+m2), visited[x-m1][y+m2]=step+1;
        if(check(x-m1, y-m2) && !visited[x-m1][y-m2])
            pox.push(x-m1), poy.push(y-m2), visited[x-m1][y-m2]=step+1;
        if(check(x+m2, y+m1) && !visited[x+m2][y+m1])
            pox.push(x+m2), poy.push(y+m1), visited[x+m2][y+m1]=step+1;
        if(check(x+m2, y-m1) && !visited[x+m2][y-m1])
            pox.push(x+m2), poy.push(y-m1), visited[x+m2][y-m1]=step+1;
        if(check(x-m2, y+m1) && !visited[x-m2][y+m1])
            pox.push(x-m2), poy.push(y+m1), visited[x-m2][y+m1]=step+1;
        if(check(x-m2, y-m1) && !visited[x-m2][y-m1])
            pox.push(x-m2), poy.push(y-m1), visited[x-m2][y-m1]=step+1;
    }
    return 0;
}

int main()
{
    int x, y;
    int i, j;
    
    cin >> m >> n >> m1 >> m2;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            cin >>mat[i][j];
            if(mat[i][j]==3)
                x=i, y=j;
        }
    }
    
    cout << bfs(x, y) << endl;
    
    return 0;
}
