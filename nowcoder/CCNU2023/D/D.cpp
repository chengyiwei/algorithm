#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;

int n,m,k;
int b[maxn][maxn];
int vis[maxn][maxn];
struct node{int x,y;}pre[maxn][maxn];

int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

bool bfs(){
    queue<node> q;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        vis[i][j]=(b[i][j]);
    q.push((node){1,1});vis[1][1]=0;
    while(!q.empty()){
        int x=q.front().x,y=q.front().y;q.pop();int x_,y_;

        if(x==n&&y==m) {
            while(1) {
                node pre_node=pre[x][y];
                if(pre_node.x==1&&pre_node.y==1) return 1;
                else x=pre_node.x,y=pre_node.y;
                b[x][y]=1;
            }
        }

        x_,y_;x_=x+1,y_=y;
        if(x_<=n&&y_<=m&&vis[x_][y_]==0){
            q.push((node){x_,y_});
            vis[x_][y_]=1;pre[x_][y_]=(node){x,y};
        }

        x_,y_;x_=x,y_=y+1;
        if(x_<=n&&y_<=m&&vis[x_][y_]==0){
            q.push((node){x_,y_});
            vis[x_][y_]=1;pre[x_][y_]=(node){x,y};
        }
    }
    return 0;
}

int main(){
    freopen("D.in","r",stdin);
    n=read(),m=read(),k=read();
    for(int i=1;i<=k;i++){
        int x=read(),y=read();
        b[x][y]=1;
    }
    if(!bfs()) printf("0\n");
    else if(!bfs()) printf("1\n");
    else printf("2\n");
    return 0;
}