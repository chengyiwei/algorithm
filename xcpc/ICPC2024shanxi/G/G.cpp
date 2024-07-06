#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18 + 5;
ll n, x, mp[12], cnt;
bool pd(string aa, string bb){
    if(aa.size() == bb.size()) return aa <= bb;
    else return aa.size() < bb.size();
}
bool check(ll x){
    ll dq = 0;
    while(x){
        dq = dq * 10 + mp[x % 9];
        x /= 9;
    }
    string ss = to_string(dq);
    string s = to_string(n);
    return pd(s, ss);
}

void solve() {
    cin >> n >> x;
    for(int i = 0; i <= 9; i ++){
        if(x == i) continue;
        mp[cnt ++] = i;
    }
    ll l = 0, r = n;
    while(l + 1 < r){
        ll mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid;
    }
    cout << r + 1 << endl;
}

int main(){
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(0);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}