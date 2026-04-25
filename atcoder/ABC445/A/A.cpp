#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    if (*s.begin() == *s.rbegin())
        cout << "Yes\n";
    else 
        cout << "No\n";
    return 0;
}