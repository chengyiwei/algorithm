#include <bits/stdc++.h>
using namespace std;
priority_queue<int,vector<int>, greater<int> > pq;
int main() {
    int n; cin >> n;
    for (int i = 0; i <= n; i++) {
        int x; cin >> x;
        pq.push(x);
    }
    while (!pq.empty()) {
        cout << pq.top() << ",";
        pq.pop();
    }
}