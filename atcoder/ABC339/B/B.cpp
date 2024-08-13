#include<bits/stdc++.h>
using namespace std;
int flg[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int maxn = 105;
int mp[maxn][maxn];
int main(){
    int H,W,N; cin>>H>>W>>N;
    int x = 0, y = 0, op = 0;
    while(N--){
        if(mp[x][y] == 0){
            op = (op+1)%4; //顺时针
            mp[x][y] = 1;
            x = (x+flg[op][0]+H)%H; // x1 =( x + dx + H) % H
            y = (y+flg[op][1]+W)%W;
        }
        else{
            op = (op+3)%4; //逆时针
            mp[x][y] = 0;
            x = (x+flg[op][0]+H)%H;
            y = (y+flg[op][1]+W)%W;
        }
    }
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            printf("%c",mp[i][j]?'#':'.');
        }
        printf("\n");
    }
    return 0;
}