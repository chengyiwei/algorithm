#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1LL<<60;
const int maxn = 4e5 + 10;
int n,m;
int q[maxn],c[maxn];
int read(){
    int ret=0,f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
    return ret*f;
}

int get(int x){
    int ret = 0 ;
        for(;x;x-=x&-x) ret += c[x];
    return ret;
}
void add(int x,int d){
    for(;x<maxn;x+=x&-x) c[x] += d;
}

signed main(){
    freopen("D.in","r",stdin);
    n=read();m=read();
    int ans = 0;
    for(int i=1;i<=m;i++) q[i]=read();
    for(int i=2;i<=m;i++){
        if(abs(q[i]-q[i-1]) < n - abs(q[i]-q[i-1])){
            int x = abs(q[i]-q[i-1]);
            ans += x;
            int d = n - 2*x;
            int L = min(q[i],q[i-1]), R = max(q[i],q[i-1]);
            add(L,d); add(R,-d);
        }
        else{
            int x = n - abs(q[i]-q[i-1]);
            ans += x;
            int d = n- 2*x;
            int L = min(q[i],q[i-1]), R = max(q[i],q[i-1]);
            add(1,d); add(L,-d); add(R,d); add(n+1,-d);
        }
    }
    int add_ans = INF;
    for(int i=1;i<=n;i++){
        add_ans = min(add_ans, get(i));
    }
    cout<<ans + add_ans<<endl;
    return 0;
}