#include <bits/stdc++.h>
using namespace std;

int brand() {
    return rand();
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cout << rand() % 100 + 1 << ' ' << rand() % 100 + 1 << '\n';
    return 0;
}