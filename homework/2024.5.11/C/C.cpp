#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll F(int x) {
    if (x == 1) return 1;
    if (x == 2) return 1;
    return F(x - 1) + F(x - 2);
}


int main() {
    int n; cin >> n;
    cout << F(n);
}