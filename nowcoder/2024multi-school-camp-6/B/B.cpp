#include <bits/stdc++.h>
using namespace std;
int main() {
    long long N, K; cin >> N >> K;
    if (N % 2 == 0 && K == N / 2) {
        cout << N << endl;
    }
    else if (K > N / 2) {
        K = N - K;
        cout << N * K + 1 << endl;
    }
    else {
        cout << N * K + 1 << endl;
    }
    return 0;
}