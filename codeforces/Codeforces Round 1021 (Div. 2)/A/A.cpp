#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int cnt[10] = {0};
        for (char c : s) {
            cnt[c - '0']++;
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < cnt[9 - i]; j++) {
                pq.push(9 - i);
            }
            cout << pq.top();
            pq.pop();
        }
        cout << endl;
    }
    return 0;
}