#include <bits/stdc++.h>
using namespace std;


struct Node {
    int id;
    pair<int, int> p;
};

vector<int> c;

void update(int x, int v) {
    for (int i = x; i < c.size(); i += i & -i) c[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= i & -i) res += c[i];
    return res;

}

vector<int> calc1(vector<Node> b) {  // 返回 x < x0, y < y0
    int n = b.size();
    
    sort(b.begin(), b.end(), [&](Node x, Node y) {
        return x.p < y.p;
    });

    vector<int> res(n);
    c.assign(n + 1, 0);

    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && b[j].p.first == b[i].p.first) j++;
        for (int k = i; k < j; k++)
            res[b[k].id] = query(b[k].p.second - 1);
        for (int k = i; k < j; k++)
            update(b[k].p.second, 1);
        i = j;
    }

    return res;
}

vector<int> calc2(vector<Node> b) { // 返回 x >= x0, y < y0 
    int n = b.size();
    sort(b.begin(), b.end(), [&](Node x, Node y) {
        return x.p > y.p;
    });

    vector<int> res(n);
    c.assign(n + 1, 0);

    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && b[j].p.first == b[i].p.first) j++;
        for (int k = i; k < j; k++)
            update(b[k].p.second, 1);
        for (int k = i; k < j; k++)
            res[b[k].id] = query(b[k].p.second - 1);
        i = j;
    }
    return res;
}

vector<int> calc3(vector<Node> b) { // 返回 x < x0, y >= y0
    int n = b.size();
    sort(b.begin(), b.end(), [&](Node x, Node y) {
        return x.p < y.p;
    });
    
    vector<int> res(n);
    c.assign(n + 1, 0);
    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && b[j].p.first == b[i].p.first) j++;
        for (int k = i; k < j; k++)
            res[b[k].id] = query(n) - query(b[k].p.second - 1);
        for (int k = i; k < j; k++)
            update(b[k].p.second, 1);
        i = j;
    }

    return res;
}

vector<int> calc4(vector<Node> b) { // 返回 x >= x0, y >= y0
    int n = b.size();
    sort(b.begin(), b.end(), [&](Node x, Node y) {
        return x.p > y.p;
    });

    vector<int> res(n);
    c.assign(n + 1, 0);
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && b[j].p.first == b[i].p.first) j++;
        for (int k = i; k < j; k++)
            update(b[k].p.second, 1);
        for (int k = i; k < j; k++)
            res[b[k].id] = query(n) - query(b[k].p.second - 1);
        i = j;
    }
    return res;
}

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;

    vector<int> tmp_x;
    vector<Node> b(n);  
    for (int i = 0; i < n; i++) b[i].id = i, b[i].p = a[i];
    for (int i = 0; i < n; i++) tmp_x.push_back(a[i].first);
    sort(tmp_x.begin(), tmp_x.end());
    tmp_x.erase(unique(tmp_x.begin(), tmp_x.end()), tmp_x.end());
    for (int i = 0; i < n; i++) b[i].p.first = lower_bound(tmp_x.begin(), tmp_x.end(), a[i].first) - tmp_x.begin();
    vector<int> tmp_y;
    for (int i = 0; i < n; i++) tmp_y.push_back(a[i].second);
    sort(tmp_y.begin(), tmp_y.end());
    tmp_y.erase(unique(tmp_y.begin(), tmp_y.end()), tmp_y.end());
    for (int i = 0; i < n; i++) b[i].p.second = lower_bound(tmp_y.begin(), tmp_y.end(), a[i].second) - tmp_y.begin();
    
    for (int i = 0; i < n; i++) {
        b[i].p.first++;
        b[i].p.second++;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << b[i].p.first << ' ' << b[i].p.second << '\n';
    // }

    // exit(0);

    vector<int> res1 = calc1(b), res2 = calc2(b), res3 = calc3(b), res4 = calc4(b);

    int k = 0;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        int tmp = min({res1[i], res2[i], res3[i], res4[i]});
        if (tmp > k) {
            k = tmp;
            pos = i;
        }
    }
    cout << k << '\n';
    cout << a[pos].first << ' ' << a[pos].second << '\n';
}

int main() {
    freopen ("E.in", "r", stdin);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}