#include <bits/stdc++.h>
using namespace std;
int main() {

    freopen ("D.in", "r", stdin);
    freopen ("D0.out", "w", stdout);
    auto check = [&] (int x) {
        string s = to_string(x);
        if (s == string(s.rbegin(), s.rend())) return 1;
        return 0;
    };

    vector<int> p;
    for (int i = 0; i <= 1000000; i++)
        if (check(i)) p.push_back(i);
    sort (p.begin(), p.end());
    // for (int i = 0; i < p.size(); i++)
        // cout << i + 1 << " " << p[i] << endl;
    int N; cin >> N;
    cout << p[N - 1] << endl;
    return 0;
}