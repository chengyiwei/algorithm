#include <bits/stdc++.h>
using namespace std;

string p = "xwr";

void solve() {
    int x; getchar();
    for (int j = 0; j < 3; j++) {
        x = getchar() - '0';
        for (int i = 2; i >= 0; i--) 
            if (x >> i & 1) 
                cout << p[i];
            else 
                cout << "-";

    }
    cout << endl;
}

int main() {
    int T; cin >> T;
    while (T--) solve();
    return 0;
}