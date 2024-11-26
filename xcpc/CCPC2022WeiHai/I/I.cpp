#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll INF = 1e14;
ll Tex, n, m, a[MAXN], b[MAXN], tmp[MAXN];
bool check(ll x){
    priority_queue<ll> op;
    for(int i = 1; i <= n; i ++){
        op.push(x * a[i]);
    }
    for(int i = 0; i < m; i ++){
        tmp[i] = b[i];
    }
    ll dq = m - 1, tot;
    while(!op.empty()){
        ll qwq = op.top();
        op.pop();
        tot = (1ll << dq);
        if(dq < 0) return 0;
        ll ned = max(1ll, min(tmp[dq], qwq / tot));
        tmp[dq] -= ned;
        qwq -= ned * tot;
        if(qwq > 0) op.push(qwq);
        if(!tmp[dq]) dq --;
    }
    return 1;
}
void AC(){
    cin >> n >> m;
    ll c1 = 0, c2 = 0;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        c1 += a[i];
    }
    for(int i = 0; i < m; i ++){
        cin >> b[i];
        c2 += b[i] * (1ll << i);
    }
    ll l = 0, r = c2 / c1 + 5;
    while(l + 1 < r){
        ll mid = l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    cout << l << "\n";
}
int main(){
    // freopen("I.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}