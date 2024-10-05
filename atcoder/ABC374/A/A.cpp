#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    int n = s.size();
    if (n >= 3 && s[n - 3] == 's' && s[n - 2] == 'a' && s[n - 1] == 'n') cout << "Yes" << endl;
    else cout << "No" << endl;
}