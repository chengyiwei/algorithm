#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    freopen ("F.in", "r", stdin);
    int N; cin >> N;
    string S, T; cin >> S >> T;
    int s = S.size(), t = T.size();
    vector<vector<int> > pos(26);
    for (int i = 0; i < s; i++)
        pos[S[i] - 'a'].push_back(i);
    vector<vector<int> > pre(s + 1, vector(20,0));


    auto check = [&](ll k) -> void {
        ll full = 0, odd = 0;
        for (auto c : T) {
            auto &a = pos[c];
            if (a.empty()) return false; // S 中没有字母 c
            if (a.size() < k) {
                ll ex_full = (k - 1) / a.size();
                k -= ex_full * a.size();
                full += ex_full;
            }
            auto p = lower_bound(a.begin(), a.end(), odd);
            if (p == a.end()) { // 后面都没有值了
                full += 1; odd = 0;
                p = lower_bound(a.begin(), a.end(), odd);
            }
            int suf_num = distance(a.end, p);
            
        }
    }

}