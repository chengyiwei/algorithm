#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define lowbit(x) (x) & (-x)
const ll MAXN = 4e5 + 5;
const ll INF = 1e18;
ll Tex, n, m, a[MAXN], x[MAXN], b[MAXN], t[MAXN];
vector<ll> idx[MAXN];
void AC(){
    cin >> n >> m;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> op;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        b[i] = a[i];
        idx[i].push_back(MAXN);
    }
    for(int i = 1; i <= m; i ++){
        cin >> x[i] >> t[i];
    }
    for(int i = m; i >= 1; i --){
        idx[t[i]].push_back(i);
    }
    for(int i = 1; i <= n; i ++){
        op.push({idx[i].back(), i});
        idx[i].pop_back();
    }
    ll dq = 0;
    for(int i = 1; i <= m; i ++){
        ll cz = x[i] - x[i - 1];
        pair<ll, ll> qwq = op.top();
        // cout << qwq.first << " " << qwq.second << "\n";
        ll tmp = min(b[qwq.second], cz);
        cz -= tmp;
        b[qwq.second] -= tmp;
        while(cz && op.size()){
            pair<ll, ll> pwp = op.top();
            tmp = min(b[pwp.second], cz);
            cz -= tmp;
            b[pwp.second] -= tmp;
            if(!b[pwp.second]) op.pop();
        }
        if(cz){
            cout << x[i] - cz << "\n";
            return;
        }
        b[t[i]] = a[t[i]];
        
        op.push({idx[t[i]].back(), t[i]});
        idx[t[i]].pop_back();
        for(int i = 1; i <= n; i ++){
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    for(int i = 1; i <= n; i ++){
        dq += b[i];
    }
    cout << x[m] + dq << "\n";
}
int main(){
    freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}