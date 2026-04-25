#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R;
    cin >> N >> L >> R;
    string S;
    cin >> S;

    // 分类存储下标
    vector<int> pos[26];
    for (int i = 0; i < N; ++i) {
        pos[S[i] - 'a'].push_back(i); // 这里用 0-indexed 也没问题
    }

    ll total_count = 0;

    for (int c = 0; c < 26; ++c) {
        const vector<int>& v = pos[c];
        int m = v.size();
        if (m < 2) continue;

        int p1 = 0; 
        int p2 = 0; 

        for (int j = 0; j < m; ++j) {
            int target_min = v[j] - R;
            int target_max = v[j] - L;

            while (p1 < m && v[p1] < target_min) {
                p1++;
            }
            while (p2 < m && v[p2] <= target_max) {
                p2++;
            }
            if (p2 > p1) {
                total_count += (p2 - p1);
            }
        }
    }

    cout << total_count << endl;

    return 0;
}