#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int T,N;
int t[maxn],w[maxn],F[maxn][maxn];
const int INF=0x3f3f3f3f;
int ans=0;

int DFS(int pos,int left_time){
    if(F[pos][left_time]!=-1) return F[pos][left_time];
    if(pos==N+1){
        return F[pos][left_time]=0;
    }
    int dfs1,dfs2=-INF;
    dfs1=DFS(pos+1,left_time);
    if(left_time>=t[pos]) //如果还有时间
        dfs2=DFS(pos+1,left_time-t[pos])+w[pos];
    return F[pos][left_time]=max(dfs1,dfs2);
}

int main(){
    freopen("P1048.in","r",stdin);
    memset(F,-1,sizeof F);
    cin>>T>>N;
    for(int i=1;i<=N;i++)
        cin>>t[i]>>w[i];
    cout<<DFS(1,T)<<endl;
    return 0;
}