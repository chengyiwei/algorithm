#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long LL;
int read() {
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}

const int maxn = 2e5 + 5;
int n;
LL a[maxn], sum[maxn];
double ans[maxn];
struct Node {
    LL x, y;
    Node(int x, int y) : x(x), y(y) {}
};

double slope(Node a, Node b) {
    return (double)(a.y - b.y) / (a.x - b.x);
}

signed main() {
    freopen ("G.in", "r", stdin);
    freopen ("G.out", "w", stdout);
    n = read();
    for (int i = n; i ; i--) a[i] = read();
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    vector<Node> st; st.push_back(Node(0, 0));
    for (int i = 1; i <= n; i++) {
        Node now = Node(i, sum[i]);
        while (st.size() > 1 && slope(st.back(), st[st.size() - 2]) > slope(now, st.back()) )
            st.pop_back();
        ans[i] = slope(now, st.back());
        st.push_back(now);
    }
    for (int i = n; i ; i--) printf("%.10lf\n", ans[i]);
    return 0;
}