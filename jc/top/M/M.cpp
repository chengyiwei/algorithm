#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int> > r;
vector<int> a;
vector<vector<int> > max_x, min_x;

bool check (int pos, int x) {
    max_x[pos][pos] = min_x[pos][pos] = x;
    for (int i = pos - 1; i >= 1; i--) {
        max_x[i][pos] = max(max_x[i][pos - 1], x);
        min_x[i][pos] = min(min_x[i][pos - 1], x);
        if (max_x[i][pos] - min_x[i][pos] != r[i][pos])
            return 0;
    }
    a[pos] = x;
    return 1;
}

void dfs(int pos) {
    if (pos > n) {
        for (int i = 1; i <= n; i++)
            printf ("%d ", a[i]);
        exit (0);
    }
    
    if (check(pos, a[pos - 1] + r[pos - 1][pos]))
        dfs(pos + 1);
    if (check(pos, a[pos - 1] - r[pos - 1][pos]))
        dfs(pos + 1);
}

int main() {
    cin >> n;
    r.resize(n + 1, vector<int>(n + 1)); a.resize(n + 1); max_x.resize(n + 1, vector<int>(n + 1)); min_x.resize(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            cin >> r[i][j];
    a[1] = 0; max_x[1][1] = min_x[1][1] = 0;
    dfs(2);
}