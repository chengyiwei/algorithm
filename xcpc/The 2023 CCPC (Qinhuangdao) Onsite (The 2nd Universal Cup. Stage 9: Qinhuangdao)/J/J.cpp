#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 5e4 + 5;
ll n, W, a[MAXN], c[15], f[9000], s[9000];
int main(){
    ios::sync_with_stdio(false);
    cin >> n >> W;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        c[a[i] - 1] ++;
    }
    for(int S = 0; S < (1 << 13); S ++){
        for(int i = 0; i < 13; i ++){
            if((S >> i) & 1){
                s[S] += c[i];
            }
        }
    }
    memset(f, 0x3f, sizeof f);
    f[0] = 0;
    for(int S = 0; S < (1 << 13); S ++){
        for(int S_ = 0; S_ < (1 << 13); S_ ++){
            if(((S_ | S) == S) && s[S_] <= W){
                // cout << S << " " << S_ << "\n";
                f[S] = min(f[S], f[S - S_] + 1);
            }
        }
    }
    // cout << s[ans_S] << "\n";
    cout << f[(1 << 13) - 1] << "\n";
    return 0;
}