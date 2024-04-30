#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    string s; cin >> s;
    vector<int> cnt(10, 0);
    int j = 0;
    
    auto check = [&] () {
        for (int i = 0; i < 10; i++)
            if (cnt[i] > i) return false;
        return true;
    };
    ll ans = 0;
    for (int i= 0; i < s.size(); i++) {
        cnt[s[i] - '0']++;
        while (!check()) 
            cnt[s[j++] - '0']--;
        ans += i - j + 1;
    }
    cout << ans << endl;
    return 0;
}