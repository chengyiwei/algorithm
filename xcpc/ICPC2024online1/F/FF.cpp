#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 4e5 + 5;
const ll MOD = 998244353;
ll Tex, n, a[MAXN], tr[MAXN][2], stk[MAXN], top, ans, sum[MAXN];
ll dfs(ll x){
    ll dq = 0;
    sum[x] ++;
    if(tr[x][0]) sum[x] += dfs(tr[x][0]);
    if(tr[x][1]) sum[x] += dfs(tr[x][1]);
    if(a[tr[x][0]] < a[x]) dq += sum[tr[x][0]];  
    if(a[tr[x][1]] < a[x]) dq += sum[tr[x][1]];
    ans += dq;
    return sum[x];
}
void AC(){
    ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        tr[i][0] = tr[i][1] = 0;
        sum[i] = 0;
        stk[i] = 0;
    }
    top = 0;
    for(int i = 1; i <= n; i ++){
        ll k = top;
        while(k && a[stk[k]] < a[i]) k --;
        if(k) tr[stk[k]][1] = i;
        if(k < top) tr[i][0] = stk[k + 1];
        stk[++ k] = i;
        top = k;
    }
    dfs(stk[1]);
    cout << ans << "\n";
}
int main(){
    freopen ("F.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}