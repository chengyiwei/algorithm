#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+5;
typedef long long LL;

LL ans[maxn],Fac=1;

LL now=1;
int main(){
    freopen("J.in","r",stdin);
    for(int i=1;i<maxn;i++){
        Fac*=i;
        while(Fac%10==0) Fac/=10;
        Fac%=100000000;
        now*=Fac;
        while(now%10==0) now/=10;
        now%=100000000;
        ans[i]=now;
    }
    int T;scanf("%d",&T);
    while(T--){
        int n,k;scanf("%d%d",&n,&k);
        LL p=ans[n];
        stack<int> st;
        for(int i=1;i<=k;i++) st.push(p%10),p/=10;
        while(!st.empty()) printf("%d",st.top()),st.pop();
        putchar('\n');
    }
    return 0;
}