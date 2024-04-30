#include <bits/stdc++.h>
using  namespace std;
int main() {
    int op = 0;
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int now; cin >> now;
        op ^= 1;
    }
    if (op == 0) 
        cout << "zzy" << endl;
    else 
        cout << "miao" << endl;
    return 0;
}