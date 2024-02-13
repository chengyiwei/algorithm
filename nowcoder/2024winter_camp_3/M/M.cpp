#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 5;
typedef long long LL;
const LL TT = 36;
int n;
LL a[maxn], num[maxn], Fac[20];
LL ans = 0;

int main(){
    freopen("M.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    Fac[0] = 1;
    for(int i = 1; i < 20; i++){
        Fac[i] = Fac[i - 1] * 10 % TT;
    }

    memset (num, 0, sizeof(num));
    for (int i = 1; i <= n; i++){
        LL len = log10(a[i]) + 1; len %= TT;
        for(int j = 0; j < TT; j++)
            if((j * Fac[len] % TT + a[i]) % TT == 0)
                ans += num[j];
        num[a[i] % TT]++;
    }

    memset (num, 0, sizeof(num));
    for (int i = n; i >= 1; i--){
        LL len = log10(a[i]) + 1; len %= TT;
        for(int j = 0; j < TT; j++)
            if((j * Fac[len] % TT + a[i]) % TT == 0)
                ans += num[j];
        num[a[i] % TT]++;
    }
    cout << ans << '\n';
    return 0;
}