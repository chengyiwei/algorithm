#include<bits/stdc++.h>
using namespace std;
const int maxn = 305;
int n, m, k, ans = 0;
int mp[maxn][maxn];

int main(){
    freopen("B.in","r",stdin);
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++){
        int x, y; scanf("%d%d",&x,&y);
        mp[x][y] = 1;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) if(mp[i][j]){
            ans += 2;
            if(mp[i][j + 1] == 0) ans += 1;
            if(mp[i + 1][j] == 0) ans += 1;
        }
    printf("%d\n",ans);
    return 0;
}