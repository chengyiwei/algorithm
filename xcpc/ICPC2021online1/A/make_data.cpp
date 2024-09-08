#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "w", stdout);
    srand(time(0));
    int n = rand() % 50 + 1, k = rand() % 10 + 1;
    cout << k << ' ' << n << endl;
    vector<pair<int, int>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        a[i].first = rand() % 100 + 1, a[i].second = rand() % 5 + 1;
    }
    sort(a.begin() + 1, a.end());
    for (int i = 1; i <= n; i++) 
        cout << a[i].first << " " << a[i].second << '\n';
    return 0;
}