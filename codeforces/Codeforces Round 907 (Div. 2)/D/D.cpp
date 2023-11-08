#pragma GCC optimize(2)
#include<bits/stdc++.h>
#include<windows.h>

#define int __int128
using namespace std;
const int MAX_X=1e18,TT=1e9+7;
int F[65];
inline int read(){
    int ret=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=getchar();}
    while(ch<='9'&&ch>='0')ret=ret*10+ch-'0',ch=getchar();
    return ret*f;
}
inline void print(int x){
    stack<int> p;
    do{p.push(x%10);x/=10;}while(x);
    while(!p.empty()) putchar(p.top()+'0'),p.pop();
    putchar('\n');
}
int get_2(int r,int p){
    if(r<=1||p==1) return 0;
    int pn=1,ret=0;
    for(int i=1;;i++){
        pn=pn*p;
        if(pn*p>r) { //如果 p^(n+1) > r 那么最后一块加上 n
            ret=(ret+(r-(pn-1))*i)%TT;
            return ret;
        }
        ret=(ret+((pn*p-1)-(pn-1))*i)%TT; // [p^n,p^(n+1)-1]
    }
}
int get_1(int now){
    int ans=0;
    int R=0,L;
    for(int i=1;;i++){
        R=(1ll<<i)-1,L=(1ll<<i-1);
        R=min(R,now);
        if(R==now){
            int sum_L=get_2(L-1,i-1);
            int sum_R=get_2(R,i-1);
            ans=(F[i-1]+sum_R-sum_L+TT)%TT;
            break;
        }
        // if(R==now) break;
    }
    return ans;
}
inline void init(){
    int ans=0;
    int R=0,L;
    for(int i=1;;i++){
        R=(1ll<<i)-1,L=(1ll<<i-1);
        int sum_L=get_2(L-1,i-1);
        int sum_R=get_2(R,i-1);
        ans=(ans+sum_R-sum_L+TT)%TT;
        F[i]=ans;
        if(R>MAX_X) break;
    }
    return ;

}
signed main(){
    // freopen("D.in","r",stdin);
    // freopen("D.out","w",stdout);
    int T=read();
    init();
    while(T--){
        int L=read(),R=read();
        print((get_1(R)-get_1(L-1)+TT)%TT);
    }
    // printf("%d\n",clock());
    return 0;
}