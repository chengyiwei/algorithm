#include <bits/stdc++.h>
using namespace std;
int main() {
    map<int, int> mp;
    for (int i = 1; i < 10; i++) mp[i] = i + 1;
    for (auto [x, y] : mp) {
        cout << x << " " << y << '\n';
    }
    return 0;
}