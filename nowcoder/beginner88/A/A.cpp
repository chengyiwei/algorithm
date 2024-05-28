#include <bits/stdc++.h>
using namespace std;
int main() {
    int x; cin >> x;
    int n; cin >> n;
    char max_ch;
    int max_x = 0;
    for (int i = 1; i <= n; i++) {
        char ch; int p;
        cin >> ch >> p;
        if (p > max_x) {
            max_x = p;
            max_ch = ch;
        }
    }
    for (int i = 0; i < x; i+= max_x) {
        cout << max_ch;
    }
    cout << endl;
    return 0;
}