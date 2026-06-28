#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 1e6 + 5;
ll Tex, n, m, b[MAXN];
vector<ll> mp[MAXN];
void AC(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        mp[i].clear();
        ll len, x;
        cin >> len;
        for(int j = 1; j <= len; j ++){
            cin >> x;
            mp[i].push_back(x);
        }
    }
    for(int i = 1; i <= m; i ++){
        ll s, len; cin >> s >> len;
        for(int j = 1; j <= len; j ++){
            cin >> b[j];
        }
        ll dq = s;
        for(int j = 1; j <= len; j ++){
            if(b[j] > mp[dq].size()){
                cout << "Packet Loss" << "\n";
                goto loop;
            }
            dq = mp[dq][b[j] - 1];
        }
        cout << dq << "\n";
        loop:
        666;
    }
}
int main(){
    freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    ll cnt = 0;
    cin >> Tex;
    while(Tex --){
        cout << "Case #" << ++ cnt << ":\n";
        AC();
    }
    return 0;
}