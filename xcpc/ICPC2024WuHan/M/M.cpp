#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
map<ll, int> mp;

stack<ll> need;

bool check(ll x) { //验证 x 是否能组成
    bool flg = 0;
    if (mp.count(x) && mp[x] > 0) {
        mp[x] -= 1;
        need.push(x);
        return 1;
    }
    else if (x & 1) {
        if (check(x / 2) && check(x - x / 2)) {
            return 1;
        }
    }
    return 0;
}

int main() {
    freopen ("M.in", "r", stdin);
    freopen ("M.out", "w", stdout); 
    int n; cin >> n;
    vector<ll> a(n + 1, 0);
    vector<ll> ans;
    priority_queue<ll> pq_odd, pq_even;
    for (int i = 1; i <= n; i++) {
        cin >> a[i], mp[a[i]] += 1;
        if (a[i] % 2 == 1) pq_odd.push(a[i]);
        else pq_even.push(a[i]);
    }

    while (!pq_even.empty()) {
        ll x = pq_even.top(); pq_even.pop(); if (mp[x] <= 0) continue;

        while (!pq_odd.empty() && pq_odd.top() > x + 1) {
            if (mp[pq_odd.top()] > 0) {
                mp[pq_odd.top()]--;
                ans.push_back(pq_odd.top());
                continue;
            }
            pq_odd.pop();
        }

        if (check(2 * x + 1)) {
            mp[x * 2 + 1] += 1;
            while (!need.empty())
                need.pop();
            pq_odd.push(x * 2 + 1);
        }
        else {
            while (!need.empty()) {
                mp[need.top()] += 1;
                need.pop();
            }
            if (check(2 * x - 1)) {
                while (!need.empty())
                    need.pop();
                mp[x * 2 - 1] += 1;
                pq_odd.push(x * 2 - 1);
            }
            else {
                while (!need.empty()) {
                    mp[need.top()] += 1;
                    need.pop();
                }
                mp[x] -= 1;
                ans.push_back(x);
            }
        }
        
    }

    while (!pq_odd.empty()) {
        if (mp[pq_odd.top()] <= 0) {
            pq_odd.pop();
            continue;
        }
        ans.push_back(pq_odd.top());
        mp[pq_odd.top()] -= 1;
        pq_odd.pop();
    }

    cout << ans.size() << endl;
    sort (ans.begin(), ans.end(), greater<ll>());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " \n"[i == ans.size() - 1];
    return 0;
}