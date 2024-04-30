#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    for (int x = 0; x <= max(n, m); x++) {
        if ((m + x) % (n + x) == 0)
            return cout << x << endl, 0;
    }
    cout << -1 << endl;
    return 0;
}