#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    string lst, now; 
    for (int i = 1; i <= n; i++) {
        cin >> now;
        if (now == lst && now == "sweet" && i != n) {
            cout << "No" << endl;
            return 0;
        }
        lst = now;
    }
    cout << "Yes" << endl;
    return 0;
}