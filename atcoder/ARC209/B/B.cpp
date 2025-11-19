#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size();

    map<char, int> cnt;
    for (int i = 0; i < n; i++) cnt[s[i]] += 1;

    int A = 0, B;
    for (auto [ch, number_ch] : cnt)  A = max(A, number_ch);
    B = n - A;
    
    if (A <= B) {
        vector<int> p;
        for (int i = 0; i < n; i += 2) p.push_back(i);
        for (int i = 1; i < n; i += 2) p.push_back(i);
        vector<pair<int, char>> num;
        for (auto [ch, number_ch] : cnt) {
            num.push_back({number_ch, ch});
        }
        sort(num.begin(), num.end());
        reverse(num.begin(), num.end());
        vector<char> t(n);
        int pos = 0;
        for (auto [number_ch, ch] : num) {
            for (int i = 0; i < number_ch; i++) 
                t[p[pos++]] = ch;
        }
        for (auto c : t) cout << c;
        cout << '\n';
    }
    else {
        int block = A / (B + 1) + (A % (B + 1) != 0);
        vector<int> p(B + 1, 0);
        
        vector<pair<int, char>> num;
        for (auto [ch, number_ch] : cnt) {
            num.push_back({number_ch, ch});
        }
        char max_ch = num[0].second;

        for (int i = 0; i < p.size(); i++) {
            int now = min(A, block);
            A -= now;
            p[i] = now;
        }

        for (int i = 0; i < p.size(); i++)
            cout << p[i] << '\n';

        // priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>> pq;

        
        for (int i = 0; i < p.size() - 1; i ++) {
            if (p[i] % 2 == 0 && p[i] > 0)
                p[i] -= 1, p[i + 1] += 1;
        }

        // for (int i = 0; i < p.size(); i++)
        //     cout << p[i] << '\n';

        vector<char> t;
        for (int i = 0; i < n; i++) 
            if (s[i] != max_ch) t.push_back(s[i]);
        
        for (int i = 0; i < p.size(); i++) {
            for (int j = 0; j < p[i]; j++) cout << max_ch;
            if (i < t.size()) cout << t[i];
        }
        cout << '\n';
    }
}

int main() {
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

