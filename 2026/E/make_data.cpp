#include <bits/stdc++.h>
using namespace std;

int main() {
    srand(time(0));
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int n = rand() % 100000 + 1;
    for (int i = 1; i <= n; i++) {
        if (rand() % 2) {
            cout << char(rand() % 26 + 'a');
        }
        else {
            cout << char(rand() % 26 + 'A');
        }
    }
    return 0;
}
