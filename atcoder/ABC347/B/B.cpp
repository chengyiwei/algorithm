#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    set<string> st;
    for (int L = 1; L <= s.size(); L++) 
        for (int i = 0; i + L - 1 < s.size(); i++) {
            string t = s.substr(i, L);
            st.insert(t);
        }
    cout << st.size() << endl;
    return 0;
}