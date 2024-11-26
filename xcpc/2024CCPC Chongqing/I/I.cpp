#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll MOD = 998244353;
ll Tex, a[10];
void AC(){
    priority_queue<ll, vector<ll>, greater<ll>> op;
    for(int i = 1; i <= 9; i ++){
        cin >> a[i];
        if(i >= 2){
            for(int j = 1; j <= a[i]; j ++){
                op.push(i);
            }
        }
    }
    if(a[1] == 0 && op.empty()){
        cout << 0 << "\n";
        return;
    }
    while(op.size() && a[1] && op.top() == 2){
        a[1] --;
        op.pop();
        op.push(3);
    }
    ll c = a[1] / 3;
    for(int i = 1; i <= c; i ++){
        op.push(3);
    }
    ll sy = a[1] % 3;
    ll ans = 1;
    if(sy == 2) ans = 2;
    else if(sy == 1){
        if(op.empty()) op.push(0);
        ll qwq = op.top() + 1;
        op.pop();
        op.push(qwq);
    }
    while(op.size()){
        ans *= op.top();
        op.pop();
        ans %= MOD;
    }
    cout << ans << "\n";
    // cout << fastPow(3, 172) % MOD * fastPow(4, 71) % MOD * fastPow(5, 60) % MOD * fastPow(6, 50) % MOD * fastPow(7, 40) % MOD * fastPow(8, 30) % MOD * fastPow(9, 20) % MOD << "\n";
}
int main(){
    // freopen("I.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}