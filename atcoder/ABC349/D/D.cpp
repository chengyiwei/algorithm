#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> pll;

vector<pll> merge(const vector<pll>& left, const vector<pll>& right) {
    vector<pll> result;
    result.reserve(left.size() + right.size()); // Ensure enough space is reserved.
    std::merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(result));
    return result;
}

vector<pll> f (ull l, ull r, ull ql, ull qr) {
    if (ql <= l && r <= qr)
        return {{l, r}};
    auto m = (l + r) / 2;
    if (qr <= m)
        return f(l, m, ql, qr);
    if (ql >= m)
        return f(m, r, ql, qr);
    return merge(f(l, m, ql, qr), f(m, r, ql, qr)); // Use std::merge instead of merge
}

int main() {
    freopen ("D.in", "r", stdin);
    ull L, R; cin >> L >> R;
    auto v = f(0, 1ull << 60, L, R);
    sort (v.begin(), v.end());
    cout << v.size() << endl;
    for (auto &[l, r] : v)
        cout << l << " " << r << endl;
    return 0;
}