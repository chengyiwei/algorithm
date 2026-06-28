#include <bits/stdc++.h>
using namespace std;
int main() {
    string s; cin >> s;
    s = " " + s;
    int lst_0 = -1;
    for (int i = 1; i < s.size(); i++) 
        if (s[i] == '0')
            lst_0 = i;
    int ans = 0;
    for (int i = 1; i <= lst_0; i++) 
        if (s[i] == '1' && s[i - 1] != '1') 
            ans += 1;
    cout << ans << endl;
    return 0;
}