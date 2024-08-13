#include<bits/stdc++.h>
#define endl '\n'

const int INF = 0x3f3f3f3f;
using namespace std;

vector<string> list_s = {"red", "edr", "dre", "der" , "erd", "rde"};

int main() {
    freopen ("K.in","r",stdin);
    freopen ("K.out","w",stdout);
    int n, m , q;
    cin >> n >> m >> q;
    vector<vector<char>> a(n + 1, vector<char>(m + 1));
    
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    
    vector<vector<vector<char> > > p;
    for (auto &s : list_s) {
        vector<vector<char> > t(n + 1, vector<char>(m + 1));
        for (int i = 1; i <= n; i += 1)
            for (int j = 1; j <= m; j += 1)
                t[i][j] = s[((i - 1) + (j - 1)) % 3];
        p.push_back(t);

        for (int i = 1; i <= n; i += 1)
            for (int j = 1; j <= m; j += 1)
                t[i][j] = s[(((i - 1) - (j - 1)) % 3 + 3) % 3];
        p.push_back(t);
    }

    vector<vector<vector<int> > > sum;
    for (auto &t : p) {
        vector<vector<int> > s(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i += 1)
            for (int j = 1; j <= m; j += 1)
                s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (t[i][j] != a[i][j]);
        sum.push_back(s);
    }

    while (q --) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        int ans = INF;
        if (x2 - x1 + 1 == 2 && y2 - y1 + 1 == 2) {
            for (auto &s : list_s) {
                char c1 = s[0], c2 = s[1];
                int now = 0;
                now += (a[x1][y1] != c1);
                now += (a[x1][y2] != c2);
                now += (a[x2][y1] != c2);
                now += (a[x2][y2] != c1);
                ans = min(ans, now);
            }
        }
        if(true) {
            for (auto &s : sum) {
                int now = s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
                ans = min(ans, now);
            }
        }
        cout << ans << endl;
    }

    return 0;
}