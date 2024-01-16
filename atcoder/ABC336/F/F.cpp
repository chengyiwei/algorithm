#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
typedef long long LL;
typedef vector<vector<int> > vee;
int n,m,ans=INF;
map<vee,int> mp1,mp2;

void F(int x,int y,vee& now){
    int cnt=0;
    for(int i=1;i<=(n-1);i++)
    for(int j=1;j<=(m-1);j++){
        swap(now[i+x][j+y],now[n-i+x][m-j+y]);
        if(++cnt>=(n-1)*(m-1)/2) return ;
    }
}

void bfs1(vee a){
    queue<vee> q;q.push(a);mp1[a]=0;
    while(!q.empty()){
        vee now=q.front(); q.pop();
        int stp=mp1[now];
        if(stp>=10) return;
        for(int x=0;x<=1;x++)
        for(int y=0;y<=1;y++){
            vee nxt=now;
            F(x,y,nxt);
            if(mp1.find(nxt)==mp1.end()){
                mp1[nxt]=stp+1;
                q.push(nxt);
            }
        }
    }
}

void bfs2(vee a){
    queue<vee> q;q.push(a);
    mp2[a]=0;
    while(!q.empty()){
        vee now=q.front(); q.pop();
        int stp=mp2[now];
        if(stp>=10) return;
        for(int x=0;x<=1;x++)
        for(int y=0;y<=1;y++){
            vee nxt=now;
            F(x,y,nxt);
            if(mp2.find(nxt)==mp2.end()){
                mp2[nxt]=stp+1;
                q.push(nxt);
            }
        }
    }
}

int main(){
    freopen("F.in","r",stdin);
    vee st;
    scanf("%d%d",&n,&m);
    st.assign(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&st[i][j]);
    bfs1(st);

    int tot=0;vee ed(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++) ed[i][j]=++tot;
    bfs2(ed);

    for(auto it=mp1.begin();it!=mp1.end();++it){
        if(mp2.find(it->first)!=mp2.end())
            ans=min(ans,it->second+mp2[it->first]);
    }

    if(ans==INF||ans>20)
        printf("-1\n");
    else 
        printf("%d\n",ans);
    return 0;
}