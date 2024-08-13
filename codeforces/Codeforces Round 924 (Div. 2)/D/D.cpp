#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
typedef long long LL;
const LL INF = 1e18;
int c[maxn];
int n;
LL b, x; 

LL check(int m){
    LL ret = 0;
    for (int i = 1; i <= n; i++){
        LL p = c[i] / m, num_lst = c[i] % m;
        ret += p * m * p * (m - 1) / 2;
        ret += num_lst * (num_lst - 1) / 2;
        ret += num_lst * p * (m - 1);
    }
    ret *= b;
    ret -= x * (m - 1);
    return ret;
}

void solve(){
    cin >> n >> b >> x;
    int l = 1, r = 0;
    for (int i = 1; i <= n; i++) cin >> c[i], r = max(r, c[i]);
    LL ans = 0; 
    //三分
    while (l <= r){
        int m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        LL f1 = check(m1), f2 = check(m2);
        if (f1 < f2){
            ans = max(ans, f2);
            l = m1 + 1;
        }else{
            ans = max(ans, f1);
            r = m2 - 1;
        }
    }
    cout << ans << '\n';
}

int main(){
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}