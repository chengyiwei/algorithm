#include <bits/stdc++.h>
using namespace std;
const int maxn = 35;
typedef long long LL;
typedef pair<int, int> pii;
int n, m;
int mp[maxn][maxn];
LL ans;
int s[maxn][maxn];
int Le[maxn][maxn], Re[maxn][maxn];
char read_ch(){
    char ch = getchar();
    while (ch != '.' && ch != '*') ch = getchar();
    return ch;
}

int c[maxn];
stack<int> st;
priority_queue<pii> pq;
void add_x(int x, int v) {
    if (x <= 0) return ;
    for (int i = x; i <= m; i += i & -i)
        c[i] += v;
}
int query_x(int x) {
    int res = 0;
    for (int i = x; i; i -= i & -i)
        res += c[i];
    return res;
}
void clear() {
    while (!pq.empty()) 
        add_x(pq.top().second, -1), pq.pop();
}
void solve(int L, int i) {
    int R;
    while (L <= m) {
        while (mp[i][L] == '.') L += 2;
        if (Re[i][L] > 1)
            pq.push(pii(Re[i][L] - 1,Re[i][L] - 1)), add_x(Re[i][L] - 1, 1); 
        R = L + 2;
        while (R <= m && s[i][R] - s[i][L - 1] == R - L + 1) {
            int siz = R - L  >> 1;
            while (!pq.empty() && pq.top().first < siz)
                add_x(pq.top().second, -1), pq.pop();
            if (Le[i][R] > 1){
                int now = query_x(Le[i][R] - 1);
                ans += now;
                if(now > 0)
                    printf("%d %d %d %d %d %d\n",i,L,R,Le[i][R],Re[i][L],now);
            }
            if (Re[i][R] > 1)
                pq.push(pii(Re[i][R] - 1 + siz, Re[i][R] - 1)), add_x(Re[i][R] - 1, 1);
            R += 2;
        }
        clear();
        L = R;
    }
}

int main() {
    freopen ("H.in", "r", stdin);
    freopen ("H.out", "w", stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            mp[i][j] = read_ch();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            s[i][j] = s[i][j - 1] + (mp[i][j] == '*');
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (mp[i][j] == '.') continue;
            Le[i][j] = Le[i - 1][j - 1] + (mp[i][j] == '*');
            Re[i][j] = Re[i - 1][j + 1] + (mp[i][j] == '*');
        }
    solve(1,3);
    for (int i = 1; i <= n; i++) {
        solve(1,i);
        solve(2,i);
    }
    printf ("%lld\n", ans);
    return 0;
}