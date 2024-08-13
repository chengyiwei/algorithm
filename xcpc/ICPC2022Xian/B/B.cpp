#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=305;
int n,m,c,d,a[maxn],b[maxn];
char s[maxn][maxn];
void solve() {
    cin >> n >> m >> c >> d;
    for (int i = 0; i < n; i++)cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                a[i]++;
                b[j]++;
            }
        }
    }
    int k = max(*max_element(a, a + n), *max_element(b, b + m));
    int ans = c * k;
    for (int i = k - 1; i >= 0; i--) {
        int cnt1 = 0;
        for (int j = 0; j < n; j++)
            cnt1 += max(0LL, a[j] - i);
        int cnt2 = 0;
        for (int j = 0; j < m; j++)
            cnt2 += max(0LL, b[j] - i);
        ans = min(ans, max(cnt2, cnt1) * d + c * i);
    }
    cout << ans << endl;
}
signed main(){
    solve();
}