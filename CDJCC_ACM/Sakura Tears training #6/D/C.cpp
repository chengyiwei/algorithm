#include <bits/stdc++.h>
using namespace std;

int ask (int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int res; cin >> res;
    return res;
}

int main() {
    int N, M, Q; cin >> N >> M >> Q;
    int ok = 0;
    vector<vector<int>> unknow;
    for (int i = 1; i <= 90; i++) {
        int fst = i * 11;
        vector<int> same, diff; same.push_back(fst);
        for (int j = 1; j <= 10; j++) {
            int now = fst + j;
            if (ask(fst, now) == 0) same.push_back(now);
            else diff.push_back(now);
        }
        if (diff.empty()) {
            ok = fst;
        }
        else {
            unknow.push_back(diff);
            unknow.push_back(same);
        }
    }
    for (int i = 1; i <= 10; i++) unknow.push_back({i});

    vector<vector<int>> ans;
    for (auto v : unknow) {
        if (ask(ok, v[0]) == 1) ans.push_back(v);
    }

    cout << "! ";
    for (auto v : ans) {
        for (int x : v) cout << x << ' ';
    }
    cout << endl;
    return 0;
}