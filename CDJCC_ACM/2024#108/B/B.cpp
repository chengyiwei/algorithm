#include <bits/stdc++.h>
using namespace std;
int main() {
    string S, T; cin >> S >> T;
    set<int> st;
    for (int i = 0; i < S.size(); i++) {
        int cz = (S[i] - T[i] + 26) % 26;
        st.insert(cz);
    }
    cout << (st.size() == 1 ? "Yes" : "No") << endl;
    return 0;
}