#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int H,W,g[maxn][maxn],fa[maxn*maxn],tot,ans,hsh[maxn*maxn];
char mp[maxn][maxn];
const int flg[8][2]={{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
int getfa(int x){
    return (fa[x]==x)?x:fa[x]=getfa(fa[x]);
}
int main(){
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d%d\n",&H,&W);
    for(int i=1;i<=H;i++)scanf("%s",mp[i]+1);
    for(int i=1;i<=H;i++)
    for(int j=1;j<=W;j++){
        g[i][j]=++tot;
        fa[tot]=tot;
    }
    for(int i=1;i<=H;i++)
    for(int j=1;j<=W;j++)if(mp[i][j]=='#'){
        for(int k=0;k<8;k++)if(mp[i+flg[k][0]][j+flg[k][1]]=='#'){
            int fx=getfa(g[i][j]),fy=getfa(g[i+flg[k][0]][j+flg[k][1]]);
            if(fx==fy)continue;
            fa[fx]=fy;
        }
    }
    
    for(int i=1;i<=H;i++)
    for(int j=1;j<=W;j++)if(mp[i][j]=='#'){
        int F=getfa(g[i][j]);
        if(hsh[F]==0) ans++,hsh[F]=1;
    }
    printf("%d\n",ans);
    return 0;
}