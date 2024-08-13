#include <bits/stdc++.h>
using namespace std;

struct Cude {
    int a, b, c, d, e, f;
    Cude (int a, int b, int c, int d, int e, int f) : a(a), b(b), c(c), d(d), e(e), f(f) {}
};

bool is_intersect(Cude A, Cude B) {
    if (A.d <= B.a || B.d <= A.a) return false;
    if (A.e <= B.b || B.e <= A.b) return false;
    if (A.f <= B.c || B.f <= A.c) return false;
    return true;

}

int main() {
    // freopen ("B.in", "r", stdin);
    Cude A(0, 0, 0, 0, 0, 0), B(0, 0, 0, 0, 0, 0);
    cin >> A.a >> A.b >> A.c >> A.d >> A.e >> A.f;
    cin >> B.a >> B.b >> B.c >> B.d >> B.e >> B.f;
    if (is_intersect(A, B)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}