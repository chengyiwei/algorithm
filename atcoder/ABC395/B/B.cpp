#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            const auto tmp = min({i, j, N - i - 1, N - j - 1});
            cout << "#."[tmp&1];
        }
        cout << '\n';
    }
    return 0;
}