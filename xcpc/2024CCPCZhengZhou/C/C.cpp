#include <bits/stdc++.h>
using namespace std;

bool check(int x) {
    return (x & (x - 1)) == 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B; cin >> A >> B;
    int tx, ty; cin >> tx >> ty;

    A = max(1, A); B = max(1, B);
    int d1 = __gcd(A, tx), d2 = __gcd(B, ty);
    if (!check(A / d1) || !check(B / d2)) {
        cout << -1 << '\n';
        return 0;
    }

    stack<array<int, 4>> stk;
    while ((tx != 0 && tx != A) || (ty != 0 && ty != B)) {
        int nx = (tx * 2 < A) ? 0 : A;
        int ny = (ty * 2 < B) ? 0 : B;
        tx = 2 * tx - nx;
        ty = 2 * ty - ny;
        stk.push({tx, ty, nx, ny});
    }

    cout << stk.size() << '\n';
    while (!stk.empty()) {
        auto [tx, ty, nx, ny] = stk.top(); stk.pop();
        cout << tx << ' ' << ty << ' ' << nx << ' ' << ny << '\n';
    }

    return 0;
}