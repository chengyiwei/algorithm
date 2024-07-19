#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 2e5 + 5;
pii a[maxn];
int L[maxn],n,m;

int main() {
    ios::sync_with_stdio(0);
    long long F[100];
    F[0] = 1;
    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j <= i; j++)
            F[i] += F[j];
        cout << i << " " << F[i] << endl;
    }
    return 0;
}