#pragma GCC optimize(2)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000000 + 5;

struct Node {
    string s1, s2;
    int m = 0;
};

int string_to_int(string s) {
    int res = 0;
    for (auto ch : s)
        res = res * 10 + ch - '0';
    return res;
}

string calc2(string s) {
    string res;
    vector<int> tmp;
    for (int i = 0; i < s.size(); ) {
        int j = i;
        while (j < s.size() && s[j] != '.') j++;
        
        int x = 0;
        for (int k = i; k < j; k++)
            x = x * 10 + s[k] - '0';
        tmp.push_back(x);

        i = j + 1;
    }
    for (auto x : tmp) {
        for (int i = 7; i >= 0; i--) 
            res.push_back((x >> i & 1) + '0');
    }
    return res;
}

string p[MAXN];
int nxt[MAXN][2];
int cnt;

void insert(Node a) {
    int now = 0;
    for (int i = 0; i < a.m; i++) {
        int op = a.s1[i] - '0';
        if (nxt[now][op] == 0) nxt[now][op] = ++cnt;
        now = nxt[now][op];
    }
    p[now] = a.s2;
}

string query(string s) {
    string res;
    int now = 0;
    for (int i = 0; i < s.size(); i++) {
        if (!p[now].empty()) res = p[now];
        int op = s[i] - '0';
        if (nxt[now][op] == 0) break;
        now = nxt[now][op];
    }
    if (!p[now].empty()) res = p[now];
    return res;
}


int main() {
    freopen ("G.in", "r", stdin);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        Node now;
        cin >> s; now.s1 = calc2(s);
        cin >> s; now.m = stoll(s);
        cin >> s; now.s2 = s;
        // cout << a[i].s1 << " " << a[i].m << " " << a[i].s2 << '\n';
        insert(now);
    }

    int m; cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> s;
        // cout << q[i] << '\n';
        cout << query(calc2(s)) << '\n';
    }
    
    return 0;
}