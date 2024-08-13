#include <bits/stdc++.h>
using namespace std;
string mp[10];
int main() {
    freopen ("B.in", "r", stdin);
    for (int i = 1; i <= 5; i++){
        getline(cin, mp[i]);
    }
    for (int i = 1; i <= 5; i++)
        mp[i] = " " + mp[i];
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 10; j++)
            putchar(mp[i][j]);
        putchar('\n');
    }
    int ans = -1;
    if (mp[3][6]=='&') {
        ans = (mp[2][1] - '0') & (mp[4][1] - '0') ;
    }
    if (mp[3][6]=='=') {
        ans = (mp[2][1] - '0') | (mp[4][1] - '0') ;
    }
    if (mp[3][6]=='1') {
        ans = ! (mp[3][1] - '0') ;
    }
    cout << ans << endl;
    return 0;
}