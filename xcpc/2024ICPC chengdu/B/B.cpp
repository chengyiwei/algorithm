#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
const ll MOD = 1e9 + 7;
ll n, q, f[2][3][305][305], sum[MAXN], g[305][305][305];
string s;
ll M(ll x){
    return (x % MOD + MOD) % MOD;
}
int main(){
    // freopen ("B.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q >> s;
    s = " " + s;
    for(int i = 1; i <= n; i ++){
        sum[i] = sum[i - 1] + (s[i] == '?');
    }
    if(s[1] == '?'){
        f[1][0][1][0] = 1;
        f[1][1][0][1] = 1;
        f[1][2][0][0] = 1;
    }
    else{
        f[1][s[1] - 'a'][0][0] = 1;
    }
    for(int i = 2; i <= n; i ++){
        ll now = i & 1, old = now ^ 1;
        memset(f[now], 0, sizeof f[now]);
        if(s[i] == '?'){
            for(int ca = 0; ca <= sum[i]; ca ++){
                for(int cb = 0; cb <= sum[i]; cb ++){
                    if(ca + cb > sum[i]) break;
                    for(int j = 0; j < 3; j ++){
                        for(int k = 0; k < 3; k ++){
                            if(j == k) continue;
                            f[now][j][ca][cb] += f[old][k][ca - (j == 0)][cb - (j == 1)];
                            f[now][j][ca][cb] %= MOD;
                        }
                    }
                }
            }
        }
        else{
            for(int ca = 0; ca <= sum[i]; ca ++){
                for(int cb = 0; cb <= sum[i]; cb ++){
                    if(ca + cb > sum[i]) break;
                    int j = s[i] - 'a';
                    for(int k = 0; k < 3; k ++){
                        if(j == k) continue;
                        f[now][j][ca][cb] += f[old][k][ca][cb];
                        f[now][j][ca][cb] %= MOD;
                    }
                }
            }
        }
    }
    for(int i = 0; i <= sum[n]; i ++){
        for(int j = 0; j <= sum[n]; j ++){
            ll k = sum[n] - i - j;
            for(int pwp = 0; pwp < 3; pwp ++){
                g[i][j][k] += f[(n & 1)][pwp][i][j];
                g[i][j][k] %= MOD;
            }
        }
    }

    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= n; j++) 
            for (int k = 1; k <= n; k++) 
                g[i][j][k] = (g[i][j][k] + g[i][j][k - 1]) % MOD;
    for (int i = 0; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            for (int k = 0; k <= n; k++) 
                g[i][j][k] = (g[i][j][k] + g[i][j - 1][k]) % MOD;
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= n; j++) 
            for (int k = 0; k <= n; k++) 
                g[i][j][k] = (g[i][j][k] + g[i - 1][j][k]) % MOD;

    while(q --){
        ll x, y, z;
        cin >> x >> y >> z;
        cout << g[x][y][z] << "\n";
    }
    return 0;
}