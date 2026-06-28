#include <bits/stdc++.h>
using namespace std;

constexpr int c[6][6] = {
    {0, 0, 2, 2, 1, 1},
    {1, 2, 0, 1, 2, 0},
    {2, 1, 1, 0, 0, 2},
    {2, 1, 1, 0, 0, 2},
    {1, 2, 0, 1, 2, 0},
    {0, 0, 2, 2, 1, 1}
};


constexpr int c2[2][3] = {
    {0, 1, 2},
    {1, 0, 2}
};

constexpr int c3[2][6] = {
    {0, 0, 1, 1, 2, 2},
    {1, 1, 0, 0, 2, 2}
};

constexpr int c4[1][3] = {
    {0, 1, 2}
};

constexpr int c5[1][6] = {
    {0, 0, 1, 1, 2, 2}
};


constexpr int c6[4][6] = {
    {0, 0, 2, 2, 1, 1},
    {1, 2, 0, 1, 2, 0},
    {1, 2, 0, 1, 2, 0},
    {2, 1, 1, 0, 0, 2},
};

vector<vector<int>> get(int n, int m) {
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = c[i % 6][j % 6];
    return res;
}

vector<vector<int>> get2(int n, int m) {
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = c2[i][j];
    return res;
}

vector<vector<int>> get3(int n, int m) {
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = c3[i][j];
    return res;
}

vector<vector<int>> get4(int n, int m) {
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = c4[i][j];
    return res;
}

vector<vector<int>> get5(int n, int m) {
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = c5[i][j];
    return res;
}

vector<vector<int>> get6(int n, int m) {
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = c6[i][j % 6];
    return res;
}

vector<vector<int>> flip(int n, int m, vector<vector<int>> a) {
    vector<vector<int>> res(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = a[j][i];
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    
    vector<vector<int>> ans;

    // if (min(n, m) == 4 && max(n, m) % 6 != 0 && max(n, m) > 3) {
    //     cout << "No\n";
    //     return ;
    // }

    if (min(n, m) == 1) {
        if (max(n, m) == 3) {
            if (n == 1) ans = get4(n, m);
            else ans = flip(n, m, get4(m, n));
        }
        else if (max(n, m) == 6) {
            if (n == 1) ans = get5(n, m);
            else ans = flip(n, m, get5(m, n));
        }
        else {cout << "No\n"; return ;}
    }
    else if (min(n, m) == 2) {
        if ((max(n, m) == 3)) {
            if (n == 2) ans = get2(n, m);
            else ans = flip(n, m, get2(m, n));
        }
        else if (max(n, m) == 6) {
            if (n == 2) ans = get3(n, m);
            else ans = flip(n, m, get3(m, n));
        }
        else {
            cout << "No\n";
            return ;
        }

    }
    else if (min(n, m) == 3) {
        if (n == 3) ans = get(n, m);
        else ans = flip(n, m, get(m, n));
    }
    else if (min(n, m) == 4) {
        if (n == 4) ans = get6(n, m);
        else ans = flip(n, m, get6(m, n));
    }
    else {
        if (n % 3 == 0) {
            ans = get(n, m);
        }
        else {
            ans = flip(n, m,get(m, n));
        }
    }
    cout << "Yes\n";
    for (auto &v : ans) {
        for (auto &x : v)
            cout << x;
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}