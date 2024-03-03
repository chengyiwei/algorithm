#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL t, a, k;
struct Line {
    LL L, R;
    Line (LL x, LL y) {
        L = min (x, y);
        R = max (x, y);
    }
};

bool fenli(Line A, Line B) {
    if (A.R < B.L) return 1;
    if (A.L > B.R) return 1;
    return 0;
}

bool check () {
    Line A = Line (t, 0);
    Line B = Line (a - k, a + k);
    if (fenli(A, B) == 0) return 0;
    return 1;
}
int main() {
    cin >> t >> a >> k;
    if (check() == 0) {
        cout << abs(a) + abs(t - a) << endl;
    }
    else {
        cout << abs(t) + abs(a - t) * 2 << endl;
    }
    return 0;
}