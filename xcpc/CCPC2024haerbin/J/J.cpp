#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(idx) (idx) & (-idx)
const ll MAXN = 4e5 + 5;
ll Tex, n, m, a[MAXN], x[MAXN], t[MAXN], tr[MAXN];
void add(ll idx, ll k){
    while(idx <= 2 * m){
        tr[idx] += k;
        idx += lowbit(idx);
    }
}
ll sum(ll idx){
    ll ret = 0;
    while(idx > 0){
        ret += tr[idx];
        idx -= lowbit(idx);
    }
    return ret;
}
void AC(){
    cin >> n >> m;
    ll dq = 0;
    map<ll, ll> mp;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        dq += a[i];
    }
    for(int i = 1; i <= m; i ++){
        cin >> x[i] >> t[i];
    }
    for(int i = 1; i <= m; i ++){
        add(i, x[i] - x[i - 1]);
        ll tmp = min(sum(i) - sum(mp[t[i]]), a[t[i]]);
        cout << i << " " << sum(i) << " " << sum(mp[t[i]]) << " " << tmp << " " << mp[t[i]] << '\n';
        dq -= x[i] - x[i - 1];
        if(dq < 0){
            cout << dq + x[i] << "\n";
            goto lp;
        }
        add(i, -tmp);
        dq += tmp;
        mp[t[i]] = i;
    }
    cout << x[m] + dq << "\n";
    lp:
    for(int i = 1; i <= 2 * m; i ++){
        add(i, -sum(i));
    }
}
int main(){
    freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}