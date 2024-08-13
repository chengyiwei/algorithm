#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] = abs(a[i]);
    for (int i = 1; i < n; i++)
        a[i + 1] = __gcd(a[i], a[i + 1]);
    cout << a[n] << endl;
    return 0; 
}