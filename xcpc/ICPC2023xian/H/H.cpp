#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen ("H.in","r",stdin);
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int ccf = -1;
    for (int i = 0; i < n; i++) {
        int cf = a[i] - a[(i - 1 + n) % n];
        cf = (cf + n) % n;
        if (ccf == -1) ccf = cf;
        else if (ccf != cf) {
            cout << -1 << endl;
            return 0;
        }
    }
    if (a[0] == 0) {
        if (ccf == 0) 
            cout << 0 << endl;
        else 
            cout << ccf << endl;
    }
    else {
        if (ccf == 0)
            cout << n + 1 << endl;
        else
            cout << ccf + 1 << endl;
    }
    return 0;
}