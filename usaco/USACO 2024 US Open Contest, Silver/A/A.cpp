#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("A.in", "r", stdin);
    int N, K; cin >> N >> K;
    priority_queue<pair<ll, int>,vector<pair<ll, int> >, greater<pair<ll, int>> > pq;
    vector<ll> t(N + 1);
    vector<int> fa(N + 1);
    iota(fa.begin(), fa.end(), 0);

    function<int(int)> find = [&](int x) {
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    };

    function<void(int, int) > merge = [&](int x, int y) {
        int fx = find(x), fy = find(y);
        if (fx != fy) fa[fx] = fy;
        return ;
    };

    for (int i = 1; i <= N; i++) cin >> t[i];
    for (int i = 1; i <= K; i++) pq.push({t[i], i});
    int pos = K + 1;
    vector<int> same_idx;
    while (pos <= N) {
        same_idx.clear();
        auto [time, idx] = pq.top(); pq.pop();
        same_idx.push_back(idx);
        while (!pq.empty() && pq.top().first == time) {
            same_idx.push_back(pq.top().second); pq.pop();
        }
        for (int i = 1; i < same_idx.size(); i++) 
            merge(same_idx[i - 1], same_idx[i]);
        for (auto idx : same_idx) {
            if (pos > N)
                break;
            pq.push({time + t[pos], idx});
            pos++;
        }
    }
    auto idx = pq.top().second;
    cout << pq.top().first << endl;
    for (int i = 1; i <= K; i++)
        cout << int(find(i) == find(idx));
    return 0;
}