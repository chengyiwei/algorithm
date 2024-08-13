#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    string p1, p2;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '|') break;
        p1.push_back(s[i]);
    }

    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '|') break;
        p2.push_back(s[i]);
    }
    reverse(p2.begin(), p2.end());
    cout << p1 + p2 << endl;
    return 0;
}