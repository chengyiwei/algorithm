#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL INF = 1e17;

void solve(){
    int n, m, k; cin >> n >> m >> k;
    k = (n - k);
    vector<LL> a(m + 1), b(m + 1);
    for(int i = 1; i <= m; i ++)
        cin >> a[i] >> b[i];
    vector<LL> F(n+1,INF);
    for(int i = 1; i <= m; i++){
        for(int j = 0, p = 0; p <= n; j = (j + a[i]) % n, p++){
            F[j] = min(F[j], 1LL * b[i] * p);
        }
    }
    for(int p = 1; p <= 2; p ++){
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n ; j++){     
                F[(i + j) % n] = min(F[(i + j) % n], F[i] + F[j]);
            }
    }
    LL ans = (F[k] == INF) ? -1 : F[k];
    cout << ans << '\n';
}

int main(){
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}