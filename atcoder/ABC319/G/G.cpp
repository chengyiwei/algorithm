#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=200205,maxe=400405;
const LL TT= 998244353;
int N,M,Q[maxn];
LL sum,dis[maxn],F[maxn],S[maxn];
inline int read(){
    int ret = 0, f = 1;char ch = getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f = -f;ch=getchar();}
    while(ch>='0'&&ch<='9')ret=ret*10+ch-48,ch=getchar();
    return ret;
}
int cnt,nxt[maxe],lnk[maxn],son[maxe],father[maxn],up[maxn],tot,clen[maxn];
inline void add_e(int x,int y){
    son[++cnt]=y;nxt[cnt]=lnk[x];lnk[x]=cnt;
}
int main(){
    freopen("G.in","r",stdin);
    freopen("G.out","w",stdout);
    N=read();M=read();
    for(int i=1;i<=M;i++){
        int a=read(),b=read();
        add_e(a,b);add_e(b,a);
    }
    dis[1]=1;F[1]=1;int hed=0,til=1;Q[til]=1;
    while(hed!=til){
        ++hed;
        for(int j=lnk[Q[hed]];j;j=nxt[j])
            if(dis[son[j]]==0){
                S[son[j]]=(S[son[j]]+F[Q[hed]])%TT;
                up[son[j]]++;clen[++clen[0]]=son[j];
            }
        sum=(sum+F[Q[hed]])%TT;tot++;
        if(hed==til){
            for(int i=1;i<=N;i++){
                if(!dis[i]&&S[i]!=sum&&up[i]!=tot){
                    dis[i]=dis[Q[hed]]+1;
                    F[i]=(sum-S[i]+TT)%TT;
                    Q[++til]=i;
                }
                S[i]=0;
            }
            sum=0,tot=0;
            while(clen[0])up[clen[clen[0]--]]=0;
        }
    }
    printf("%lld\n",(!F[N])?-1:F[N]);
    return 0;
}