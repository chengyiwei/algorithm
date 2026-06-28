#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, n, m, k, f[MAXN], du[MAXN], now_du[MAXN], qwq[MAXN];
vector<ll> mp[MAXN];
void AC(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++){
        ll x;
        cin >> x;
        f[x] = 1;
    }
    ll cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= m; i ++){
        ll x, y;
        cin >> x >> y;
        if(f[x] && f[y]) cnt0 ++;
        else if(f[x]) du[y] ++;
        else if(f[y]) du[x] ++;
        else if(x == y) du[x] ++;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    ll ans = cnt0;
    set<pair<ll, ll>> st;
    for(int i = 1; i <= k; i ++){
        if(du[i]) st.insert({du[i], i});
        now_du[i] = du[i];
    }
    for(int i = 1; i <= k; i ++){
        if(f[i]) continue;
        cnt1 = du[i];
        st.erase({du[i], i});
        f[i] = 1;
        for(auto it : mp[i]){
            if(f[it]) continue;
            now_du[it] ++;
        }
        for(auto it : mp[i]){
            if(f[it]) continue;
            if(qwq[it]) continue;
            qwq[it] = 1;
            st.erase({du[it], it});
            st.insert({now_du[it], it});
        }
        if(st.size()) cnt2 = (*st.rbegin()).first;
        else cnt2 = 0;
        for(auto it : mp[i]){
            if(f[it]) continue;
            if(qwq[it]){
                qwq[it] = 0;
                st.erase({now_du[it], it});
                st.insert({du[it], it});
                now_du[it] = du[it];
            }
        }
        f[i] = 0;
        st.insert({du[i], i});
        ans = max(ans, cnt0 + cnt1 + cnt2);
    }
    cout << ans << "\n";
    for(int i = 1; i <= k; i ++){
        mp[i].clear();
        f[i] = now_du[i] = du[i] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);  cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}