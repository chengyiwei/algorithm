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
            b[j][i] = a[n - i - 1][m - j - 1];
    a = b;
    for (auto &_ : a)
        for (auto &x : _) {
            if (x == 'D') x = 'L';
            else if (x == 'R') x = 'U';
            else if (x == 'L') x = 'D';
            else if (x == 'U') x = 'R';
        }
}

vector<vector<char>> get_n2(int n) {
    vector<vector<char>> res(n, vector<char>(2));
    res[0] = {'D','.'};
    res[1] = {'C','L'};
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
    return res;
}

vector<vector<char>> get_55 () {
    vector<vector<char>> res(5, vector<char>(5));
    res[0] = {'C','L','C','L','.'};
    res[1] = {'U','D','U','R','C'};
    res[2] = {'R','C','R','C','U'};
    res[3] = {'C','L','D','U','D'};
    res[4] = {'U','R','C','R','C'};
    return res;
}



vector<vector<char>> get(int n, int m) {
    if (n == 4 && m == 4) return get_44();
    if (n == 5 && m == 5) return get_55();
    if (m == 2) return get_n2(n);
    if (n == 2) return get_2m(m);
    vector<vector<char>> res(n, vector<char>(m));
    if (n == m) {
        if (n % 3 == 1) {
            auto A = get(n - 2, m - 2), B = get_n2(2), C = get(2, m - 2), D = get(n - 2, 2);
            flip_x(C); flip_y(D); A[0].back() = 'C'; C.back().back() = 'D'; D.front().front() = 'L';
            int dx, dy;

            dx = 2, dy = 0;
            for (int i = 0; i < n - 2; i++) 
                for (int j = 0; j < m - 2; j++) 
                    res[i + dx][j + dy] = A[i][j];
        
        dx = 0, dy = m - 2;
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < 2; j++) 
                res[i + dx][j + dy] = B[i][j];
        
        dx = 0, dy = 0;
        for (int i = 0; i < 2; i++)
                for (int j = 0; j < m - 2; j++)
                    res[i + dx][j + dy] = C[i][j];
            
            dx = 2, dy = m - 2;
            for (int i = 0; i < n - 2; i++)
                for (int j = 0; j < 2; j++)
                    res[i + dx][j + dy] = D[i][j];
        }
        else {
            auto A = get(n - 4, m - 4), B = get_44(), C = get(4, m - 4), D = get(n - 4, 4);
            flip_x(C); flip_y(D); A[0].back() = 'C'; C.back().back() = 'D'; D.front().front() = 'L';
            int dx, dy;

            dx = 4, dy = 0;
            for (int i = 0; i < n - 4; i++) 
                for (int j = 0; j < m - 4; j++) 
                    res[i + dx][j + dy] = A[i][j];
            
            dx = 0, dy = m - 4;
            for (int i = 0; i < 4; i++) 
                for (int j = 0; j < 4; j++) 
                    res[i + dx][j + dy] = B[i][j];

            dx = 0, dy = 0;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < m - 4; j++)
                    res[i + dx][j + dy] = C[i][j];

            dx = 4, dy = m - 4;
            for (int i = 0; i < n - 4; i++)
                for (int j = 0; j < 4; j++)
                    res[i + dx][j + dy] = D[i][j];
        }
    }
    else {
        if (n % 3 == 1) {
            int L = min(n, m) - 2;
            auto A = get(L, L), B = get(n - L, m - L), C = get(n - L, L), D = get(L, m - L);
            flip_x(C); flip_y(D); A[0].back() = 'C'; C.back().back() = 'D'; D.front().front() = 'L';
            int dx, dy;

            dx = n - L, dy = 0;
            for (int i = 0; i < L; i++)
                for (int j = 0; j < L; j++)
                    res[i + dx][j + dy] = A[i][j];
            
            dx = 0, dy = L;
            for (int i = 0; i < n - L; i++)
                for (int j = 0; j < m - L; j++)
                    res[i + dx][j + dy] = B[i][j];
            
            dx = 0, dy = 0;
            for (int i = 0; i < n - L; i++)
                for (int j = 0; j < L; j++)
                    res[i + dx][j + dy] = C[i][j];
            
            dx = n - L, dy = L;
            for (int i = 0; i < L; i++)
                for (int j = 0; j < m - L; j++)
                    res[i + dx][j + dy] = D[i][j];
        }
        else {
            int L = min(n, m) - 4;
            auto A = get(L, L), B = get(n - L, m - L), C = get(n - L, L), D = get(L, m - L);
            flip_x(C); flip_y(D); A[0].back() = 'C'; C.back().back() = 'D'; D.front().front() = 'L';
            int dx, dy;

            dx = n - L, dy = 0;
            for (int i = 0; i < L; i++)
                for (int j = 0; j < L; j++)
                    res[i + dx][j + dy] = A[i][j];
            
            dx = 0, dy = L;
            for (int i = 0; i < n - L; i++)
                for (int j = 0; j < m - L; j++)
                    res[i + dx][j + dy] = B[i][j];
            
            dx = 0, dy = 0;
            for (int i = 0; i < n - L; i++)
                for (int j = 0; j < L; j++)
                    res[i + dx][j + dy] = C[i][j];
            
            dx = n - L, dy = L;
            for (int i = 0; i < L; i++)
                for (int j = 0; j < m - L; j++)
                    res[i + dx][j + dy] = D[i][j];
        }
    }
    return res;
}

void solve() {
    int n, m; cin >> n >> m;
    if (n * m % 3 != 1) {cout << "No\n"; return ;}
    else cout << "Yes\n";
    auto res = get(n, m);
    for (auto &x : res) {
        for (auto &y : x) cout << y;
        cout << '\n';
    }
}

int main() {
    freopen ("D.in", "r", stdin);
    freopen ("D.out", "w", stdout);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}