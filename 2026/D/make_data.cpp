#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n = rand() % 100000 + 1;
    cout << n << '\n';
    int no = rand() % n + 1;
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (i != no) v.push_back(i);
    }
    random_shuffle(v.begin(), v.end());
    for (auto x : v) cout << x << ' ';
    cout << '\n';
    return 0;
}
