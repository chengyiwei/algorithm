#include <bits/stdc++.h>
using namespace std;
int a[10];
int main() {
    a[1] = 0, a[2] = a[1] + 3, a[3] = a[2] + 1, a[4] = a[3] + 4, a[5] = a[4] + 1, a[6] = a[5] + 5, a[7] = a[6] + 9;
    char p, q;
    cin >> p >> q; p = p - 'A' + 1, q = q - 'A' + 1;
    cout << abs(a[p] - a[q]) << endl;
    return 0;
}