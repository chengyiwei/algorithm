#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int n_ = n;
    int x = 0;
    while (n) {
        x += n % 10;
        n /= 10;
    }
    // cout << x << endl;
    if (int(sqrt(x)) * int(sqrt(x)) == x && int(sqrt(n_)) * int(sqrt(n_)) == n_) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}