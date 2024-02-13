#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
char mp[maxn][maxn];
int n,m,F[maxn][maxn][maxn][maxn];

int main(){
    freopen("CF1199F.in","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cin>>mp[i][j];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            F[i][j][i][j] = (mp[i][j] == '#');
    for(int len_x=1;len_x<=n;len_x++)
        for(int len_y=1;len_y<=n;len_y++)
            for(int x_1=1;x_1+len_x-1<=n;x_1++)
                for(int y_1=1;y_1+len_y-1<=n;y_1++){
                    int x_2 = x_1+len_x-1, y_2 = y_1+len_y-1;
                    if(len_x == 1 && len_y == 1) continue;
                    F[x_1][y_1][x_2][y_2] = max(len_x,len_y);
                    for(int k=x_1;k<x_2;k++)
                        F[x_1][y_1][x_2][y_2] = min(F[x_1][y_1][x_2][y_2],F[x_1][y_1][k][y_2]+F[k+1][y_1][x_2][y_2]);
                    for(int k=y_1;k<y_2;k++)
                        F[x_1][y_1][x_2][y_2] = min(F[x_1][y_1][x_2][y_2],F[x_1][y_1][x_2][k]+F[x_1][k+1][x_2][y_2]);  
                }
    printf("%d\n",F[1][1][n][n]);
    return 0;
}