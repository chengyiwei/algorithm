#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<int> st;
    int n; cin >> n;
    int pos = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (st.size() > 0 && x == st.top()) st.pop();
        else if (pos < x) {
            for (int j = pos + 1; j < x; j++) st.push(j);
            pos = x;
        }
        else {
            cout << "NO" << endl;
            return 0;
        }
    }
    if (st.size() == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}