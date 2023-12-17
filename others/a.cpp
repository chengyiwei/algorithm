#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mp[1005];
ll p[1005];
vector<int> q;
ll n, t, x, a, ans;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> t;
    q.resize(1e9);
    while(n --)
    {
        cin >> x >> a;
        x <<= 1;
        for(int i = x - a - t + 1; i <= x + a + t - 1; i ++)
        {
//			cout << i << " ";
            mp[i] = 1;
        }
//        cout << endl;
//        cout << x - a - t << " " << x + a + t << endl; 
        p[x - a - t] = 1;
        p[x + a + t] = 1;
    }
    for(int i = -6000; i <= 6000; i ++)
        if(p[i] && !mp[i]) ans ++;
    cout << ans << endl;
    return 0;
}
