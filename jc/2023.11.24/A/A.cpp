#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=505;
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int N;
vector<int> E[maxn],Q[maxn];
vector<int> pos[maxn];
int du[maxn];

inline void topo(){
    queue<int> q;
    int num=0,ans=0;
    for(int i=1;i<=N;i++){
        if(!du[i]) q.push(i),num++;
    }
    while(!q.empty()){
        int now=q.front();q.pop();
        int M=E[now].size();
        for(int j=0;j<M;j++){
            du[E[now][j]]--;
            if(du[E[now][j]]==0) q.push(E[now][j]),num++;
        }
    }
    if(num==0) printf("YES\n");
    else printf("%d\n",N-num);
    return ;
}
signed main(){
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        int x;scanf("%d",&x);
        pos[x].push_back(i);
        int M;scanf("%d",&M);
        for(int j=1;j<=M;j++){
        	int now;scanf("%d",&now);
            Q[i].push_back(now);
        }
    }
    for(int i=1;i<=N;i++){
        int M=Q[i].size();
        for(int j=0;j<M;j++){
        	if(pos[Q[i][j]].size()==0)continue; //pos这个地方没有监视器
            for(auto p: pos[Q[i][j]]){
                E[i].push_back(p);
                du[p]++;
            }
        }
    }
    topo();
    return 0;
}
