#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    s = s.substr(3,3);
    int x = 0;
    x = (s[0] -'0') * 100 + (s[1] - '0') * 10 + (s[2] - '0');
    if (x >= 350)
        return cout << "No" << endl, 0;
    if (x == 316)
        return cout << "No" << endl, 0;
    if (x <= 0)
        return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    return 0;
}