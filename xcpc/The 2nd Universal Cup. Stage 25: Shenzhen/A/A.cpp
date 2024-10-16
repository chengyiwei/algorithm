#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e3 + 5;
ll n, ql[MAXN], qr[MAXN], a[MAXN], cnt;
struct node{
    ll id, val;
}b[MAXN];
bool operator < (node xx, node yy){
    return xx.val < yy.val;
}
vector<pair<ll, ll>> ans;
void f(ll l, ll r, ll val){
    if(l > r) return;
    ll mid = l + r >> 1;
    ll pl = ql[b[mid].val];
    ll pr = qr[b[mid].val];
    if(val != b[mid].val){
        for(int i = pl; i <= r; i ++){
            ans.push_back({2, b[i].id});
        }
        for(int i = val + 1; i < b[mid].val; i ++){
            ans.push_back({1, i});
        }
    }
    f(l, pl - 1, val);
    f(pr + 1, r, b[mid].val);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> b[i].val;
        b[i].id = i;
    }
    sort(b + 1, b + n + 1);
    ll idx = 1; b[n + 1].val = -1;
    for(int i = 1; i <= n; i ++){
        if(b[i].val != b[i + 1].val){
            ql[b[i].val] = idx;
            qr[b[i].val] = i;
            idx = i + 1;
        }
    }
    f(1, n, 0);
    cout << ans.size() << "\n";
    for(auto it : ans){
        cout << it.first << " " << it.second << "\n";
    }
    return 0;
}

