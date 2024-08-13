#include <bits/stdc++.h>
using namespace std;
string s;

void reverse(int x) {
    if (x < 0) return;
    cout << s[x];
    reverse(x - 1);
}

int main() {
    cin >> s;
    reverse(s.size() - 1);
}