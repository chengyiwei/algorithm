#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;  cin >> n;
    int s = 0;
    for (int i = 1; i < n; i++) {
        int x;  cin >> x; s += x;
    }
    cout << -s << endl;
    return 0;
}