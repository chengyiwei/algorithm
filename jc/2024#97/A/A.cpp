#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int n; cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i + 2 < s.size(); i++) {
        if (s.substr(i, 3) == "ABC") {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}