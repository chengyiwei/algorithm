#include <bits/stdc++.h>
using namespace std;
int main() {
    int W, B; cin >> W >> B;
    string s, p = "wbwbwwbwbwbw";
    while (s.size() < 2000) s += p;
    int n = s.size(); s = " " + s; 
    vector<int> sumb(n + 1), sumw(n + 1);
    for (int i = 1; i <= n; i++) {
        sumb[i] = sumb[i - 1] + (s[i] == 'b');
        sumw[i] = sumw[i - 1] + (s[i] == 'w');
    }
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) {
            int nw = sumw[j] - sumw[i - 1], nb = sumb[j] - sumb[i - 1];
            if (W == nw && B == nb) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    cout << "No" << endl;
    return 0;
}