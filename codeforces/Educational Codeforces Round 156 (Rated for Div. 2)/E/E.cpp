#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int N,M;
int F[1<<19+5],mn[25][maxn],lst[1<<19+5];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int a[maxn],id[maxn],b[25],INF;
vector<int> ans[maxn];
bool cmp(int i,int j){return a[i]>a[j];}
int main(){
    // freopen("E.in","r",stdin);
    // freopen("E.out","w",stdout);
    N=read();M=read();
    for(int i=1;i<=N;i++) a[i]=read(),id[i]=i;
    for(int i=1;i<=M;i++) b[i]=read();
    sort(id+1,id+1+N,cmp);
    
    memset(F,127,sizeof F);INF=F[0];
    for(int i=1;i<=M;i++){
        int r=1;
        for(int l=0;l<=N;l++){
            r=max(r,l+1);
            while(r<=N&&a[id[r]]*(r-l)<b[i]) ++r;
            mn[i][l]=(r==N+1?INF:r);
        }
    }
    
    F[0]=0;
    for(int s=0;s<(1<<M);s++)if(F[s]!=INF)
        for(int i=1;i<=M;i++)
            if(!((s>>(i-1))&1)&&F[s|(1<<(i-1))]>mn[i][F[s]]){
                F[s|(1<<(i-1))]=mn[i][F[s]];
                lst[s|(1<<(i-1))]=s;
            }
    
    if(F[(1<<M)-1]==INF){printf("NO\n");return 0;}
    printf("YES\n");
    
    int now=(1<<M)-1;
    while(now){
        int i=__builtin_ctz(now^lst[now]);
        for(int j=F[lst[now]]+1;j<=F[now];j++)
            ans[i+1].push_back(id[j]);
        now=lst[now];
    }
    for(int i=1;i<=M;i++){
        printf("%d",ans[i].size());
        for(int x:ans[i]) printf(" %d",x);
        printf("\n");
    }
    return 0;
}