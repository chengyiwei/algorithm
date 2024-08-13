#include <bits/stdc++.h>
using namespace std;
int brand() {
    return (rand() << 16) + (rand() << 1) + (rand() & 1);
}
int main() {
    freopen ("B.in", "w", stdout);
    int t = 10;
    cout << t << '\n';
    while (t--) {
        for (int i = 1; i <= 5; i++)
            cout << brand() % 10 << ' ';
        cout << '\n';
    }
    return 0;
}