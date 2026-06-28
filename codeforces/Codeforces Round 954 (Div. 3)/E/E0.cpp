#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const ll MAXN = 5e5 + 5;
const ll INF = 4e18;
ll Tex = 1, n, k, a[MAXN];
vector<ll> f[MAXN];
void AC(){
    cin >> n >> k;
    ll cnt = 0, p = n & 1;
    unordered_map<ll, ll> mp;
    for(int i = 0; i <= (ll)(2e5); i ++){
        f[i].clear();
    }
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        if(!mp[a[i] % k]) mp[a[i] % k] = ++ cnt;
        f[mp[a[i] % k]].push_back(a[i]);
    }
    ll ans = 0;
    for(int i = 1; i <= cnt; i ++){
        ll len = f[i].size();
        sort(f[i].begin(), f[i].end());
        if(len & 1){
            if(p){
                p = 0;
                if(len == 1) continue;
                ll mn = INF;
                vector<ll> b(len + 1);
                vector<ll> s(len + 1);
                for(int j = 0; j < f[i].size() - 1; j ++){
                    b[j] = (f[i][j + 1] - f[i][j]);
                    if(j <= 1) s[j] = b[j];
                    else s[j] = s[j - 2] + b[j];
                }
                for(int j = 0; j < f[i].size(); j ++){
                    if(j & 1){
                        ll tmp = f[i][j + 1] - f[i][j - 1];
                        mn = min(s[len - 2] - s[j] + (j - 3 >= 0 ? s[j - 3] : 0) + tmp, mn);
                    }
                    else{
                        mn = min(s[len - 2] - (j - 1 >= 0 ? s[j - 1] : 0) + (j - 2 >= 0 ? s[j - 2] : 0), mn);
                    }
                    // cout << j << " " << mn << endl;
                }
                ans += (mn / k);
                continue;
            }
            else{
                cout << -1 << endl;
                return;
            }
        }
        for(int j = 0; j < len; j += 2){
            ans += ((f[i][j + 1] - f[i][j]) / k);
        }
    }
    cout << ans << endl;
}
signed main(){
    freopen ("E.in", "r", stdin);
    freopen ("E0.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}