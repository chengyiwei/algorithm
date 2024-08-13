#include<bits/stdc++.h>
using namespace std;

int n,m,K,h,ed_x,ed_y,INF;

int a[6][1005][1005],dis[6][1005][1005];

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}

struct node{
    int k,x,y;
    node(int k,int x,int y):k(k),x(x),y(y){}
};

int solve(){

    scanf("%d%d%d",&n,&m,&K);
    for(int k=1;k<=K;k++)
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        char ch=getchar();
        while(ch!='.'&&ch!='*') ch=getchar();
        a[k][i][j]=(ch=='*');
    }
    scanf("%d%d%d",&h,&ed_x,&ed_y);
    if(ed_x==n&&ed_y==m) return 1;
    memset(dis,0x3f,sizeof(dis)); INF=dis[0][0][0];
    queue<node> Q; Q.push(node(1,n,m)); dis[1][n][m]=0;

    while(!Q.empty()){
        node now=Q.front(); Q.pop();
        int n_k,n_x,n_y; n_k=now.k+1;if(n_k>K) n_k=1;
        if(now.x==n||a[now.k][now.x+1][now.y]==1){  // 可以跳一下
            for(int i=0;i<=h;i++){
                if(a[now.k][now.x-i][now.y]==1) break; //被卡住
                for(int j=-1;j<=1;j++){
                    n_x=now.x-i; n_y=j+now.y;
                    if(n_x<1||n_x>n||n_y<1||n_y>m) continue;
                    if(a[n_k][n_x][n_y]==1 || dis[n_k][n_x][n_y]!=INF || a[now.k][n_x][n_y]==1) continue;
                    dis[n_k][n_x][n_y]=dis[now.k][now.x][now.y]+1;
                    if(n_x==ed_x&&n_y==ed_y) return dis[n_k][n_x][n_y];
                    Q.push(node(n_k,n_x,n_y));
                }
            }
        }
        else{ //往下掉
            if(a[now.k][now.x+1][now.y]==0){
                n_x=now.x+1;
                for(int j=-1;j<=1;j++){
                    n_y=now.y+j;
                    if(n_x<1||n_x>n||n_y<1||n_y>m) continue;
                    if(a[n_k][n_x][n_y]==1 || dis[n_k][n_x][n_y]!=INF || a[now.k][n_x][n_y]==1) continue;
                    dis[n_k][n_x][n_y]=dis[now.k][now.x][now.y]+1;
                    if(n_x==ed_x&&n_y==ed_y) return dis[n_k][n_x][n_y];
                    Q.push(node(n_k,n_x,n_y));
                }
            }
        }
    }
    return -1;
}

int main(){
    freopen("G.in","r",stdin);
    freopen("G.out","w",stdout);
    int T; scanf("%d",&T);
    while(T--) printf("%d\n",solve());
}