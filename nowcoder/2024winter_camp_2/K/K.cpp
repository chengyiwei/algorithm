#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 15;
const LL TT = 1e9 + 7;
int n,y;
string s;
int cnt[maxn];

LL dfs(int pos, int limit, int pre, int mod_8, int a_, int b_, int c_, int d_){
    if(pos == n){
        return mod_8 == 0;
    }
    LL ans = 0;
    if('0' <= s[pos] && s[pos] <= '9'){
        int x = s[pos] - '0';
        if(pre && x == 0) return 0; // 0不能作为前导零
        if(limit && x > cnt[pos]) return 0;
        ans += dfs(pos + 1, limit && x == cnt[pos], 0, (mod_8 * 10 + x) % 8, a_, b_, c_, d_), ans %= TT;
        
    }
    if(s[pos] == '_'){
        int up = limit ? cnt[pos] : 9, dn = pre ? 1 : 0;
        for(int i = dn; i <= up ; i ++)
            ans += dfs(pos + 1, limit && i == cnt[pos], 0, (mod_8 * 10 + i) % 8, a_, b_, c_, d_) , ans %= TT;
    }
    if(s[pos] == 'a'){
        if(a_ == -1){
            int up = limit ? cnt[pos] : 9, dn = pre ? 1 : 0;
            for(int i = dn; i <= up ; i ++){
                if(i == b_ || i == c_ || i == d_) continue; // 不能和b,c,d重复
                ans += dfs(pos + 1, limit && i == cnt[pos], 0, (mod_8 * 10 + i) % 8, i, b_, c_, d_), ans %= TT;
            }
        }
        else{
            int x = a_;
            if(limit && x > cnt[pos]) return 0;
            ans += dfs(pos + 1, limit && x == cnt[pos], 0, (mod_8 * 10 + x) % 8, a_, b_, c_, d_), ans %= TT;
        }
    }
    if(s[pos] == 'b'){
        if(b_ == -1){
            int up = limit ? cnt[pos] : 9, dn = pre ? 1 : 0;
            for(int i = dn; i <= up ; i ++){
                if(i == a_ || i == c_ || i == d_) continue; // 不能和a,c,d重复
                ans += dfs(pos + 1, limit && i == cnt[pos], 0, (mod_8 * 10 + i) % 8, a_, i, c_, d_), ans %= TT;
            }
        }
        else{
            int x = b_;
            if(limit && x > cnt[pos]) return 0;
            ans += dfs(pos + 1, limit && x == cnt[pos], 0, (mod_8 * 10 + x) % 8, a_, b_, c_, d_), ans %= TT;
        }
    }
    if(s[pos] == 'c'){
        if(c_ == -1){
            int up = limit ? cnt[pos] : 9, dn = pre ? 1 : 0;
            for(int i = dn; i <= up ; i ++){
                if(i == a_ || i == b_ || i == d_) continue; // 不能和a,b,d重复
                ans += dfs(pos + 1, limit && i == cnt[pos], 0, (mod_8 * 10 + i) % 8, a_, b_, i, d_), ans %= TT;
            }
        }
        else{
            int x = c_;
            if(limit && x > cnt[pos]) return 0;
            ans += dfs(pos + 1, limit && x == cnt[pos], 0, (mod_8 * 10 + x) % 8, a_, b_, c_, d_), ans %= TT;
        }
    }
    if(s[pos] == 'd'){
        if(d_ == -1){
            int up = limit ? cnt[pos] : 9, dn = pre ? 1 : 0;
            for(int i = dn; i <= up ; i ++){
                if(i == a_ || i == b_ || i == c_) continue; // 不能和a,b,c重复
                ans += dfs(pos + 1, limit && i == cnt[pos], 0, (mod_8 * 10 + i) % 8, a_, b_, c_, i), ans %= TT;
            }
        }
        else{
            int x = d_;
            if(limit && x > cnt[pos]) return 0;
            ans += dfs(pos + 1, limit && x == cnt[pos], 0, (mod_8 * 10 + x) % 8, a_, b_, c_, d_), ans %= TT;
        }
    }
    return ans % TT;
}

void solve(){
    cin >> n >> s >> y;
    for(int i = n - 1; i>= 0; i--){
        cnt[i] = y % 10;
        y /= 10;
    }
    LL ans = dfs(0,1,n > 1 && 1,0,-1,-1,-1,-1);
    cout << ans << '\n';
}

int main(){
    freopen("K.in","r",stdin);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}