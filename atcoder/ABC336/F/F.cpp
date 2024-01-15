#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
typedef vector<vector<int> > vee;
int n,m,ans=100000;
map<vee,int> mp;

void F(int x,int y,vee& now){
    for(int i=1;i<=(n-1)/2;i++)
    for(int j=1;j<=(m-1);j++){
        swap(now[i+x][j+y],now[n-i+x][m-j+y]);
    }
}

void dfs1(vee a,int stp,int lst_x,int lst_y){
    if(stp>10) return ;
    if(mp.find(a)!=mp.end()) return ;
    mp[a]=stp;
    for(int x=0;x<=1;x++)
    for(int y=0;y<=1;y++){
        if(x==lst_x&&y==lst_y) continue;
        vee now=a;
        F(x,y,now);
        dfs1(now,stp+1,x,y);
    }
}

void dfs2(vee a,int stp,int lst_x,int lst_y){
    if(stp>2) return ;
    if(mp.find(a)!=mp.end()){
        ans=min(ans,stp+mp[a]);
    }
    for(int x=0;x<=1;x++)
    for(int y=0;y<=1;y++){
        if(x==lst_x&&y==lst_y) continue;
        vee now=a;
        F(x,y,now);
        dfs1(now,stp+1,x,y);
    }
}

int main(){
    freopen("F.in","r",stdin);
    vee st;
    scanf("%d%d",&n,&m);
    st.assign(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        cin>>st[i][j];
    }
    dfs1(st,0,-1,-1);
    int tot=0;
    vee ed(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        ed[i][j]=++tot;
    dfs2(ed,0,-1,-1);
    if(ans==INF||ans>20)
        printf("-1\n");
    else 
        printf("%d\n",ans);
    return 0;
}