#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int N,Q;
int vis[maxn];
typedef pair<int,int> pii;
set<pii> p;
int get(int x,int y){
    return N*x+y;
}
void in(int x_1,int y_1,int x_2,int y_2){
    int now_1=get(x_1,y_1),now_2=get(x_2,y_2);
    if(now_2<now_1) swap(now_1,now_2);
    pii now_pair=make_pair(now_1,now_2);
    if(p.find(now_pair)==p.end()) //如果不存在
        p.insert(now_pair);
}
void de(int x_1,int y_1,int x_2,int y_2){
    int now_1=get(x_1,y_1),now_2=get(x_2,y_2);
    if(now_2<now_1) swap(now_1,now_2);
    pii now_pair=make_pair(now_1,now_2);
    if(p.find(now_pair)!=p.end()) //如果存在
        p.erase(now_pair);
}
int main(){
    freopen("D.in","r",stdin);
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=Q;i++){
        int x,y;scanf("%d%d",&x,&y);x--;
        int now=get(x,y);
        if(vis[now]==0){ //放置一个
            vis[now]=1;
            if(y!=1&&vis[get(x^1,y-1)]==1)
                in(x,y,x^1,y-1);
            if(vis[get(x^1,y)]==1)
                in(x,y,x^1,y);
            if(y!=N&&vis[get(x^1,y+1)]==1)
                in(x,y,x^1,y+1);
        }
        else { //拿走一个
            vis[now]=0;
            if(y!=1&&vis[get(x^1,y-1)]==1)
                de(x,y,x^1,y-1);
            if(vis[get(x^1,y)]==1)
                de(x,y,x^1,y);
            if(y!=N&&vis[get(x^1,y+1)]==1)
                de(x,y,x^1,y+1);
        }
        if(p.size()==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
}