#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e9;
const int maxn = 1e5+5;
int n,m;
LL a[maxn];

map<LL,int> num;
set<LL> st;

bool check(LL x){
    LL now = 1;
    for(int i=1;i<=n;i++){
        LL p = a[i] + x;
        now *= p;
        if(now==0 || abs(now) > INF) return 0;
    }
    st.insert(now);
    return 1;
}

int main(){
    freopen("D.in","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(num.find(a[i]) == num.end()) num[a[i]] = 1;
        else num[a[i]]++;
    }
    sort(a+1,a+n+1);
    check(0);
    for(int i=1;i<=n;i++){
        if(a[i] == a[i-1]) continue;
        for(int l=-a[i]-1;check(l);--l);
        for(int r=-a[i]+1;check(r);++r);
    }
    st.insert(0);
    while(m--){
        LL x; scanf("%lld",&x);
        if(st.find(x) != st.end()) puts("Yes");
        else puts("No");
    }
    return 0;
}