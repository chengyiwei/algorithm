#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;

int n,tot;
int F[maxn][maxn],D[maxn],sum[maxn];

int read(){
    int x = 0, f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

void solve(){
    n = read();
    for(int i=1;i<=n;i++) D[i] = read(), sum[i] = sum[i-1] + D[i];
    for(int len = 2; len <= n; len ++)
        for(int i = 1; i + len - 1 <= n; i ++){
            int j = i + len - 1;
            F[i][j] = INF;
            for(int k = i; k <= j; k ++)
                F[i][j] = min(F[i][j], F[i+1][k] + D[i] * (k - i) + (k - i + 1) * (sum[j] - sum[k]) + F[k+1][j]);
        }
    printf("Case #%d: %d\n",++tot,F[1][n]);
}

int main(){
    freopen("4283.in","r",stdin);
    int T = read();
    while (T --) solve();
    return 0;
}