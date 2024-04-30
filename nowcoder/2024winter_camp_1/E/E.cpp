#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int bit[] = {1,3,9,27,81,243,729,2187,6561,19683,59049};
int p[15];
void solve(){
    int n,m; scanf("%d%d",&n,&m);
    int ans = INF;
    vector<int> a(n+1),u,v;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=m;i++) {
        int x,y; scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        if(x == 1) a[x] += 3;
        else{
            u.push_back(x);
            v.push_back(y);
        }
    }
    m = u.size();
    for(int S=0;S<bit[m];S++){
        int now = S;
        for(int j=0;j<m;j++)
            p[j] = now % 3, now /= 3;
        vector<int> b = a;
        for(int j=0;j<m;j++){
            if(p[j] == 0)      b[u[j]] += 1, b[v[j]] += 1;
            else if(p[j] == 1) b[v[j]] += 3;
            else               b[u[j]] += 3; 
        }
        int ret = 1;
        for(int j=2;j<=n;j++) ret += (b[j] > b[1]);
        ans = min(ans,ret);
    }
    printf("%d\n",ans);
}
int main(){
    freopen("E.in","r",stdin);
    int T; scanf("%d",&T);
    while(T--) solve();
}