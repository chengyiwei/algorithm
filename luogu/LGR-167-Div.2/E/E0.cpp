#include<bits/stdc++.h>
using namespace std;
const int flg[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
typedef long long LL;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
const int maxn=1e5+5;
struct AS{
    int w,y,x,id;
}q[maxn];
int n;

void AC1(){
    vector<vector<int> > vis(n+2);
    for(auto& e:vis) e.assign(n+2,0);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
        vis[i][j]=1;
    for(int i=1;i<=n;i++){
        if(q[i].y==1){
            for(int j=1;j<=n;j++)
                vis[q[i].x][j]=q[i].w;
        }
        else{
            for(int j=1;j<=n;j++)
                vis[j][q[i].x]=q[i].w;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)if(vis[i][j]){
            for(int k=0;k<4;k++){
                if(vis[i+flg[k][0]][j+flg[k][1]]==0)
                    ans++;
            }
        }   
        printf("%d\n",ans);
    }
}

void ACB(){
    vector<int> vis(n+2,0);
    for(int i=1;i<=n;i++) vis[i]=1;
    LL ans=n*4;
    for(int i=1;i<=n;i++){
        if(q[i].w==0){
            if(vis[q[i].x]==0){printf("%lld\n",ans);continue;}
            if(vis[q[i].x+1]&&vis[q[i].x-1]) ans=ans-2+n*2;
            else if(vis[q[i].x+1]==0&&vis[q[i].x-1]==0) ans=ans-2-2*n;
            else ans=ans-2; 
            vis[q[i].x]=0;
        }
        else{
            if(vis[q[i].x]==1){printf("%lld\n",ans);continue;}
            if(vis[q[i].x+1]&&vis[q[i].x-1]) ans=ans+2-2*n;
            else if(vis[q[i].x+1]==0&&vis[q[i].x-1]==0) ans=ans+2+2*n;
            else ans=ans+2; 
            vis[q[i].x]=1;
        }
        printf("%lld\n",ans);
    }
}

void ACA(){
    vector<int> visx(n+2,0),visy(n+2,0);
    for(int i=1;i<=n;i++) visx[i]=visy[i]=1;
    LL ans=n*4,now_x=n,now_y=n,kong_x=0,kong_y=0;
    for(int i=1;i<=n;i++){
        if(q[i].y==1){//染x行
            if(visx[q[i].x]==0){printf("%lld\n",ans);continue;}
            if(visx[q[i].x+1]&&visx[q[i].x-1]) ans=ans-2+now_y*2;
            else if(visx[q[i].x+1]==0&&visx[q[i].x-1]==0) ans=ans-2-2*now_y;
            else ans=ans-2; 
            visx[q[i].x]=0;
            now_x--;
        }
        else {//染x列
            if(visy[q[i].x]==0){printf("%lld\n",ans);continue;}
            if(visy[q[i].x+1]&&visy[q[i].x-1]) ans=ans-2+now_x*2;
            else if(visy[q[i].x+1]==0&&visy[q[i].x-1]==0) ans=ans-2-2*now_x;
            else ans=ans-2; 
            visy[q[i].x]=0;
            now_y--;
        }
        printf("%lld\n",ans);
    }

}

int main(){
    freopen("E.in","r",stdin);
    n=read();
    for(int i=1;i<=n;i++)
        q[i].w=read(),q[i].y=read(),q[i].x=read(),q[i].id=i;
    int flg=0;
    for(int i=1;i<=n;i++) flg|=q[i].y;
        if(flg==0) {ACB();return 0;}
    flg=0;
    for(int i=1;i<=n;i++) flg|=q[i].w;
    if(flg==0) {ACA();return 0;}
    AC1();
}