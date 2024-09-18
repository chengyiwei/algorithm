#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll MOD = 998244353;
ll Tex, n, a[MAXN];
ll fastPow(ll a, ll b){
    ll ret = 1;
    while(b){
        if(b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
string s, t, p;
void AC(){
    cin >> n;
    map<pair<string, string>, ll> mp1;
    map<string, ll> mp2;
    ll mx = 0;
    for(int i = 1; i <= n; i ++){
        cin >> s >> t >> p;
        if(p == "accepted"){
            if(!mp1[{s, t}]){
                mp2[t] ++;
                mx = max(mp2[t], mx);
            }
            mp1[{s, t}] = 1;
        }
    }
    vector<string> ans;
    for(auto it : mp2){
        if(it.second == mx) ans.push_back(it.first);
    }
    sort(ans.begin(), ans.end());
    cout << ans[0] << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}