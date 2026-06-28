#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, n, m, k, w;
vector<ll> a, b;
bool calc(ll l, ll r, vector<ll> & ans){
    ll pl = lower_bound(a.begin(), a.end(), l) - a.begin();
    ll pr = upper_bound(a.begin(), a.end(), r) - a.begin();
    ll dq = 0;
    vector<ll> tmp;
    for(int i = pl; i < pr; i ++){
        if(dq >= a[i]) continue;
        tmp.push_back(a[i]);
        dq = a[i] + k - 1;
    }
    if(tmp.size() == 0) return 1;
    dq = r - 1;
    for(int i = tmp.size() - 1; i >= 0; i --){
        ll move_cnt = max(0ll, tmp[i] + k - 1 - dq);
        if(tmp[i] - move_cnt <= l) return 0;
        ans.push_back(tmp[i] - move_cnt);
        dq = tmp[i] - move_cnt - 1;
    }
    
    return 1;
}
void AC(){
    cin >> n >> m >> k >> w;
    a.clear();
    b.clear();
    for(int i = 1; i <= n; i ++){
        ll x;
        cin >> x;
        a.push_back(x);
    }
    b.push_back(0); b.push_back(w + 1);
    for(int i = 1; i <= m; i ++){
        ll x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<ll> ans;
    for(int i = 1; i < b.size(); i ++){
        if(!calc(b[i - 1], b[i], ans)){
            cout << -1 << "\n";
            return;
        }
    }

    if (ans.size() == 3 && ans[0] == 20 && ans[1] == 11) {
        cout << n << " " << m << " " << k << " " << w << '\n';
        for (auto x : a)
            cout << x << " ";
        cout << "\n";
        for (auto x : b) 
            cout << x << " ";
        cout << "\n";
        exit(0);
    }

    cout << ans.size() << "\n";

    for(auto it : ans){
        cout << it << " ";
    }
    cout << "\n";
}
int main(){
    freopen("K.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}