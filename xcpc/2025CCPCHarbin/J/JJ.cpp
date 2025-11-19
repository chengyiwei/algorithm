#include <bits/stdc++.h>
using namespace std;
const int N = 2e7 + 5;
int Tex, n, nn, p[N << 1], qwq[N << 1], f[N << 1], ff[N << 1], ans, L, R;
char s[N << 1], b[N];
string a;
void check(int i) {
    if (p[i] <= 1) return;
    int l = f[i - (p[i] - 2)];
    int r = f[i + (p[i] - 2)];
    // cout << i << " " << p[i] << " " << l << " " << r << "\n";
    int cnt = 0;
    if (qwq[l] == 2) {
        cnt ++;
        l ++;
    }
    if (qwq[r] == 1) {
        r --;
        cnt ++;
    }
    if (cnt & 1) return;
    // cout << " " << l << " " << r << " " << ff[l] << " " << ff[r] << '\n';
    if (l > r) return;
    l = ff[l];
    r = ff[r];
    if (ans < r - l + 1) {
        ans = r - l + 1;
        L = l;
        R = r;
    }
}
void change() {
    for (int i = 0; i <= 4 * n + 10; i ++) {
        qwq[i] = 0;
        f[i] = 0;
        ff[i] = 0;
        p[i] = 0;
    }
    nn = 0;
    for (int i = 0; i < n; i ++) {
        if (a[i] == 'w') {
            qwq[nn] = 1;
            ff[nn] = i;
            b[nn ++] = 'v';
            ff[nn] = i;
            qwq[nn] = 2;
            b[nn ++] = 'v';
        }
        else {
            ff[nn] = i;
            b[nn ++] = a[i];
        }
    }
    int k = 0;
    s[k ++] = '$';
    s[k ++] = '#';
    for (int i = 0; i < nn; i ++) {
        f[k] = i;
        s[k ++] = b[i];
        s[k ++] = '#';
    }
    s[k ++] = '$';
    nn = k;
}
void manacher() {
    int R = 0, C;
    for (int i = 1; i < nn; i ++) {
        if (i < R) {
            p[i] = min(p[(C << 1) - i], p[C] + C - i);
        }
        else p[i] = 1;
        check(i);
        while (s[i + p[i]] == s[i - p[i]]) {
            p[i] ++;
            check (i);
        }
        if (p[i] + i > R) {
            R = p[i] + i;
            C = i;
        }
    }
}
void AC() {
    cin >> n >> a;
    change();
    ans = L = R = 0;
    // cout << s << '\n';
    manacher();
    string tmp;
    // cout << L << " " << R << "\n";
    for (int i = L; i <= R; i ++) {
        tmp.push_back(a[i]);
    }
    cout << tmp << "\n";
}
/*
3
8
wwwovvvv
16
wwwooooooooovwww
11
wwwovoovvvv
*/
int main() {
    // freopen("J.in", "r", stdin);
    // freopen("J.out", "w", stdout);
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    cin >> Tex;
    while (Tex --) AC();
    return 0;
}