#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val, id;
    bool operator < (const Node &B) const{
        return val < B.val;
    }
};

bool is_ok(vector<Node> &a) {
    for (auto v : a) {
        if (v.id == 1) return true;
    }
    return false;
}

void solve() {
    vector<Node> a(33);
    for (int i = 1; i <= 32; i++) cin >> a[i].val, a[i].id = i;
    vector<Node> tmp;
    vector<Node> match_16; match_16.push_back({0, 0});
    vector<Node> match_8; match_8.push_back({0, 0});
    vector<Node> match_4; match_4.push_back({0, 0});
    vector<Node> match_2; match_2.push_back({0, 0});
    vector<Node> match_1; match_1.push_back({0, 0});
    for (int i = 1; i <= 32; i += 4) {
        tmp.clear();
        for (int j = 0; j < 4; j++)
            tmp.push_back(a[i + j]);
        sort(tmp.begin(), tmp.end());
        match_16.push_back(tmp[2]); match_16.push_back(tmp[3]);
    }
    if (!is_ok(match_16)) {cout << 32 << '\n'; return ;}

    for (int i = 1; i <= 16; i += 4)
        match_8.push_back(max(match_16[i], match_16[i + 3]));
    for (int i = 2; i <= 16; i += 4) 
        match_8.push_back(max(match_16[i], match_16[i + 1]));
    if (!is_ok(match_8)) {cout << 16 << '\n'; return ;}

    for (int i = 1; i <= 8; i += 2) 
        match_4.push_back(max(match_8[i], match_8[i + 1]));
    if (!is_ok(match_4)) {cout << 8 << '\n'; return ;}

    
    for (int i = 1; i <= 4; i += 2) 
        match_2.push_back(max(match_4[i], match_4[i + 1]));
    if (!is_ok(match_2)) {cout << 4 << '\n'; return ;}

    match_1.push_back(max(match_2[1], match_2[2]));
    if (!is_ok(match_1)) {cout << 2 << '\n'; return ;}
    else {cout << 1 << '\n'; return ;}
}

int main() {
    freopen ("A.in", "r", stdin);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}