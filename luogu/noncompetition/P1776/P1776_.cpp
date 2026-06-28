#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e2 + 10;
int n, C;
int f[maxn];
struct node{
    int id, val;
    node(int id, int val):id(id), val(val){};
};
deque<node> q;
int main(){
    freopen ("P1776.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> C;
    for (int i = 1; i <= n; i++){
        int w, c, m; cin >> w >> c >> m;
        if (m > C/c) m = C/c;  // m 为物品数量
        for (int b = 0; b < c; b ++) { 
            q.clear(); q.push_back(node(0, 0));
            for (int y = 0; y <= (C - b) / c; y ++) {
                while (!q.empty() && q.front().id < y - m) q.pop_front(); 
                node cur(y, f[y * c + b] - w * y);
                f[y * c + b] = max(f[y * c + b], q.front().val + w * y);
                while (!q.empty() && q.back().val <= cur.val) q.pop_back();
                q.push_back(cur);
            }
        }
    }
    cout << f[C] << '\n';
    return 0;
}