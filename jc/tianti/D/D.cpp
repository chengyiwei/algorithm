#include <bits/stdc++.h>
using namespace std;
int main() {
    int p; double sum = 0; cin >> p;
    for (int i = 1; i; i++) {
        sum += 1.0 / i;
        if (sum > p) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}