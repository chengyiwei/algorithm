#include <bits/stdc++.h>

using namespace std;
typedef __int128 LL;

LL read() {
    LL x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}

void print(LL x) {
    if (x < 0) {putchar('-'); x = -x;}
    if (x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

struct Node {
    LL x, y;
    Node (LL x, LL y) : x(x), y(y) {}
};

double slope(Node a, Node b) {
    return (double)(a.y - b.y) / (a.x - b.x);
}

void solve() {
    int n; scanf ("%d", &n);
    vector<LL> a(n+1), F(n+1,0); vector<Node> st;
    for (int i = 1; i <= n; i++) a[i] = read();
    // if (n % 2 == 0) {printf("YES\n"); return;}
    for (int i = 1; i <= n; i ++) {
        if (i == n && i % 2 == 1) continue;

        Node now = Node(i, a[i]);
        while (st.size() >= 2 && slope(st[st.size() - 1], st[st.size() - 2]) < slope(now, st[st.size() - 1])) st.pop_back();

        double p;
        if(st.size() > 0) p = -slope(st[st.size() - 1], now);
        else p = 0;
        LL int_p = ceil(p);
        if (p < 0) int_p = 0;
        if (i % 2 == 0) 
            F[i] = int_p;
        else 
            F[i + 1] = int_p;
        st.push_back(now);
    }

    LL lst = 0;
    for (int i = (n % 2 == 0 ? n : n - 1) ; i ; i--) {
        lst = max(lst, F[i]);
        a[i] += lst * i;
    }

    for (int i = 1; i <= n; i++) {
        print(a[i]); putchar(' ');
    }

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i + 1]) {printf("NO\n"); return ;}
    }
    printf("YES\n");
}

int main() {
    freopen("E.in", "r", stdin);
    int T; scanf ("%d", &T);
    while (T--) solve(); 
}