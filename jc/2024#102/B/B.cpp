#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> vis(N + 1, 0);
    vis[1] = 1;
    for (int i = 2; i * i <= N; i++) {
        int now = i * i;
        while (now <= N) {
            vis[now] = 1;
            now *= i;
        }
    }

    for (int i = N; i >= 1; i--) {
        if (vis[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}G