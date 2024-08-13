#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("A.in", "w", stdout);
    srand(time(0));
    int t = 10;
    cout << t << endl;
    while (t--) {
        int n = rand() % 10 + 1;
        for (int i = 1; i <= n; i++) 
            if (rand() & 1)
                cout << "(";
            else 
                cout << "[";
        cout << endl;
    }
    return 0;
}