#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    if (s.size() == 3 && (s[0] == 'Y' || s[0] == 'y') && (s[1] == 'e' || s[1] == 'E') && (s[2] == 's' || s[2] == 'S')) cout << "accept" << '\n';
    else cout << "wrong answer" << '\n';
}