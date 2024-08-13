#include<bits/stdc++.h>
using namespace std;
const int maxn = 65;
int mp[maxn][maxn];
const int INF = 0x3f3f3f3f;

const int flg[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int n;
struct node{
    int x,y;
    node(int x,int y):x(x),y(y){}
}A(0,0),B(0,0);

struct AS{
    node A,B;
    int dis;
    AS(node A,node B,int dis):A(A),B(B),dis(dis){}
};

bool check(int x,int y){
    if(mp[x][y]) return 0;
    return x >= 1 && x <= n && y >= 1 && y <= n;
}

node next(int x,int y,int op){
    int nx = x + flg[op][0], ny = y + flg[op][1];
    if(check(nx,ny)) return node(nx,ny);
    return node(x,y);
}

int vis[maxn][maxn][maxn][maxn];
int ans = INF;

void bfs(){
    queue<AS> q;
    q.push(AS(A,B,0));
    while(!q.empty()){
        node now_A = q.front().A, now_B = q.front().B; int now_dis = q.front().dis; q.pop();
        if(now_A.x == now_B.x && now_A.y == now_B.y){ans = now_dis;break;}
        for(int k=0;k<4;k++){
            node nxt_A = next(now_A.x,now_A.y,k), nxt_B = next(now_B.x,now_B.y,k);
            if(vis[nxt_A.x][nxt_A.y][nxt_B.x][nxt_B.y]) continue;
            q.push(AS(nxt_A,nxt_B,now_dis+1));
            vis[nxt_A.x][nxt_A.y][nxt_B.x][nxt_B.y] = 1;
        }
    }
}

int main(){
    freopen("D.in","r",stdin);
    scanf("%d",&n); getchar();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) {
            char ch = getchar();
            if(ch == '#') mp[i][j] = 1;
            else if(ch == '.') mp[i][j] = 0;
            else {
                if(A.x == 0) A = node(i,j);
                else B = node(i,j);
            }
        }
        getchar();
    }
    
    bfs();
    if (ans == INF) ans = -1; printf("%d\n",ans);
    return 0;
}