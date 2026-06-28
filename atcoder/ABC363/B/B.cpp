#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, t, p; cin >> n >> t >> p;
    int num = 0;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    while (true) {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (h[i] >= t) cnt++;
        if (cnt >= p)
            break;
        for (int i = 1; i <= n; i++)
            h[i] += 1;
        num++;
    }
    cout << num << endl;
    return 0;
}