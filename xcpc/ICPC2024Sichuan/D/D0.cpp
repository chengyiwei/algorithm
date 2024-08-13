#include <bits/stdc++.h>
using namespace std;

void flip_x(vector<vector<char>> &a) {
    reverse(a.begin(), a.end());
    for (auto &_ : a)
        for (auto &x : _) {
            if (x == 'U') x = 'D';
            else if (x == 'D') x = 'U';
        }
}

void flip_y(vector<vector<char>> &a) {
    for (auto &x : a) reverse(x.begin(), x.end());
    for (auto &_ : a)
        for (auto &x : _) {
            if (x == 'R') x = 'L';
            else if (x == 'L') x = 'R';
        }
}

void flip(vector<vector<char>> &a) {
    int n = a.size(), m = a[0].size();
    vector<vector<char>> b(m, vector<char>(n));
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++)
            b[j][i] = a[i][j];
    a = b;
    for (auto &_ : a)
        for (auto &x : _) {
            if (x == 'D') x = 'R';
            else if (x == 'R') x = 'D';
            else if (x == 'L') x = 'U';
            else if (x == 'U') x = 'L';
        }
}

vector<vector<char>> all_32() {
    vector<vector<char>> res(3, vector<char>(2));
    res[0] = {'C','L'};
    res[1] = {'U','D'};
    res[2] = {'R','C'};
    return res;
}

vector<vector<char>> all_23() {
    auto res = all_32();
    flip(res);
    return res;
}

vector<vector<char>> all_n6(int n) {
    vector<vector<char>> res(n, vector<char>(6));
    int pos = 0;
    if (n & 1) {
        auto a = all_32();
        for (int dy = 0; dy < 6; dy += 2) {
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 2; j++)
                    res[i][dy + j] = a[i][j];
        }
        pos = 3;
    }
    else {
        auto a = all_23();
        for (int dy = 0; dy < 6; dy += 3) {
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 3; j++)
                    res[i][dy + j] = a[i][j];
        }
        pos = 2;
    }
    auto b = all_23();
    while (pos < n) {
        for (int dy = 0; dy < 6; dy += 3) {
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 3; j++)
                    res[pos + i][dy + j] = b[i][j];
        }
        pos += 2;
    }
    return res;
} 

vector<vector<char>> all_6m(int m) {
    auto res = all_n6(m);
    flip(res);
    return res;
}

vector<vector<char>> get_n2(int n) {
    vector<vector<char>> res(n, vector<char>(2));
    res[0] = {'.','D'};
    res[1] = {'R','C'};
    for (int i = 2; i < n; i++) {
        if (i % 3 == 2) res[i] = {'C', 'L'};
        if (i % 3 == 0) res[i] = {'U', 'D'};
        if (i % 3 == 1) res[i] = {'R', 'C'};
    }
    return res;
}

vector<vector<char>> get_2m(int m) {
    auto res = get_n2(m);
    flip(res);
    return res;
}

vector<vector<char>> get_44() {
    vector<vector<char>> res(4, vector<char>(4));
    res[0] = {'C','L','D','.'};
    res[1] = {'U','D','C','L'};
    res[2] = {'D','C','L','D'};
    res[3] = {'C','L','R','C'};
    flip_y(res);
    return res;
}

vector<vector<char>> get_55 () {
    vector<vector<char>> res(5, vector<char>(5));
    res[0] = {'C','L','C','L','.'};
    res[1] = {'U','D','U','R','C'};
    res[2] = {'R','C','R','C','U'};
    res[3] = {'C','L','D','U','D'};
    res[4] = {'U','R','C','R','C'};
    flip_y(res);
    return res;
}

vector<vector<char>> get_77() {
    vector<vector<char>> res(7, vector<char>(7));
    res[0] = {'C','L','C','L','R','C','.'};
    res[1] = {'U','D','U','R','C','U','D'};
    res[2] = {'R','C','R','C','U','R','C'};
    res[3] = {'C','L','D','U','D','R','C'};
    res[4] = {'U','D','C','L','C','L','U'};
    res[5] = {'D','C','L','D','D','R','C'};
    res[6] = {'C','L','R','C','C','L','U'};
    flip_y(res);
    return res;
}

vector<vector<char>> get_47() {
    vector<vector<char>> res(4, vector<char>(7));
    res[0] = {'C','L','D','C','L','D','.'};
    res[1] = {'U','R','C','U','D','C','L'};
    res[2] = {'C','L','D','D','C','L','D'};
    res[3] = {'U','R','C','C','L','R','C'};
    flip_y(res);
    return res;
}

vector<vector<char>> get_74() {
    auto res = get_47();
    flip(res);
    return res;
}

vector<vector<char>> get(int n, int m) {
    if (n == 4 && m == 4) return get_44();
    if (n == 5 && m == 5) return get_55();
    if (m == 2) return get_n2(n);
    if (n == 2) return get_2m(m);
    if (n == 7 && m == 7) return get_77();
    if (n == 4 && m == 7) return get_47();
    if (n == 7 && m == 4) return get_74();
    vector<vector<char>> res(n, vector<char>(m, '.'));
    return res;
}

void solve() {
    int n, m; cin >> n >> m; int n_ = n, m_ = m;
    if (n * m % 3 != 1) { cout << "No\n"; return; }
    if (n == 1 || m == 1) { cout << "No\n"; return; }
    cout << "Yes\n";
    vector res(n, vector<char>(m, '.') );
    while (n_ > 7) n_ -= 6;
    auto A = all_6m(m);

    for (int pos_x = n_; pos_x < n; pos_x += 6) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < m; j++) {
                res[pos_x + i][j] = A[i][j];
            }
        }
    }
    while (m_ > 7) m_ -= 6;
    auto B = all_n6(n_);
    for (int pos_y = m_; pos_y < m; pos_y += 6) {
        for (int i = 0; i < n_; i++) {
            for (int j = 0; j < 6; j++) {
                res[i][pos_y + j] = B[i][j];
            }
        }
    }

    auto C = get(n_, m_);
    for (int i = 0; i < n_; i++) {
        for (int j = 0; j < m_; j++) {
            res[i][j] = C[i][j];
        }
    }

    flip_y(res);
    for (auto &x : res) {
        for (auto &y : x) cout << y;
        cout << '\n';
    }
}

int main() {
    freopen ("J.in", "r", stdin);
    freopen ("J.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}