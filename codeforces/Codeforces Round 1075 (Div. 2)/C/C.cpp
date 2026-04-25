#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n + 1, 0);
        if (n % 2 == 0) {
            a[n] = 1; a[1] = n;
            for (int i = 2; i < n; i++) 
                a[i] = i ^ 1;
        }
        else {
            a[n] = 1; a[1] = n - 1;
            for (int i = 2; i < n; i++) 
                a[i] = i ^ 1;
        }
        for (int i = 1; i <= n; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
    return 0;
}