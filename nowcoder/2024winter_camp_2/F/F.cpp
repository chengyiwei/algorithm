#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

struct Tree{
    int n;
    vector<int> t;
    Tree(int _n){
        this -> n = _n + 1;
        t.assign(n,INF);
    }
    void update(int x, int data){
        for(int i = x; i < n; i += i & -i)
            t[i] = min(t[i],data);
    }
    int query(int x){
        int ans = INF;
        for(int i = x; i; i -= i & -i)
            ans = min(ans,t[i]);
        return ans;
    }
};

void solve(){
    int n; scanf("%d",&n);
    vector<int> c(n+1),nxt(n+1,n+1),p(n+1,0),dp(n+1,0);;
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        if(p[c[i]])
            nxt[p[c[i]]] = i;
        p[c[i]] = i;
    }
    Tree T(n);
    for(int i=n;i;i--){
        if(nxt[i] == n +1)
            dp[i] = 1;
        else{
            dp[i] = T.query(nxt[i]) + 1;
        }
        T.update(i,dp[i]);
    }
    printf("%d\n",dp[1]);
}

int main(){
    freopen("F.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--) solve();
    return 0;
}