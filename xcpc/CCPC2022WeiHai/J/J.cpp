#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll Tex, n, m, a[MAXN];
void AC(){
    map<ll, ll> mp;
    vector<ll> idx, b;
    b.push_back(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }
    a[n + 1] = (ll)(1e9 + 2);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= m; i ++){
        ll x, y;
        cin >> x >> y;
        mp[x] = y;
        if(y == 0) idx.push_back(x);
    }
    idx.push_back(-1); idx.push_back((ll)(1e9 + 1));
    sort(idx.begin(), idx.end());

    ll l = 1, r = 1, ans = 0;
    for(int i = 0; i < idx.size() - 1; i ++){
        while(a[r] <= idx[i + 1]) r ++;
        ll cnt = r - l;
        for(int j = idx[i] + 1; j <= idx[i + 1]; j ++){
            if(!mp.count(j)){
                while(cnt){
                    b.push_back(j);
                    cnt --;
                }
            }
            else{
                ll qwq = mp[j];
                while(cnt && qwq){
                    b.push_back(j);
                    cnt --;
                    qwq --;
                }
            }
            if(!cnt) break;
        }
        l = r;
    }

    for(int i = 1; i <= n; i ++){
        // cout << b[i] << " ";
        ans += a[i] - b[i];
    }
    if(ans & 1) cout << "Pico\n";
    else cout << "FuuFuu\n";
}
int main(){
    // freopen("J.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> Tex;
    while(Tex --) AC();
    return 0;
}