#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen ("E.in", "r", stdin);
    string s; cin >> s;
    int n = s.size();
    string t; t.resize(n);
    vector<deque<int>> v(26);
    for (int i = 0; i < s.size(); i++) {
        v[s[i] - 'a'].push_back(i);
    }
    
    auto put = [&] (int color1,int color2) {
        int pos1 = v[color1].front(), pos2 = v[color2].front();
        t[pos1] = color2 + 'a', t[pos2] = color1 + 'a';
        v[color1].pop_front(); v[color2].pop_front();
    };

    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < 26; i++) {
        if (v[i].size())
            pq.push({v[i].size(), i});       
    }
    while (!pq.empty()) {
        if (pq.size() == 3) {
            auto [siz1, clr1] = pq.top(); pq.pop();
            auto [siz2, clr2] = pq.top(); pq.pop();
            auto [siz3, clr3] = pq.top(); pq.pop();
            if (siz1 == siz2 && siz2 == siz3) {
                for (int i = 0; i < siz1; i++) {
                    int pos1 = v[clr1].front(), pos2 = v[clr2].front(), pos3 = v[clr3].front();
                    t[pos1] = clr2 + 'a', t[pos2] = clr3 + 'a', t[pos3] = clr1 + 'a';
                    v[clr1].pop_front(); v[clr2].pop_front(); v[clr3].pop_front();
                }
                break;
            }
            pq.push({siz1, clr1}); pq.push({siz2, clr2}); pq.push({siz3, clr3});
        }

        if (pq.size() == 1) {cout << "-1" << '\n'; return 0;}
        auto [siz1, clr1] = pq.top(); pq.pop();
        auto [siz2, clr2] = pq.top(); pq.pop();
        put(clr1, clr2);
        siz1 -= 1; siz2 -= 1;
        if (siz1) pq.push({siz1, clr1});
        if (siz2) pq.push({siz2, clr2});
    }
    cout << t << '\n';
    return 0;
}