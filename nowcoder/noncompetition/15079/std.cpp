#include<iostream>
#include<algorithm>
#include<set>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
#define close_stdin  ios::sync_with_stdio(false)
#define P pair<int,int>
typedef long long ll;
const int maxn = 0;
int main()
{
    close_stdin;
    long long p;
    while (cin >> p) {
        ll ans = p;
        ans -= (p / 2 + p / 5 + p / 11 + p / 13);
        ans += (p / 10 + p / 22 + p / 26 + p / 55 + p / 65 + p / 143);
        ans -= (p / 110 + p / 130 + p / 715 + p / 286);
        ans += (p / 1430);
        cout << ans << "\n";
    }
}