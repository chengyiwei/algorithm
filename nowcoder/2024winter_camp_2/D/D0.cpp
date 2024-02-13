#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e18;

void solve(){
    int n, m, k; cin >> n >> m >> k; k = (n - k);
    vector<LL> a(m + 1), b(m + 1);
    for(int i = 1; i <= m; i ++)
        cin >> a[i] >> b[i];
    // vector<vector<int> > F(m+1,vector<int>(n+1,INF));
    vector<LL> F(n+1,INF);
    F[0] = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 0; j <= n ; j++){
            F[(j + a[i]) % n] = min(F[(j + a[i]) % n], F[j] + b[i]);
        }
        for(int j = 0; j <= n ; j++){
            F[(j + a[i]) % n] = min(F[(j + a[i]) % n], F[j] + b[i]);
        }
    }
    LL ans = F[k] == INF ? -1 : F[k];
    cout << ans << '\n';
}

int main(){
    freopen("D.in","r",stdin);
    freopen("D0.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}