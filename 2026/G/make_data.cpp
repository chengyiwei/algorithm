#include <bits/stdc++.h>
using namespace std;

long long randll() {
    return (1ll * rand() << 31) | rand();
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int A = rand() % 100000000 + 1;
    int B = rand() % 100000000 + 1;
    cout << A << ' ' << B << '\n';
    return 0;
}
