#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector mp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (a[i] > a[j]) mp[i][j] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cout << mp[i][j] << ' ';
        cout << endl;
    }
}