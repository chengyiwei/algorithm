#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen ("L.in", "r", stdin);
    int T; cin >> T;
    int n; cin >> n;
    deque<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    freopen ("L.out", "r", stdin);
    string s; cin >> s;
    cout << s << "\n";
    for (auto c : s) {
        if (c == '1') {
            int tmp = a.front();
            a.pop_front(); a.push_back(tmp);
        }
        else if(c == '2'){
            int tmp1 = a.front(); a.pop_front();
            int tmp2 = a.front(); a.pop_front();
            a.push_back(tmp2);
            a.push_front(tmp1);
        }
        cout << " " << c << "\n";
        for(auto it : a){
            cout << it;
        }
        cout << "\n";
    }
    if (a == b) cout << "AC" << endl;
    else cout << "WA" << endl;
    return 0;
}