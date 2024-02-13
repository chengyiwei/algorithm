#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
int bit[12] = {0,1,3,9,27,81,243,729,2187,6561,19683,59049};
int tri[60000][11];
int F[11][60000];
int g[11][11];

void make_tri(){
    for(int i=0;i<59050;i++){
        int tmp = i;
        for(int j=1;j<=10;j++){
            tri[i][j] = tmp % 3;
            tmp /= 3;
        }
    }
}

int dp(){
    int ans = INF;
    memset(F,INF,sizeof(F));
    for(int j=0;j<=n;j++)
        F[j][bit[j]] = 0;
    for(int i=0;i<bit[n+1];i++){
        int flg = 1;
        for(int j=1;j<=n;j++){
            if(tri[i][j] == 0){
                flg = 0;
                continue;
            }
            for(int k=1;k<=n;k++){
                int l = i - bit[j];
                F[j][i] = min(F[j][i], F[k][l] + g[j][k]);  // j -> k
            }
        }
        if(flg){
            for(int j=1;j<=n;j++)
                ans = min(ans, F[j][i]);
        }
    }
    return ans;
}

int main(){
    make_tri();
    while(scanf("%d%d",&n,&m) != EOF){
        memset(g,INF,sizeof(g));
        while(m--){
            int a,b,c; scanf("%d%d%d",&a,&b,&c);
            if(c < g[a][b]) g[a][b] = g[b][a] = c;
        }
        int ans = dp();
        if(ans == INF) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}