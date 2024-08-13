#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> up;
    priority_queue<int> dn;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int mid = a[1];
    cout << mid << endl;
    for (int i = 2; i <= n; i ++) {
        if (a[i] > mid) up.push(a[i]);
        else dn.push(a[i]); 
        if (i % 2 == 1) {
            while (dn.size() != up.size()) {
                if (dn.size() > up.size()) {
                    up.push(mid);
                    mid = dn.top();
                    dn.pop();
                } else {
                    dn.push(mid);
                    mid = up.top();
                    up.pop();
                }
            }
            cout << mid << endl;
        }
    }
    return 0;
}