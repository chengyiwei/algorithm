#include <bits/stdc++.h>
using namespace std;
int main () {
    int n, x; cin >> n >> x;
    if ((x + n) % 2 != 0) {
        cout << "-1" << endl;
    }
    else
        cout << (x + n) / 2 << " " << n - (x + n) / 2 << endl;
    return 0;
}