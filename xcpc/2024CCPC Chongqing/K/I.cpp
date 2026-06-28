#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2e5 + 5;
ll n;
string s, p, q;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> s >> p;
    for (int i = 0; i < n; i++) {
        if ((s[i] == '0' && p[i] == '0') || (s[i] == '2' && p[i] == '0' ) || ( s[i] == '0' && p[i] == '2')  || (s[i] == '2' && p[i] == '2'))
        {
            cout << "0" << '\n'; return 0;
        }
    }
    cout << "1" << "\n";
    return 0;
}