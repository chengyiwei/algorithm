#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll n, m, vis[MAXN], cnt;
ll s1[MAXN], s2[MAXN];
bool p;
vector<ll> mp[MAXN];
vector<ll> h;
vector<ll> lst;
void dfs(ll x, ll fa){
    cnt ++;
    vis[x] = 1;
    for(auto it : mp[x]){
        if(it == fa) continue;
        if(vis[it]){
            p = 1;
            continue;
        }
        dfs(it, x);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        ll x, y;
        cin >> x >> y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    for(int i = 1; i <= n; i ++){
        if(!vis[i]){
            cnt = 0;
            p = 0;
            dfs(i, -1);
            if(cnt == 1) continue;
            if(p) h.push_back(cnt);
            else lst.push_back(cnt - 1);
        }
    }
    sort(lst.begin(), lst.end(), greater<ll>());
    if(lst.size()){
        s1[0] = lst[0];
        s2[0] = lst[0] - 1;
        for(int i = 1; i < lst.size(); i ++){
            s1[i] = s1[i - 1] + lst[i];
            s2[i] = s2[i - 1] + lst[i] - 1;
        }
    }
    bitset<(int)(2e5 + 1)> S;
    S[0] = 1;
    for(int i = 0; i < h.size(); i ++){
        S = (S << h[i]) | S;
    }
    ll mx = 0;
    for(int i = (int)(2e5); i >= 0; i --){
        if(S[i]){
            mx = i;
            break;
        }
    }
    ll fst = 0;
    for(int i = 1; i <= n; i ++){
        ll ans;
        if(S[i] == 1) fst = i, ans = i;
        else if(i <= mx) ans = fst + (i - fst - 1);
        else{
            ll cz = i - fst;
            ans = fst;
            ll idx = lower_bound(s1, s1 + lst.size(), cz) - s1;
            if(idx == lst.size()) ans += s2[lst.size() - 1];
            else if(idx == 0) ans += cz - 1;
            else ans += s2[idx - 1] + (cz - s1[idx - 1] - 1);
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}