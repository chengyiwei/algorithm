#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[4];
    for (int i = 1; i <= 3; i++) cin >> a[i];
    string s; cin >> s;
    int C = 0;
    if (s[0] == 'R') C = 1;
    if (s[0] == 'G') C = 2;
    if (s[0] == 'B') C = 3;
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= 3; i++) if (i != C) q.push(a[i]);
    cout << q.top() << endl;
    return 0;
}