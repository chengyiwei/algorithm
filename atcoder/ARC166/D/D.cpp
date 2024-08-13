#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5,INF=1e9;
struct node{
    int pos,number;
};
int N,X[maxn],Y[maxn],hed=1,til,ans=INF;
node q[maxn];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    N=read();
    for(int i=1;i<=N;i++) X[i]=read();
    for(int i=1;i<=N;i++) Y[i]=read();
    X[0]=-INF;
    for(int i=1;i<=N;i++){
        if(Y[i]==Y[i-1]) continue;
        if(Y[i]>Y[i-1]) q[++til]=(node){X[i-1]+1,Y[i]-Y[i-1]};
        else {
            int now=Y[i-1]-Y[i];
            while(hed<=til&&q[hed].number<=now){
                ans = min(ans,X[i]-q[hed].pos);
                now -= q[hed].number;
                hed++;
            }
            if(hed<=til&&q[hed].number>now&&now) {
                q[hed].number-=now;now=0;
                ans=min(ans,X[i]-q[hed].pos);
            }
        }
    }
    if(ans==INF)printf("-1\n");
    else printf("%d\n",ans-1);
    return 0;
}