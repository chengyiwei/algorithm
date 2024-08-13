#include <bits/stdc++.h>
using namespace std;
const int maxn = 200;
int c1[maxn + 1], c2[maxn + 1];
int main() {
    int n;
    for (int i = 0; i <= maxn; i++)
        c1[i] = 1;
    for (int k = 2; k <= maxn; k++) {
        for (int i = 0; i <= maxn; i++)
            for (int j = 0; j + i <= maxn; j += k) 
                c2[i + j] += c1[i];
        for (int i = 0; i <= maxn; i++) c1[i] = c2[i], c2[i] = 0;
    }
    while (cin >> n) {
        cout << c1[n] << endl;
    }
    return 0;
}